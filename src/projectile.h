#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <utility>
class Projectile 
{
public:
    Projectile(double launchSpeed, double launchAngleDegrees, double launchHeight);
    std::pair<double, double> positionAt(double t) const;
    std::pair<double, double> velocityAt(double t) const;
    double flightTime() const;

private:
    double x0_, y0_, vx0_, vy0_;
};
#endif