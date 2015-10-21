---
title: Short introduction to Valgrind
layout: main
---

[Valgrind](http://valgrind.org/) is an instrumentation framework
for dynamic analysis tools. At this school we use the tools for checking
memory management bugs, but it includes many other tools such as for
finding threading bugs and analysing cache access patterns. This
exercise will introduce you to the basic mechanics of using Valgrind;
later exercises will go into more detail.

1. Build [`memerror.cc`]({{site.exercise_repo}}/hands-on/basic/memerror.cc):

        [studentNM@esc-XY ~]$ cd esc15/hands-on/basic
        [studentNM@esc-XY basic]$ c++ -std=c++14 -g -o memerror memerror.cc
        
2. Run the test program under valgrind:

        [studentNM@esc-XY basic]$ valgrind ./memerror

3. Try enabling the optimization (`-O`) and see if there is an effect
   on the valgrind analysis.

4. The compiler can sometimes warn us about the same thing:

        [studentNM@esc-XY basic]$ c++ -std=c++14 -g -Wall -Wextra -o memerror memerror.cc
