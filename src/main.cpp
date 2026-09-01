#include <iostream>
#include "Projectile.h"
#include "Physics.h"
#include "DataLogger.h"

int main() 
{
    double speed, angle, height;

    std::cout << "Enter launch speed (m/s): ";
    std::cin >> speed;

    std::cout << "Enter launch angle (degrees): ";
    std::cin >> angle;

    std::cout << "Enter launch height (m): ";
    std::cin >> height;

    Projectile projectile(speed, angle, height);

    double totalTime = projectile.flightTime();
    DataLogger logger("data/trajectory_no_drag.csv");

    for (double t = 0.0; t <= totalTime; t += 0.1) 
    {
        auto [x, y] = projectile.positionAt(t);
        std::cout << t << " " << x << " " << y << "\n";
        logger.writeRow(t, x, y);
    }

    return 0;
}