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
<img width="640" height="480" alt="image" src="https://github.com/user-attachments/assets/8710edbe-8618-49f2-8f02-f604bd10d56a" />




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
<img width="640" height="480" alt="image" src="https://github.com/user-attachments/assets/9972ef61-51bc-499d-b557-98cf2971946f" />



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
<img width="640" height="480" alt="image" src="https://github.com/user-attachments/assets/a0748ae1-fd1b-46ae-b36a-655d229bd199" />


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
<img width="640" height="480" alt="image" src="https://github.com/user-attachments/assets/cad6acd5-cfde-4f38-8472-6f8f4ee60323" />


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
<img width="640" height="480" alt="image" src="https://github.com/user-attachments/assets/98433ce4-eabc-4c2b-a339-6751d97ad012" />


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
<img width="640" height="480" alt="image" src="https://github.com/user-attachments/assets/e7445991-a4d1-4fd5-8519-3b021c8b33ba" />



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
