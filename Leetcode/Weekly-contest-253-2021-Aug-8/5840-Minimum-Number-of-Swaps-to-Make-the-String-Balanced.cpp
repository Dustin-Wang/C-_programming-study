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
    int minSwaps(string s) {
        int SLen = s.size();
        int PosInGrid = 0;
        int MaxPosInGrid = 0;
        int CrossDiagnalLine = 0;
        for(int i = 0; i<SLen; i++){
        	if(s[i] == ']')
        		PosInGrid++;
        	else if(s[i] == '[')
        		PosInGrid--;
        	if(PosInGrid > MaxPosInGrid){
        		MaxPosInGrid = PosInGrid;
        	}
        	// if(PosInGrid == 0)
        	// 	CrossDiagnalLine++;
        }
        if(MaxPosInGrid%2 == 0){
        	return MaxPosInGrid/2;
        }
        else{
        	return MaxPosInGrid/2+1;
        }

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
	Solution  mysol;
    //string s = "][][";
	//string s = "]]][[[";
	string s = "[]";
	cout<<mysol.minSwaps(s)<<endl;
	
}