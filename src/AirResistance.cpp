#include "AirResistance.h" 
#include "Physics.h" 
#include <cmath>

void AirResistance::simulate (double x0, double y0, double vx0, double vy0, double mass, double dragCoefficient, double crossSectionalArea, double dt, DataLogger& logger) 
{ 
    double x = x0; 
    double y = y0; 
    double vx = vx0; 
    double vy = vy0; 
    double t = 0.0;
    while (y >= 0.0) 
    { 
        logger.writeRow(t, x, y);
        double speed = std::sqrt(vx * vx + vy * vy);
        double dragForce = 0.5 * dragCoefficient * AIR_DENSITY * crossSectionalArea * speed * speed;
        double dragForceX = -dragForce * (vx / speed); double dragForceY = -dragForce * (vy / speed); 
        double ax = dragForceX / mass;
        double ay = (dragForceY / mass) - Physics::GRAVITY;
        vx += ax * dt;
        vy += ay * dt;
        x += vx * dt;
        y += vy * dt;
        t += dt;
    }
}