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
    bool canArrange(vector<int>& arr, int k) {
        vi counter(k+1,0);
        int i=0;
        for(i=0;i<sz(arr);i++)
        	if (arr[i]%k>=0){
        		//cout<<arr[i]%k<<" ";
        	   counter[arr[i]%k]++;
        	}
        	else{
        		//cout<<arr[i]%k+k<<" ";
        	    counter[arr[i]%k+k]++;
        	}
        //cout<<endl;
        /*for (auto const& i:counter)
        	cout<<i<<" ";*/
        if (counter[0]%2!=0)
        	return false;
        for(int i=1;i<=k/2;i++)
        	if (i!=k-i && counter[i]!=counter[k-i])
        		return false;
        if (k%2==0 && counter[k/2]%2!=0)
        	return false;
        return true;
    }
};

int main(){
	vi arr={-1,1,-2,2,-3,3,-4,4};
	Solution mysol;
	cout<<mysol.canArrange(arr,3);
    int i=0;
    for(i=0;i<=3;i++)
        cout<<i;
}