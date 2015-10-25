---
title: AoS vs SoA
layout: main
---

In this exercise you will touch with hand the difference between AoS and SoA.

Copy and paste to a file and compile the following two programs:

    #include <vector>
    #define NUM_ITEMS 100000000

    struct A {
      double x;
      double y;
      double z;
      double w;
    };
    
    int main (int argc, char ** argv)
    {
      std::vector<A> myAoS(NUM_ITEMS);
      for (int i = 0; i < 10; ++i)
        for (auto &p : myAoS)
          p.w = 1.0;
      return 0;
    }

and:

    #include <vector>
    #define NUM_ITEMS 10000000

    struct A {
      std::vector<double> x;
      std::vector<double> y;
      std::vector<double> z;
      std::vector<double> w;
      A() : x(NUM_ITEMS), y(NUM_ITEMS), z(NUM_ITEMS), w(NUM_ITEMS) {}
    };

    int main (int argc, char **argv)
    {
      A mySoA;
      for (int i = 0; i < 10; ++i)
        for (auto &w : mySoA.w)
          w = 1.0;
      return 0;
    }

we will call them `aos.cc` and `soa.cc`.

    c++ -O3 -std=c++14 -o aos aos.cc
    c++ -O3 -std=c++14 -o soa soa.cc

1. Which one is faster?

2. How many bytes are written in the AoS case? How many in the SoA case?

3. How many cache-lines are touched in the AoS case? How many in the
   SoA case?

4. How many memory pages?

5. What happens to the performance of the two examples if you add a virtual
   destructor to A? Why?
