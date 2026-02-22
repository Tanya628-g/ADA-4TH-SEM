import matplotlib.pyplot as plt

n = [3, 4, 5, 6, 7, 8]   
time_ns = [83, 42, 125, 166, 125, 167] 

plt.plot(n, time_ns, marker='o')
plt.xlabel("Number of elements")
plt.ylabel("Time(nanoseconds)")
plt.title("time complexity")
plt.grid(True)
plt.show()
