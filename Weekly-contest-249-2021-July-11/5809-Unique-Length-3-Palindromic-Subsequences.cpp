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
    int countPalindromicSubsequence(string s) {
    	int LenUpperBound=100001;
    	int sLen=s.size();
    	int res=0;
    	vector<int> FirstAppearLocsForEachLetter(26,LenUpperBound);
    	vector<vector<int>> DifferentLettersAfterEachLetter(26,vector<int>(26,0));
    	vector<vector<int>> PossibleLength3Palindromic(26,vector<int>(26,0));//
    	//this two dimensional array first index is the starting letter,
    	// second index is the middle letter, it's 0 means that such subsequence
    	//has not appeared. 
    	for(int i=0;i<sLen;i++){
    		//record the location whether letter s[i] first appear
    		if (FirstAppearLocsForEachLetter[s[i]-'a']==LenUpperBound){
    			FirstAppearLocsForEachLetter[s[i]-'a']=i;
    		}
    		
    		//update the record of all possible length 3 palindromic 
    		for(int j=0;j<26;j++){
    			if(FirstAppearLocsForEachLetter[s[i]-'a']<i){
    				PossibleLength3Palindromic[s[i]-'a'][j]=DifferentLettersAfterEachLetter[s[i]-'a'][j];
    			}
    		}
    		//update the record of different letters after the letter s[i]-a
    		for(int j=0;j<26;j++){
    			if(FirstAppearLocsForEachLetter[j]<i){
    				DifferentLettersAfterEachLetter[j][s[i]-'a']=1;
    			}
    		}
    	}
    	for(int i=0;i<26;i++){
    		for(int j=0;j<26;j++){
    			res=res+PossibleLength3Palindromic[i][j];
    		}
    	}

    	return res;
    }
};
int main(){
	Solution mysol;
	//string s="aabca";//3
	//string s="abc";//0
	string s="bbcbaba";//4
	cout<<mysol.countPalindromicSubsequence(s)<<endl;
	
}