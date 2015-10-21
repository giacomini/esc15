---
title: Catching memory errors
layout: main
---

The goal of this exercise is to locate some common memory errors using
[Valgrind](http://valgrind.org).

Steps
-----

1. Make sure your environment is correct:

        c++ -v 2>&1 | grep version  # should say 'gcc version 4.9.0 (GCC)'
        valgrind --version          # should say 'valgrind-3.10.0'

2. Go to the exercise directory:

        cd esc15/exercises/memory

3. Examine the little test programs in this directory.  You use them for
   dedicated little studies on container memory allocation behaviour:

   - [uninitialised.cc]({{site.exercises_repo}}/hands-on/memory/uninitialised.cc):
     Catch use of uninitialised memory.

   - [array-smash.cc]({{site.exercises_repo}}/hands-on/memory/array-smash.cc):
     Catch writing past the end of an object.

   - [stack-smash.cc]({{site.exercises_repo}}/hands-on/memory/stack-smash.cc):
     Catch destruction of stack frame caused by overwriting outside bounds.

4. Build each program.  The command is mentioned in each source file.  To
   build all in one go:

        grep -h Compile *.cc | sed 's|// Compile: ||' | sh -x

5. Run the programs under Valgrind:

        valgrind --num-callers=50 --leak-check=full ./uninitialised
        valgrind --num-callers=50 --leak-check=full ./array-smash
        valgrind --num-callers=50 --leak-check=full ./stack-smash
 
6. Find the problems, fix them, recompile and repeat until the issues are
   fixed.

References
----------

* [Valgrind](http://valgrind.org)
