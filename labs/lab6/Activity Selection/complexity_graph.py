import matplotlib.pyplot as plt

n_values = []
time_values = []

with open("job_scheduling.txt", "r") as file:
    next(file)

    for line in file:
        n, t, s = line.split()   
        n_values.append(int(n))
        time_values.append(int(t))

plt.plot(n_values, time_values, marker='o')
plt.xlabel("Number of Jobs (n)")
plt.ylabel("Time (ns)")
plt.title("Job Scheduling Time Complexity")
plt.grid(True)
plt.show()