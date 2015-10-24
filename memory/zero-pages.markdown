---
title: Zero Pages
layout: main
---

In this exercise you will touch with hand the difference between RSS and VSIZE
and you will see zero pages in action.

Copy and paste to a file and compile the following two programs:

    #include <unistd.h>
    #include <cstdlib>
    #include <cstring>

    #define NUM_ITEMS 100000000
    #define SIZE_ITEM 10

    int
    main (int argc, char ** argv)
    {
      void *ptr = malloc(NUM_ITEMS * SIZE_ITEM);
      memset(ptr, 0, NUM_ITEMS * SIZE_ITEM);
      while(true) sleep(1);
      return 0;
    }

and:

    #include <unistd.h>
    #include <cstdlib>

    #define NUM_ITEMS 100000000
    #define SIZE_ITEM 10

    int
    main (int argc, char ** argv)
    {
      calloc(NUM_ITEMS, SIZE_ITEM);
      while(true) sleep(1);
      return 0;
    }

we will call them `mallocTest.cc` and `callocTest.cc`.

    c++ -o mallocTest mallocTest.cc
    c++ -o callocTest callocTest.cc

1. Use top and ps to find out what is their RSS and VSIZE. 

2. Why mallocTest has much larger RSS than the callocTest?

3. Remove the `while(true) sleep(1);` line in both of them (so that they exit),
   recompile and use IgProf to do the memory profiling. What do you see? Why?
