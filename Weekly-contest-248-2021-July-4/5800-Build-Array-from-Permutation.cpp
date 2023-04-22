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
    vector<int> buildArray(vector<int>& nums) {
        int numsLen=nums.size();
        vector<int> res(numsLen,0);
        for(int i=0;i<numsLen;i++){
            res[i]=nums[nums[i]];
        }
        return res;
    }
};
int main(){
	Solution mysol;
	// vector<vector<int>> grid;
	// grid.push_back(vector<int>{40,10});
	// grid.push_back(vector<int>{30,20});
	// vector<vector<int>> grid;
	// grid.push_back(vector<int>{1,2,3,4});
	// grid.push_back(vector<int>{16,1,2,5});
	// grid.push_back(vector<int>{15,8,3,6});
	// grid.push_back(vector<int>{14,7,4,7});
	// grid.push_back(vector<int>{13,6,5,8});
	// grid.push_back(vector<int>{12,11,10,9});
 //    vector<vector<int>> res=mysol.rotateGrid(grid,1);
 //    for(const auto &c:res){
 //    	for(const auto &d:c){
 //    		cout<<d<<" ";
 //    	}
 //    	cout<<endl;
 //    }
	//cout<<mysol.makeEqual(words)<<endl;
}