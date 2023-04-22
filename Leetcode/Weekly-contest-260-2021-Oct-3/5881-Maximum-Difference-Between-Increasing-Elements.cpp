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
    int minimumMoves(string s) {
        int sLen=s.size();
        int start = 0;
        int res = 0;
        
        for(start = 0; start<sLen; start++){
            if(s[start]=='X'){
                res ++;
                start = start+2;//after this, start will also +1
            }

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
	string s = "XXXX";
	cout<<mysol.minimumMoves(s)<<endl;
}