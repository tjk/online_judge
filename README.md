online_judge
============

Repository used to track my progress through the http://uva.onlinejudge.org/ problem sets.

running solutions
-----------------

For individual problems:

    % cd $PROBLEM_DIR
    % g++ -lm -lcrypt -O2 -pipe -DONLINE_JUDGE main.cpp
    % ./a.out < input.txt
    << output suppressed >>

OR (example output):

    % make
    ✗ ./100__3n_+_1
    ✓ ./101__blocks_problem
    ✓ ./102__ecological_bin_packing
    ✗ ./103__stacking_boxes
    ✗ ./105__the_skyline_problem
