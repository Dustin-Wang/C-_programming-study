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
    int reductionOperations(vector<int>& Nums) {
        map<int,int> CounterForNoOfSameIntegers;//It should be ordered map based on the Key in ascending order by default
        for(const auto&c:Nums){
            if(CounterForNoOfSameIntegers.find(c)==CounterForNoOfSameIntegers.end()){
                CounterForNoOfSameIntegers[c]=1;//first time appear in the CounterForNoOfSameIntegers
            }
            else{
                CounterForNoOfSameIntegers[c]++;
            }
        }
        int NoOfReductionOperations=0;
        int NoOfNums=Nums.size();
        int PartialSumFromSmallestInteger=0;
        for(const auto&c:CounterForNoOfSameIntegers){
            NoOfReductionOperations+=NoOfNums-c.second-PartialSumFromSmallestInteger;
            PartialSumFromSmallestInteger+=c.second;
        }
        return NoOfReductionOperations;

    }
};
int main(){
	Solution mysol;
	//vector<int> Nums{5,1,3};
	//vector<int> Nums{1,1,1};
    vector<int> Nums{1,1,2,2,3};
    int res=mysol.reductionOperations(Nums);
	cout<<res<<endl;
	return 0;
	
}