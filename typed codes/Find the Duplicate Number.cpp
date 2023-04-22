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

using namespace std;
// BEGIN NO SAD
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
// END NO SAD
// REMEMBER CLEAR GLOBAL STATE
class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
    	set<int> s(all(nums));
    	int a =nums.size()-s.size();
    	int b=accumulate(all(nums),0)-accumulate(all(s),0);
    	return b/a;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       if (nums.size() > 1)
	{
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		printf("%d %d\n",slow, fast );

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1; 
    }
};

int main(){
	std::vector<int> v = { 2,5,9,6,9,3,8,9,7,1};
	Solution mysol;
	cout<<mysol.findDuplicate(v);
}