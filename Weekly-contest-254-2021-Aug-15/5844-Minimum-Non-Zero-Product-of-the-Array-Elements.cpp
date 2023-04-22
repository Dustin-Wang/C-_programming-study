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
#include <unordered_map>

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
    int minNonZeroProduct(int p) {
         
        unsigned long long res = 1;
        unsigned int mod = pow(10,9)+7;
        unsigned long long base = 1;
        vector<unsigned long  long> recordForTwoPower;
        unsigned long long tmp = 2;
        for(int i = 0; i< 6; i++){
            recordForTwoPower.push_back(tmp);
            tmp = (tmp*tmp)%mod;
        }
        for(int i = 0; i<6; i++){
            if(p>>i&1){
                base = (base*recordForTwoPower[i])%mod;
            }
        }
        base = base -2;//base = pow(2,p)-2
        //cout<<base<<endl;    
        vector<unsigned long long> record;
        tmp = base;
        res = 1;
        for(int i = 0; i < p-1; i++){
            record.push_back(tmp);
            tmp = (tmp*tmp)% mod;
        }
        for(int i = 0; i < p-1; i++){
            res = (res * record[i]) %mod;
        }
        //cout<<res<<endl;
        res = (res*(base+1))%mod;
        return res;
    }
};
template <size_t rows, size_t cols>
vector<vector<int>> ArrayTo2dVector(int (&array)[rows][cols])
{
    vector<vector<int>> res;
    for (size_t i = 0; i < rows; ++i)
    {
        vector<int> row;
        for (size_t j = 0; j < cols; ++j)
            row.push_back(array[i][j]);
        res.push_back(row);
    }
    return res;
};
int main(){
	Solution mysol;
    int p = 5;
	cout<<mysol.minNonZeroProduct(p)<<endl;
	
}