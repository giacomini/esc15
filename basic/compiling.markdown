---
title: Basic compilation of test programs
category: basic
layout: main
---

The goal of this exercise is to understand how to compile and run test
programs on a student server. The default compiler is 64-bit gcc v. 5.2.0.

Build [cputicks.cc]({{exercises_repo}}/exercises/basic/cputicks.cc):

	{% highlight bash %}
    cd hands-on/basic
    c++ -std=c++14 -o cputicks cputicks.cc
    ./cputicks
	{% endhighlight %}
