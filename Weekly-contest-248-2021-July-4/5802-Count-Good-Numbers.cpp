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
    int countGoodNumbers(long long n) {
        unsigned long long res=1;
        unsigned int Prime=1000000007;
        unsigned long long ProcessedNoOfPairs=(n>>1)%(Prime-1);
        int Bits=32;
        vector<unsigned long> Residents(Bits,20);
        for(int i=1;i<Bits;i++){//store 20^{2to the power} residence with respect to Prime for the following usage
            Residents[i]=(Residents[i-1]*Residents[i-1])%Prime;
            //cout<<Residents[i]<<endl;
        }
        if((n&1)==0){
            cout<<ProcessedNoOfPairs<<endl;
            for(int i=0;i<Bits;i++){
                if(((1<<i)&ProcessedNoOfPairs)!=0){
                    res=(res*Residents[i])%Prime;
                    //cout<<"i"<<i<<endl;
                }
            }
        }
        else if((n&1)==1){
            for(int i=0;i<Bits;i++){
                if(((1<<i)&ProcessedNoOfPairs)!=0){
                    res=(res*Residents[i])%Prime;
                }
            }
            res=(res*5)%Prime;
        }
        return res;
    }
};
int main(){
	Solution mysol;
	//vector<int> dist{1,3,4};
	//vector<int> speed{1,1,1};
	//vector<int> dist{1,1,2,3};
	//vector<int> speed{1,1,1,1};
	//vector<int> dist{3,2,4};
	//vector<int> speed{5,3,2};
	cout<<mysol.countGoodNumbers(806166225460393)<<endl;
    //cout<<mysol.countGoodNumbers(789623948667401)<<endl;
     //cout<<mysol.countGoodNumbers(50)<<endl;
	
}