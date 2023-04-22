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
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int FirstAcheived=0;
        int SecondAchieved=0;
        int ThirdAchieved=0;
        for(const auto &e:triplets){
            if(e[0]>target[0] ||e[1]>target[1] ||e[2]>target[2]){
                continue;
            }
            else{
                FirstAcheived=FirstAcheived||(e[0]==target[0]);
                SecondAchieved=SecondAchieved||(e[1]==target[1]);
                ThirdAchieved=ThirdAchieved||(e[2]==target[2]);
            }
        }
        return FirstAcheived&&SecondAchieved&&ThirdAchieved;
    }
};
int main(){
	Solution mysol;
	vector<vector<int>> triplets;
    // triplets.push_back(vector<int>{2,5,4});
    // triplets.push_back(vector<int>{1,8,4});
    // triplets.push_back(vector<int>{1,7,5});
    // vector<int> target{2,7,5};
    // triplets.push_back(vector<int>{2,5,3});
    // triplets.push_back(vector<int>{1,8,4});
    // triplets.push_back(vector<int>{1,7,5});
    // vector<int> target{2,7,5};
    // triplets.push_back(vector<int>{1,3,4});
    // triplets.push_back(vector<int>{2,5,8});
    // vector<int> target{2,5,8};
    // triplets.push_back(vector<int>{2,5,3});
    // triplets.push_back(vector<int>{2,3,4});
    // triplets.push_back(vector<int>{1,2,5});
    // triplets.push_back(vector<int>{5,2,3});
    // vector<int> target{5,5,5};
    triplets.push_back(vector<int>{3,5,1});
    triplets.push_back(vector<int>{10,5,7});
    vector<int> target{3,5,7};
    cout<<mysol.mergeTriplets(triplets,target)<<endl;
	//cout<<mysol.makeEqual(words)<<endl;
}