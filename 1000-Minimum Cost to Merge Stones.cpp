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
    int mergeStones(vector<int>& stones, int K) {
        if ((stones.size()-1)%(K-1)!=0)
            return -1;
        
        
    }
};

int main(){
    Solution* m=new Solution();
    vector<int> stones={3,2,4,1};
    int K=2;
    cout<<m->mergeStones(stones,K)<<endl;
}