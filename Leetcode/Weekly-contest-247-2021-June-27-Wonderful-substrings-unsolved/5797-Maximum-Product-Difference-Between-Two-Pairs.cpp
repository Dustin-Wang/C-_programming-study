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


class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int NumsLen=nums.size();
        return (nums[NumsLen-1]*nums[NumsLen-2]-nums[0]*nums[1]);
    }
};

int main(){
	Solution mysol;
	vector<int> Num{5,6,2,7,4};
    cout<<mysol.maxProductDifference(Num)<<endl;
	//cout<<mysol.makeEqual(words)<<endl;
}