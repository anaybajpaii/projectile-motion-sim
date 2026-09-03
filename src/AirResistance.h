#ifndef AIRRESISTANCE_H
#define AIRRESISTANCE_H
#include <string>
#include "DataLogger.h"

namespace AirResistance
{
    constexpr double AIR_DENSITY = 1.225;
    void simulate (double x0, double y0, double vx0, double vy0, double mass, double dragCoefficient, double crossSectionalArea, double dt, DataLogger& logger);
}

#endif