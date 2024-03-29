---
title: String memory use
layout: main
---

The goal of this exercise is to understand the memory use and performance of
[std::string](http://www.cplusplus.com/reference/string/string/). You will
get familiar with the [IgProf](http://igprof.org) profiler tool.

Steps
-----

1. Make sure your environment is correct:

        c++ -v 2>&1 | grep version  # should say 'gcc version 4.9.0 (GCC)'
        igprof -h                   # should print simple help message

2. Go to the exercise directory:

        cd esc15/hands-on/memory

3. Examine the little test programs in this directory.  You use them for
   dedicated little studies on container memory allocation behaviour:

   - [ls-build.cc]({{site.exercises_repo}}/hands-on/memory/ls-build.cc): Build a
     `std::list<std::string>` one at a time.

   - [vs-build.cc]({{site.exercises_repo}}/hands-on/memory/vs-build.cc): Build a
     `std::vector<std::string>` one at a time.

   - [vvs-build-and-copy.cc]({{site.exercises_repo}}/hands-on/memory/vvs-build-and-copy.cc): Build a
     Same as `vvvi-build-and-copy.cc`, but using doubly nested vector of
     strings.  Behaves differently because strings are copy-on-write -- less
     memory copies but more reference counting.

4. Build each program.  The command is mentioned in each source file.  To
   build all in one go:

        grep -h Compile *.cc | sed 's|// Compile: ||' | sh -x

5. Run the programs under the igprof profiler:

        rm -f *.gz
        igprof -mp ./ls-build
        igprof -mp ./vs-build
        igprof -mp ./vvs-build-and-copy

6. Analyse the profiles using:

        for f in *.gz; do
          igprof-analyse --sqlite -d -v -g -r MEM_TOTAL $f |
            sqlite3 ~/public_html/cgi-bin/data/${f}_tot.sql3
          igprof-analyse --sqlite -d -v -g -r MEM_LIVE $f |
            sqlite3 ~/public_html/cgi-bin/data/${f}_live.sql3
          igprof-analyse --sqlite -d -v -g -r MEM_LIVE --value peak $f |
            sqlite3 ~/public_html/cgi-bin/data/${f}_live_peak.sql3
        done

7. This results in profiles such as:

   http://131.154.193.33/~<student>/cgi-bin/igprof-navigator.py/vvs-copy.gz_tot/
