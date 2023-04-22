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
    bool exist(vector<vector<char>>& board, string word) {
    	int h=board.size();
    	int w=board[0].size();
    	for(int i=0;i<h;i++){
    		for(int j=0;j<w;j++){
    			if(DFS(board,i,j,word,0)){
    				return true;
    			}
    		}
    	}
    	return false;
    }
private:
	bool DFS(vector<vector<char>>& board,int i, int j,string& word,int k){
		if (k==word.size()){
			return true;
		}
		int h=board.size();
    	int w=board[0].size();
		if(i<0 || i>=h ||j<0 || j>=w || word[k]!=board[i][j]){
			return false;
		}
		char temp=board[i][j];
		board[i][j]='#';
		bool res=DFS(board,i+1,j,word,k+1)||DFS(board,i,j+1,word,k+1)\
		         ||DFS(board,i-1,j,word,k+1)||DFS(board,i,j-1,word,k+1);
		board[i][j]=temp;
		return res;
	}
};




int main(){
	Solution* m=new Solution();
	vector<vector<char>> board;
	board.push_back(std::vector<char>{'a','b','c','e'});
	board.push_back(std::vector<char>{'s','f','c','s'});
	board.push_back(std::vector<char>{'a','d','e','e'});
	string word="abcb";
	cout<<m->exist(board,word);
}