import matplotlib.pyplot as plt

n_values = []
time_values = []

with open("/Users/tanya/Desktop/ADA/labs/lab9/All_Pairs_Shortest_Path/Allpairshortest.txt", "r") as file:
    next(file)  

    for line in file:
        n, t = line.split()
        n_values.append(int(n))
        time_values.append(int(t))

plt.plot(n_values, time_values, marker='o')
plt.xlabel("Number of Vertices")
plt.ylabel("Time (ns)")
plt.title("All Pairs Shortest Path Time Complexity")
plt.grid(True)
plt.show()