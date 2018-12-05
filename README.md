Author          : Sunil Shankar Jaishankar
Created         : September 14, 2018
Last Modified   : September 14, 2018

Institute       : Georgia Institute of Technology


Description
-------------

This program is a solution to the problem statement in Assignment 1C for CSE 6010. The 'functions.c' file has function definitions for
1. Definition for struct PrioQ plus 'typedef and definition' of its implementation (i.e struct Node that defines the data in every node)
2. Function to create Priority Queue
3. Function to insert nodes into the priority queue by prority
4. Function to delete nodes from the queue
5. Function to count number of nodes in the queue
6. Function to free up/release the priorit queue and all its node from the memory
7. An additional function to facilitate printing of the queue by priority

Further, the 'functions.h' file has the prototypes for all the functions above and the typedef for the PrioQ struct.

The 'assg1C.c' file has the main() program which makes use of the above listed function to create to
1. Create a queue
2. Insert nodes into the queue
3. Delete nodes in queue
4. Count nodes in queue
5. Print nodes in the queue
6. Free nodes in a queue as well as the queue itself


Installation
------------

To install, run

    gcc functions.c assg1C.c -std=c99 -o Assignment1C

Note: The -std=c99 flag is required on some C compilers
to allow variable declarations at arbitrary locations in
a function.

Execution
-----------

Run executable using on linux and iOS

    ./Assignment1C

For Windows, use

    Assignment1C


