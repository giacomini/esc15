---
title: Use of function objects and algorithms
layout: main
category: cpp
---

The goal of this exercise is to get some confidence with the C++
entities that are _callable_: functions, functors and lambdas. You
will use them to customize the behaviour of some of the algorithms
provided by the C++ standard library.

The test program
[`algo.cpp`](https://github.com/infn-esc/esc15/hands-on/cpp/algo.cpp)
generates and prints a vector of randomly-chosen integer numbers.

Build it and run it a few times to verify that it works as
expected:

    cd esc15/hands-on/cpp
    c++ -std=c++14 -O -o algo algo.cpp
    ./algo
    ./algo

Then extend the program in order to:

* sum all the elements of the vector
* multiply all the elements of the vector
* sort the vector in ascending and descending order
* move the even numbers at the beginning
* move the three central numbers at the beginning
* erase from the vector the elements that satisfy a predicate

The source code contains some hints about what algorithms can be used
to implement the requested functionality. 
[cppreference.com](http://en.cppreference.com/w/) is an excellent source of
documentation for the algorithms (and C++ in general).
