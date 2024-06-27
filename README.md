# First-Come-First-Serve-FCFS-
##Description:
This code implements the FIFO (First-In-First-Out) page replacement algorithm in C++. The FIFO algorithm is used in operating systems for memory management, specifically for managing the pages in a page frame when there are page faults.

Code Breakdown:
1.Include Statements and Namespace:

#include <iostream>: for input and output operations.
#include <vector>: to use the std::vector container.
#include <queue>: to use the std::queue container.
#include <unordered_set>: to use the std::unordered_set container.
#include <algorithm> and #include <ctime>: included but not used in the given code.

2.Using Namespace std:

This allows the use of standard library names without the std:: prefix.

3.FIFO Function:

The fifo function takes two parameters: a vector of integers pages representing the sequence of pages to be loaded, and an integer capacity representing the number of page frames available in memory.
A queue<int> named q is used to store the page numbers in the order they are loaded.
An unordered_set<int> named s is used to quickly check if a page is already in memory.
An integer pageFaults is initialized to zero to keep track of the number of page faults.

4.Page Replacement Logic:

The function iterates over each page in the pages vector.
If a page is not in the unordered_set s (indicating a page fault):
       If the queue q is full (i.e., its size equals the capacity), the oldest page (the front of the queue) is removed from both the queue q and the set s.
       The new page is then added to the queue q and the set s.
       The pageFaults counter is incremented.
If the page is already in the set, it is ignored, as it does not cause a page fault.

5.Main Function:

An example sequence of page requests is stored in the pages vector.
The capacity of the page frames is set to 3.
The fifo function is called with the pages vector and capacity.
The total number of page faults is printed to the console.

Example Execution:
Given the example page sequence {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1} and a capacity of 3 page frames, the FIFO algorithm will determine how many page faults occur as pages are loaded into memory.

Output:
The output will be:
Total page faults using FIFO: 15
