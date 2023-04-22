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
    int numberOfRounds(string startTime, string finishTime) {
        int startHour=stoi(startTime.substr(0,2));
        int finishHour=stoi(finishTime.substr(0,2));
        int startMinutes=stoi(startTime.substr(3,2));
        int finishMinutes=stoi(finishTime.substr(3,2));
        int res=0;
        if(startTime.compare(finishTime)<0){
            res=(finishHour-startHour-1)*4+finishMinutes/15+(60-startMinutes)/15;
        }
        else{
            //cout<<"here"<<endl;
            res=(finishHour+23-startHour)*4+finishMinutes/15+(60-startMinutes)/15;
        }
        return res;
    }
};

int main(){
	Solution mysol;
	string startTime = "12:01";string finishTime = "12:44";
    //string startTime = "20:00";string finishTime = "06:00";
    //string startTime = "00:00";string finishTime = "23:59";
    cout<<mysol.numberOfRounds(startTime,finishTime)<<endl;
	//cout<<mysol.makeEqual(words)<<endl;
}