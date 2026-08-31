#include "Physics.h"
#include <cmath>


namespace Physics 
{
double timeOfFlight(double vy0, double y0, double gravity)
{
    double result = (vy0 + std::sqrt(vy0 * vy0 + 2.0 * gravity * y0)) / gravity;
    return result;
}
double maxHeight(double vy0, double gravity) 
{
    double result = (vy0 * vy0) / (2.0 * gravity);
    return result;
}
double range(double speed, double angleDegrees, double gravity) 
{
    double result = (speed * speed) * std::sin(2 * degreesToRadians(angleDegrees)) / gravity;
    return result;
}
double positionX(double x0, double vx0, double t) 
{
    double result = x0 + (vx0 * t);
    return result;
}
double positionY(double y0, double vy0, double t, double gravity)
{
    double result = y0 + (vy0 * t) - (0.5 * gravity * t * t);
    return result;
}
double velocityY(double vy0, double t, double gravity)
{
    double result = vy0 - (gravity * t);
    return result;
}
double degreesToRadians(double degrees) 
{
    double result = degrees * PI / 180.0;
    return result;
}
}