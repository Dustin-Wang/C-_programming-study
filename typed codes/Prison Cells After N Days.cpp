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
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    	N=(N-1)%14+1;
    	vector<int> today(all(cells));
    	vector<int> nextday(8,0);
    	//cout<<"here"<<endl;
    	for(int j=1;j<=N;j++){
    		fill(all(nextday),0);
    		for(int k=1;k<=6;k++){
    			//cout<<"here"<<endl;
    			nextday[k]=(today[k-1]==today[k+1]);
    		}
    		today=nextday;
    	}
    	return today;
    }
};

int main(){
	//vi cells{1,0,0,1,0,0,1,0};
	vi cells{1,0,0,1,0,0,0,1};
	//int N=1000000000;
	int N=826;
	Solution mysol;
	vi a=mysol.prisonAfterNDays(cells,N);
	for(auto const&c:a){
		cout<<c<<" ";
	}
	
}