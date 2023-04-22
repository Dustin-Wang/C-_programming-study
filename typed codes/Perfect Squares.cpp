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
    int numSquares(int n) {
    	vector<int> v(n+1,n);
    	int i=1;
    	v[0]=0;
    	for (i=1;i*i<=n;i++)
    		v[i*i]=1;
    	
    	int j=1;
    	for (i=1;i<=n;i++){
    		for (j=1;j*j<=i;j++){
    			if (1+v[i-j*j]<=v[i])
    				v[i]=1+v[i-j*j];
    		}
    	    /*for(j=1;j<=n;j++)
    	        cout<<v[j-1]<<' ';
    	    cout<<endl;*/
    	}
    	return v[n];
    }
};

int main(){
	Solution mysol;
	int n=8405;
	cout<<mysol.numSquares(n);
}