---
title: Smart pointers
layout: main
category: cpp
---

The goal of this exercise is to get some confidence with the smart
pointers provide by the C++ standard library: unique_ptr and
shared_ptr.

Open the test program
[`dir.cpp`](https://github.com/infn-esc/esc15/hands-on/cpp/dir.cpp)
and complete the existing code to:

* create a smart pointer managing a DIR resource obtained with the
  opendir() function call
* associate a deleter to that smart pointer
* implement a function to read the names of the files in that
  directory
* check if the deleter is called at the right moment
* hide the creation of the smart pointer behind a factory function

You can experiment with both kinds of smart pointers and with the type
of the function arguments.

The commands to build and run the code are:

    cd esc15/hands-on/cpp
    c++ -std=c++14 -O -o dir dir.cpp
    ./dir /tmp
