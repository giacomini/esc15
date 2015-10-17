---
title: Basic compilation of test programs
category: basic
layout: main
---

The goal of this exercise is to understand how to compile and run test
programs on the student servers. We have installed 64-bit GCC 5.2.0
which you can experiment with.

Build 64-bit [cputicks.cc]({{exercises_repo}}/exercises/basic/cputicks.cc) with
GCC 5.2.0:

    type c++
    cd esc15/exercises/basic
    c++ -o cputicks cputicks.cc
    file cputicks
    ./cputicks 1
