---
title: Basic profiling using std::chrono
layout: main
category: basic
---

The goal of this exercise is to introduce you to the use of
`std::chrono` to do some basic performance measurements.

The test program includes manually inserted calls to
`high_resolution_clock` to retrieve the current `time_point`, which
allows to measure the elapsed time between two points.

Build and run
[`cputicks.cc`](https://github.com/infn-esc/esc15/hands-on/basic/cputicks.cc):

	{% highlight bash %}
	cd hands-on/basic
	c++ -std=c++14 -O -o cputicks cputicks.cc
	./cputicks
	{% endhighlight %}

Run the program a few times, possibly also with arguments:

	{% highlight bash %}
	./cputicks 100
	./cputicks 1000
	{% endhighlight %}

1. Why does `test1()` report much more time spent than `test2()`?

2. Why do the times reported by `test1()` fluctuate so much?

3. Do the times change if you change the optimization level of the
   compilation (`-O0` through `-O3`)?
