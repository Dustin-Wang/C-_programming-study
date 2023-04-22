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
    string maxValue(string n, int x) {
    	string res;
    	int nlen=sz(n);
    	int i=0;
    	char xc=x+'0';
    	string xs(1,xc);
        if(n[0]!='-'){
        	for(i=0;i<nlen;i++){
        		if (n[i]-'0'<x){
        			break;
        		}
        	}
        	res=n.substr(0,i)+xs+n.substr(i,nlen-i);
        	return res;
        }
        else{
        	for(i=1;i<nlen;i++){
        		if(n[i]-'0'>x){
        			break;
        		}
        	}
        	res=n.substr(0,i)+xs+n.substr(i,nlen-i);
        	return res;
        }

    }
};

int main(){
	Solution mysol;
	string n="962942516613939";
	int x=3;
	string res=mysol.maxValue(n,x);
	cout<<res<<endl;
	return 0;
	
}