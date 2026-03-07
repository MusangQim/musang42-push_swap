# musang42-push_swap
This is my journey as 42 cadet - sort data in a stack using a limited set of instructions, aiming to achieve the lowest possible number of actions and also need to work with various algorithms and choose the most appropriate one for optimized data sorting.

*This project has been created as part of the 42 curriculum by adzmusta.*

#push_swap

## Description

push_swap is a project that leads to sorting algorithm in 42 cursus. The goal is to sort a stack of integers using two stacks (stack A and stack B) with a limited set of operations, aiming for the lowest possible number of moves.

As my first experience dealing with algorithm, sorting method, and etc about this project, the program program receives a list of integers as arguments, and outputs the sequence of instructions needed to sort them in ascending order on stack A.

## Instruction

### Compilation

```bash
make
```

This will compiling all `libft`, `ft_printf`, and the main `push_swap` folder.

### Usage

```bash
./push_swap 4 67 3 87 23
```

The first argument is treated as the top of the stack. You can put any numbers but don't put similar number to test it.

You can also pass numbers as a single quoted string:

```bash
./push_swap "4 67 3 87 23"
```

### Checking the result

While evaluation, checker_linux had been given in 42 intra, make sure download it first (For Linux just use checker_linux)

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

Output will be `OK` if sorted correctly, or `KO` if not.

### Counting operations

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

### Cleanup

```bash
make clean    # remove object files
make fclean   # remove object files and binary
make re       # full recompile
```

## Resource
- [Push_swap 42 gitbook] (https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)
- [Push_Swap Tutorial-Nirmal Gope] (https://www.youtube.com/watch?v=4dMsuxfqufg&t=103s)
- [push_swap TUTORIAL-Thuggonaut] (https://www.youtube.com/watch?v=wRvipSG4Mmk&t=509s)
- [Push swap visualizer](https://push.eliotlucas.ch/)
- 42 subject PDF: push_swap project
-

## Algorithm

The project uses two different strategies depending on the input size:

**Small input (<=5 numbers):** Hardcoded sorting logic optimized for 2, 3, 4, and 5 elements.

**Large input (>5 numbers):** A combination of Chunk Sort and Greedy Algorithm.

Chunk Sort alone cannot efficiently place elements in the correct final order, and Greedy alone on a large unsorted stack would be too costly. Together, they complement each other:

1. All elements are assigned an index (0 to n-1) based on their sorted position.
2. **Chunk Sort** — Elements are pushed from stack A to stack B in groups (chunks) based on index range. This organises the data into manageable sorted groups.
3. **Greedy Algorithm** — Stack B is rebuilt back into stack A one element at a time. At each step, the element with the cheapest total move cost (rotations needed in both stacks combined: `cost_a + cost_b`) is chosen first.
4. Finally, stack A is rotated until the minimum value is at the top.

## Operation Usage

| Instruction | Description |
|---|---|
| sa | Swap top 2 elements of stack A |
| sb | Swap top 2 elements of stack B |
| ss | sa and sb at the same time |
| pa | Push top of stack B to stack A |
| pb | Push top of stack A to stack B |
| ra | Rotate stack A up by 1 |
| rb | Rotate stack B up by 1 |
| rr | ra and rb at the same time |
| rra | Reverse rotate stack A by 1 |
| rrb | Reverse rotate stack B by 1 |
| rrr | rra and rrb at the same time |

---

## Benchmark Targets

| Input Size | Target (100%) | Minimum Pass |
|---|---|---|
| 100 numbers | < 700 operations | < 1100 operations |
| 500 numbers | <= 5500 operations | < 8500 operations |

---

## Project Structure

```
push_swap/
├── main.c               - Entry point
├── parse.c              - Argument parsing
├── error.c              - Error checking (invalid chars, overflow, duplicates)
├── error_utils.c        - Overflow helper and error exit
├── stack.c              - Node creation and stack operations
├── stack_utils.c        - min, max, is_sorted, position helpers
├── index.c              - Assign sorted index to each node
├── sort_small.c         - Sort for 2-5 elements
├── sort_big.c           - Chunk-based sort for large input
├── sort_big_utils.c     - Cost calculation and target finding
├── sort_big_utils2.c    - Stack rotation helpers
├── push.c               - pa, pb operations
├── swap.c               - sa, sb, ss operations
├── rotate.c             - ra, rb, rr operations
├── reverse_rotate.c     - rra, rrb, rrr operations
├── utils.c              - free_stack
├── push_swap.h          - Main header
├── libft/               - Custom C library
└── ft_printf/           - Custom printf implementation
```

---
