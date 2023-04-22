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

bool mycompare(pair<int,int> i, pair<int,int> j){
	return (i.second>j.second);
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> counter;
        for(auto const&c: nums){
        	if (counter.find(c)==counter.end())
        		counter[c]=1;
        	else
        		counter[c]++;
        }
        vector<pair<int,int>> count;
        for(auto const&c: counter){
        	count.push_back(pair<int,int>(c.first,c.second));
        }
        sort(count.begin(),count.end(),mycompare);
        std::vector<int> res;
        while(k>0){
        	res.push_back(count[k-1].first);
        	k--;
        }
        return res;
    }
};


int main(){
	Solution* m=new Solution();
	std::vector<int> nums={1};
	int k=1;
	std::vector<int> v=m->topKFrequent(nums,k);
	for(auto const&c: v)
		cout<<c<<" ";
}