import matplotlib.pyplot as plt

n= []
selected_values= []

with open("job_scheduling.txt", "r") as file:
    next(file)
    for line in file:
        n, t, s = line.split()
        n.append(int(n))
        selected_values.append(int(s))

plt.plot(n, selected_values, marker='o')
plt.xlabel("Total Jobs (n)")
plt.ylabel("Selected Non-Overlapping Jobs")
plt.title("Job Scheduling Efficiency")
plt.grid(True)
plt.show()