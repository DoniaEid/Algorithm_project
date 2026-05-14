# 🃏 Wildcard Matching Algorithm Project

## 📌 Overview
This project implements the **Wildcard Matching** problem, which is a classic algorithmic challenge often solved using Dynamic Programming. The goal is to determine if a given input string matches a pattern that contains special characters like `?` and `*`.

### Special Characters:
- `?` : Matches any single character.
- `*` : Matches any sequence of characters (including an empty sequence).

---

## 🚀 Implementations

I have provided two distinct architectural approaches to solve this problem:

### 1. Recursive Approach (Top-Down)
- **Methodology**: Uses a recursive function to break down the matching process. It handles the `*` wildcard by branching into two possibilities: ignoring the `*` or matching it with the current character.
- **Optimization**: (Optional: Mention if you used Memoization).
- **Best for**: Small string lengths and understanding the logic flow.

### 2. Iterative Approach (Non-Recursive / Bottom-Up)
- **Methodology**: Uses **Nested Loops** to process the string and pattern iteratively. 
- **Efficiency**: This approach is highly efficient as it avoids the overhead of the function call stack, making it safer for large input strings and preventing `Stack Overflow` errors.
- **Complexity**: $O(N \times M)$ where $N$ and $M$ are lengths of the string and pattern.

---

## 📊 Comparison Table

| Feature | Recursive (Top-Down) | Iterative (Bottom-Up) |
| :--- | :--- | :--- |
| **Logic** | Intuitive & Simple | Loop-based & Robust |
| **Memory** | Uses Stack Memory | Uses Heap/Table Memory |
| **Performance** | Slower (due to recursion) | Faster (Direct iteration) |
| **Safety** | Risk of Stack Overflow | Very Safe |

---

## 🛠 Project Structure & Setup

### Folder Structure
```text
Algorithm_project/
├── main.cpp              # Entry point with test cases
├── wildcard_logic.cpp     # Implementation of both functions
├── README.md             # Documentation
└── .git/                 # Git configuration
