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
#include <iterator>
template<typename T>
void printvector(vector<T> vector)
{
 //    int arraysize = array.size();
	// for(int k=0; k<arraysize; k++)
	// 	printf("%d  ",array[k]);
	// printf("size: %d\n",arraysize);
	copy(vector.begin(), vector.end(), std::ostream_iterator<T>(std::cout, " "));
	printf("\n");
	fflush(stdout);
};

bool compareVector(vector<int> i1, vector<int> i2)
{
	return(i1.size()<i2.size());
};
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
    	clock_t begin1 = clock();
    	// sort(hats.begin(),hats.end(), compareVector);
    	
    	// printvector(hats[0]);

    	int NoOfPpl = hats.size();
    	vector<unsigned long long> PreferranceByEachPpl(NoOfPpl,0);
    	//convert each ppl's preference to a binary number of length at most 40.
    	for(int k=0; k<NoOfPpl; k++)
    		for(auto j : hats[k])
    		{
 	   			PreferranceByEachPpl[k] = PreferranceByEachPpl[k] |( 1ULL<<(j-1));
 	   			// printf("Ppl: %d\n, PreferranceByEachPpl[%d]: %llu\n", k, k, PreferranceByEachPpl[k]);
    		}
    	// printvector(PreferranceByEachPpl);
    	//Notice that NoOfPpl<=10, so we could consider all subsets of these NoOfPpl, which is at most 1024
    	//let us construct an vector int to represent this
    	//there are only 40 hats, 40bits can be represented by unsigned long long
    	int NoOfSubsets = (1<<NoOfPpl);
    	vector<unsigned long long> Preferrance(NoOfSubsets, (1ULL<<40)-1);
    	for(int i=1; i<=NoOfPpl; i++)
    	{
    		vector<unsigned long long> NextPreferrance(NoOfSubsets, (1ULL<<40)-1);

    		// printvector(Preferrance);
    		int Power = (1<<(i-1));
    		// printf("Power: %d\n", Power);
    		// fflush(stdout);
    		for(int k=0; k<Power; k++)
    		{
    			//get the ppl in this susbset of Preferrance(k)
    			// vector<int> PplInThisSubset;
    			NextPreferrance[k] = Preferrance[k] & (~PreferranceByEachPpl[i-1]);
    			// if(i & (1<<k) )
    			// 	HatsLovedByThisSubset = HatsLovedByThisSubset & PreferranceByEachPpl[k];
    			// else
    			// 	HatsLovedByThisSubset = HatsLovedByThisSubset & (~PreferranceByEachPpl[k]);
    		}
    		for(int k=Power; k<(1<<i); k++)
    		{
    			NextPreferrance[k] = Preferrance[k-Power] & (PreferranceByEachPpl[i-1]);
    		}
    		Preferrance = NextPreferrance;
    		// printf("Subset: %d\n",i);
    		// printvector(Preferrance);
    	}
    	//Notice that here Preferrance[0] is all 1 vector, because it corresponds to empty set.

    	// vector<int> NoOfHatsPerferedByEachSubset;
    	// map<int,int> NoOfHatsPerferedByEachSubset;
    	vector<vector<pair<int,int>>> PplXinWhichNonzeroSubset(NoOfPpl, vector<pair<int,int>>());
    	for(int i=0; i<NoOfSubsets; i++)
    	{
    		int temp = __builtin_popcountll(Preferrance[i]);
    		if(temp > 0)
    		{
    			for(int k=0; k<NoOfPpl; k++)
    				if(i&(1<<k))
    				{
    					PplXinWhichNonzeroSubset[k].push_back(pair<int,int>(i,temp));
    				}
    		}
    	}
    	// printf("size: %d\n", NoOfHatsPerferedByEachSubset.size());


    	

    	// printvector(NoOfHatsPerferedByEachSubset);
    	vector<int> OccupiedSubsets(NoOfSubsets,0);
    	clock_t end1 = clock();
		double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
		printf("time elapsed: %f\n", time_spent1);
		fflush(stdout);

		clock_t begin2 = clock();
    	// int count = BackTrack(NoOfHatsPerferedByEachSubset, OccupiedSubsets, 0, NoOfPpl, NoOfSubsets);
    	int count = BackTrack(PplXinWhichNonzeroSubset, OccupiedSubsets, 0, NoOfPpl, NoOfSubsets);

    	clock_t end2 = clock();
		double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
		printf("time elapsed: %f\n", time_spent2);
		fflush(stdout);
    	return(count);
    }
private:
	int bigPrime = 1000000007;
	int BackTrack(vector<vector<pair<int,int>>>& PplXinWhichNonzeroSubset, vector<int>& OccupiedSubsets, int k, int NoOfPpl, int NoOfSubsets ){
		if(k == NoOfPpl)
			return(1);
		else
		{
			int res = 0;
			// for(auto &pair:NoOfHatsPerferedByEachSubset)
			// {
			// 	// printf("k:%d; i: %d\n",k,i);
			// 	int i = pair.first;
			// 	int temp = pair.second - OccupiedSubsets[i];
			// 	if( (i & (1<<k)) && ( temp>0 ) )
			// 	{
			// 		OccupiedSubsets[i]++;
			// 		res = (res + (temp * BackTrack(NoOfHatsPerferedByEachSubset, OccupiedSubsets, k+1, NoOfPpl, NoOfSubsets))%bigPrime)%bigPrime;
			// 		// printf("insdie: k: %d; i:%d; res: %d\n",k, i, res);
			// 		OccupiedSubsets[i]--;		
			// 	}
			// }
			for(auto &pair:PplXinWhichNonzeroSubset[k])
			{
				int i = pair.first;
				int temp = pair.second - OccupiedSubsets[i];
				if(temp > 0)
				{
					OccupiedSubsets[i]++;
					res = (res + (temp * BackTrack(PplXinWhichNonzeroSubset, OccupiedSubsets, k+1, NoOfPpl, NoOfSubsets))%bigPrime)%bigPrime;
					OccupiedSubsets[i]--;	
				}				
			}
			return(res%bigPrime);
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
	
	// graph.push_back(vector<int>{1,2,3,4});
	// graph.push_back(vector<int>{1,2,3,4});
	// graph.push_back(vector<int>{1,2,3,4});
	// graph.push_back(vector<int>{1,2,3,4});
	
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
	
	graph.push_back(vector<int>{1,2,4,6,7,8,9,11,12,13,14,15,16,18,19,20,23,24,25});
	graph.push_back(vector<int>{2,5,16});
	graph.push_back(vector<int>{1,4,5,6,7,8,9,12,15,16,17,19,21,22,24,25});
	graph.push_back(vector<int>{1,3,6,8,11,12,13,16,17,19,20,22,24,25});
	graph.push_back(vector<int>{11,12,14,16,18,24});
	graph.push_back(vector<int>{2,3,4,5,7,8,13,14,15,17,18,21,24});
	graph.push_back(vector<int>{1,2,6,7,10,11,13,14,16,18,19,21,23});
	graph.push_back(vector<int>{1,3,6,7,8,9,10,11,12,14,15,16,18,20,21,22,23,24,25});
	graph.push_back(vector<int>{2,3,4,6,7,10,12,14,15,16,17,21,22,23,24,25});

	Solution* m= new Solution();
	int res=m->numberWays(graph);
	cout<<res<<endl;
	
}