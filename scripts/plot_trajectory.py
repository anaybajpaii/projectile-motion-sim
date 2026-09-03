import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("data/trajectory_no_drag.csv")
data_drag = pd.read_csv("data/trajectory_with_drag.csv")

plt.plot(data["x"], data["y"], label="No Drag")
plt.plot(data_drag["x"], data_drag["y"], label="With Drag")

plt.xlabel("Horizontal Distance (m)")
plt.ylabel("Height (m)")
plt.title("Projectile Trajectory: Analytical vs. Numerical (with Drag)")
plt.legend()
plt.show()