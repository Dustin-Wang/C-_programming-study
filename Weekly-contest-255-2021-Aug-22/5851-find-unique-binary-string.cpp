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
    string findDifferentBinaryString(vector<string>& nums) {
    	string res = "";
    	int n = nums.size();
    	for(int i = 0; i<n ; i++){
    		if(nums[i].at(i) =='0')
    			res += '1';
    		else
    			res += '0';
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
    //vector<string> nums{"01", "10"};
	//vector<string> nums{"00", "01"};
	vector<string> nums{"111", "011", "001"};
	cout<<mysol.findDifferentBinaryString(nums)<<endl;
	
}