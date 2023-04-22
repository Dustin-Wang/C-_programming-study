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
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    	int NoOfMonsters=dist.size();
    	vector<int> TimeToReachCity(NoOfMonsters,0);
    	for(int i=0;i<NoOfMonsters;i++){
    		if(dist[i]%speed[i]==0){
    			TimeToReachCity[i]=dist[i]/speed[i];
    		}
    		else{
    			TimeToReachCity[i]=dist[i]/speed[i]+1;
    		}
    	}
    	sort(TimeToReachCity.begin(),TimeToReachCity.end());
    	int count=0;
    	int Time=0;
    	while(count<NoOfMonsters && TimeToReachCity[count]>Time){
    		Time++;
    		count++;
    	}
    	return count;

        
    }
};
int main(){
	Solution mysol;
	//vector<int> dist{1,3,4};
	//vector<int> speed{1,1,1};
	//vector<int> dist{1,1,2,3};
	//vector<int> speed{1,1,1,1};
	vector<int> dist{3,2,4};
	vector<int> speed{5,3,2};
	cout<<mysol.eliminateMaximum(dist,speed)<<endl;
	
}