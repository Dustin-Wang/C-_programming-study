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
    bool findRotation(vector<vector<int>>& SquareMatrix, vector<vector<int>>& Target) {
        int SquareMatrixLength=SquareMatrix.size();
        bool ClockwiseZero=true;
        bool ClockwiseNinety=true;
        bool ClockwiseOneHundredEighty=true;
        bool ClockwiseTwoHundredSeventy=true;
        for(int i=0;i<SquareMatrixLength;i++){
            for(int j=0;j<SquareMatrixLength;j++){
                if(SquareMatrix[i][j]!=Target[i][j]){
                    ClockwiseZero=false;
                    break;
                }
            }
        }
        for(int i=0;i<SquareMatrixLength;i++){
            for(int j=0;j<SquareMatrixLength;j++){
                if(SquareMatrix[i][j]!=Target[j][SquareMatrixLength-1-i]){
                    ClockwiseNinety=false;
                    break;
                }
            }
        }
        for(int i=0;i<SquareMatrixLength;i++){
            for(int j=0;j<SquareMatrixLength;j++){
                if(SquareMatrix[i][j]!=Target[SquareMatrixLength-1-i][SquareMatrixLength-1-j]){
                    ClockwiseOneHundredEighty=false;
                    break;
                }
            }
        }
        for(int i=0;i<SquareMatrixLength;i++){
            for(int j=0;j<SquareMatrixLength;j++){
                if(SquareMatrix[i][j]!=Target[SquareMatrixLength-1-j][i]){
                    ClockwiseTwoHundredSeventy=false;
                    break;
                }
            }
        }
        return (ClockwiseZero||ClockwiseNinety||ClockwiseTwoHundredSeventy||ClockwiseOneHundredEighty);
    }
};
int main(){
	Solution mysol;
	string n="962942516613939";
	int x=3;
	string res=mysol.maxValue(n,x);
	cout<<res<<endl;
	return 0;
	
}