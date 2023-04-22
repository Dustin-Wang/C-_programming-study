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
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res="";
        if(n==0)
        	return res;
        else if(n==1)
        	res=strs[0];
       	else{
        	int i=2;
        	res=longestCommonPrefixBetweenTwoWords(strs[0],strs[1]);
        	while(res.size()>=1 && i<strs.size()){
        		res=longestCommonPrefixBetweenTwoWords(res,strs[i]);
        		i++;
        	}
        }
        return res;
    }
private:
	string longestCommonPrefixBetweenTwoWords(string& a,string& b){
		string res="";
		int alen=a.size();
		int blen=b.size();
		int i=0;
		while(i<min(alen,blen) && a[i]==b[i]){
			res+=a[i];
			i++;
		}
		return res;
	}
};

int main(){
	Solution mysol;
	vector<string> strs{"dog","racecar","car"};
	string res=mysol.longestCommonPrefix(strs);
	cout<<res<<endl;
	return 0;
}