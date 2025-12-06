## Objective🏆:

This repository contain codes i have written in my course of data structure  and as  practice.
The main goal is to keep the track of my progress and understand and practice new programming concepts.
## LAB-01 – Polynomial Class 💻

My first lab was focused on implementing a **Polynomial class**.  
Writing code for the first time in the DSA course challenged my programming skills  
and pushed me to think outside the box.

### What I Learned
- Representing a polynomial using arrays or linked lists  
- Implementing core operations:
  - Addition  
  - Subtraction  
  - Evaluation  
  - Displaying polynomial  
- Understanding dynamic memory handling  
- Applying object-oriented programming concepts  

### Reflection
This lab strengthened my logical thinking and problem-solving skills.  
It helped me build confidence and prepared me for the upcoming, more advanced labs.
## LAB-02 – NDArray Class 📦

The second lab focused on building an **NDArray (N-Dimensional Array) Class**,  
which strengthened my understanding of how multi-dimensional structures work internally.  
This lab required converting N-dimensional indexing into a **linear 1D memory layout**,  
which pushed me to think about memory mapping, indexing formulas, and clean class design.

### What I Learned
- How N-dimensional arrays are stored in a single contiguous 1D array  
- Implementing row-major index mapping  
- Designing a class with:
  - Dynamic dimensions  
  - Set and Get functions  
  - Index validation  
  - Print function  
- Understanding how multi-dimensional indexing translates into a single integer position  
- Applying templates for generic data types  

### Reflection
This lab helped me deeply understand how arrays work beneath the surface.  
It improved my problem-solving skills, strengthened my C++ fundamentals,  
and prepared me for more advanced data structures in future labs.
Writing the Polynomial class for the first time pushed me to think logically, break problems into smaller parts, and understand how mathematical structures can be represented in code.
### LAB 03 🧠:

### **Task 1 — Palindrome Checker**
- Removed spaces, punctuation, and converted string to lowercase.
- Pushed characters onto a stack and formed a reversed string by popping.
- Compared cleaned string with its reversed form to check palindrome.

### **Task 2 — Checking aⁿbⁿ Pattern**
- Pushed all `a` characters into a stack.
- After encountering the first `b`, ensured no more `a`s appear.
- Popped one element for each `b`.
- String is valid only if the stack becomes empty at the end.

### **Task 3 — Expression Validation**
- Scanned the expression and pushed all opening brackets onto a stack.
- For each closing bracket, matched it with the top of the stack.
- Expression is correct only if the stack is empty after scanning.

### **Task 4 — Adding Large Numbers**
- Took two numbers as C-strings and pushed digits onto two stacks.
- Popped digits, added with carry, and pushed results onto a result stack.
- Displayed the final sum by popping from the result stack.
# 📘 Lab 4 – My Approach

## 🧭 Task 1 – Maze Solver
- Used **recursive backtracking** to find a path from `P` to `T`.
- Skipped walls `*` and visited cells.
- Explored in four directions (up, down, left, right).
- Printed full path if `T` is reached; otherwise reported unsolved.

## 🔁 Task 2 – Reverse Words Using Stack
- Traversed the string and pushed characters of each word into a stack.
- On encountering a space, popped characters to reverse the word.
- Maintained the original word order.

## 🔄 Task 3 – Circular Queue
- Implemented circular queue using front, rear, capacity, and modulo indexing.
- Completed `enQueue`, `deQueue`, `isFull`, `isEmpty`, `getFront`, `getRear`.
- Tested using the provided driver program.

## 🎟️ Task 4 – Ticket Buying Simulation
- Simulated people buying tickets one per second.
- Used a queue to rotate people until the `k`th person finished.
- Counted total time required.

## 🖥️ Bonus – Round Robin Scheduler
- Created `Process` class and used a circular queue to store processes.
- Executed each process for a time quantum.
- Reduced execution time or removed it when completed.
- Continued until all processes finished.

# 🧪 Lab 05

## 🔧 Approach
- Used recursion to convert decimal to octal by repeatedly dividing by 8.
- Validated digit strings recursively by checking even indices for even digits and odd indices for prime digits.
- Solved the staircase problem using a Fibonacci-style recursive formula.
- Determined how many nested squares contain a point using recursive size reduction.

## 🎯 Learning Outcomes
- Understood how to design and apply recursive functions.
- Learned to break problems into smaller subproblems.
- Gained experience with number conversion, string validation, and mathematical recursion.
- Improved logical thinking, problem-solving, and recursive algorithm design.
# STACK & QUEUE ⏳
## Approach
- Implemented **Stack** and **Queue** using **static arrays**.
- Used `top` pointer for Stack and `front/rear` pointers for Queue.
- Added core operations: `push`, `pop`, `peek`, `isEmpty`, `isFull`.
- Ensured boundary checks to avoid overflow and underflow.

## Learning Outcomes
- Understood how linear data structures work internally using arrays.
- Learned pointer/index manipulation for efficient operations.
- Practiced implementing ADTs without using STL.
- Improved understanding of memory layout and fixed-size limitations.


It strengthened my confidence and prepared me for more complex labs that followed.

# Postfix evaluation using stack ➡️
## Approach
- Implemented helper functions to identify operands, operators, and brackets.
- Used an array-based Stack to convert an infix expression into postfix using precedence rules.
- Managed operator precedence and bracket handling through stack operations.
- Evaluated the postfix expression by pushing operands and applying operations via stack popping.

## Learning Outcomes
- Understood how Stacks enable expression conversion and evaluation.
- Learned operator precedence handling and bracket resolution in infix expressions.
- Gained experience with stack-based algorithms and array implementation.
- Strengthened understanding of expression parsing and postfix evaluation.


