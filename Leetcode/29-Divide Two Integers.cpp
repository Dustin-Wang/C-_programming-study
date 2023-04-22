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
    int divide(int dividend, int divisor) {
        if(divisor==0)
            return INT_MAX;
        if (dividend==0)
            return 0;
        if(dividend==divisor)
            return 1;
        if(divisor==INT_MIN){
            return 0;
        }
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        if(dividend==INT_MIN){
            if(divisor>0){
                return divide(dividend+divisor,divisor)-1; 
            }
            else if(divisor<0){
                return divide(dividend-divisor,divisor)+1;
            }
        }
        if(dividend<0&&divisor<0)
            return divide(-dividend,-divisor);
        else if(dividend<0&&divisor>0)
            return -divide(-dividend,divisor);
        else if(dividend>0&&divisor<0)
            return -divide(dividend,-divisor);
        if(dividend==divisor){
            return 1;
        }

        int div=dividend;
        int res=0;
        int NoOfZerosAtBeginningOfDivisor=__builtin_clz(divisor);
        //cout<<NoOfZerosAtBeginningOfDivisor<<endl;
        for(int k=NoOfZerosAtBeginningOfDivisor-1;k>=0;k--){
            if((div-(divisor<<k))>=0){
                cout<<k<<endl;
                div=div-(divisor<<k);
                res=res+(1<<k);
            }
        }
        return res;
    }
};

int main(){
	Solution* m=new Solution();
	int dividend=10;
    int divisor=3;
    cout<<m->divide(dividend,divisor)<<endl;
}