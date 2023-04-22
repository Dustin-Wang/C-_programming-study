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

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
    	

    	int NoOfPpl = hats.size();
    	vector<unsigned long long> PreferranceByEachPpl(NoOfPpl,0);
    	//convert each ppl's preference to a binary number of length at most 40.
    	for(int k=0; k<NoOfPpl; k++)
    		for(auto j : hats[k])
    		{
 	   			PreferranceByEachPpl[k] = PreferranceByEachPpl[k] |( 1ULL<<(j-1));
 	   			// printf("Ppl: %d\n, PreferranceByEachPpl[%d]: %llu\n", k, k, PreferranceByEachPpl[k]);
    		}

    	//Notice that NoOfPpl<=10, so we could consider all subsets of these NoOfPpl, which is at most 1024
    	//let us construct an vector int to represent this
    	//there are only 40 hats, 40bits can be represented by unsigned long long
    	int NoOfSubsets = (1<<NoOfPpl);
    	vector<unsigned long long> Preferrance(NoOfSubsets, 0);
    	for(int i=0; i<NoOfSubsets; i++)
    	{
    		unsigned long long HatsLovedByThisSubset = (1ULL<<40)-1;
    		for(int k=0; k<NoOfPpl; k++)
    		{
    			//get the ppl in this susbset of Preferrance(k)
    			// vector<int> PplInThisSubset;
    			
    			if(i & (1<<k) )
    				HatsLovedByThisSubset = HatsLovedByThisSubset & PreferranceByEachPpl[k];
    			else
    				HatsLovedByThisSubset = HatsLovedByThisSubset & (~PreferranceByEachPpl[k]);
    		}
    		Preferrance[i] = HatsLovedByThisSubset;
    		// printf("Subset: %d\n",i);
    		// printf("Preferrance[%d]: %llu\n", i, Preferrance[i]);
    	}
    	//Notice that here Preferrance[0] is all 1 vector, because it corresponds to empty set.

    	vector<int> OccupiedSubsets(NoOfSubsets,0);

    	int count = BackTrack(Preferrance, OccupiedSubsets, 0, NoOfPpl, NoOfSubsets);
    
    	return(count);
    }
private:
	int bigPrime = 1000000007;
	int BackTrack(vector<unsigned long long>& Preferrance, vector<int>& OccupiedSubsets, int k, int NoOfPpl, int NoOfSubsets ){
		if(k == NoOfPpl)
			return(1);
		else
		{
			int res = 0;
			for(int i = 0; i< NoOfSubsets; i++)
			{
				// printf("k:%d; i: %d\n",k,i);
				int temp = __builtin_popcountll(Preferrance[i])- OccupiedSubsets[i];
				if( ( temp >0 ) && (i & (1<<k)) )
				{
					OccupiedSubsets[i]++;
					res = (res + temp * BackTrack(Preferrance, OccupiedSubsets, k+1, NoOfPpl, NoOfSubsets))%bigPrime;
					// printf("insdie: k: %d; i:%d; res: %d\n",k, i, res);
					OccupiedSubsets[i]--;		
				}
			}
			return(res);
		}
	}
};

int main(){
	// unsigned long long x = 11;
	// cout<<__builtin_popcount(x)<<endl;

	vector<vector<int>> graph;
	// graph.push_back(vector<int>{3,4});
	// graph.push_back(vector<int>{4,5});
	// graph.push_back(vector<int>{5});
	
	// graph.push_back(vector<int>{3,5,1});
	// graph.push_back(vector<int>{3,5});
	
	graph.push_back(vector<int>{1,2,3,4});
	graph.push_back(vector<int>{1,2,3,4});
	graph.push_back(vector<int>{1,2,3,4});
	graph.push_back(vector<int>{1,2,3,4});
	
	// graph.push_back(vector<int>{1,2,3,4,5,6,7,8,9,10,11});
	// graph.push_back(vector<int>{1,2,3,4,5,6,7,8,9,10,11});
	// graph.push_back(vector<int>{1,2,3,4,5,6,7,8,9,10,11});
	// graph.push_back(vector<int>{1,2,3,4,5,6,7,8,9,10,11});
	// graph.push_back(vector<int>{1,2,3,4,5,6,7,8,9,10,11});
	// graph.push_back(vector<int>{1,2,3,4,5,6,7,8,9,10,11});
	// graph.push_back(vector<int>{1,2,3,4,5,6,7,8,9,10,11});
	// graph.push_back(vector<int>{1,2,3,4,5,6,7,8,9,10,11});
	// graph.push_back(vector<int>{1,2,3,4,5,6,7,8,9,10,11});
	// graph.push_back(vector<int>{1,2,3,4,5,6,7,8,9,10,11});
	// graph.push_back(vector<int>{1,2,3,4,5,6,7,8,9,10,11});
	

	Solution* m= new Solution();
	int res=m->numberWays(graph);
	cout<<res<<endl;
	
}