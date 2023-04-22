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
    int getLucky(string s, int k) {
        vector<int> Maps{1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,10,2,3,4,5,6,7,8};
        vector<int> PowerRecord(10,0);
        for(int i=0;i<9;i++){
            PowerRecord[i]=pow(10,i);
        }
        int PreviousTransformedNum=0;
        for(const auto&c:s){
            PreviousTransformedNum+=Maps[c-'a'];
        }
        k--;
        int NextTransformedNum=0;
        while(k>0 && PreviousTransformedNum>=10){
            NextTransformedNum=0;

            int LargestTenPower=(int)log10((double) PreviousTransformedNum);
            while(LargestTenPower>=0){
                NextTransformedNum+=PreviousTransformedNum/PowerRecord[LargestTenPower];
                PreviousTransformedNum=PreviousTransformedNum%PowerRecord[LargestTenPower];
                LargestTenPower--;       
            }
            PreviousTransformedNum=NextTransformedNum;
            //cout<<PreviousTransformedNum<<endl;
            k--;
        }
        return PreviousTransformedNum;
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
    //string s="leetcode";int k=2;
    //string s="iiii";int k=1;
    string s="zbax";int k=2;
    cout<<mysol.getLucky(s,k)<<endl;
	
}