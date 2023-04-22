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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    	map<int,vector<int>> nei;
    	for(auto const&c: prerequisites)
    		nei[c[0]].push_back(c[1]);
    	vector<int> res;
    	vector<int> visited(numCourses,0);
    	for(int i=0;i<numCourses;i++){
    		if(visited[i]==0){
    			if (DFS(i,res,visited,nei)==false){
    				return vector<int>();
    			}
    		}
    	}
    	return res;
    }

private:
	bool DFS(int i, vector<int>& res, vector<int>& visited, map<int,vector<int>>& nei){
		visited[i]=1;
		bool noloop=true;
		for(int j=0;j<nei[i].size()&& noloop;j++){
			int n=nei[i][j];
			if (visited[n]==0){
				noloop=noloop && DFS(n, res, visited,nei);
			}
			else if(visited[n]==1){
				return false;
			}
		}
		res.push_back(i);
		visited[i]=2;
		return noloop;
	}
};


int main(){
	Solution* m=new Solution();
	// int numCourses=2;
	// vector<vector<int>> prerequisites;
	// prerequisites.push_back(vector<int>{1,0});
	int numCourses=4;
	vector<vector<int>> prerequisites;
	prerequisites.push_back(vector<int>{1,0});
	prerequisites.push_back(vector<int>{2,0});
	prerequisites.push_back(vector<int>{3,1});
	prerequisites.push_back(vector<int>{3,2});
	vector<int> res=m->findOrder(numCourses,prerequisites);
	for(auto const&c: res)
		cout<<c<<" ";
}