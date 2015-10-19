# Disjoint sets
Implementation of a disjoint sets (also called union-find data structure or
merge-find set). It will pass
[Kattis](https://open.kattis.com/problems/unionfind).

## How-to
For running tests you will need [Google C++ Mocking
Framework](https://code.google.com/p/googlemock/). Build with
[SCons](http://www.scons.org) from root directory.

    $ scons
    $ cd bin
    $ ./run_all_tests

You can also run the Kattis test cases.

    $ cat kattis/unionfind1.in | ./unionfind

## References
KTH lecture notes.
