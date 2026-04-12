import matplotlib.pyplot as plt

n_values = []
selected_values = []

with open("labs/lab6/Activity Selection/job_scheduling.txt", "r") as file:
    next(file)  
    
    for line in file:
        n, time_ns, selected_jobs = line.split()
        
        n_values.append(int(n))
        selected_values.append(int(selected_jobs))

plt.plot(n_values, selected_values, marker='o')
plt.xlabel("Total Jobs (n)")
plt.ylabel("Selected Non-Overlapping Jobs")
plt.title("Job Scheduling Efficiency")
plt.grid(True)
plt.show()