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
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end){
        int ns=succProb.size();
        vector<vector<pid>> nei(n,vector<pid>());
        for(int i=0;i<ns;i++){
            nei[edges[i][0]].push_back(make_pair(edges[i][1],succProb[i]));
            nei[edges[i][1]].push_back(make_pair(edges[i][0],succProb[i]));
        }
        //vector<double> prob(n,0);
        //prob[start]=1;
        map<int, double> unvisited;
        for(int i=0;i<n;i++){
            unvisited[i]=0;
        }
        int cur=start;
        //int f=1;
        double probcur=1;
        while(probcur>0){
            for(auto const&n:nei[cur]){
                if (unvisited.find(n.first)!=unvisited.end())
                    unvisited[n.first]=max(unvisited[n.first],probcur*n.second);
            }
            unvisited.erase(cur);
            probcur=0;
            for(auto const&v: unvisited){
                if (probcur<v.second){
                    probcur=v.second;
                    cur=v.first;
                }
            }
            if (cur==end){
                return unvisited[cur];
            }
        }
        return 0;
    }
};


class Solution2 {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end){
        int ns=succProb.size();
        vector<vector<pid>> nei(n,vector<pid>());
        for(int i=0;i<ns;i++){
        	nei[edges[i][0]].push_back(make_pair(edges[i][1],succProb[i]));
        	nei[edges[i][1]].push_back(make_pair(edges[i][0],succProb[i]));
        }
        vector<int> q{start};
        vector<double> prob(n,0);
        prob[start]=1;
        int next=n+1;
        double nextprb=0;
        int par=0;
        int index=0;
        int f=1;
        while(f && prob[end]==0){
        	next=n+1;
        	nextprb=0;
        	par=0;
        	index=0;
        	for(auto const&l:q){
        		for(int i=0;i<nei[l].size();i++){
        			//cout<<c.first<<" "<<c.second<<endl;
        			auto c=nei[l][i];
        			if (prob[c.first]==0 && c.second*prob[l]>nextprb){
        				nextprb=c.second*prob[l];
        				next=c.first;
        				par=l;
        				index=i;
        			}
        		}
        	}

        	// for(auto const&l:q){
        	// 	cout<<l<<" "<<prob[l]<<";";
        	// }

        	// cout<<endl;
        	// cout<<next<<endl;

        	if (next!=n+1){
        		prob[next]=nextprb;
        		q.push_back(next);
        		nei[par].erase(nei[par].begin()+index);
        	}
        	else{
        		f=0;
        	}
        }
        return prob[end];
    }
};

int main(){
	Solution* m=new Solution();
	// int n=3;
	// vector<vector<int>> edges;
	// edges.push_back(vi{0,1});
	// edges.push_back(vi{1,2});
	// edges.push_back(vi{0,2});
	// vector<double> succProb{0.5,0.5,0.2};
	// int start=0;
	// int end=2;
	int n=5;
	vector<vector<int>> edges;
	edges.push_back(vi{1,4});
	edges.push_back(vi{2,4});
	edges.push_back(vi{0,4});
	edges.push_back(vi{0,3});
	edges.push_back(vi{0,2});
	edges.push_back(vi{2,3});
	vector<double> succProb{0.37,0.17,0.93,0.23,0.39,0.04};
	int start=3;
	int end=4;
	cout<<m->maxProbability(n,edges,succProb,start,end)<<endl;
}