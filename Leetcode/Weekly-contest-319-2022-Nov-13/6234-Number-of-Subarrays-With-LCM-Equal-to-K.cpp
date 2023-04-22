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
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;
// BEGIN NO SAD
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
// END NO SAD
// REMEMBER CLEAR GLOBAL STATE

// struct myclass{
// 	bool operator()(string a, string b){
// 		if(a.size()<b.size())
// 			return false;
// 		else if(a.size()>b.size())
// 			return true;
// 		else
// 			return(a>b);
// 	}
// } myobject;

/*
Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the subarray's elements is k.

A subarray is a contiguous non-empty sequence of elements within an array.

The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.

 

Example 1:

Input: nums = [3,6,2,7,1], k = 6
Output: 4
Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
- [3,6]
- [3,6,2]
- [6]
- [6,2]

Example 2:

Input: nums = [3], k = 2
Output: 0
Explanation: There are no subarrays of nums where 2 is the least common multiple of all the subarray's elements.

 

Constraints:

    1 <= nums.length <= 1000
    1 <= nums[i], k <= 1000


*/
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
    	int length = nums.size();
    	// printf("length: %d\n", length);
        vector<int> FirstKLcms1(length, 1);
        int count = 0;
        for(int i = 0; i < length; i ++)
        {
        	// printf("i: %d\n", i );
        	// fflush(stdout);
        	vector<int> FirstKLcms2(length, 1);
        	for(int j = 0; j<= i; j++)
        	{
        		// printf("j: %d\n", j );
        		
        		// printf("hello FirstKLcms1[%d]: gcd %d\n",j, gcd(FirstKLcms1[j],1));
        		// fflush(stdout);
        		FirstKLcms2[j] = min( lcm(FirstKLcms1[j], nums[i]), 1001);
        		// printf("Fuck, FirstKLcms2[%d]: %d FirstKLcms2[%d]: %d\n",j, FirstKLcms1[j], j, FirstKLcms2[j]);
        		// fflush(stdout);
        		if(FirstKLcms2[j] == k)
        			count++;
        	}
        	FirstKLcms1 = FirstKLcms2;
        	// printarray(FirstKLcms1, length);
        	// cout<<count<<endl;
        	// fflush(stdout);
        }
        return(count);
    }
private:
	int gcd(int a, int b){
		if( b == 0)
			return(a);
		else
			return( gcd(b,a%b) );
	}
	int lcm(int a, int b){
		return(abs(a*b)/gcd(a,b));
	}
	void printarray(vector<int> array, int arraysize)
	{
		for(int k=0; k<arraysize; k++)
			printf("%d  ",array[k]);
		printf("size: %d\n",arraysize);
	}
};
template <size_t rows, size_t cols>
vector<vector<int>> ArrayTo2dVector(int (&array)[rows][cols])
{
    vector<vector<int>> res;
    for (size_t i = 0; i < rows; ++i)
    {
        vector<int> row;
        for (size_t j = 0; j < cols; ++j)
            row.push_back(array[i][j]);
        res.push_back(row);
    }
    return res;
};
int main(){
	Solution mysol;
 	
	
	// int array[][4] ={{1,3,1,15},{1,3,3,1}};
    //vector<vector<int>> mat = ArrayTo2dVector(array);
	
    vector<int> nums = {3,6,2,7,1};
    int k = 6;
    // vector<int> nums = {3};
    // int k = 2;
	cout<<mysol.subarrayLCM(nums, k)<<endl;
    
}