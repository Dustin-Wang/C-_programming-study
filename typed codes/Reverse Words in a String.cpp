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
typedef pair<int,double> pid;
// END NO SAD
// REMEMBER CLEAR GLOBAL STATE

class Solution {
public:
    string reverseWords(string s) {
        int sl=s.size();
        string res="";
        int i=0;
        int f=0;
        while(i<sl){
        	if(s[i]!=' '){
        		res.insert(f,1,s[i]);
        		f++;
        		i++;
        	}
        	else{
        		if (f!=0){
        			res=s[i]+res;
        	    }
        		f=0;
        		while(s[i]==' '){
        			i++;
        		}
        	}
        }
        if (res[0]==' '){
        	res.erase(0,1);
        }
        return res;
    }
};

int main(){
	string s="  a good   example ";
	Solution* m=new Solution();
	cout<<m->reverseWords(s)<<endl;
}