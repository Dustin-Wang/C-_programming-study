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
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    	map<int, vector<int>> nei;
    	for(auto const&c: edges){
    		nei[c[0]].push_back(c[1]);
    		nei[c[1]].push_back(c[0]);
    	}
    	vector<int> seen(n,0);
    	vector<int> res(n,0);
    	vector<int> col(26,0);
    	DFS(0,res,nei,labels,seen);

    	return res;
    }
private:
	vector<int> DFS(int i, vector<int>& res, map<int,vector<int>>& nei,string& labels,vector<int>& seen){
		seen[i]=1;
		vector<int> col(26,0);
		col[labels[i]-'a']++;
		if (nei[i].size()!=0){
			for(auto const&c: nei[i]){
				if(seen[c]==0){
					vector<int> bra=DFS(c, res, nei,labels, seen);
					for(int j=0;j<26;j++){
						col[j]=col[j]+bra[j];
					}
				}
			}
		}
		seen[i]=2;
		res[i]=col[labels[i]-'a'];
		return col;
	}
};


int main(){
	return 0;
}