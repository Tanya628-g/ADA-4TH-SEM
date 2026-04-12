import matplotlib.pyplot as plt

n_values=[]
time_values=[]

with open("labs/lab5/Matrix multiplication/matrix_multiplication.txt", "r") as file:
    next(file)

    for line in file:
        n, t= line.split()
        n_values.append(int(n))
        time_values.append(int(t))

plt.plot(n_values, time_values, marker='o')
plt.xlabel("Number of Elements")
plt.ylabel("Time (ns)")
plt.title("Matrix Multiplication Time Complexity")
plt.grid(True)
plt.show()