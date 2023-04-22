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
    vector<int> getConcatenation(vector<int>& nums) {
    	int n=nums.size();
    	vector<int> res(2*n,0);
    	for(int i=0;i<2*n;i++){
    		res[i]=nums[i%n];
    	}
        return res;
    }
};
int main(){
	Solution mysol;
	vector<int> res{1,2,1};
	vector<>
	
}