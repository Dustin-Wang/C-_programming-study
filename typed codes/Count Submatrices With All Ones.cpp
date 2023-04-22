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
    int numSubmat(vector<vector<int>>& mat) {
        vector<vector<int>> colones;
        vector<vector<int>> rowones;
        int res=0;
        int h=mat.size();
        int w=mat[0].size();
        for(int i=0;i<h;i++){
        	colones.push_back(vi(w,0));
        	rowones.push_back(vi(w,0));
        }
        //cout<<"h"<<endl;
        for(int i=0;i<h;i++){
        	for(int j=0;j<w;j++){
        		if (i>=1 && mat[i][j]==1){
        			colones[i][j]=colones[i-1][j]+1;
        		}
        		else if (i==0 && mat[i][j]==1){
        			colones[i][j]=1;
        		}
        	}
        }
        /*for(auto const&a:colones){
        	for(auto const&b:a){
        		cout<<b<<" ";
        	}
        	cout<<endl;
        }*/
        int k=0;
        int mini=h*w;
        for(int i=0;i<h;i++){
        	for(int j=0;j<w;j++){
        		if (mat[i][j]==1){
        			k=j;
        			mini=h*w;
        			while(k>=0 && mini>0){
        				mini=min(mini,colones[i][k]);
        				res+=mini;
        				k--;
        			}
        		}
        	}
        }




        return res;
    }
};

int main(){
	Solution m;
	vector<vector<int>> mat;
	// mat.push_back(vi{0,1,1,0});
	// mat.push_back(vi{0,1,1,1});
	// mat.push_back(vi{1,1,1,0});
    mat.push_back(vi{1,0,1});
	mat.push_back(vi{0,1,0});
	mat.push_back(vi{1,0,1});
	cout<<m.numSubmat(mat)<<endl;
}