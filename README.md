<h1 align=center>
  42 Cursus
 </h1>
<h2 align=center>
  push_swap
</h2>
<h2 align=center>

  ![push_swap Logo](https://github.com/beatrizdile/beatrizdile-utils/blob/master/push_swapm.png)
</h2>

Push_swap is a sorting algorithm project that aims to sort a stack of integers using a limited set of operations while minimizing the number of moves. The goal is to implement two programs: one that checks if a given list of instructions sorts the stack, and another that generates the list of instructions to sort the stack.

## Description

The push_swap program uses a sorting algorithm that involves manipulating two stacks, commonly referred to as Stack A and Stack B. The algorithm follows a combination of operations like pushing, rotating, reverse rotating, and swapping elements between the two stacks to sort the numbers. To do this project, I've implemented the [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97), an optimization algorithm created by Ali Yigit Ogun: a student from 42 Heilbronn school.

## Installation

Follow the steps below to test the project: 

1. Clone the repository:
```bash
git clone https://github.com/your-username/push_swap.git
```
2. Compile the project:
```bash
make
```
3. Run the program with the following syntax:
```bash
./push_swap num1 num2 num3 num4 num5
```
- **num**: unique numbers in a non-ascending order.

### Examples
```bash
./push_swap 8 5 2 4 9 1 3
```

## Visualizer

To better understand the algorithm and operations done in the push_swap project you can download a GUI to experience a visual demonstration.

- [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
- [push_swap_gui](https://github.com/elijahkash/push_swap_gui)
