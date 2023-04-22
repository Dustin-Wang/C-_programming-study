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
    bool makeEqual(vector<string>& words) {
    	vector<int> LowercaseLetterCounter(26,0);
        int NoOfWords=words.size();
    	for(int i=0;i<NoOfWords;i++){
    		for(const auto&character:words[i]){
    			LowercaseLetterCounter[character-'a']++;
    		}
    	}
    	int OccureFreq=0;
    	for(const auto&occurrence:LowercaseLetterCounter){
    		if (occurrence%NoOfWords!=0){
    				return false;
    			}
    	}
    	return true;
    }
};

int main(){
	Solution mysol;
	// vector<string> words;
 //    words.push_back("abc");
 //    words.push_back("aabc");
 //    words.push_back("bc");
	vector<string> words{"b","a"};
	//cout<<"1"<<endl;
	cout<<mysol.makeEqual(words)<<endl;
}