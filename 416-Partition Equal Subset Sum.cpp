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
Given a non-empty array nums containing only positive integers, 
find if the array can be partitioned into two subsets such that 
the sum of elements in both subsets is equal.


Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

Example 3:
[2,2,3,5] 
false
 

Constraints:

    1 <= nums.length <= 200
    1 <= nums[i] <= 100

*/

class Solution {
public:
     bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int TotalSum = accumulate(begin(nums),end(nums),0);
        if(TotalSum%2)
        	return(false);
        vector<int> AvailableSum1(TotalSum+1,0);
        AvailableSum1[0] = 1;
		// printf("n:%d\n",n);
     	// fflush(stdout);
        //consider all possible sums using first k numbers in nums
        int FirstKSum=0;
        for(int k=0; k<n; k++)
        {
        	vector<int> AvailableSum2(TotalSum+1,0);
        	for(int i=0;i<FirstKSum+1; i++)
        	{
        		if( AvailableSum1[i] )
        		{
        			AvailableSum2[i]=1;
        			AvailableSum2[i+nums[k]] = 1;
        		}
        	}
        	FirstKSum = FirstKSum + nums[k];
        	AvailableSum1 = AvailableSum2;
        	printarray(AvailableSum1, TotalSum+1);
        }	

        return(AvailableSum1[TotalSum/2]);

    }
private:
	void printarray(vector<int> array, int arraysize)
	{
		for(int k=0; k<arraysize; k++)
			printf("%d  ",array[k]);
		printf("size: %d\n",arraysize);
	}
};


int main(){
	// vector<int> nums = {1,5,11,5};
	vector<int> nums = {2,2,3,5};
	Solution Question;
	cout<<Question.canPartition(nums)<<endl;
}
