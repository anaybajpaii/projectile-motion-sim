#include "Physics.h"
#include "projectile.h"
#include <cmath>

Projectile::Projectile
(double launchSpeed, double launchAngleDegrees, double launchHeight) 
{
    double angleRadians = Physics::degreesToRadians(launchAngleDegrees);
    vx0_ = launchSpeed * std::cos(angleRadians);
    vy0_ = launchSpeed * std::sin(angleRadians);
    x0_=0.0;
    y0_=launchHeight;
}
double Projectile::flightTime() const
{
    double result = Physics::timeOfFlight(vy0_, y0_, Physics::GRAVITY);
    return result;
}
std::pair<double, double> 
Projectile::positionAt(double t) const 
{
    double x=Physics::positionX(x0_, vx0_, t);
    double y=Physics::positionY(y0_, vy0_, t, Physics::GRAVITY);
    return {x,y};
}
std::pair<double, double> 
Projectile::velocityAt(double t) const 
{
    double y=Physics::velocityY(vy0_, t, Physics::GRAVITY);
    return {vx0_,y};
}















