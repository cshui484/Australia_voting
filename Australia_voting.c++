// ----------------------------
// projects/australia_voting/Australia_voting.c++
// Copyright (C) 2015
// CS Hui
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <deque>
#include <functional>
#include <map>
#include <climits>
#include <set>

#include "Australia_voting.h"

using namespace std;

// ------------
// australia_voting_read
// ------------
/*
pair<int, int> australia_voting_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}
*/
// ------------
// australia_voting_read1
// ------------
/*
tuple <int, int, int> australia_voting_read1 (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    int z;
    sin >> i >> j >> z;
    return make_tuple(i, j, z);}
*/

int maxValue(vector<int>& v, int bIdx = 0) {
	int m = v[bIdx];
	
	for (int i=bIdx+1; i<(int)v.size(); i++) {
		if (v[i] > m) {
			m = v[i]; }}
	return m; }
			
int minValue(vector<int>& v, int bIdx = 0) {
	int m = INT_MAX;
	
	for (int i=bIdx; i<(int)v.size(); i++) {
		if ((v[i] < m) && (v[i] != -1)) {
			m = v[i]; }}
	return m; }
			
int index(vector<int>& v, int n, int bIdx = 0) {
	
	for (int i=bIdx; i<(int)v.size(); i++) {
		if (v[i] == n) {
			return i; }}
	return -1; }
	
vector<int> allIndex(vector<int>& v, int n, int bIdx = 0) {
	vector<int> rc;
	
	for (int i=bIdx; i<(int)v.size(); i++) {
		if (v[i] == n) {
			rc.push_back(i); }}
	return rc; }
	
		
// ------------
// australia_voting_eval
// ------------

void australia_voting_eval (AVcase& avCase, ostream& w) {

	vector< vector<int> >	c2bNum(avCase.cNo+1);		// entry 0 is not used
	vector<int>				c2bCnt(avCase.cNo+1);
	vector<int>				losers(avCase.cNo+1);
	vector<int>				reCnt, newLosers, tiedIdx;
	int 					bCnt, wCnt, minCnt, maxCnt;
	int						wIdx;
	
	bCnt	= (int) avCase.ballots.size();
	wCnt	= (bCnt >> 1) + 1;							// min. ballot count to win
	
	for (int i=0; i<bCnt; i++) {
		reCnt.push_back(i); }

	while (true) {

/*
avCase.print();
printVec(reCnt);
printVec(c2bCnt);
*/

		for (int i : reCnt) {
			int v = avCase.ballots[i].front();
			while (losers[v] == 1) {
				avCase.ballots[i].pop_front();
				v = avCase.ballots[i].front(); }
			avCase.ballots[i].pop_front();			
			c2bNum[v].push_back(i);
			c2bCnt[v]++; }
		maxCnt = maxValue(c2bCnt, 1);
		if (maxCnt >= wCnt) {							// we got a winner
			wIdx = index(c2bCnt, maxCnt, 1);
			w << avCase.cNames[wIdx-1] << endl;
			return; }
		minCnt = minValue(c2bCnt, 1);
//cout << "minCnt = " << minCnt << endl;
		if (minCnt == 0) {								// special cases: losers w/ 0 votes 
			newLosers = allIndex(c2bCnt, minCnt, 1);
			for (int i : newLosers) {
				losers[i] = 1; 
				c2bCnt[i] = -1; }						// remove losers from c2bCnt vector
			minCnt = minValue(c2bCnt, 1); }
//cout << "minCnt = " << minCnt << endl;
		newLosers = allIndex(c2bCnt, minCnt, 1);
		if (maxCnt == minCnt) {							// tied, no winner
			for (int i : newLosers) {
				w << avCase.cNames[i-1] << endl; }
			return; }
			
/*
cout << "newLosers:" << endl;
printVec(newLosers);
*/

		reCnt.clear();									// prepare for re-count
		for (int i : newLosers) {
			losers[i] = 1;
			c2bCnt[i] = -1;								// remove losers from c2bCnt vector
			reCnt.insert(reCnt.end(), c2bNum[i].begin(), c2bNum[i].end()); }}}

/*
cout << "reCnt:" << endl;
printVec(reCnt);
		if (reCnt.size() == 0) {						// tied, no winnder
			tiedIdx = allIndex(c2bCnt, maxCnt, 1);
			for (int i : tiedIdx) {
				cout << avCase.cNames[i-1] << endl; }
			return; }}}
*/



// -------------
// printVec
// -------------

void printVec(vector<int> &v) {
	int i;
	cout << "[";
	for (i=0; i<(int)v.size()-1; i++) {
		cout << v[i] << " "; }
	cout << v[i] << "]" << endl;
}

// -------------
// australia_voting_print
// -------------
/*
void australia_voting_print (ostream& w, vector<int> &v) {
//void australia_voting_print (ostream& w, string &v) {

	for (unsigned int i=0; i<v.size(); i++) {
    	w << v[i] << ' '; }
    w << endl; }

//	w << v << endl; }  
 */  
// -------------
// australia_voting_solve
// -------------

void australia_voting_solve (istream& r, ostream& w) {
    int				numCase, cNo, n;
    string			blank, s;
	deque<int>		ballot; 	
	istringstream 	sin;

/*
	r >> numCase;
	r >> blank;
	r >> blank1;
*/

	getline(r, s);
	sin.str(s);
	sin >> numCase;
	
	getline(r, s);
	sin.clear();
	sin.str(s);
	sin >> blank;
	
/*
	cout << "numCase = " << numCase << endl;
	cout << "blank = '" << blank << "'" << endl;
*/
	
	for (int i=0; i<numCase; i++) {
	
//cout << "case = " << i << endl;

		getline(r, s);
		sin.clear();
		sin.str(s);		
		sin >> cNo;							// get number of candidates
//cout << cNo << endl;
		AVcase avCase(cNo);
		for (int j=0; j<cNo; j++) {			// get candidates' name
			getline(r, s);
//cout << s << endl;
			avCase.cNames.push_back(s); } 
		while (getline(r, s)) {				// get ballot data
			if ((s.empty() || s[0] == ' ')) {				// done w/ fetching ballot data for current case
				break; }
			deque<int> ballot;
			sin.clear();
			sin.str(s);
//cout << sin.str() << endl;
			while (!sin.eof()) {
				sin >> n; 
				ballot.push_back(n); }
			avCase.ballots.push_back(ballot); }
			
//avCase.print();

		australia_voting_eval(avCase, w);
		if (i < numCase - 1) {
			w << endl; }}}

