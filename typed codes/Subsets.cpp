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
    vector<vector<int>> subsets(vector<int>& nums) {
    	int n=nums.size();
    	unsigned long long k=0;
    	vector<vector<int>> res;
    	while(k<pow(2,n)){
    		int cut=k;
    		std::vector<int> tmp;
    		for(int j=0;j<n && cut>0;j++){
    			if(cut%2==1)
    				tmp.push_back(nums[j]);
    			cut=cut>>1;
    		}
    		res.push_back(tmp);
    		k++;
    	}
    	return res;
    }
};


int main(){
	Solution* m= new Solution();
	std::vector<int> v{1,2,3};
	std::vector<vector<int>> res=m->subsets(v);
	for(auto const&c:res){
		for(auto const&d: c){
			cout<<d<<" ";
		}
		cout<<endl;
	}
}