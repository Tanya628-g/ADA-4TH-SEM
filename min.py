import matplotlib.pyplot as plt

n_values = []
time_values = []

with open("results.txt", "r") as file:
    next(file)  # skip header

    for line in file:
        n, t = line.split()
        n_values.append(int(n))
        time_values.append(int(t))

plt.plot(n_values, time_values, marker='o')
plt.xlabel("Number of Elements (n)")
plt.ylabel("Time (nanoseconds)")
plt.title("Divide and Conquer Max-Min Time Complexity")
plt.grid(True)
plt.show()