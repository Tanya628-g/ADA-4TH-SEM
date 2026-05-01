import matplotlib.pyplot as plt

n_vals = []
t_vals = []

with open("subsetsum.txt", "r") as f:
    next(f)

    for line in f:
        line = line.strip()
        if not line:
            continue

        n, t = map(int, line.split())
        n_vals.append(n)
        t_vals.append(t)

# Plot
plt.figure()
plt.plot(n_vals, t_vals, marker='o')

plt.xlabel("n (number of elements)")
plt.ylabel("time (ns)")
plt.title("Subset Sum Time Complexity")
plt.grid()

plt.show()