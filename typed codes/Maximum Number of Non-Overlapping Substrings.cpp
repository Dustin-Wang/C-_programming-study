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
typedef pair<int,double> pid;
// END NO SAD
// REMEMBER CLEAR GLOBAL STATE


class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        map<int,vector<int>> leb;
        for(int i=0;i<s.size();i++){
        	if(leb.find(s[i]-'a')==leb.end()){
        		leb.[s[i]-'a'].push_back(i);
        	}
        }
        map<int,vector<int>> lee;
        for(int i=s.size()-1;i>=0;i--){
        	if(lee.find(s[i]-'a')==lee.end()){
        		lee.[s[i]-'a'].push_back(i);
        	}
        }
        
    }
};


int main(){
	Solution* m=new Solution();
	string s="adefaddaccc";
	vector<string> res=m->maxNumOfSubstrings(s);
	for(auto const&c: res){
		cout<<c<<endl;
	}
}