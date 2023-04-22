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
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    	unordered_map<double, long long> counter;
    	for(const auto pair:rectangles){
    		double pairRatio= (double) pair[0]/(double)pair[1];
    		if(counter.find(pairRatio)==counter.end())
    			counter.insert({pairRatio, 1});
    		else
    			counter[pairRatio]++;
    	}
    	long long res = 0;
        for(const auto pair:counter){
        	res += pair.second*(pair.second-1)/2;
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
 	int array[][2] ={{4,5},{7,8}};
   	// int target = 145;
   	vector<vector<int>> mat = ArrayTo2dVector(array);
	cout<<mysol.interchangeableRectangles(mat)<<endl;
	
}