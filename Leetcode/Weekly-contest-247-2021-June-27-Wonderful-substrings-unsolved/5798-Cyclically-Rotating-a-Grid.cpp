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
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int GridHeight=grid.size();
        int GridWidth=grid[0].size();
        vector<vector<int>> Res;
        for(int i=0;i<GridHeight;i++){
        	Res.push_back(grid[i]);
        }
        int LayerMin=min(GridHeight,GridWidth);
        int LayerWidth=0;
        int LayerHeight=0;
        int rotk=0; 
        vector<int> ArrayToStoreLayer;
    	for(int Layer=1;Layer<=LayerMin/2;Layer++){
    		if(GridWidth<=GridHeight){
        		LayerWidth=Layer*2;
        		LayerHeight=LayerWidth+GridHeight-GridWidth;
        		
    		}
    		else if(GridWidth>GridHeight){
    			LayerHeight=Layer*2;
        		LayerWidth=LayerHeight+GridWidth-GridHeight;
    		}
    		int LayerLength=2*LayerWidth+2*LayerHeight-4;
    		//cout<<LayerLength<<endl;
    		rotk=k%LayerLength;
    		if(rotk==0){
    			continue;
    		}
    		
    		// if (rotk<=LayerHeight-1)
    		// 	Res[-LayerWidth/2][-LayerHeight/2]=Grid[-LayerWidth/2][-LayerHeight/2+rotk];
    		// else if(LayerHeight-1<rotk<=LayerHeight+LayerWidth-2)
    		// 	Res[-LayerWidth/2][-LayerHeight/2]=Grid[-LayerWidth/2+rotk-(LayerHeight-1)][LayerHeight/2];
    		// else if(LayerHeight+LayerWidth-2<rotk<=2*LayerHeight+LayerWidth-3)
    		// 	Res[-LayerWidth/2][-LayerHeight/2]=Grid[LayerWidth/2][LayerHeight/2-(rotk-LayerHeight+LayerWidth-2)];
    		// else if(2*LayerHeight+LayerWidth-3<rotk<=2*LayerHeight+2*LayerWidth-4)
    		// 	Res[-LayerWidth/2][-LayerHeight/2]=Grid[LayerWidth/2-(rotk-(2*LayerHeight+LayerWidth-3))][-LayerHeight/2];
    		// end
    		int x=LayerWidth/2-1; int y=LayerHeight/2-1;//index -LayerWidth/2 to LayerWidth/2-1, -LayerHeight/2 to LayerHeight/2-1
    		int count=0;int flag=0;//0 left, 1 down, 2 right, 3 up
    		while(count<LayerLength){
    			ArrayToStoreLayer.push_back(grid[-y+GridHeight/2-1][x+GridWidth/2]);
    			// for(const auto&c:ArrayToStoreLayer){
    			// cout<<c<<" ";
	    		// }
	    		// cout<<endl;
    			count++;
    			if(x==LayerWidth/2-1 && y==LayerHeight/2-1){
    				flag=0;
    			}
    			else if(x==LayerWidth/2-1 && y==-LayerHeight/2){
    				flag=3;
    			}
    			else if(x==-LayerWidth/2 && y==LayerHeight/2-1){
    				flag=1;
    			}
    			else if(x==-LayerWidth/2 && y==-LayerHeight/2){
    				flag=2;
    			}
    			if(flag==0){
    				x--;
    			}
    			else if(flag==1){
    				y--;
    			}
    			else if(flag==2){
    				x++;
    			}
    			else if(flag==3){
    				y++;
    			}
    		}

    		x=LayerWidth/2-1;y=LayerHeight/2-1;count=0;flag=0;
    		while(count<LayerLength){
    			Res[-y+GridHeight/2-1][x+GridWidth/2]=ArrayToStoreLayer[(LayerLength-rotk+count)%(LayerLength)];
    			count++;
    			if(x==LayerWidth/2-1 && y==LayerHeight/2-1){
    				flag=0;
    			}
    			else if(x==LayerWidth/2-1 && y==-LayerHeight/2){
    				flag=3;
    			}
    			else if(x==-LayerWidth/2 && y==LayerHeight/2-1){
    				flag=1;
    			}
    			else if(x==-LayerWidth/2 && y==-LayerHeight/2){
    				flag=2;
    			}
    			if(flag==0){
    				x--;
    			}
    			else if(flag==1){
    				y--;
    			}
    			else if(flag==2){
    				x++;
    			}
    			else if(flag==3){
    				y++;
    			}
    		}
    		ArrayToStoreLayer.clear();
    	}
    	
    	return Res;

    }
};
int main(){
	Solution mysol;
	// vector<vector<int>> grid;
	// grid.push_back(vector<int>{40,10});
	// grid.push_back(vector<int>{30,20});
	vector<vector<int>> grid;
	grid.push_back(vector<int>{1,2,3,4});
	grid.push_back(vector<int>{16,1,2,5});
	grid.push_back(vector<int>{15,8,3,6});
	grid.push_back(vector<int>{14,7,4,7});
	grid.push_back(vector<int>{13,6,5,8});
	grid.push_back(vector<int>{12,11,10,9});
    vector<vector<int>> res=mysol.rotateGrid(grid,1);
    for(const auto &c:res){
    	for(const auto &d:c){
    		cout<<d<<" ";
    	}
    	cout<<endl;
    }
	//cout<<mysol.makeEqual(words)<<endl;
}