//
// Created by Abiel on 1/3/18.
//

#ifndef ROBOCUP2018SIMULATOR_MOTORBASE_H
#define ROBOCUP2018SIMULATOR_MOTORBASE_H

#include "RobotUtils.h"

class MotorBase {

  /**
   * Move the robot for a certain ammount of tiles. Returns true if robot encountered a "special tile".
   * @param tiles
   * @return
   */
  virtual bool MoveRobot(long tiles) = 0; //Long should be more than enough here

  /**
   * Turns the robot to face the specified direction.
   * @param side
   */
  virtual void TurnToFace(RobotDirection side) = 0;
};


#endif //ROBOCUP2018SIMULATOR_MOTORBASE_H
