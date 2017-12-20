//
// Created by Alberto Jahuey on 11/1/2017.
//
#include "Utils.h"

float random(float lowerLimit, float upperLimit) {
    return (lowerLimit + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (upperLimit - (lowerLimit)))));
}
