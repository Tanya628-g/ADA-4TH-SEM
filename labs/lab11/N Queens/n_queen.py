import matplotlib.pyplot as plt

n_values = []
time_values = []

with open("/Users/tanya/Desktop/ADA/labs/lab11/N Queens/nqueen.txt", "r") as file:
    next(file)  

    for line in file:
        n, t = line.split()
        n_values.append(int(n))
        time_values.append(int(t))

plt.plot(n_values, time_values, marker='o')
plt.xlabel("Number of Queens")
plt.ylabel("Time (ns)")
plt.title("N Queens Time Complexity")
plt.grid(True)
plt.show()