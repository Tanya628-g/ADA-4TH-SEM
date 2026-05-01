import matplotlib.pyplot as plt

n = []
t = []

with open("graphcoloring.txt") as f:
    next(f)
    for line in f:
        if line.strip():
            a, b = map(int, line.split())
            n.append(a)
            t.append(b)

plt.plot(n, t, marker='o')
plt.yscale('log')   
plt.xlabel("number of vertices")
plt.ylabel("time(us)")
plt.title("Graph Coloring Time Complexity")
plt.grid()
plt.show()