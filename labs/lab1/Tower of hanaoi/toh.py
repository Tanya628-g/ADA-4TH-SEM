import matplotlib.pyplot as plt

n_values = []
time_values = []

with open("toh.txt", "r") as file:
    next(file)  

    for line in file:
        n, t = line.split()
        n_values.append(int(n))
        time_values.append(int(t))

plt.plot(n_values, time_values, marker='o')
plt.xlabel("Number of Elements")
plt.ylabel("Time (ns)")
plt.title("Tower of Hanoi Time Complexity")
plt.grid(True)
plt.show()