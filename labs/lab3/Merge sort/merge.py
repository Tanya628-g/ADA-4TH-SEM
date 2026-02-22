import matplotlib.pyplot as plt

n = [3, 4, 5, 6, 7, 8]   
time_ns = [1250, 709, 750, 917, 1042, 1250] 

plt.plot(n, time_ns, marker='o')
plt.xlabel("Number of elements")
plt.ylabel("Time(nanoseconds)")
plt.title("time complexity-Merge Sort")
plt.grid(True)
plt.show()
