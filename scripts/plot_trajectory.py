import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("data/trajectory_no_drag.csv")
plt.plot(data["x"], data["y"])
plt.xlabel("Horizontal Distance (m)") 
plt.ylabel("Height (m)") 
plt.title("Projectile Trajectory (No Drag)")
plt.show()