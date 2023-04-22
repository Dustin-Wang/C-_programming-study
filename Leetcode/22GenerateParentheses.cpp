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
    vector<string> generateParenthesis(int n) {
  //       int memorysize=0;
  //       vector<vector<string>> memory;
		// for(memorysize=0;memorysize<n;memorysize++){
		// 	if(memorysize==0){
		// 		vector<string> newmemory{"()"};
		// 		memory.push_back(newmemory);
		// 		//cout<<"hello?\n"<<endl;
		// 	}
		// 	else{
		// 		//cout<<"hello?\n"<<endl;
		// 		vector<string> newmemeory;
		// 		for(int i=1;i<=(memorysize+1)/2;i++){
		// 			string prefix="";
		// 			string postfix="";
		// 			// for(int k=1;k<=i;k++){
		// 			// 	prefix+="(";
		// 			// 	postfix+=")";
		// 			// }
		// 			for(auto const &amid: memory[memorysize-1]){
		// 				newmemeory.push_back("("+amid+")");
		// 			}
		// 			for(auto const &ai: memory[i-1]){
		// 				for(auto const &ami: memory[memorysize-i]){
		// 					newmemeory.push_back(ai+ami);
		// 					//cout<<"hello?\n"<<endl;
		// 				}
		// 			}
					
		// 		}
		// 		memory.push_back(newmemeory);
		// 	}
		// }
		// return memory[n-1];
		vector<string> res;
		string s="";
		producer(s,0,0,n,res);
		return res;
    }
private:
	void producer(string s,int right,int up, int n, vector<string>& res){
		if(right==n && up==n){
			res.push_back(s);
		}
		else if(right==n && up<n){
			producer(s+")",right,up+1,n,res);
		}
		else if(right<n && up<right){
			producer(s+"(",right+1,up,n,res);
			producer(s+")",right,up+1,n,res);
		}
		else if(right<n && up==right){
			producer(s+"(",right+1,up,n,res);
		}
	}
};

int main(){
	Solution mysol;
	int n=2;
	vector<string> res=mysol.generateParenthesis(n);
	for(auto const&c:res){
		cout<<c<<endl;
	}
	return 0;
}