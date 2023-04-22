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
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int,set<int>> rec;
        for(auto const& c:logs){
        	if(rec.find(c[0])==rec.end()){
        		rec[c[0]]=set<int>();
        	}
        	rec[c[0]].insert(c[1]);
        } 
        vector<int> res(k,0);
        for(auto const& d:rec){
        	int l=d.second.size();
        	//cout<<"User id"<<d.first<<"User UAM"<<l<<endl;
        	if(l<=k && l>=1){
        		res[l-1]++;
        	}
        }
        return res;
    }
};
int main(){
    Solution* m=new Solution();
    vector<vector<int>> logs;
    logs.push_back(vector<int>{0,5});
    logs.push_back(vector<int>{1,2});
    logs.push_back(vector<int>{0,2});
    logs.push_back(vector<int>{0,5});
    logs.push_back(vector<int>{1,3});
    vector<int> res=m->findingUsersActiveMinutes(logs,5);
    for(auto const& c:res){
    	cout<<c<<endl;
    }
}