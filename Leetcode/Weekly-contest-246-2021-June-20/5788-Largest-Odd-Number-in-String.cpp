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
    string largestOddNumber(string Num) {
        int NumLen=Num.size();
        // int StartLoc=-1;
        // int MaxOddLen=0;
        // int count=0;
        // string MaxOddNum="";
        for(int i=NumLen-1;i>=0;i--){
            if((Num[i]-'0')%2==1){
                return Num.substr(0,i+1);
            }
        }
        return "";
    }
};

int main(){
	Solution mysol;
	string Num="4206";
    cout<<mysol.largestOddNumber(Num)<<endl;
	//cout<<mysol.makeEqual(words)<<endl;
}