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
    vector<int> plusOne(vector<int>& digits) {
        vi res;
        res.swap(digits);
        int l=res.size()-1;
        while (l>=0 && res[l]==9){
            res[l]=0;
            l--;
        }
        if (l==-1){
            res.reserve(res.size()+1);
            res.push_back(1);
            //reverse(all(res));
            cout<<res.size()<<endl;
        }
        else if (res[l]!=9){
            res[l]++;
        }
        cout<<res.size()<<endl;
        return res;
    }
};

int main(){
    Solution mysol;
    vi digits{9};
    auto a=mysol.plusOne(digits);
    //cout<<a.size()<<endl;
    for(auto const&c: a){
            cout<<c<<endl;
        }
}