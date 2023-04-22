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
    	vector<int> HatXLovedByWhichPpl(40,0);
    	for(int Ppl=0; Ppl<NoOfPpl; Ppl++)
    	{
    		for(auto i:hats[Ppl])
    			HatXLovedByWhichPpl[i-1] = HatXLovedByWhichPpl[i-1] | (1<<Ppl);
    	}
    	// printvector(HatXLovedByWhichPpl);
    	return(Memoimization(HatXLovedByWhichPpl, NoOfPpl, 0, 0));

    	
    }
private:
	int bigPrime = 1000000007;
	map<int,int> Memory;//the key will be MaskOnPplWhoGetHats*100 + the hat index we are considering
	int Memoimization(vector<int>& HatXLovedByWhichPpl, int NoOfPpl, int MaskOnPplWhoGetHats, int HatIndex){
		int key = MaskOnPplWhoGetHats*100 + HatIndex;
		// printf("HatIndex: %d: key: %d\n", HatIndex, key);
		if(Memory.find(key)!=Memory.end())
			return(Memory[key]);
		else if(MaskOnPplWhoGetHats == (1<<NoOfPpl)-1 )
		{
			// printf("Hello: MaskOnPplWhoGetHats: %d\n", MaskOnPplWhoGetHats);
			return(1);
		}
		else if(HatIndex==40 && MaskOnPplWhoGetHats != (1<<NoOfPpl)-1 )
			return(0);
		else
		{
			int Candidates = HatXLovedByWhichPpl[HatIndex] & (~MaskOnPplWhoGetHats);
			if(Candidates == 0)
			{
				// printf("no candidnates\n");
				return(Memoimization(HatXLovedByWhichPpl, NoOfPpl, MaskOnPplWhoGetHats, HatIndex+1));
			}
			int res = 0;
			for(int k=0; k<NoOfPpl; k++)
			{
				if(Candidates & (1<<k) )
				{
					//pick this ppl k as the user for this hatIndex;
					int NewMaskOnPplWhoGetHats = MaskOnPplWhoGetHats | (1<<k);
					// printf("So k:%d; MaskOnPplWhoGetHats: %d\n", k, NewMaskOnPplWhoGetHats);
					res = (res + Memoimization(HatXLovedByWhichPpl, NoOfPpl, NewMaskOnPplWhoGetHats, HatIndex+1))%bigPrime;
				}
			}
			//the other possibility is that we don't assign any ppl to use this hat
			res =(res + Memoimization(HatXLovedByWhichPpl, NoOfPpl, MaskOnPplWhoGetHats, HatIndex +1))%bigPrime;

			//put this into the memory;
			Memory[key] = res;
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