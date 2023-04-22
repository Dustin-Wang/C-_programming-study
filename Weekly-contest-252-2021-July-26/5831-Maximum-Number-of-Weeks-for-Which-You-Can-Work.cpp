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
    long long numberOfWeeks(vector<int>& milestones) {
        long long Max=0;
        long long Sum=0;
        for(auto const&c:milestones){
        	if( c > Max ){
        		Max = c;
        	}
        	Sum = Sum + c;
        }
        long long Others = Sum - Max;
        if( Max > Others ){
        	return 2*Others+1;
        }
        else{
        	return Sum;
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
	vector<int> milestones{1,2,3};
	//vector<int> milestones{5,2,1};
	cout<<mysol.numberOfWeeks(milestones)<<endl;
	
}