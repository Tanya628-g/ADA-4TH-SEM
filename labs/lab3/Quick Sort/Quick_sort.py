import matplotlib.pyplot as plt

n = [3, 4, 5, 6, 7, 8]   
time_ns = [417, 333, 541, 667, 416, 500] 

plt.plot(n, time_ns, marker='o')
plt.xlabel("Number of elements")
plt.ylabel("Time(nanoseconds)")
plt.title("time complexity- Quick Sort")
plt.grid(True)
plt.show()
