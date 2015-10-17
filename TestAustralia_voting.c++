// --------------------------------
// projects/australia_voting/TestAustralia_voting.c++
// Copyright (C) 2015
// CS Hui
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Australia_voting.h"

using namespace std;

// -----------
// TestAustralia_voting
// -----------

// ----
// read
// ----
/*
TEST(Australia_votingFixture, read) {
    string s("1 10\n");
    const pair<int, int> p = australia_voting_read(s);
    ASSERT_EQ( 1, p.first);
    ASSERT_EQ(10, p.second);}

TEST(Australia_votingFixture, read1) {
	int i, j, k;
    string s("1 10 100\n");
    const tuple<int, int, int> t = australia_voting_read1(s);
    tie(i, j, k) = t;
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);
    ASSERT_EQ(100, k);}
*/
// ----
// eval
// ----

/*
TEST(Australia_votingFixture, eval_4) {
    const int v = australia_voting_eval(3, 11);
    ASSERT_EQ(3, v);}
*/

// -----
// print
// -----
/*
TEST(Australia_votingFixture, print) {
	vector<int> v = {1, 2, 3, 4};
    ostringstream w;
    australia_voting_print(w, v);
    ASSERT_EQ("1 2 3 4 \n", w.str());}
*/
// -----
// solve
// -----

TEST(Australia_votingFixture, solve) {
    istringstream r("1\n\n2\nA\nB\n1 2\n\n");
    ostringstream w;
    australia_voting_solve(r, w);
    ASSERT_EQ("A\n", w.str());}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Australia_voting.c++ TestAustralia_voting.c++ -o TestAustralia_voting -lgtest -lgtest_main -lpthread



% valgrind TestAustralia_voting                                         >  TestAustralia_voting.out 2>&1
% gcov -b Australia_voting.c++     | grep -A 5 "File 'Australia_voting.c++'"     >> TestAustralia_voting.out
% gcov -b TestAustralia_voting.c++ | grep -A 5 "File 'TestAustralia_voting.c++'" >> TestAustralia_voting.out



% cat TestAustralia_voting.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestAustralia_voting
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Australia_voting
[ RUN      ] Australia_voting.read
[       OK ] Australia_voting.read (31 ms)
[ RUN      ] Australia_voting.eval_1
[       OK ] Australia_voting.eval_1 (5 ms)
[ RUN      ] Australia_voting.eval_2
[       OK ] Australia_voting.eval_2 (3 ms)
[ RUN      ] Australia_voting.eval_3
[       OK ] Australia_voting.eval_3 (3 ms)
[ RUN      ] Australia_voting.eval_4
[       OK ] Australia_voting.eval_4 (3 ms)
[ RUN      ] Australia_voting.print
[       OK ] Australia_voting.print (17 ms)
[ RUN      ] Australia_voting.solve
[       OK ] Australia_voting.solve (10 ms)
[----------] 7 tests from Australia_voting (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'Australia_voting.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Australia_voting.c++.gcov'
File 'TestAustralia_voting.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestAustralia_voting.c++.gcov'
*/
