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
    long long minimumPerimeter(long long neededApples) {
        long long  UpperBound = (long long)ceil(cbrt((double)neededApples/4));
    	//cout<<UpperBound<<endl;
        long long LowerBound = 0;
        //cout<<LowerBound<<endl;

        long long Mid = 0;
        while(LowerBound <= UpperBound){
        	Mid = (LowerBound + UpperBound)/2;
        	if( ApplesCanBeCollected(Mid)>neededApples ){
        		UpperBound = Mid-1;
        	}
        	else if(ApplesCanBeCollected(Mid)<neededApples){
        		LowerBound = Mid+1;
        	}
        	else{
        		return 8*Mid;
        	}
        } 
        return 8*LowerBound;
    }

private:
	long long ApplesCanBeCollected(long long HalfSideLength){
		return 2*HalfSideLength*(HalfSideLength+1)*(2*HalfSideLength+1);
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
	//long long neededApples = 1;
	//long long neededApples = 13;
   	long long neededApples = 1000000000;
   	cout<<mysol.minimumPerimeter(neededApples)<<endl;
	
}