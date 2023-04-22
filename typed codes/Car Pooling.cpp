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
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> people(1000,0);
        for(const auto&c:trips){
        	people[c[1]]=people[c[1]]+c[0];
        	people[c[2]]=people[c[2]]-c[0];
        }
        int carry=0;
        for(const auto&d:people){
        	carry+=d;
        	if(carry>capacity){
        		return false;
        	}
        }
        return true;
    }
};

int main(){
	Solution mysol;
	vector<vector<int>> trips;
	trips.push_back(vector<int>{2,1,5});
	trips.push_back(vector<int>{3,3,7});
	cout<<mysol.carPooling(trips,3)<<endl;
}