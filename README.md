# Analysis and Design of Algorithms
## Lab 1
### 1. Duplicate Elements

**Problem Statement:** Find duplicate elements in an array.  
**Topic:** Array  
**Naive Approach:** Compare each element with every other element.

**Algorithm:**
```
1.1 An array is input from user
1.2 Index is initialized to –1
1.3 The elements are compared to every other element
1.4 When the first duplicate is found the index is returned
```

**Time Complexity:** O(n²)


### 2. Horner’s Rule
**Problem Statement:** To evaluate polynomial using Horner’s Rule.  

**Algorithm:**
```
1.1 Make a recursive function “horner”.
1.2 Take input from user about the degree of the polynomial
1.3 In the main function call the recursive function “horner”
```
**Time Complexity:** O(n)


### 3. Linear Search
**Problem Statement:** To search for a particular element in an array  
**Naive Approach:** Search for the element in the entire array  

**Algorithm:**
```
1.1 Take input from the user which search for the element
1.2 Using the for loop traverse the array and search for the element
1.3 Return the index of the element so found
```
**Time Complexity:** O(n)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/b243c51f-864f-4ec2-9cee-e94bfe17616c" />


### 4. Permutation Generator
**Problem Statement:** To generate all permutations of the given set  

**Algorithm:**
```
1.1 Take input of set from the user
1.2 Fix one element
1.3 Recursively permute remaining
1.4 Swap elements
1.5 Return all possible sets
```
**Time Complexity:** O(n!)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/8710edbe-8618-49f2-8f02-f604bd10d56a" />


### 5. Tower of Hanoi
**Problem Statement:** To solve Tower of Hanoi  
**Naive Approach:** Moving of disks manually  

**Algorithm:**
```
1.1 Move n-1 disks to auxiliary
1.2 Move largest disk
1.3 Move n-1 disks to destination
```
**Time Complexity:** O(2^n)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/9972ef61-51bc-499d-b557-98cf2971946f" />


### 6. Velocity
**Problem Statement:** Given an initial velocity, determine how many times the velocity reduces until it becomes less than 1.0, where each reduction multiplies the velocity by a constant factor.  
**Naive Approach:** Use an iterative loop to repeatedly multiply velocity by the reduction factor until it becomes less than 1.  

**Algorithm:**
```
1.1 Input initial velocity v
1.2 Define reduction factor (0.575)
1.3 If v < 1, stop recursion
1.4 Return total number of tips till the velocity becomes 0
```
**Time Complexity:** O(log v)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/a0748ae1-fd1b-46ae-b36a-655d229bd199" />


### 7. Power
**Problem Statement:** To compute power of a given number  
**Naive Approach:** Multiply the given number to itself power times  

**Algorithm:**
```
1.1 Initialize result to –1
1.2 Using the for loop multiply result by the given number
1.3 Return the final result
```
**Time Complexity:** O(n)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/cad6acd5-cfde-4f38-8472-6f8f4ee60323" />


### 8. Sum of N Numbers
**Problem Statement:** To Find the sum of first n natural numbers  
**Naive Approach:** Add numbers from 1 to n using a loop.  

**Algorithm:**
```
1.1 Input value of n
1.2 Initialize sum = 0
1.3 Loop from 1 to n:
1.4 Add i to sum
1.5 Output sum
```
**Time Complexity:** O(n)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/98433ce4-eabc-4c2b-a339-6751d97ad012" />


### 9. Truth Table Generation
**Problem Statement:** To generate truth table for logical expressions  

**Algorithm:**
```
1.1 From the user take input of number of variables
1.2 Loop through all binary combinations
1.3 Evaluate logical expression
1.4 Give the truth table of the desired number of variable
```
**Time Complexity:** O(2^n)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/e7445991-a4d1-4fd5-8519-3b021c8b33ba" />



### 10. Consecutive Numbers
**Problem Statement:** From a given sequence of consecutive numbers with one number missing, find the missing number. 
**Naive Approach:** Check every possible number in the range and compare with array elements.  

**Algorithm:**
```
1.1 Take input of elements from user
1.2 Traverse array from index 0 to n-2

For each element:
1.3 Increment current element by 1
1.4 Compare with next element

If mismatch found:
1.5 Missing number = current element + 1

1.6 If no mismatch, no number is missing
```
**Time Complexity:** O(n)


## LAB 2

### 1. Binary Search

**Problem Statement:** To search an element in a sorted array using binary search.  
**Topic:** Divide and Conquer  
**Naive Approach:** Traverse the array linearly to find the element.  

**Algorithm:**
```
1. Take array input from the user
2. Ask for the element to search
3. Sort the array
4. Find the low and high of array
5. Find mid using (low + high) / 2
6. Compare mid element with target
7. Update low or high accordingly
8. Repeat until element is found
9. Return the index of the searched element
```
**Time Complexity:** O(log n)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/1f89cb11-34e9-4f1a-a5f0-26ffc1f76336" />



### 2. Insertion Sort

**Problem Statement:** Sort an array using Insertion Sort.  
**Topic:** Sorting  
**Naive Approach:** Insert each element in its correct position in a sorted part of the array.  

**Algorithm:**
```
1. Take one element
2. Compare with previous elements
3. Shift elements if needed
4. Insert element in correct position
5. Repeat for all elements
```

**Time Complexity:** O(n²)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/98f3b12b-7c94-49f3-a9b4-a5b623bdb7d6" />

## LAB 3

### 1. Merge Sort

**Problem Statement:** To sort an array using Merge Sort.  
**Topic:** Divide and Conquer  
**Naive Approach:** Use simple sorting methods like bubble or selection sort.

**Algorithm:**
```
1. Take an array input from user
2. Divide array into two halves
3. Recursively sort both halves
4. Merge the sorted halves
5. Return the sorted array
```

**Time Complexity:** O(n log n)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/72044e30-2033-4e24-a0bf-8262aca99a36" />


### 2. Quick Sort

**Problem Statement:** To sort an array using Quick Sort.  
**Topic:** Divide and Conquer  
**Naive Approach:** Use simple sorting algorithms like bubble sort.

**Algorithm:**
```
1. Take an array input from the user
2. Choose a pivot element
3. Partition array into elements smaller and greater than pivot
4. Recursively apply quicksort on subarrays
5. Return the sorted array
```

**Time Complexity:** Best: O(n log n), Worst: O(n²)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/dfd0bee6-6319-4e90-aec4-6c380558b617" />

## Lab 4
### Minimum – Maximum

**Problem Statement*:* To find the maximum and minimum element in an array.
**Naive Approach:**Traverse the array twice to find the maximum and minimum values separately.

**Algorithm:**
```
1. Take an array input from the user  
2. Initialize min and max as the first element of the array  
3. Traverse the array  
4. Update min and max accordingly  
5. Return the maximum and minimum values
```

**Time Complexity:**O(n)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/7f2a2bb7-8c17-4fc7-815f-3e2edd9c2ba9" />



## Lab 5

### 1) Convex Hull

**Problem Statement:**  
To find the convex hull of a set of points.

**Algorithm:**  
1. Take input of number of points from user  
2. Take input of set of points from user  
3. Use the orientation function to determine orientation of triplets  
4. Check whether points lie inside a triangle using an inside-triangle boolean function  
5. Return the convex hull points  
**Time Complexity:**  
O(n^4)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/b4cac1f5-32f8-4019-80e8-35df1d4c0310" />


### 2) Knapsack Problem

**Problem Statement:**  
To purchase items while maximizing profit while staying within the maximum capacity.

**Algorithm:**  
1. Take input of number of items from user  
2. Generate weights and profits using `rand()` function  
3. Compute profit-to-weight ratio for each item  
4. Sort items based on ratio in descending order  
5. Select items that fit within maximum capacity  
**Time Complexity:**  
O(n log n)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/a63feba9-75d4-467c-9bd9-9cffb4b6767c" />


### 3) Matrix Multiplication

**Problem Statement:**  
To find the product of two matrices.

**Algorithm:**  
1. Take input of two matrices from user  
2. Use nested loops to compute matrix multiplication  
3. Return the resultant matrix  

**Time Complexity:**  
O(n^3)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/9964a4a2-f8bc-4896-878c-0466b6bef7da" />

## Lab 6

### 1) Dijkstra Algorithm  

**Problem Statement-**To find the shortest path from a source vertex to all other vertices in a weighted graph.
**Algorithm:**  
```
1. Take input of number of vertices from the user  
2. Initialize all distances to infinity  
3. Set source distance = 0  
4. Repeat V-1 times:  
   - Select unvisited vertex with minimum distance  
   - Mark it as visited  
   - Update distances of adjacent vertices  
5. Print shortest distances  
```
**Time Complexity:**O(V²)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/fa784293-980d-42f5-8c42-a318771466fd" />


### 2) Prim’s Algorithm  

**Problem Statement-**  To find the Minimum Spanning Tree (MST) of a graph using Prim’s Algorithm.
**Algorithm:**
```
1. Take input of number of vertices from the user  
2. Take input of the distance matrix  
3. Start from any vertex  
4. Select the minimum weight edge connecting a visited vertex to an unvisited vertex  
5. Repeat until all vertices are included  
6. Return the Minimum Spanning Tree  
```
**Time Complexity:** O(V²)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/db9d3cdf-5277-42a2-b843-a2c928fb36b4" />


### 3) Kruskal’s Algorithm  

**Problem Statement-** To find the Minimum Spanning Tree (MST) of a graph.
**Naive Approach-** Generate all spanning trees and select the one with minimum weight.
**Algorithm:**
```
1. Take input of number of vertices from the user  
2. Take input of all edges (or distance matrix)  
3. Sort all edges in increasing order of weight  
4. Make each vertex its own set  
5. For each edge:  
   - If it connects two different sets:  
     - Add the edge to MST  
     - Perform union of the sets  
6. Stop when V-1 edges are selected  
7. Return the Minimum Spanning Tree  
```
**Time Complexity:** O(E log E)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/176be919-9e55-4296-bbe0-6a501c31aa30" />



### 4) Activity Selection  

**Problem Statement-** To select the maximum number of non-overlapping activities (jobs) based on their start and finish times.
**Algorithm:**
```
1. Take input of number of jobs from the user  
2. Generate start and finish times for each job  
3. Sort all jobs in increasing order of finish time  
4. Select the first job and store its finish time  
5. For each remaining job:  
   - If start time ≥ last selected job’s finish time:  
     - Select the job  
     - Update last finish time  
6. Continue until all jobs are processed  
7. Return the total number of selected jobs  
```
**Time Complexity:** O(n log n)
<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/8e3761c7-1dbb-426b-8737-4ffe318a5e2d" />

<img width="540" height="380" alt="image" src="https://github.com/user-attachments/assets/2af206a3-3d33-4f63-aa5e-c64be73026cc" />
