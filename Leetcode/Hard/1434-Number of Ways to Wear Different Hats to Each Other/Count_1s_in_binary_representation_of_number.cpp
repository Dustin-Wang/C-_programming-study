#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>
#include <cstdio>
#include <cmath>
#include <list>
#include <cctype>
#include <typeinfo>
using namespace std;
// BEGIN NO SAD
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
// END NO SAD
// REMEMBER CLEAR GLOBAL STATE

/*
There are n people and 40 types of hats labeled from 1 to 40.

Given a 2D integer array hats, where hats[i] is a list of all hats preferred by the ith person.

Return the number of ways that the n people wear different hats to each other.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: hats = [[3,4],[4,5],[5]]
Output: 1
Explanation: There is only one way to choose hats given the conditions. 
First person choose hat 3, Second person choose hat 4 and last one hat 5.

Example 2:

Input: hats = [[3,5,1],[3,5]]
Output: 4
Explanation: There are 4 ways to choose hats:
(3,5), (5,3), (1,3) and (1,5)

Example 3:

Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
Output: 24
Explanation: Each person can choose hats labeled from 1 to 4.
Number of Permutations of (1,2,3,4) = 24.

Constraints:

    n == hats.length
    1 <= n <= 10
    1 <= hats[i].length <= 40
    1 <= hats[i][j] <= 40
    hats[i] contains a list of unique integers.

*/


int main(){
	
	unsigned long x = 1UL<<30;
	cout<<__builtin_popcount(x)<<endl;
	unsigned long long y = 1ULL<<40;
	cout<<__builtin_popcountll(y)<<endl;

	// vector<vector<int>> graph;
	// graph.push_back(vector<int>{3,4});
	// graph.push_back(vector<int>{4,5});
	// graph.push_back(vector<int>{5});
	
	// graph.push_back(vector<int>{3,5,1});
	// graph.push_back(vector<int>{3,5});
	
	// graph.push_back(vector<int>{1,2,3,4});
	// graph.push_back(vector<int>{1,2,3,4});
	// graph.push_back(vector<int>{1,2,3,4});
	// graph.push_back(vector<int>{1,2,3,4});

	// Solution* m= new Solution();
	// int res=m->numberWays(graph);
	// cout<<res<<endl;
	
}