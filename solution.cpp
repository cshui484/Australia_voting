// --------------------------
// projects/australia_voting/Australia_voting.h
// Copyright (C) 2015
// CS Hui
// --------------------------

#ifndef Australia_voting_h
#define Australia_voting_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;

// ------------
// class AVcase
// ------------

class AVcase {
	public:
		int						cNo;
		vector <string>			cNames;
		vector < deque <int> > 	ballots; 

		AVcase (int n) {
			cNo = n; }

		void print () {
			cout << "Number of candidates = " << cNo << endl;
			cout << "candidates are: [ ";
			for (string s : cNames) {
				cout << "'" << s << "' "; }
			cout << "]" << endl;
			cout << "Ballots are:" << endl;
			for (int i=0; i<(int)ballots.size(); i++) {
				deque<int> q = ballots[i];
				cout << "[ ";
				while (q.size() > 0) {
					cout << "'" << q.front() << "' ";
					q.pop_front(); }
				cout << "]" << endl; }}
					

/*			
		void append (int cId, int w) {
			vector<int> v = { cId, w };
			children.push_back(v); }

			
		void print () {
			cout << "id = " << id << " weight = " << weight << " pId = " << pId \
			     << " visited = " << visited << " done = " << done << " children = ";
			if (children.size() == 0) {
				cout << "None"; }
			else {
				cout << "[ ";
				for (unsigned int i=0; i<children.size(); i++) {
					cout << "(";
					unsigned int j;
					for (j=0; j<children[i].size()-1; j++) {
						cout << children[i][j] << ", "; }
					cout << children[i][j] << ") "; }}
			cout << "]" << endl; }


		void printNodes(vector<Node> &nodes) {
			for (int i=0; i<(int)nodes.size(); i++) {
				nodes[i].print(); }}

			
		void clrSP (vector<Node> &nodes) {
			int numNode = (int) nodes.size();
			for (int i=1; i<numNode; i++) {
				nodes[i].weight  = 0;
				nodes[i].visited = false;
				nodes[i].done	 = false; }}

				
		void setSP (vector<Node> &nodes) {
			int 	numNeighbor = (int) children.size();
			int 	nId, wt, tpw, tnw;			
			if (done) { return; }					// skip because this node has been processed
			for (int i=0; i<numNeighbor; i++) {
				nId = children[i][0];
				wt  = children[i][1];
				if (nId != pId) {					// skip if this route has been processed
					tpw = weight + wt;
					if (! nodes[nId].visited) {		// update n if needed	
						nodes[nId].weight  = tpw;
						nodes[nId].pId	   = id;
						nodes[nId].visited = true; }
					else if (nodes[nId].weight > tpw) {
						nodes[nId].weight  = tpw;
						nodes[nId].pId	   = id;
						nodes[nId].done    = false; }
					tnw = nodes[nId].weight + wt;
					if (weight > tnw) {				// update self is needed
						weight = tnw;
						pId    = nId;
						setSP(nodes); }}}			// re-do setSP again
			done = true;
			
			// time to call setSP() recusively for all the neighbors
			
			for (int i=0; i<numNeighbor; i++) {	
				nId = children[i][0];
				nodes[nId].setSP(nodes); }}
				
				
		vector<int> getReversedSP (int dId, vector<Node> &nodes) {
			vector<int> path;
			clrSP(nodes);
			visited 		= true;			// src  node is always visited
			nodes[dId].done = true;			// dest node is always done
			setSP(nodes);
			
			// SP info is available, time to retrive it
			
			path.push_back(nodes[dId].id);
			while (nodes[dId].id != id) {
				path.push_back(nodes[dId].pId);
				nodes[dId] = nodes[nodes[dId].pId]; }				
			return path; }	
				
				
		vector<int> getSP(int dId, vector<Node> &nodes) {
			vector<int> path;
			path = getReversedSP(dId, nodes);
			reverse(path.begin(), path.end());
			return path; }
*/
						
};

/*
void printNodes(vector<Node> &nodes);
*/
void printVec(vector<int> &v);
		
// ------------
// australia_voting_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, representing the numbers of node and branches [n, b]
 */
pair<int, int> australia_voting_read (const string& s);

// ------------
// australia_voting_read1
// ------------

/**
 * read three ints
 * @param s a string
 * @return a tuple of 3 ints, representing the 2 nodes and weight [n1, n2, w]
 */
tuple<int, int, int> australia_voting_read1 (const string& s);

// ------------
// australia_voting_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the min number of button pressed for numbers [i, j]
 */
void australia_voting_eval (AVcase& avcase);


// -------------
// australia_voting_print
// -------------

/**
 * print single int
 * @param w an ostream
 * @param v the min number of button pressed
 */
void australia_voting_print (ostream& w, vector<int> &v);

// -------------
// australia_voting_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void australia_voting_solve (istream& r, ostream& w);

#endif // Australia_voting_h
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

// ------------------------------/
// projects/australia_voiing/RunAustralia_voting.c++
// Copyright (C) 2015
// CS Hui
// -------------------------------

// --------
// includes
// --------

#include <iostream> // cin, cout



// ----
// main
// ----

int main () {
    using namespace std;
    australia_voting_solve(cin, cout);
    return 0;}

/*
% g++ -pedantic -std=c++11 -Wall Australia_voting.c++ RunAustralia_voting.c++ -o RunAustralia_voting



% cat RunAustralia_voting.in
1 10
100 200
201 210
900 1000



% RunAustralia_voting < RunAustralia_voting.in > RunAustralia_voting.out



% cat RunAustralia_voting.out
1 10 1
100 200 1
201 210 1
900 1000 1



% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES



% doxygen Doxyfile
// That creates the directory html/.
*/
