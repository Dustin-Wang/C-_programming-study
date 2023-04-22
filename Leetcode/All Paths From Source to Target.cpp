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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
    	int N=graph.size();
    	vector<vector<int>> res;
    	vector<vector<int>> res1=DFS(graph,0,N-1);
    	for(vector<int> it:res1){
    		reverse(it.begin(),it.end());
    		res.push_back(it);
    	}
    	return res;
    }
private:
	vector<vector<int>> DFS(vector<vector<int>>& graph, int i,int des){
		vector<vector<int>> res;
		if(i==des){
			res.push_back(vector<int>{des});
			return res;
		}
		vector<vector<int>> temp;
		for(auto const&in:graph[i]){
			temp=DFS(graph,in,des);
			if(!temp.empty()){
				for(vector<int> it:temp){
					it.push_back(i);
					res.push_back(it);
				}
			}
		}
		return res;
	}
};


int main(){
	vector<vector<int>> graph;
	graph.push_back(vector<int>{1,2});
	graph.push_back(vector<int>{3});
	graph.push_back(vector<int>{3});
	graph.push_back(vector<int>());
	Solution* m= new Solution();
	vector<vector<int>> res=m->allPathsSourceTarget(graph);
	for(auto const&c: res){
		for(auto const&c1:c){
			cout<<c1<<" ";
		}
		cout<<endl;
	}
}