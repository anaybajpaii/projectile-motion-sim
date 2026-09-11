# Physics Notes

This document explains the physics and numerical methods used in the projectile motion simulator.

## 1. Ideal Projectile Motion

The analytical model treats the projectile as being affected only by gravity. Air resistance is ignored, and gravitational acceleration is taken as a constant:

$(g = 9.81\ \text{m/s}^2)$

The initial velocity is split into horizontal and vertical components using the launch angle $\theta$:

$v_{x0} = v_0\cos \theta$ \
$v_{y0} = v_0\sin\theta$

The horizontal velocity remains constant because there is no horizontal acceleration:

$x(t) = x_0 + v_{x0}t$

The vertical position is calculated using constant-acceleration kinematics (using gravity as acceleration):

$y(t) = y_0 + v_{y0}t - \frac{1}{2}gt^2$

The vertical velocity at any given time is:

$v_y(t) = v_{y0} - gt$

### Flight Time

For a projectile launched from an initial height $y_0$, the flight time is found by setting $y(t)=0$ and solving the resulting quadratic equation:

$$t_f = \frac{v_{y0}+\sqrt{v_{y0}^2+2gy_0}}{g}$$

This allows the simulator to handle launches from heights above the ground.

### Maximum Height

The vertical rise above the launch point is:

$\Delta h = \frac{v_{y0}^2}{2g}$

Hence, the total maximum height is:

$h_{\max} = y_0+\frac{v_{y0}^2}{2g}$
### Range

The range calculation in the physics module assumes that the projectile lands at the same height from which it was launched:

$R = \frac{v_0^2\sin(2\theta)}{g}$

This is separate from the flight-time calculation, which can account for a non-zero launch height.

## 2. Quadratic Air Resistance

The numerical model introduces air resistance. The drag force is assumed to be proportional to the square of the projectile's speed:

$F_D = \frac{1}{2}C_D\rho A v^2$

where:

* $C_D$ = drag coefficient
* $\rho$ = air density
* $A$ = cross-sectional area
* $v$ = instantaneous speed

The simulator uses an air density of:

$\rho = 1.225\ \text{kg/m}^3$

The instantaneous speed is calculated from the horizontal and vertical velocity components:

$v = \sqrt{v_x^2+v_y^2}$

Because drag acts opposite to the direction of motion, the drag force is resolved into horizontal and vertical components:

$F_{Dx} = -F_D\frac{v_x}{v}$ \
$F_{Dy} = -F_D\frac{v_y}{v}$

The resulting accelerations are:

$a_x = \frac{F_{Dx}}{m}$ \
$a_y = \frac{F_{Dy}}{m}-g$

Unlike the analytical model, both velocity components therefore change throughout the flight.

## 3. Numerical Integration

There is no durect trajectory equation used for the air-resistance model, so the simulator calculates the motion step by step

The numerical model uses an Euler-style integration method with a fixed timestep. At each timestep, the current acceleration is used to update velocity:

$v_x(t+\Delta t) = v_x(t)+a_x\Delta t$ \
$v_y(t+\Delta t) = v_y(t)+a_y\Delta t$

The updated velocity is then used to update position:

$x(t+\Delta t) = x(t)+v_x(t+\Delta t)\Delta t$ \
$y(t+\Delta t) = y(t)+v_y(t+\Delta t)\Delta t$

The air-resistance simulation uses a timestep of: $\Delta t = 0.01 \text{s}$. This process is repeated until the projectile reaches the ground.

### Why Use Numerical Integration?

With quadratic drag, the acceleration depends on the projectile's current velocity. As the velocity changes, the drag force also changes, making the equations of motion coupled and difficult to represent with the simple closed-form equations used for ideal projectile motion.

Numerical integration provides a practical way to approximate the trajectory by repeatedly calculating the forces and updating the projectile's state.

## 4. Analytical vs Numerical Models

The two models use different physical assumptions:

| Analytical Model                       | Numerical Model                   |
| -------------------------------------- | --------------------------------- |
| No air resistance                      | Quadratic air resistance          |
| Constant horizontal velocity           | Horizontal velocity changes       |
| Constant gravitational acceleration    | Gravity + drag                    |
| Closed-form kinematic equations        | Euler-style numerical integration |
| Exact for the assumptions of the model | Approximate numerical solution    |

Comparing the two trajectories shows the effect of air resistance on projectile motion. In particular, drag reduces the projectile's horizontal range and changes the shape of the trajectory compared with ideal projectile motion.

## 5. Numerical Considerations

The timestep affects the accuracy of the numerical simulation. A smaller timestep generally provides a closer approximation to the continuous motion, while a larger timestep can introduce greater numerical error.

The simulator uses a timestep of $0.01$ seconds for the air-resistance model, providing a sufficiently small step for the trajectory simulation while keeping the implementation straightforward.

The numerical result is therefore an approximation rather than an exact solution. This is an important distinction when comparing the numerical trajectory with the analytical model.