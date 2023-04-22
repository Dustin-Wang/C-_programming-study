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
#include <unordered_set>
#include <climits>

using namespace std;
// BEGIN NO SAD
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
// END NO SAD
// REMEMBER CLEAR GLOBAL STATE

// struct myclass{
// 	bool operator()(string a, string b){
// 		if(a.size()<b.size())
// 			return false;
// 		else if(a.size()>b.size())
// 			return true;
// 		else
// 			return(a>b);
// 	}
// } myobject;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
    	int glen = grid[0].size();
    	if(glen==1){
    		return 0;
    	}
    	long long res = LLONG_MAX;
    	long long SumOfRow0=0;
    	for(int l=0;l<glen; l++){
    		SumOfRow0+=grid[0][l];
    	}

    	long long PartialSumInRow0 = SumOfRow0-grid[0][0];
    	long long PartialSumInRow1 = 0;
    	res = min(res, max(PartialSumInRow0,PartialSumInRow1));
    	for(int k = 1;k < glen;k++){
    		PartialSumInRow0 -= grid[0][k];
    		// cout<<"PartialSumInRow0: "<<PartialSumInRow0<<endl;
    		PartialSumInRow1 +=grid[1][k-1];
    		// cout<<"PartialSumInRow1: "<<PartialSumInRow1<<endl;
    		res = min(res, max(PartialSumInRow0,PartialSumInRow1));
    	}
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
 	// int array[][2] ={{4,8},{3,6},{10,20},{15,30}};
 	// int array[][2] ={{4,5},{7,8}};
   	// int target = 145;
 //   	vector<vector<int>> mat = ArrayTo2dVector(array);
	// cout<<mysol.interchangeableRectangles(mat)<<endl;
	
	int array[][4] ={{1,3,1,15},{1,3,3,1}};
 	// int array[][2] ={{4,5},{7,8}};
   	// int target = 145;
   	vector<vector<int>> mat = ArrayTo2dVector(array);
	// cout<<mysol.interchangeableRectangles(mat)<<endl;
	cout<<mysol.gridGame(mat)<<endl;
}