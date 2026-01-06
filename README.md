# Push_swap - Highly Efficient Stack Sorting

![Language](https://img.shields.io/badge/Language-C-blue)
![Build](https://img.shields.io/badge/Build-Makefile-green)

**Push_swap** is a 42 School algorithm project. The goal is to sort a stack of integers using a limited set of instructions and the smallest number of moves possible.

This project challenges the understanding of **algorithmic complexity**, **data structures (Stacks)**, and **optimization strategies**.

## 💡 The Challenge
You have two stacks named `a` and `b`.
* **Stack A:** Contains a random amount of negative and/or positive numbers which cannot be duplicated.
* **Stack B:** Initially empty.

The goal is to sort the numbers in **Stack A** in ascending order using the following operations:

| Operation | Description |
| :--- | :--- |
| `sa`, `sb`, `ss` | **Swap:** Swap the first 2 elements at the top of stack A, B, or both. |
| `pa`, `pb` | **Push:** Take the first element at the top of one stack and put it at the top of the other. |
| `ra`, `rb`, `rr` | **Rotate:** Shift up all elements of stack A, B, or both by 1. (First becomes last). |
| `rra`, `rrb`, `rrr` | **Reverse Rotate:** Shift down all elements of stack A, B, or both by 1. (Last becomes first). |

## 🧠 Algorithmic Approach: The "Turk" Algorithm

For this project, I implemented the **"Turk Algorithm,"** a sophisticated **greedy algorithm** that calculates the most efficient move at every step based on a cost heuristic.

Unlike simple sorting algorithms (like Bubble or Radix sort), this approach treats the problem as a **pathfinding optimization** to minimize the total instruction count.

### How it works:
1.  **Initial Push (A → B):**
    * Push elements from Stack A to Stack B until only 3 elements remain in A.
    * While pushing, I perform preliminary sorting by placing smaller elements below larger ones to approximate a descending order in B.
2.  **Base Case:**
    * Sort the remaining 3 elements in Stack A using a simple hard-coded logic.
3.  **Greedy Sort (B → A):**
    * This is the core of the algorithm. For **every element** in Stack B, I calculate the **"Cost"** to move it to its correct sorted position in Stack A.
    * **Cost Calculation:** $$Cost = |Moves\_in\_A| + |Moves\_in\_B|$$
    * I maximize the usage of simultaneous rotations (`rr` or `rrr`) to significantly reduce the operation count.
    * The algorithm selects the element with the **absolute minimum cost**, executes the required moves, and pushes it to A.
4.  **Final Alignment:**
    * Once all elements are back in Stack A, perform final rotations to bring the minimum element to the top.

### Complexity Analysis
* **Time Complexity:** The algorithm generally performs at $O(n^2)$ in the worst case for decision making, but the **operation count** is highly optimized (approx $O(n \log n)$ moves).
* **Space Complexity:** $O(n)$ to store the stack structures.

## 📊 Benchmarks
The algorithm was tested against various random sets of integers using the provided checker.

| Stack Size | Target Moves | My Result (Avg) |
| :--- | :--- | :--- |
| **3 numbers** | < 3 | 2 |
| **5 numbers** | < 12 | 9 |
| **100 numbers** | < 700 | ~550 |
| **500 numbers** | < 5500 | ~4800 |

## 🛠️ Installation & Usage

### Compilation
Use the provided `Makefile` to compile the project:
```bash
make
```
This generates the executable `push_swap`.

### Execution
You can run the program by passing the list of integers as arguments. The program handles both individual arguments and a single string argument.

**1. Standard Arguments:**
```bash
./push_swap 2 1 3 6 5 8
```

**2. String Argument:**
```bash
./push_swap "2 1 3 6 5 8"
```

The output will be the list of instructions required to sort Stack A:
```text
pb
pb
ra
sa
pa
pa
```

---

### 🔍 Verification

To verify that the generated instructions actually sort the stack correctly, you should use the provided checker (or `checker_linux`).

**Using a variable to store the list:**
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

* If the sorting is correct, it will output: `OK`
* If incorrect: `KO`
* If an error occurs: `Error`

**Counting the number of operations:**
To check if you meet the project requirements (e.g., < 700 moves for 100 numbers):
```bash
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
```
