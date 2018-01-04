//
// Created by Abiel on 1/3/18.
//

#ifndef ROBOCUP2018SIMULATOR_SENSORBASE_H
#define ROBOCUP2018SIMULATOR_SENSORBASE_H

#include "RobotUtils.h"
#include "../Tiles/TileTypes.h"
#include "../Tiles/WallTypes.h"

class SensorBase {
public:
  /**
   * Checks if there is currently a wall in the chosen side.
   * @param side
   * @return
   */
  virtual bool GetWall(RobotDirection side) const = 0;

  /**
   * Checks if there is a thermal victim in the chosen side.
   * @param side
   * @return
   */
  virtual TileVictim getThermalVictim(RobotDirection side) const = 0;

  /**
   * Checks if there is a visual victim in the chosen side
   * @param side
   * @return
   */
  virtual VisualVictim getVisualVictim(RobotDirection side) const = 0;

  /**
   * Gets the current tile type that the robot is on.
   * @return
   */
  virtual TileType getTileType() const = 0;
};


#endif //ROBOCUP2018SIMULATOR_SENSORBASE_H
