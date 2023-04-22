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
    bool isPrefixString(string s, vector<string>& words) {
        bool res = true;
        int WordsLen = words.size();
        int StringLen = s.size();
        int SLoc = 0;
        int WLoc = 0;
        for(int i=0; i<WordsLen; i++){
            WLoc = 0;
            while( SLoc < StringLen && WLoc < words[i].size() && s[SLoc] == words[i][WLoc]){
                SLoc++;
                WLoc++;
            }

            if(SLoc == StringLen){
                if(WLoc == words[i].size()){
                    return true;
                }
                else{
                    return false;
                }
            }
            else if(WLoc == words[i].size()){
                continue;
            }
            else if(s[SLoc] != words[i][WLoc]){
                return false;
            }
        }
        if(SLoc<StringLen){
            return false;
        }
        return false;

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
    // string s="iloveleetcode";
    // vector<string> words{"i", "love", "leetcode", "apples"};
    string s="a";
    vector<string> words{"aa", "love", "leetcode", "apples"};
	//vector<int> milestones{1,2,3};
	//vector<int> milestones{5,2,1};
	cout<<mysol.isPrefixString(s, words)<<endl;
	
}