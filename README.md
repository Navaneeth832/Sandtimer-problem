# Sandtimer-problem
This repository contains a C-based solution to the classic sand-timer (hourglass) problem. The goal of the problem is to measure an exact target time using two sand-timers of different durations. The solution involves recursion, tree structures, and backtracking to explore all possible combinations.

# Problem Statement
You are given two sand-timers of durations A and B minutes. The challenge is to measure an exact target time T minutes using these two sand-timers. You can:

1.Start both timers simultaneously.
2.Flip any of the timers when one runs out.
3.Stop once the exact time is measured.
Example:
Sand-timers: A = 4 minutes, B = 7 minutes.
Target: 9 minutes.
Output: A sequence of sand-timer flips and waits to achieve exactly 9 minutes.

# Key Features
1.Recursive Tree Construction:

The program generates all possible scenarios using a binary tree. Each node represents a possible state defined by the remaining time in both sand-timers and the elapsed total time.
Backtracking Solution:

2.The tree is explored recursively to find the optimal sequence of actions to measure the target time.
3.Multiple Paths:

The program can determine multiple ways to measure the target and selects the shortest sequence of steps.
4.Edge Case Handling:

Accounts for cases where the target time cannot be measured.
Handles any valid input values of A, B, and T.
# How It Works
Start the program and input the durations of the two sand-timers (A and B) and the target time (T).
The program recursively builds a tree of possibilities.
It searches the tree for paths that achieve the exact target time.
If a solution is found, it outputs the sequence of steps. Otherwise, it notifies the user that the target cannot be measured.
