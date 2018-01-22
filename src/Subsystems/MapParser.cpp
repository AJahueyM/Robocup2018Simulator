//
// Created by alber on 1/3/2018.
//

#include "MapParser.h"

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
    ofstream file(path + gridName);

    string stringBuffer;
    getline(file, stringBuffer);
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

    if(counter != 4){
        log->error("Error on first line of: {}, expected 4 values, read: {}", path + gridName, counter);
        assert(counter == 4);
    }

    StartingMapConfig setupConfig(setupLine[0], setupLine[1], setupLine[2], setupLine[3]);

    vector<vector<Tile>> tileGrid;
    while(getline(file, stringBuffer)) {
        counter++;
        streamBuffer = stringstream(stringBuffer);
        vector<int> tileSettings;
        vector<Tile> column;
        while (streamBuffer >> numBuffer) {
            tileSettings.emplace_back();
            if(streamBuffer.peek() == ' '){
                streamBuffer.ignore();
            }
        }
        if(tileSettings.size() != 11){
            log->error("Error on line: {} of: {}, expected 11 values, read; {}", counter, path + gridName, tileSettings.size());
            assert(tileSettings.size() == 11);
        }
        Walls wall;
        wall.left = Wall( (bool) tileSettings[2], static_cast<VisualVictim>(tileSettings[3]));
        wall.top = Wall( (bool) tileSettings[4], static_cast<VisualVictim> (tileSettings[5]));
        wall.right = Wall( (bool) tileSettings[6], static_cast<VisualVictim>(tileSettings[7]));
        wall.bottom = Wall( (bool) tileSettings[8], static_cast<VisualVictim>(tileSettings[9]));

        column.emplace_back(Tile(static_cast<Status>(tileSettings[0]), static_cast<Type>(tileSettings[1]), wall, static_cast<TileVictim>(tileSettings[10])));


        }


}

long StartingMapConfig::StartingMapConfig(int sizeX, int sizeY, int startingRobotX, int startingRobotY) {
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->robotX = startingRobotX;
    this->robotY = startingRobotY;
}

int StartingMapConfig::getSizeX() const {
    return sizeX;
}

int StartingMapConfig::getSizeY() const {
    return sizeY;
}


int StartingMapConfig::getRobotX() const {
    return robotX;
}

int StartingMapConfig::getRobotY() const {
    return robotY;
}

