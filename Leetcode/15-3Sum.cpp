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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size(); ++i){
            int tar = -nums[i];
            int start = i+1;
            int end = nums.size()-1;
            while(start<end){
                int sum = nums[start]+nums[end];
                
                if(sum>tar) end--;
                else if(sum<tar) start++;
                else {
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    res.push_back(temp);
                    
                    while(start<end && nums[start]==temp[1]) start++;
                    while(start<end && nums[end]==temp[2]) end--;
                }
            }
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};

int main(){
	Solution* m=new Solution();
	vector<int> nums{-1, 0, 1, 2, -1, -4};
	vector<vector<int>> res=m->threeSum(nums);
	for(auto const&c: res){
		for(auto const&d:c){
			cout<<d<<" ";
		}
		cout<<endl;
	}
}