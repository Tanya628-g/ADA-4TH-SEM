import matplotlib.pyplot as plt

n_values = []
time_values = []

with open("truth_table.txt", "r") as file:
    next(file)  

    for line in file:
        n, t = line.split()
        n_values.append(int(n))
        time_values.append(int(t))

plt.plot(n_values, time_values, marker='o')
plt.xlabel("Number of Variable")
plt.ylabel("Time (ns)")
plt.title("Truth Table Time Complexity")
plt.grid(True)
plt.show()