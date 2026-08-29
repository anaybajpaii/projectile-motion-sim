#ifndef PHYSICS_H
#define PHYSICS_H

namespace Physics {constexpr double GRAVITY = 9.80665;
constexpr double PI = 3.14159265358979323846;
double timeOfFlight(double vy0, double y0, double gravity); 
double maxHeight(double vy0, double gravity); 
double range(double speed, double angleDegrees, double gravity); 
double positionX(double x0, double vx0, double t); 
double positionY(double y0, double vy0, double t, double gravity); 
double velocityY(double vy0, double t, double gravity); 
double degreesToRadians(double degrees);
}
#endif