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
    int uniquePaths(int m, int n) {
    if(m==1||n==1){
    	return 1;
    }
    vi dp(n,1);
    for(int i=0;i<m-1;i++){
    	vi newdp(n,1);
    	for(int j=n-2;j>=0;j--){
    		newdp[j]=newdp[j+1]+dp[j];
    	}
    	dp=newdp;
    	/*cout<<sz(dp)<<"diue ";
    	for(auto const&c: dp)
    		cout<<c<<" ";
    	cout<<endl;*/
    }
    return dp[0];  
    }
};

int main(){
	Solution mysol;
	int m=7;
	int n=3;
	cout<<mysol.uniquePaths(m,n);
}