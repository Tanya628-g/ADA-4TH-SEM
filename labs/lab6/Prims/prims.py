import matplotlib.pyplot as plt

vel=[]
tips=[]

with open("prims.txt", "r") as f:
    next(f)
    for line in f:
        v, t = map(int, line.split())
        vel.append(v)
        tips.append(t)
plt.figure()
plt.plot(vel, tips, marker='o')
plt.xlabel("Number or Vertices")
plt.ylabel("Time(ns)")
plt.title("Prims Time Complexity")
plt.grid()
plt.show()