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

It strengthened my confidence and prepared me for more complex labs that followed.
