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
    	vector<vector<vector<int>>> caw;
    	int w=mat.size();
    	int h=mat.size();
    	for(int i=0;i<w;i++){
    		vector<vector<int>> tmp(w,vector<int>{0,0})
    		tmp[0]=
    		caw.push_back(tmp);
    		for(int j=0;j<w;j++){
    			if (mat[i][j]==1){
    				if (i-1>=0 && j-1>=0){
    				    caw[i][j][0]=caw[i-1][j]+1;
    				    caw[i][j][1]=caw[i][j-1]+1;
    			    }
    			    else if(i==0 && j-1>=0){
    			    	caw[i][j][0]=1;
    				    caw[i][j][1]=caw[i][j-1]+1;
    			    }
    			    else if(i-1>=0 && j-1)
    			}
    		}
    	}
        
    }
};


int main(){
	Solution mysol;
	vi arr={3,5,1};
	cout<<mysol.canMakeArithmeticProgression(arr)<<endl;
}