//
// Created by alber on 1/3/2018.
//

#include "MapParser.h"

const shared_ptr<spd::logger> MapParser::log = spd::stdout_color_mt("Map Parser");

MapParser::MapParser(const string& searchDir) {
    path = searchDir;

}

vector<string> MapParser::getPathsOnDir() {
    HANDLE hFind;
    WIN32_FIND_DATA data;

    string pathToSearch = path + "*.map";
    vector<string> files;
    hFind = FindFirstFile( pathToSearch.c_str(), &data);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            files.emplace_back(data.cFileName);
        } while (FindNextFile(hFind, &data));
        FindClose(hFind);
    }
    return files;
}

TileGrid MapParser::getGrid(const string &gridName) {
    bool validName = false;
    for(const string& i : getPathsOnDir()){
        if(i == gridName){
            validName = true;
        }
    }
    if(!validName){
        log->error( "Not a valid name provided for MapParser");
        assert(validName);
    }
    ifstream file(path + gridName);
    int lineCounter = 0;
    string stringBuffer;
    getline(file, stringBuffer);
    lineCounter++;
    stringstream streamBuffer(stringBuffer);
    int numBuffer;

    vector<int> setupLine;
    int counter = 0;
    while(streamBuffer >> numBuffer){
            setupLine.emplace_back(numBuffer);
            counter++;
        if(streamBuffer.peek() == ' '){
            streamBuffer.ignore();
        }
    }

    if(counter != 3){
        log->error("Error on first line of: {}, expected 3 values, read: {}", path + gridName, counter);
        assert(counter == 3);
    }

    StartingMapConfig setupConfig(setupLine[0], setupLine[1], setupLine[2]);
    vector<vector<Tile>> tileGrid;
    int currentColumn = 0;
    while(getline(file, stringBuffer)) {
        lineCounter++;
        log->info("Reading line: {} from: {}", lineCounter, path + gridName);
        streamBuffer = stringstream(stringBuffer);
        vector<int> tileSettings;
        while (streamBuffer >> numBuffer) {
            tileSettings.emplace_back(numBuffer);
            log->info("Read at line: {} value: {}", lineCounter, numBuffer);
            if(streamBuffer.peek() == ' '){
                streamBuffer.ignore();
            }
        }
        if(tileSettings.size() != 11){
            log->error("Error on line: {} of: {}, expected 11 values, read; {}", lineCounter, path + gridName, tileSettings.size());
            assert(tileSettings.size() == 11);
        }
        TileWalls wall;

        wall.left = Wall( (bool)tileSettings[2], static_cast<VisualVictim>(tileSettings[3]));
        wall.top = Wall( (bool)tileSettings[4], static_cast<VisualVictim> (tileSettings[5]));
        wall.right = Wall((bool)tileSettings[6], static_cast<VisualVictim>(tileSettings[7]));
        wall.bottom = Wall((bool)tileSettings[8], static_cast<VisualVictim>(tileSettings[9]));

        auto status = static_cast<TileStatus>(tileSettings[0]);
        auto type =  static_cast<TileType>(tileSettings[1]);
        auto victim = static_cast<TileVictim>(tileSettings[10]);

        Tile tile(status, type, wall,victim );
        if(tileGrid.size()  < setupConfig.getSizeX()){
            tileGrid.emplace_back();
            currentColumn++;
        }else if(currentColumn < setupConfig.getSizeX()){
            currentColumn++;
        }else{
            currentColumn = 1;
        }
        tileGrid[currentColumn-1].emplace_back(tile);
    }
    log->info("Size of map: X= {} Y= {} ", tileGrid.size(), tileGrid[0].size());
    return TileGrid(tileGrid);
}

StartingMapConfig::StartingMapConfig(int sizeX, int startingRobotX, int startingRobotY) {
    this->sizeX = sizeX;
    this->robotX = startingRobotX;
    this->robotY = startingRobotY;
}

int StartingMapConfig::getSizeX() const {
    return sizeX;
}

int StartingMapConfig::getRobotX() const {
    return robotX;
}

int StartingMapConfig::getRobotY() const {
    return robotY;
}

