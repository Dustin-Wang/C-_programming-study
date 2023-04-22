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
    int minStoneSum(vector<int>& piles, int k) {
    	priority_queue<int> PilesPQ;
    	int Sum = 0;
    	for(const auto & c: piles){
    		PilesPQ.push(c);
    		// Sum += c;
    	}
    	int NoOfOperations = 0;
    	while( !PilesPQ.empty() && PilesPQ.top()>1 && NoOfOperations < k){
    		int tmp = PilesPQ.top();
    		// Sum = Sum - tmp/2;
    		int NewPile = tmp - tmp/2;
    		PilesPQ.pop();
    		if( NewPile > 0){
    			PilesPQ.push(NewPile);
    		}
    		NoOfOperations++;
    	}
        while ( !PilesPQ.empty() ){
        	Sum += PilesPQ.top();
        	PilesPQ.pop();
        }
        return Sum;
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
    // vector<int> piles{5,4,9};
    // int k = 2;
    vector<int> piles{4,3,6,7};
    int k = 3;
	cout<<mysol.minStoneSum(piles, k)<<endl;
	
}