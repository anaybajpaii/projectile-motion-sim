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
    double initialVx() 
    const { return vx0_; } 
    double initialVy() 
    const { return vy0_; }
    double mass() const { return mass_; }
    double dragCoefficient() const { return dragCoefficient_; }
    double crossSectionalArea() const { return crossSectionalArea_; }

    private:
    double x0_, y0_, vx0_, vy0_;
    double mass_ = 0.145;
    double dragCoefficient_ = 0.47;
    double crossSectionalArea_ = 0.0042;
};
#endif