import matplotlib.pyplot as plt

vel=[]
tips=[]

with open("/Users/tanya/Desktop/ADA/labs/lab6/Kruskals/kruskal.txt", "r") as f:
    next(f)
    for line in f:
        v, t = map(int, line.split())
        vel.append(v)
        tips.append(t)
plt.figure()
plt.plot(vel, tips, marker='o')
plt.xlabel("Number or Vertices")
plt.ylabel("Time(ns)")
plt.title("Kruskals Time Complexity")
plt.grid()
plt.show()