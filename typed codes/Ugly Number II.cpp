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
    int nthUglyNumber(int n) {
    	int i2=0;
    	int i3=0;
    	int i5=0;
    	vector<int> un={1};
    	int tmp=1;
    	while(un.size()<=n){
    		tmp=min(un[i2]*2,min(un[i3]*3,un[i5]*5));
    		if (tmp==un[i2]*2){
    			i2++;
    		}
    		if (tmp==un[i3]*3){
    			i3++;
    		}
    		if (tmp==un[i5]*5){
    			i5++;
    		}
    		un.push_back(tmp);
    	}
    	return un[n-1];
    }
};

int main(){
	Solution mysol;
	cout<<mysol.nthUglyNumber(10)<<endl;
}