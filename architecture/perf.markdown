---
title: Profiling using perf
layout: main
category: Architecture
---

``perf`` is a tool to profile a process using ``Hardware Performance Counters``. Each counter counts
Events in the CPU such as cycles, executed instructions, load from a given level of the memory caches,
branches...

{% highlight bash %}
perf list
{% endhighlight %}
lists the event that are predefined inside the tool.


the easiest way to use perf is to profile the whole application (say ./a.out) using a default set of events
{% highlight bash %}
perf stat ./a.out
{% endhighlight %}

On can choose a set of events and list them on the command line as in

[`doPerf`](https://github.com/infn-esc/esc15/exercises/architecture/doPerf)

For large applications more details can be obtained running ``perf record``  that will produce a file containing all sampled events and their location in the application.
``perf report`` can be used to display the detailed profile

a wrapper defining more user-friedly name for INTEL counters can be downloaded
{% highlight bash %}
git clone https://github.com/andikleen/pmu-tools.git
{% endhighlight %}
and executed in place of `perf` as
 {% highlight bash %}
pmu-tools/ocperf.py
{% endhighlight %}
