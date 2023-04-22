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
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        vector<vector<int>> VisitedInDFS;
        for(int i=0;i<m;i++){
            VisitedInDFS.push_back(vector<int>(n,0));
        }
        int SubIslands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid1[i][j]==1 &&grid2[i][j]==1 &&VisitedInDFS[i][j]==0){
                    int res= DFS(i,j,grid1,grid2,VisitedInDFS);
                    // if(res==1){
                    //     cout<<"i "<<i<<";"<<"j "<<j<<endl;
                    // }
                    SubIslands+=res;
                }
            }
        }
        return SubIslands;
    }
private:
    int DFS(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& VisitedInDFS){
        int m=grid1.size();
        int n=grid1[0].size();
        if(i>=0&&i<m && j>=0 &&j<n){
            if(VisitedInDFS[i][j]==1){
                return 1;
            }
            else if(VisitedInDFS[i][j]==2){
                return 0;
            }
            if(grid1[i][j]==1 &&grid2[i][j]==1){
                VisitedInDFS[i][j]=1;
                int res=DFS(i-1,j,grid1,grid2,VisitedInDFS)&&DFS(i,j-1,grid1,grid2,VisitedInDFS)
                    &&DFS(i+1,j,grid1,grid2,VisitedInDFS)&&DFS(i,j+1,grid1,grid2,VisitedInDFS);
                if(res==0){
                    VisitedInDFS[i][j]=2;//if you are connected to some bad grid by 11 grids                
                }
                else{
                    VisitedInDFS[i][j]=1;
                }
                return res;
            }
            else if(grid1[i][j]==0&&grid2[i][j]==1){
                VisitedInDFS[i][j]=2;//this is the island in grid 2 but not in grid 1, touch this bad grid then no longer subisland
                return 0;
            }
            else if(grid2[i][j]==0){
                return 1;
            }
            return 1;
        }
        else{
            return 1;
        }
    }
};


int main(){
	Solution mysol;
    //cout<<mysol.numberOfRounds(startTime,finishTime)<<endl;
	//cout<<mysol.makeEqual(words)<<endl;
    // vector<vector<int>> grid1;
    // grid1.push_back(vector<int>{1,1,1,0,0});
    // grid1.push_back(vector<int>{0,1,1,1,1});
    // grid1.push_back(vector<int>{0,0,0,0,0});
    // grid1.push_back(vector<int>{1,0,0,0,0});
    // grid1.push_back(vector<int>{1,1,0,1,1});
    // vector<vector<int>> grid2;
    // grid2.push_back(vector<int>{1,1,1,0,0});
    // grid2.push_back(vector<int>{0,0,1,1,1});
    // grid2.push_back(vector<int>{0,1,0,0,0});
    // grid2.push_back(vector<int>{1,0,1,1,0});
    // grid2.push_back(vector<int>{0,1,0,1,0});
    // vector<vector<int>> grid1;
    // grid1.push_back(vector<int>{1,0,1,0,1});
    // grid1.push_back(vector<int>{1,1,1,1,1});
    // grid1.push_back(vector<int>{0,0,0,0,0});
    // grid1.push_back(vector<int>{1,1,1,1,1});
    // grid1.push_back(vector<int>{1,0,1,0,1});
    // vector<vector<int>> grid2;
    // grid2.push_back(vector<int>{0,0,0,0,0});
    // grid2.push_back(vector<int>{1,1,1,1,1});
    // grid2.push_back(vector<int>{0,1,0,1,0});
    // grid2.push_back(vector<int>{0,1,0,1,0});
    // grid2.push_back(vector<int>{1,0,0,0,1});
    vector<vector<int>> grid1;
    grid1.push_back(vector<int>{1,0,1,0,1,1,1,0,1,1,0,1,1,1,1});
    grid1.push_back(vector<int>{1,1,1,1,1,0,1,1,1,1,0,0,0,1,1});
    grid1.push_back(vector<int>{1,1,1,1,1,0,1,1,1,1,1,1,1,1,0});
    grid1.push_back(vector<int>{1,1,1,1,0,1,0,0,1,1,1,1,0,0,1});
    grid1.push_back(vector<int>{0,0,1,1,1,1,1,0,1,0,1,1,1,0,0});
    grid1.push_back(vector<int>{0,1,1,1,1,1,1,1,1,0,1,1,1,1,1});
    grid1.push_back(vector<int>{0,0,1,1,1,1,1,1,1,1,1,1,1,1,0});
    grid1.push_back(vector<int>{0,1,1,1,1,1,1,1,0,1,1,1,1,1,1});
    grid1.push_back(vector<int>{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0});
    grid1.push_back(vector<int>{1,1,1,1,0,1,0,0,1,1,1,0,0,1,1});
    grid1.push_back(vector<int>{1,0,1,1,1,1,1,0,0,1,1,1,1,0,1});
    grid1.push_back(vector<int>{0,1,0,0,0,1,1,1,1,1,1,1,0,0,1});
    vector<vector<int>> grid2;
    grid2.push_back(vector<int>{1,0,1,0,0,0,1,0,0,0,0,0,1,0,1});
    grid2.push_back(vector<int>{1,1,0,1,0,1,1,1,1,1,0,1,0,1,1});
    grid2.push_back(vector<int>{1,1,1,0,1,1,1,1,1,1,0,1,0,1,1});
    grid2.push_back(vector<int>{1,0,0,1,0,1,1,1,0,0,1,0,1,0,1});
    grid2.push_back(vector<int>{0,1,1,1,1,1,1,0,1,1,1,1,1,0,0});
    grid2.push_back(vector<int>{0,1,1,1,1,1,1,1,1,1,0,1,1,1,0});
    grid2.push_back(vector<int>{1,1,1,1,1,1,1,1,1,0,0,1,0,1,1});
    grid2.push_back(vector<int>{1,0,1,0,0,1,1,1,0,1,0,1,1,1,1});
    grid2.push_back(vector<int>{0,1,0,1,1,1,0,1,1,1,1,0,0,0,1});
    grid2.push_back(vector<int>{1,1,1,0,1,0,0,0,1,1,0,0,1,1,1});
    grid2.push_back(vector<int>{1,0,0,1,1,1,0,0,0,0,1,0,1,0,0});
    grid2.push_back(vector<int>{0,0,1,1,1,1,1,0,1,0,1,1,1,0,0});
    cout<<mysol.countSubIslands(grid1,grid2)<<endl;
}