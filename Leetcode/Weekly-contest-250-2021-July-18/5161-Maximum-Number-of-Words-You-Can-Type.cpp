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
    int canBeTypedWords(string text, string brokenLetters) {
        int textLen=text.size();
        vector<int> BrokenTable(26,0);
        for(const auto&c:brokenLetters){
        	BrokenTable[c-'a']=1;
        }
        int count=0;
        int AbleToType=1;
        for(int i=0;i<textLen;i++){
        	if(i<textLen && text[i]==' '){
        		if(AbleToType){
        			count++;
        		}
        		if(i+1<=textLen){
        			AbleToType=1;
        		}

        		//cout<<count<<endl;
        		//AbleToType=0;
        	}
        	else if (i<textLen && BrokenTable[text[i]-'a']){
        		AbleToType=0;
        	}
        }
        if(AbleToType){
        	count++;
        }
        return count;
    }
};
int main(){
	Solution mysol;
	
	// string text="hello world";
	// string brokenLetters="ad";
	// string text="a b c d e";
	// string brokenLetters="abcde";
	string text="leet code";
	string brokenLetters="lt";
	cout<<mysol.canBeTypedWords(text,brokenLetters)<<endl;
	
}