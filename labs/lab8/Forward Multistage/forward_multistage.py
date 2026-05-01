import matplotlib.pyplot as plt

n_values = []
time_values = []

with open("/Users/tanya/Desktop/ADA/labs/lab8/Forward Multistage/multistage_fwd.txt", "r") as file:
    next(file)  

    for line in file:
        n, t = line.split()
        n_values.append(int(n))
        time_values.append(int(t))

plt.plot(n_values, time_values, marker='o')
plt.xlabel("Number of Vertices")
plt.ylabel("Time (ns)")
plt.title("Forward Multisatge Time Complexity")
plt.grid(True)
plt.show()