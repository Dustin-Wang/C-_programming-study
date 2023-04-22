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
    int islandPerimeter(vector<vector<int>>& grid) {
        int h=grid.size();
        if (h==0)
        	return 0;
        int w=grid[0].size();
        int i=0;
        int j=0;
        int f=1;
        for(i=0;f&&i<h;++i){
        	for(j=0;f&&j<w;++j){
        		if (grid[i][j]){
        			f=0;
        		}
        	}
        }
        int res=0;
        // cout<<i<<" "<<j<<endl;
        queue<vector<int>> q;
        q.push(vector<int>{i-1,j-1});
        grid[i-1][j-1]=2;
        vector<int> cur;
        while(!q.empty()){
        	cur=q.front();
        	
        	 // cout<<cur[0]<<"?"<<cur[1]<<endl;
        	if (cur[0]-1>=0 && grid[cur[0]-1][cur[1]]==1){
        		q.push(vector<int>{cur[0]-1,cur[1]});
        		grid[cur[0]-1][cur[1]]=2;
        	}
        	else if (cur[0]==0 || grid[cur[0]-1][cur[1]]==0){
        		res++;
        	}
        	if (cur[0]+1<h && grid[cur[0]+1][cur[1]]==1){
        		q.push(vector<int>{cur[0]+1,cur[1]});
        		grid[cur[0]+1][cur[1]]=2;
        	}
        	else if (cur[0]+1==h || grid[cur[0]+1][cur[1]]==0){
        		res++;
        	}
        	if (cur[1]-1>=0 && grid[cur[0]][cur[1]-1]==1){
        		q.push(vector<int>{cur[0],cur[1]-1});
        		grid[cur[0]][cur[1]-1]=2;
        	}
        	else if (cur[1]==0 || grid[cur[0]][cur[1]-1]==0){
        		res++;
        	}
        	if (cur[1]+1<w && grid[cur[0]][cur[1]+1]==1){
        		q.push(vector<int>{cur[0],cur[1]+1});
        		grid[cur[0]][cur[1]+1]=2;
        	}
        	else if (cur[1]+1==w || grid[cur[0]][cur[1]+1]==0){
        		res++;
        	}
        	

        	q.pop();
        	
        	// cout<<res<<endl;
        }
        return res;
    }
};
int main(){
	Solution* my=new Solution();
	vector<vector<int>> grid;
	// grid.push_back(vi{0,1,0,0});
	// grid.push_back(vi{1,1,1,0});
	// grid.push_back(vi{0,1,0,0});
	// grid.push_back(vi{1,1,0,0});
	grid.push_back(vi{1,1});
	grid.push_back(vi{1,1});
	cout<<my->islandPerimeter(grid)<<endl;
    cout<<"hello"<<endl;
}