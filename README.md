# Projectile Motion Simulator

This is a C++17 projectile motion simulator that compares analytical projectile motion with projectile motion with numerical integration under quadratic air resistance.

## Overview

The simulator models the trajectory of a projectile given its initial velocity, launch angle, and physical properties.

It includes two models:

* **Analytical model** — standard projectile-motion equations without air resistance.
* **Numerical model** — time-stepped simulation incorporating gravity and quadratic air resistance.

Simulation data can be exported to CSV and plotted using Python.

## Physics

For ideal projectile motion, the initial velocity is resolved into horizontal and vertical components:

$v_x = v_0\cos(\theta)$

$v_y = v_0\sin(\theta)$

The analytical model uses standard kinematic equations under constant gravitational acceleration and assumes no air resistance.

The numerical model adds quadratic drag:

$F_D = \frac{1}{2}C_D\rho A v^2$

where ($C_D$) is the drag coefficient, ($\rho$) is air density, ($A$) is cross-sectional area, and ($v$) is the projectile's instantaneous speed.

The drag force is resolved into horizontal and vertical components based on the projectile's velocity. An Euler-style integration method then updates the projectile's velocity and position at each fixed timestep using the calculated acceleration, producing an approximate trajectory under gravity and air resistance.

## Features

* Analytical projectile-motion calculations
* Numerical simulation with quadratic air resistance
* Configurable projectile properties
* CSV trajectory data output
* Python trajectory visualization
* Unit tests for physics calculations

## Project Structure

```text
projectile-motion-sim/
├── src/
│   ├── AirResistance.cpp
│   ├── AirResistance.h
│   ├── DataLogger.cpp
│   ├── DataLogger.h
│   ├── main.cpp
│   ├── physics.cpp
│   ├── physics.h
│   ├── projectile.cpp
│   └── projectile.h
├── tests/
│   └── test_physics.cpp
├── scripts/
│   └── plot_trajectory.py
├── data/
├── docs/
│   ├── notes.md
│   └── screenshots/
└── LICENSE
```

## Tools

* **C++17** — simulation and physics calculations
* **Python** — data visualization
* **Matplotlib** — trajectory plots
* **Git/GitHub** — version control

## Documentation

See [`docs/notes.md`](docs/notes.md) for the mathematical model, numerical integration method, assumptions, and additional physics notes.
