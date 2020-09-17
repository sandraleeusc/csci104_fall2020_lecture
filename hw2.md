---
layout: default
title: Homework 2
nav: assignments
---
## HW2

+ Due: Fri. Sep. 18, 2020, 11:59pm (PST)
+ Directory name in your github repository for this homework (case sensitive): `hw2`
   - Once you have cloned your `hw-usc_username` repo, create this `hw2` folder underneath it (i.e. `hw-usc_username/hw2`).
   - If your `hw-usc_username` repo has not been created yet, please do your work in a separate folder and you can copy over relevant files before submitting.
   
### Problem 0: Experimental Runtime Analysis (0 out 100 points)
This problem will be discussed during our class meeting on stacks and queues. You do not need to submit this as part of your programming assignment. We want to give you extra time as this exercise involves coding and running experiments. It is helpful if you think about this problem before we meet and start collecting data to discuss.

For this exercise we have implemented for you an abstract Queue class in `queue.h`. This class defines the Queue ADT. As we mentioned briefly in lecture, the STL queue class is an adaptive container. It is essentially a list, but with the first in first out protocol (FIFO), so we can only add to the the back of the list and remove from the front of the list. We provide two different implementations of the queue using different data structures. The List Queue implementation in `listqueue.h` uses STL list. The Vector Queue implementation in `vectorqueue.h` uses STL vector. *Please study these implementations.*  The implementation of queue classes use public inheritance for the abstract Queue class to implement the interface and use composition for STL vector or STL list as the private data. They are essentially wrapper implementations and an example of how to use an abstract class. This will be similar to writing a stack as a wrapper implementation for using your circular linked list for Problem 2 below.

We want to measure the differences in the operations given each implementation and why this may be occurring.  We will step you through this here. Starting code for running experiements is include in `queue_test.cpp`. The test as written creates queues, pushes integers onto the queues and tests the timing of the pop_front operations. To compile: ` g++ --std=c++17 -o queuetest queue_test.cpp`

We will discuss the following questions during class and how you may be able to verify them either using analysis or experimentally.<BR>
*Runtime Questions for Queue Implementations:*
1. In both implementations the functions front(), empty(), size() and push_back() all take constant time O(1). How can you verify this experimentally or using analysis?
2. Which implementation is more efficient for pop_front(), the vector or list? How can you verify your claim experimentally or using analysis? Can you present data to convince a skeptic? What is the runtime of each? (These are runtimes that were covered in CSCI 103.)

We have included code in `queue_test.cpp` for collecting timing data for an experiment. (This is not the best approach for runtime efficiency analysis, but it is sometimes used in practice. We will discuss the benefits and disadvantages.) To do so we use, we use the C++ high_resolution_clock as show below. You may use this code wherever you want to take timing measurements.
```
#include <chrono>
// Start the timer by getting the current time
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now(); 
  
//Run experiment
our_experiment();

// End timer by getting current time when you have finished what you would like to measure
  std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();

 // Get the duration of your experiment
  std::chrono::duration<double, std::milli> fp_ms = stop - start;
```

   
### Problem 1: Circular Linked List (20 points out of 100)

For this problem, we will create a class that stores a doubly-linked list of ints.  The list will also be circular, meaning that the head and tail of the list link to each other.  The list supports all operations in the List ADT, including insert, remove, get, and set.

A class skeleton has been provided in `circular_list_int.h`.  Copy this header to your homework folder and, in `circular_list_int.cpp`, implement the functions in `CircularListInt` according to their descriptions in the header file.

#### Circular Indicies

Since this class is a circular list, it is meant to store data that will be accessed continuously in a circle, so indicies past the end of the list should wrap around back to the front of the list. For example, if a list has 5 members, index 5 wraps back to element 0, index 6 maps to element 1, and index 10 maps to element 0. This is the same as using modular arithmetic. If there are n members of a list, then to get the appropriate position in the list for index i, the position in the list is `i % n`. This rule applies to `get()`, `set()`, and `remove()`. When the list has 0 length, i.e. n = 0, and there are no elements at all,  `get()` should return -1 and `set()` and `remove()` should just return without modifying the list.  


### Problem 2 (Stacks, 15 points out of 100)
Now you will use your `CircularListInt` class to create a Stack data structure for variables of type `int`.  Alternatively, you can use the STL `list<int>` if your Circular Linked List does not work for a cost of 4 points.  Download and use the provided `stackint.h` as is. You may add private data and members if necessary (although it most likely will not be necessary).  Notice the stack has a CircularListInt as a private data member. (If you are using the 4 point penalty to buy use of STL list, you need to change the private data member to type `list<int>` instead of CircularListInt).  This is called **composition**. The member functions of the `StackInt` class that you write should really just be wrappers around calls to the underlying linked list implementation.

You should think **carefully** about efficiency.  **All operations (other than possibly the destructor) should run in O(1).**

### Problem 3 (Simple Arithmetic Parser and Evaluator, 60 points out of 100)

Simple arithmetic expressions consist of integers, the operators PLUS (+), MULTIPLY (\*), MINUS (-), and DIVISION (/), along with parentheses to specify a desired order of operations.  The DIVISION operator rounds down to the nearest integer. (C++ automatically does this for division of integers.) *Your parser will only be given non-negative integers.*

Your task is to complete the implementation of the parser class that will evaluate and show the output of given arithmetic expressions in strings. 

Simple Arithmetic Expressions are defined formally as follows:

1. Any string of digits is a simple arithmetic expression, namely a non-negative integer.
1. If Y and Z are simple arithmetic expressions then the following are simple arithmetic expressions:
    + (Y+Z)
    + (Y\*Z)
    + (Y-Z)
    + (Y/Z)

Notice that our format rules out the expressions such as  12+23, since it is missing the parentheses. It also rules out expressions such as (12+34\*123) which would have to instead be written (12+(34\*123)), so you never have to worry about precedence. This should make your parsing task significantly easier. Whitespace may occur in arbitrary places in arithmetic expressions, but never in the middle of an integer. Each expression will be on a single line. *Expressions within parentheses must not be empty.*

Examples:  

```
10 // evaluates to 10
(14 *(123+333)) // evaluates to 6384
(2 * (500000000/2)) // evaluates to 500000000
((6/4) * 2) // evaluates to 2
((8+4)/(9-2)) // evaluates to 1
((123*234)+10    // Malformed
(1337*9001+42)   // Malformed
(*1138*3720)    // Malformed
() // Malformed 
```

A sample program that will use your parser is included in `parser_test.cpp` that is driver code for testing your parser. Parser_test takes as an argument the filename in which the expressions are stored as an input parameter.  For each expression in the input file, the program should output to `cout`, one per line, one of the options below:

 - `Malformed` if the formula was malformed (did not meet the definition of an expression above) and then continue to the next expression.  
 - An integer equal to the evaluation of the expression, if the expression was well-formed.

It is the responsibility of the `evaluate_expression` function of your parser class to produce the correct output for each arithmetic expression string passed to it as explained above. Each expression will be on a single line read in using getline() and that line will then be passed to the parser. If the line is blank, the parser may return immediately.  The numbers will always fit into `int` types. Your parser implementation should work with  `parser_test.cpp`. We have included some expressions for testing in the file, `test_expressions`. Your completed parser implementation should be in the library file `parser.h` and corresponding implementation file, `parser.cpp`.

**You must not use recursion to solve this problem**. Instead keep a stack on which you push pieces of formula.  **Use your `StackInt` class** from Problem 2 for this purpose.  In order to develop your algorithm, you should use STL stack. If your StackInt class is not working, you may submit the implementation using STL Stack for an 11 point deduction.

*Guideline for parsing and evaluating expressions:*
1. Push open parentheses '(', integers, and operators onto the stack.  
2. When you encounter a closing parenthesis ')', pop things from the stack and evaluate them until you pop the open parenthesis '('. 
3. Now --- assuming everything was correctly formatted --- compute the value of the expression in parentheses, and push it onto the stack as an integer. 
4. When you reach the end of the string, assuming that everything was correctly formatted (otherwise, report an error), your stack should contain exactly one integer, which you can output.

We have provided `parser.h` with suggestions for how you may implement your parser. Aside from using your StackInt or STL stack to evaluate the expression, you are welcome to change the private data and functions. However we would like to make two additional strong suggestions. First it is highly adviseable for you to consider using a stringstream in order to help in parsing the expressions. When you are parsing the expressions, the parser will be extracting tokens. Tokens in the expression strings your parser will be given are integers, parentheses, and mathematical operators. In order to help you keep track of these tokens, we have included an enum for tokens in the parser class and a function to take a character and return a token. If a token is an integer, it is necessary to parse it correctly even if it has multiple digits.

In order to help you keep track of tokens the following enum of tokens that may be in valid expressions is included in the Parser class:

```
 enum token {
	     MIN_NUM = 0,
	     OPEN_PAREN = -1,
             CLOSE_PAREN = -2,
	     PLUS = -3,
	     MULTIPLY = -4,
	     MINUS = -5,
	     DIVIDE = -6,
	     UNINITIALIZED = -7
     };
```

The MIN_NUM token may be used to keep track of when a number is found, but may need to be processed correctly from the expression. The UNINITIALIZED token may be used when a character in an expression violates the rules for expressions or when the value of token is not know yet. You may use the tokens as a type, namely `Parser::token`, or you may also use them as an int.

### Code Readability (5 out of 100 points)
Your code will be manually inspected for readability.  This includes the formatting of your code and function names etc.
