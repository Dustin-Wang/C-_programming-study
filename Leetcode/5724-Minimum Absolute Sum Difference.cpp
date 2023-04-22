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

int mod=1e9+7;
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> absoluteDiffPartialSum(n,0);
        absoluteDiffPartialSum[0]=abs(nums1[0]-nums2[0])%mod;
        for(int i=1;i<n;i++){
            absoluteDiffPartialSum[i]=(absoluteDiffPartialSum[i-1]+abs(nums1[i]-nums2[i])%mod)%mod;
        }
        
        vector<int> sortednums1(nums1);
        sort(all(sortednums1));
        vector<int> closestToNums2(n,0);
        for(int i=0;i<n;i++){
            int tmp=binarySearch(sortednums1,0,n-1,nums2[i]);
            if(tmp==0){
                closestToNums2[i]=0;
            }
            else if(tmp==n){

            }

        }

    }
private:
    int findInsertIndex(vector<int>& sortednums1, int key){
        int low=0;
        int high=sortednums1.size()-1;
        int mid=(low+high)/2;
        while (sortednums1[low]<n2){
            return binarySearch(sortednums1, mid+1, high, n2);
        }
        else if(sortednums1[mid]>n2){
            return binarySearch(sortednums1, low, mid-1, n2);
        }
        else
            return mid;
    }
    int minAbsoluteSumDiffShorter(vector<int>& nums1, vector<int>& nums2, vector<int>& absoluteDiffPartialSum, int n, int rep){
        int min=INT_MAX;
        int res=0;
        if(n==0){
            return 0;
        }
        if(rep==0){
            return absoluteDiffPartialSum[n-1];
        }
        if(nums1[n-1]==nums2[n-1]){
            return minAbsoluteSumDiffShorter(nums1,nums2,absoluteDiffPartialSum,n-1,1);
        }

    }
};
int main(){
    Solution* m=new Solution();
    // vector<vector<int>> logs;
    // logs.push_back(vector<int>{0,5});
    // logs.push_back(vector<int>{1,2});
    // logs.push_back(vector<int>{0,2});
    // logs.push_back(vector<int>{0,5});
    // logs.push_back(vector<int>{1,3});
    // vector<int> res=m->findingUsersActiveMinutes(logs,5);
    // for(auto const& c:res){
    // 	cout<<c<<endl;
    // }
}