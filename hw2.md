---
layout: asides
toc: true
tasks: true
title: Homework 2
---

# Homework 2


- Assigned: September 07, 2020 PST
- Due: September 18, 2020 at 23:59 PST
- Directory name in your github repository for this homework (case sensitive): `hw2`
   - Skeleton code for this assignment is available in [`resources/hw2/`]({{ site.data.urls.github }}/resources/).
   - Once you have cloned your `hw-username` repo, copy the `hw2/` directory into it from `resources`.


The goal of this assignment is to guide you through building an arithmetic calculator.
By the time you're ready to submit, you'll be able to compute the value of things like `((1 + 3) * 5)` and `(20 / (2 * 2))`.

## A Note on Formatting

Please modify the `.clang-format` file in the root of your repository to change the line `AccessModifierOffset: -2` to `AccessModifierOffset: -4`.
This affects the indentation of `switch` labels and `class` access modifiers, and was originally published incorrectly.


## Experimental Runtime Analysis

This problem will be discussed during our class meeting on stacks and queues.
**You do not need to submit this as part of your programming assignment**.
We want to give you extra time as this exercise involves coding and running experiments.
It is helpful if you think about this problem before we meet and start collecting data to discuss.

For this exercise we have implemented for you an abstract queue class in `int_queue.h`.
As we mentioned briefly in lecture, the STL queue class is an adaptive container.
It is essentially a list, but with the first in first out protocol (FIFO), so we can only add to the the back of the list and remove from the front of the list.
We provide two different implementations of the queue using different data structures.
The list queue implementation in `int_queue_list.h` uses an STL `list`.
The vector queue implementation in `int_queue_vector.h` uses an STL `vector`.
**Please study these implementations**.

- [ ] Read through the queue implementations.

Both queues publicly inherit from the abstract queue class to implement the interface.
Both use composition of an STL `vector` and STL `list` respectively to store the data internally.
They are essentially wrapper implementations and an example of how to use an abstract class.
This will be similar to writing a stack as a wrapper implementation for using your circular linked list below.

Our goal is to measure and compare the speed of our abstract queue operations between the two implementations. 
Starting code for running experiments is include in `int_queue_tests.cpp`.
The test as written creates queues, pushes integers onto the queues and tests the timing of the `pop_front` operations.
To compile, run:
 
```shell
g++ --std=c++17 -o int_queue_tests int_queue_tests.cpp
```

We will discuss the following questions during class and how you may be able to verify them either using analysis or experimentally.

### Runtime Questions

1. In both implementations, the functions `front()`, `empty()`, `size()`, and `push_back()` all take constant time `O(1)`.
   How can you verify this experimentally or using analysis?
2. Which implementation is more efficient for `pop_front()`, the vector or list?
   How can you verify your claim experimentally or using analysis?
   Can you present data to convince a skeptic?
   What is the runtime of each (all runtimes here are covered in CSCI 103)?

### Running the Tests

We have included code in `int_queue_tests.cpp` for collecting timing data for an experiment.
Note that this is not the best approach for runtime efficiency analysis, but it is sometimes used in practice; we will discuss the benefits and disadvantages.
To run the tests, use:

```shell
./int_queue_tests
```

The tests use the C++ `high_resolution_clock` as shown below.
You may use this code whenever you want to do any timing in your own code.

```
#include <chrono>


// Start the timer by getting the current time.
std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now(); 

// TODO: the code you're measuring should be here.

// End timer by getting current time when you have finished what you would like to measure.
std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();

// Get the duration of your experiment
std::chrono::duration<double, std::milli> duration = stop - start;
```


## 1. Token Containers (50%)

A `struct Token` has been provided in the `tokenizer/token.h`, and will be the basis for our arithmetic parser.
Besides passing it into your linked list, **you can completely ignore its content and meaning for this problem**.
We'll get to it later.

For this part of the homework, we will create a class that stores a doubly-linked list of `Token` objects.
Because `Token`s are simply our value type, we don't have to worry about their specific implementation details in this section.
**Our list implementation will be circular**, meaning that the head and tail of the list link to each other.
This will allow us to more efficiently append to the end of the list.
It will also support all common operations expected of an abstract list data type, including insert, remove, get, and set.


Since this class is a circular list, it is meant to store data that will be accessed continuously in a circle, so indicies past the end of the list should wrap around back to the front of the list. For example, if a list has 5 members, index 5 wraps back to element 0, index 6 maps to element 1, and index 10 maps to element 0. This is the same as using modular arithmetic. If there are n members of a list, then to get the appropriate position in the list for index i, the position in the list is `i % n`. This rule applies to `at`, `insert`, and `remove`. To be consistent with this, these functions should behave in the following manner:
-  If the list is empty, `at` in the starter code throws an exception for you. Otherwise, the function should return the token at the index%n where n is current size of the list assuming that the head of the list is at index 0.
- `insert` should  first increase the size of the list by 1. Then it should insert the token at index%n where n is the new size of the list and assuming that the head of the list is at index 0. 
- If the list is empty, `remove` should just return without modifying the list. Otherwise, remove should remove the item at index%n where n is the current size of the list assuming that the head of the list is at index 0.

A class skeleton has been provided in `hw2/tokens/` in the `resources` repository. and 
Run `git pull` in your local clone to make sure it is up to date.
You can then copy the entire `hw2/` directory into your local `hw-username` as you did for `hw1`.

### Token List

The first thing you'll want to do is read through the header `hw2/tokens/token_list.h`.
Everything you need to implement is marked with `TODO`, and you'll want to write out the definitions in the corresponding `token_list.cpp`.

- [ ] Read through `token_list.h`.

There are a couple notes you'll want to consider while implementing the remaining methods:

- The `const` and non-`const` implementation of `at(size_t index)` will likely be identical.
  In general, the reason you offer both is so that you can access members with the correct `const` permission.
  The non-`const` version returns a reference you may modify, whereas the `const` version returns a reference you may not.
- Make sure that your `push_back` and `insert` correctly set the `next` and `previous` on all affected nodes.
  Don't be afraid to review the linked list slides.
- The same applies to `remove`.
  This will ensure that the number of references to the removed `Item` hits zero, and consequently that the removed `Item` is deallocated.
- We encourage you to use helper methods to avoid repetition and keep your code clean.
  Some suggestions are included in `token_list.h`.
  
With all of these things in mind, go ahead and implement `TokenList`.
We've provided a `Makefile` for you to use, and an example test harness that you may modify in `token_list_tests.cpp`.
You can run the that test file using `make token_list_tests`.

- [ ] Implement the rule of three.
- [ ] Implement the `at`.
      You can copy the implementation for the `const` version.
- [ ] Implement `push_back`.
- [ ] Implement `insert`.
- [ ] Implement `remove`.
- [ ] Run the basic tests to check that it works.

### Composing a Stack

Now you will use your `TokenList` class to create a stack data structure for `Token`s.
The stack skeleton is provided, you simply have to implement the marked methods.
Notice the `TokenStack` has a `TokenList` as a private data member.
This is called **composition**.
The member functions of the `TokenStack` class that you write should really just be wrappers around calls to the underlying linked list implementation.
If you are not able to fully implement your TokenList class, you may purchase the use of STL list, i.e. list\<Token\>, for **a flat rate penalty of 3%**. If you do so, please be sure to include the appropriate libraries (i.e. #include \<list\>).

You should think **carefully** about efficiency.
**All operations other than `reverse` and the destructor should run in O(1)**.

- [ ] Implement the `TokenStack` methods.
- [ ] Optionally, test out your `TokenStack`.


## 2. Simple Arithmetic (50%)

Wait, so what is a `Token`?

When you see the mathematical expression `(13 * 3)`, the first thing your brain probably does is break it down into syntactic pieces.
We can think of those pieces as tokens, and in this case we have five: `"("`, `"13"`, `"*"`, `"3"`, and `")"`.

Formally speaking, a token is an atomic part of a syntax, and one or more tokens form an expression.
By atomic, we mean that they are the smallest division of the expression that have meaning.
It doesn't make sense to keep track of `"13"` as two individual tokens `"1"` and `"3"`.
Doing so loses the original meaning of `"13"`, which we need in order to compute the result correctly.
On the other hand, we separate `"("` and `"13"` even though they're directly next to each other.
This is because an open parenthesis' meaning is unrelated to that of the `"13"`.

For the purpose of our arithmetic parser, we will keep track of seven kinds of tokens.
These kinds are outlined in the `enum class TokenKind` in `token/token.h`:

- The parentheses, `(` and `)`, will each be their own token kind.
- The operators, `+`, `-`, `*`, `/`, will all be a unique token kind.
- All non-negative integers, which consist of one or more digits, will be a single token kind. 

### Grammar

When you think about evaluating a mathematical expressions, you tend to think in patterns.
For example, when you see an expression of the form `number + number`, you know to sum the two numbers.
Formally, we call these patterns a **grammar**, but don't worry; we won't need the fancy terminology to implement our parser.

What you should take away from this is that the `TokenKind`s are a matter of practicality. 
We use them in order to verify that the expressions we're evaluating match our the patterns we're expecting.
When it comes to evaluation, we can simply store the actual value of numeric tokens in `Token.value`.
For symbols, this is irrelevant. 

The patterns we'll concern ourselves with for this homework are as follows.
Note the recursive structure, which we'll point out in each:

1. A non-negative integer is a **simple arithmetic expression**.
   Think of it as the **base case** for our general idea of what a simple arithmetic expression is. 

2. If `p` and `q` are **simple arithmetic expressions**, then the following patterns are also simple arithmetic expressions, invariant to whitespace:
    - `(p)`
    - `(-p)`
    - `(p + q)`
    - `(p - q)`
    - `(p * q)`
    - `(p / q)`

3. Additionally, you may chain as many of the same binary operations together as you want. 
   We'll call these chained binary operators (where p, q, r and remaining terms are simple arithmetic expressions):
    - `(p + q + r + ...)`
    
 4. A valid expression cannot be empty and must contain at least one non-negative integer.

These are the cases our parser will address while its consuming tokens from the stack.
They provide a set of constraints for the kinds of input we accept as valid.
For example, `(32)` and `((1 - 2) * 3)` are valid, but `(1 - 2 * 3)` is not because we can't build it with our simple arithmetic expression patterns. 

### Creating Tokens

Our first order of business will be to split our `string expression` into a `TokenStack`.
Because the format of each token is pretty simple, we can do so by consuming a `stringstream`.
We recommend using `stringstream.get()`, `stringstream.peek()`.
When you need to extract an integer from the stream, you should use the `>>` operator.

For symbols, you can instantiate the `Token` by calling the constructor with just the `TokenKind`:

```c++
// For +:
stack.push(Token(TokenKind::PLUS));
``` 

For numbers, you can pass an additional argument of the integer value:

```c++
// For some int value:
stack.push(Token(TokenKind::NUMBER, value));
```

How you actually identify and consume these tokens from the stream is up to you.
Note that you can expect any amount of whitespace between the tokens we've outlined.
Therefore, while you're tokenizing, you can simply ignore it.

- [ ] Complete `tokenize` in `arithmetic/arithmetic.cpp`.
- [ ] You can test your tokenizer is by modifying `evaluate` to `cout` the stack from `tokenize`.

### Evaluating Your Stack

If you take a look at `evaluate` in `arithmetic/arithmetic.cpp`, you will see that we first `tokenize` and store the result as `tokens`.
In order to actually evaluate the expression, you will instantiate a second `TokenStack` called `work`.
This will contain the tokens you're actively computing.

As you pop tokens off of `tokens`, you will push them onto `work`.
Every time you reach a `Token` with `kind` `TokenKind::RP`, you will know that there should be a full binary operation on `work`, at which point you will `reduce` it.
The `reduce` method simply pops a right operand, operator, left operand, and corresponding `TokenKind::LP` off of `work`, evaluates them mathematically, and pushes the result back onto `work`.

Here are a couple examples of how this might look.
Note that **as depicted, `work` is shown in reverse so that you can see its relation to `tokens`**.
This reversal will be handled in `reduce`.

<div class="text-align-center">
    <table class="simple center">
        <thead>
            <tr>
                <th>Work</th>
                <th>Tokens</th>
                <th>Action</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td><code></code></td>
                <td><code>(1 + 3)</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>(</code></td>
                <td><code>1 + 3)</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>(1</code></td>
                <td><code> + 3)</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>(1 +</code></td>
                <td><code>3)</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>(1 + 3</code></td>
                <td><code>)</code></td>
                <td>Reduce</td>
            </tr>
            <tr>
                <td><code>4</code></td>
                <td><code></code></td>
            </tr>
        </tbody>
    </table>
</div>

For further clarification, also be sure to read through the comments in `reduce` and `evaluate`.
They will guide you through actually implementing the parser.
Here's a slightly more complex example:

<div class="text-align-center">
    <table class="simple center">
        <thead>
            <tr>
                <th>Work</th>
                <th>Tokens</th>
                <th>Action</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td><code></code></td>
                <td><code>((1 + 3) / (4 - 2))</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>(</code></td>
                <td><code>(1 + 3) / (4 - 2))</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>((</code></td>
                <td><code>1 + 3) / (4 - 2))</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>((1</code></td>
                <td><code>+ 3) / (4 - 2))</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>((1 +</code></td>
                <td><code>3) / (4 - 2))</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>((1 + 3</code></td>
                <td><code>) / (4 - 2))</code></td>
                <td>Reduce</td>
            </tr>
            <tr>
                <td><code>(4</code></td>
                <td><code>/ (4 - 2))</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>(4 /</code></td>
                <td><code>(4 - 2))</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>(4 / (</code></td>
                <td><code>4 - 2))</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>(4 / (4</code></td>
                <td><code>- 2))</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>(4 / (4 -</code></td>
                <td><code>2))</code></td>
                <td></td>
            </tr>
            <tr>
                <td><code>(4 / (4 - 2</code></td>
                <td><code>))</code></td>
                <td>Reduce</td>
            </tr>
            <tr>
                <td><code>(4 / 2</code></td>
                <td><code>)</code></td>
                <td>Reduce</td>
            </tr>
            <tr>
                <td><code>2</code></td>
                <td><code></code></td>
                <td></td>
            </tr>
        </tbody>
    </table>
</div>

### Implement Evaluate

We recommend you start by implementing `evaluate`, which will hopefully give you the bigger picture of how the parser works.
The evaluation loop is fairly simple if we don't concern ourselves with the specifics of `reduce`.

- [ ] Write `evaluate`.

### Implementing Reduce

In order to understand how to implement reduce, we first have to think about the preconditions it's executed with.
Namely, once we've popped items off of `work` and into `immediate` until we hit the corresponding open paren, what will `immediate` look like?
Based on the patterns we described above, there are two possible cases given a valid expression:

1. The `immediate` stack has a series of tokens comprising some expression `-p` on top.
   If we check immediate and determine that this is the case, we can simply pop `p`, negate its value, and push it back onto work.
2. The `work` stack has a series of tokens comprising some expression `p` or `p @ q` or `p @ q @ ...` where `@` represents one of our four binary operators.
   If this is the case, we will first pop `p`.
   For every consequent operator and right-hand operand, compute the result and store it in `p.value` (if we have just `(p)`, this loop will run zero times).
   Once we're done, we can simply put `p` back onto work.

You'll need to make sure both of these branches are handled properly for your parser to work.

- [ ] Implement the `-p` case for `reduce`.
- [ ] Implement the `p` or `p @ ...` case for `reduce`

There are two notes worth mentioning here about `reduce` that are echoed in the skeleton code comments:

- All arithmetic can be done with `int`.
  The expressions `(1 / 3)` and `((-1) / 3)` should simply evaluate to `0`, so you don't have to do anything fancy when doing binary operations (you can use C++'s normal integer math behavior).
- For any problems with the expressions as well as attempting division by zero, throw the exception `invalid_argument("malformed")`.
  The exact exception you should throw is already written for you in comments in the starter code as well as some cases for you to check for when these incorrect expressions may occur.
  Here are some examples of malformed expressions:
```
()
-5
(5 * 6 * 8) + (10)
(-7 - 9)
(8 * 7
(7 / 0)
(5 / (7 - 7))
7 / 2
(* 5 * 8)
5 * 8)
(5 + 8 * 5)
```

- Any chained binary expressions that have different operators are invalid.
  For example, `(p + q + r)` is fine but anything like `(p + q - r)` is not.
 - **The final result of reduce from evaluating a properly formed expression can be any integer**.

### Testing

When you're done, you can test it by running the following:

```shell
# Build
make

# Pass an expression
./arithmetic "(3 + (4 / 2))"
```

- [ ] Test arithmetic by running it on the command line.




## Submitting

Once you've finished, check that all of the code you're submitting is consistently formatted.
The `README.md` in your homework repository provides instructions for using `clang-format` to do so automatically.
You can then submit your code on the [Curricula submission page]({{ site.baseurl }}/submit/assignment/hw2).
Be sure to carefully read and follow the instructions there.

- [ ] Format your code using `clang-format`.
- [ ] Submit your code.
- [ ] Check that your homework satisfies the [Visual Inspection Rubric]({{ site.baseurl }}/homework/rubric)




