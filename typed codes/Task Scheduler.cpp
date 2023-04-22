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
#include <unordered_map>
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
    
    int leastInterval(vector<char>& tasks, int k) {
        
        map <int,int> mp;
        int n = tasks.size();
        int number_of_cycles = 0;
        
        // the approach employed here is to find the maximum number of cycles(m) of atleast length k
        // (which is the minimum distance between two same executions). The length of first (m-1)
        // cycles have to be fixed but the last cycle's length may vary, as the last cycle will always contain
        // the processes that require maximum number of cycles. Therefore, assuming the final length to be 
        // 'ans', we have to add 1 to the length as and when we encounter the number_of_cycles required for
        // a process to be equal to the maximum number_of_cycles.
        
        for(int i=0;i<n;i++)
        {
            mp[tasks[i] - 'A'] += 1;
            number_of_cycles = max(number_of_cycles,mp[tasks[i] - 'A']);
        }
        
        int ans = (number_of_cycles - 1) * (k+1); // minimum length required to complete (m-1) cycles
        
        for(auto it : mp)
        {
            if(it.second == number_of_cycles)
                ans += 1;
        }
        
        ans = max(ans,n);
        return ans;
        
    }
};


int main(){
	Solution* m=new Solution();
	vector<char> tasks{'A','A','A','A','A','A'};
	int n=2;
	cout<<m->leastInterval(tasks,n)<<endl;
}
