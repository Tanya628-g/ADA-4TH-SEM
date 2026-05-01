import matplotlib.pyplot as plt

vel=[]
tips=[]

with open("tips_data.txt", "r") as f:
    next(f)
    for line in f:
        v, t = map(int, line.split())
        vel.append(v)
        tips.append(t)
plt.figure()
plt.plot(vel, tips, marker='o')
plt.xlabel("Velocity")
plt.ylabel("Number of Tips")
plt.title("Velocity vs Number of Tips")
plt.grid()
plt.show()