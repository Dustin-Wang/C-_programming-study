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
    int arrangeCoins(int n) {
    	int k=0;
    	while(n>=0){
    		++k;
    		n-=k;
    	}
    	return (k-1);
        
    }
};

int main(){
	Solution* my=new Solution();
	cout<<my->arrangeCoins(2147483647)<<endl;
	cout<<"hello"<<endl;
}