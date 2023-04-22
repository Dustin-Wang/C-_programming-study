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


int mod=pow(10,9)+7;

class Solution {
public:
    int colorTheGrid(int m, int n) {
    	
    	int res=0;
    	//vector<int> PreColumn(5,0);//1 2 3 represents 3 colors
    	//first column totally has at most 3*2*2*2*2 painting methods, since 1<=m<=5
    	//due to symmetricity, there are totally 3*2*2*2*2/6=8 cases.

    	//case 1: 12121 maps to 23212,23213,23232() 21 31
    	//case 2: 12123
    	//case 3: 12131
    	//case 4: 12132
    	//case 5: 12312
    	//case 6: 12313
    	//case 7: 12321
    	//case 8: 12323
    	//without loss of generality, we could assume that the first two in the first column
    	//is always 1 and 2. Then we could multiply the result by 6=3 pick 2
    	

    	//no need to simplify by symmetricity, first try to consider all cases for each column, 
    	//and find what columns can be arranged next to the columns


    	unordered_map<string, vector<string>> NeighborsForColumns;
    	//cout<<m<<endl;
    	DFSConstructNeighborsForColumns("",m,NeighborsForColumns);
    	// for(const auto &c:NeighborsForColumns){
    	// 	cout<<c.first<<": ";
    	// 	for(const auto &d:c.second){
    	// 		cout<<d<<" ";
    	// 	}
    	// 	cout<<endl;
    	// }
    	int NoOfDifferentColumns=3*pow(2,m);
    	unordered_map<string, int> DP;
    	for(const auto&c: NeighborsForColumns){
    		pair<string, int> tmp(c.first,1 );
    		DP.insert(tmp);
    	}
    	unordered_map<string, int> NextDP;
    	for(int i=2;i<=n;i++){
    		for(const auto&Current:NeighborsForColumns){
    			int count=0;
    			for(const auto &d: Current.second){
					count=(count+DP[d])%mod;
				}
				pair<string,int> tmp(Current.first,count);
				NextDP.insert(tmp);
    		}
    		DP.swap(NextDP);
    		NextDP.clear();
    	}
    	
    	for(const auto&c:DP){
    		res=(res+c.second)%mod;
    	}
    	return res;
        
    }
private:
	void DFSConstructNeighborsForColumns(string KeyCol, int unfinishedLenOfKeyCol,
		unordered_map<string, vector<string>>& NeighborsForColumns){
		if(unfinishedLenOfKeyCol>0){
			int KeyColLen=KeyCol.size();
			for(int i=1;i<=3;i++){
				if(KeyColLen==0 || KeyCol[KeyColLen-1]!=(char)('0'+i)){
					KeyCol=KeyCol+(char)('0'+i);
					unfinishedLenOfKeyCol--;
					DFSConstructNeighborsForColumns(KeyCol,unfinishedLenOfKeyCol,NeighborsForColumns);
					KeyCol.pop_back();
					unfinishedLenOfKeyCol++;
				}	
			}
		}
		else{
			//cout<<"KeyCol:"<<KeyCol<<endl;
			pair<string, vector<string>> tmp(KeyCol,vector<string>());
			NeighborsForColumns.insert(tmp);
			int ColLen=KeyCol.size();
			DFSConstructNeighborsForKeyColumn("",ColLen,KeyCol,NeighborsForColumns);
		}

		
	}
	void DFSConstructNeighborsForKeyColumn(string NextCol, int unfinishedLenOfNextCol, string KeyCol, unordered_map<string, vector<string>>& NeighborsForColumns){
		if(unfinishedLenOfNextCol>0){
			int NextColLen=NextCol.size();
			for(int i=1;i<=3;i++){
				if((NextColLen==0 || NextCol[NextColLen-1]!=(char)('0'+i)) && KeyCol[NextColLen]!=(char)('0'+i)){
					NextCol=NextCol+(char)('0'+i);
					unfinishedLenOfNextCol--;
					DFSConstructNeighborsForKeyColumn(NextCol,unfinishedLenOfNextCol,KeyCol,NeighborsForColumns);
					NextCol.pop_back();
					unfinishedLenOfNextCol++;
				}
			}
		}
		else{
			NeighborsForColumns[KeyCol].push_back(NextCol);
		}
	}
};
int main(){
	Solution mysol;
	//1 1 answer 3
	//1 2 answer 6
	//5 5 answer 580986
	//2 37
	cout<<mysol.colorTheGrid(2,37)<<endl;
	
}