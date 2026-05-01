import matplotlib.pyplot as plt

n_vals = []
t_vals = []

with open("/Users/tanya/Desktop/ADA/labs/lab10/Travelling Sales Person/tsp.txt", "r") as f:
    next(f)
    for line in f:
        line = line.strip()
        if not line:
            continue
        n, t = map(int, line.split())
        n_vals.append(n)
        t_vals.append(t)
        
plt.figure()
plt.plot(n_vals, t_vals, marker='o')

plt.xlabel("number of Cities")
plt.ylabel("time (ns)")
plt.title("Travelling Sales Person Time Complexity")
plt.grid()

plt.show()