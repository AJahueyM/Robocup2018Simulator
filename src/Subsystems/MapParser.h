//
// Created by alber on 1/3/2018.
//

#ifndef MYPROJECT_MAPPARSER_H
#define MYPROJECT_MAPPARSER_H
#include <string>
#include <vector>
#include <windows.h>
#include "Tiles/Tile.h"
#include "Tiles/TileGrid.h"
#include "Tiles/WallTypes.h"
#include "Tiles/TileTypes.h"
#include "Tiles/Wall.h"
#include <iostream>
#include <fstream>
#include "../spdlog/spdlog.h"

namespace spd = spdlog;

using namespace std;

class StartingMapConfig {
public:
    StartingMapConfig(int sizeX, int startingRobotX, int startingRobotY);
protected:
    int sizeX, robotX, robotY;
public:
    int getSizeX() const;

    int getRobotX() const;

    int getRobotY() const;

private:
};
class MapParser {
public:
    explicit MapParser(const string& searchDir);
    TileGrid getGrid(const string& gridName);
protected:
    vector<string> getPathsOnDir();

private:
    const static shared_ptr<spd::logger> log;
    string path;

};


#endif //MYPROJECT_MAPPARSER_H
