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
#include <unordered_map>
#include <unordered_set>
#include <climits>

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
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    	int Height = mat.size();
    	int Width = mat[0].size();
    	int minSum = 0;
		unordered_set<int> PossibleSum = {0};
		for(int i = 0; i < Height; i++){
			unordered_set<int> NextPossibleSum = {};
			int minSumLargerThanTargetAtThisRow = 70*i+1;
			for(const auto & c : PossibleSum){
				if( c< target  ){
					for(int j = 0; j< Width; j++){
						NextPossibleSum.insert(c + mat[i][j]);
						// cout<<c+mat[i][j]<<" "<<endl;
					}
				}
				else{
					minSumLargerThanTargetAtThisRow = min(minSumLargerThanTargetAtThisRow, c);
				}
			}
			if(minSumLargerThanTargetAtThisRow != 70*i+1){
				int minElementInRow = 71;
				for(int j = 0; j< Width; j++){
					minElementInRow = min(minElementInRow, mat[i][j]);
					// cout<<c+mat[i][j]<<" "<<endl;
				}
				NextPossibleSum.insert(minSumLargerThanTargetAtThisRow + minElementInRow);
			}
			PossibleSum = NextPossibleSum;
		}
		// vector<int> PossibleSumOrdered(PossibleSum.begin(),PossibleSum.end());
		// int NoOfPossibleSums = PossibleSumOrdered.size();
		// sort(PossibleSumOrdered.begin(),PossibleSumOrdered.end());

		// // for(const auto &c : PossibleSum)
		// // 	cout<<c<<" "<<endl;

		// int lb = 0;
		// int ub = NoOfPossibleSums - 1;
		// while(lb <= ub){
		// 	int mid = (lb + ub )/2;
		// 	if(PossibleSumOrdered[mid]<target)
		// 		lb = mid+1;
		// 	else if(PossibleSumOrdered[mid]>target)
		// 		ub = mid-1;
		// 	else
		// 		return 0;
		// }

		// if(ub == -1)
		// 	return PossibleSumOrdered[0]-target;
		// if(ub == NoOfPossibleSums -1)
		// 	return target - PossibleSumOrdered[NoOfPossibleSums-1];
		// int a = target - PossibleSumOrdered[ub];
		// int b = PossibleSumOrdered[ub+1]-target;
		// return min(a,b); 

		int res = 5000;
		for(const auto &c : PossibleSum){
			res = min(res, abs(c-target));
		}
		return res;

		
    }
};

template <size_t rows, size_t cols>
vector<vector<int>> ArrayTo2dVector(int (&array)[rows][cols])
{
    vector<vector<int>> res;
    for (size_t i = 0; i < rows; ++i)
    {
        vector<int> row;
        for (size_t j = 0; j < cols; ++j)
            row.push_back(array[i][j]);
        res.push_back(row);
    }
    return res;
};
int main(){
	Solution mysol;
    // int array[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> mat = ArrayTo2dVector(array);
    // int target = 13;

    // int array[3][3]= {{1},{2},{3}};
    // vector<vector<int>> mat = ArrayTo2dVector(array);
    // int target = 100;

    //  int array[1][5]= {{1,2,9,8,7}};
    // vector<vector<int>> mat = ArrayTo2dVector(array);
    // int target = 6;
 //    int array[][10]= {{10,3,7,7,9,6,9,8,9,5},{1,1,6,8,6,7,7,9,3,9},{3,4,4,1,3,6,3,3,9,9},{6,9,9,3,8,7,9,6,10,6}};
 //    vector<vector<int>> mat = ArrayTo2dVector(array);
	// int target = 100;
    int array[][39] ={{24,18,31,34,31,47,47,27,32,44,19,26,15,11,32,39,17,36,28,45,44,45,6,38,47,37,7,5,23,12,35,10,27,5,6,44,42,3,9},{19,25,15,46,43,44,22,29,12,34,19,8,10,35,49,28,7,22,34,16,46,33,17,11,11,30,46,16,26,23,49,37,47,10,30,29,47,2,39},{25,48,12,26,33,4,31,18,26,17,46,47,27,46,42,31,24,36,22,46,48,43,6,49,47,15,35,40,13,26,43,25,41,1,21,30,34,46,30},{42,12,7,2,26,14,47,37,39,25,14,7,25,36,50,13,18,48,38,38,13,32,40,9,1,40,44,28,31,17,33,37,12,30,46,14,49,5,23},{1,32,35,43,43,5,49,38,32,44,22,30,18,33,30,2,6,40,49,23,12,49,49,26,17,44,41,47,9,4,11,32,25,30,44,19,10,1,19},{36,30,1,24,3,35,25,37,29,14,44,20,32,42,9,31,45,35,46,20,5,17,21,20,22,42,20,42,42,26,34,6,33,41,14,26,39,34,10},{33,41,6,20,3,15,30,36,15,34,18,4,8,8,44,25,24,14,21,23,5,22,30,24,11,32,29,19,30,9,46,29,41,14,18,21,11,7,16},{31,13,49,44,24,12,23,9,9,15,18,36,41,25,26,48,22,18,47,39,33,38,45,47,21,48,26,49,46,46,41,49,46,19,35,40,41,43,5},{24,20,26,31,12,17,23,29,31,6,12,21,25,9,2,7,23,11,23,5,47,49,42,28,1,35,21,16,39,25,35,19,31,41,10,24,21,13,32},{7,10,14,22,17,10,27,24,17,6,22,13,16,46,16,47,40,3,22,24,42,50,40,4,10,12,5,28,29,50,18,9,21,34,37,8,22,42,50},{46,40,26,15,4,26,50,31,32,40,21,35,40,39,6,38,33,35,43,32,26,45,30,11,27,25,34,29,3,7,29,38,9,8,44,33,12,5,26},{20,30,46,1,17,7,43,23,15,12,2,10,28,43,6,22,42,30,4,31,16,5,31,9,36,2,9,45,33,35,4,4,13,35,1,34,22,44,34},{16,9,24,32,1,9,35,8,16,7,30,14,4,40,14,41,25,22,40,42,26,46,34,33,50,44,11,33,7,10,41,14,12,25,13,20,22,28,10},{28,9,26,21,20,7,36,7,31,18,19,34,49,32,18,15,27,45,9,45,36,43,7,2,39,36,49,13,14,13,26,38,3,42,9,41,2,48,17},{45,47,31,35,4,48,50,15,10,39,21,3,45,13,7,9,41,45,35,12,49,6,44,30,41,19,14,11,21,45,18,34,37,5,27,27,43,47,3},{30,20,43,8,41,45,47,18,2,14,27,22,17,35,47,26,38,34,48,13,28,50,9,45,11,29,30,23,25,31,40,17,40,13,38,31,29,13,49},{31,37,22,20,5,11,24,39,41,31,15,50,40,42,43,37,9,44,20,14,35,20,7,1,2,13,21,4,21,35,17,47,43,22,29,5,27,31,46},{2,19,38,37,9,14,10,11,39,50,25,47,5,41,38,29,18,42,6,32,31,16,10,37,20,15,13,40,46,22,38,40,45,26,34,27,16,42,14},{36,4,17,43,16,9,40,47,26,28,8,30,26,26,31,25,19,14,16,15,4,35,34,6,39,35,44,1,4,25,46,28,26,15,33,18,7,24,33},{24,34,32,38,5,46,30,48,45,15,18,2,2,31,3,9,42,10,14,21,16,35,4,40,10,42,19,49,7,42,36,35,6,44,43,9,28,46,9},{3,20,33,43,18,31,4,36,23,49,22,44,7,39,24,7,39,23,24,41,18,31,19,33,39,10,2,3,22,28,41,1,23,44,35,46,4,43,5},{45,35,33,40,50,28,28,27,16,12,11,40,3,2,38,49,47,23,44,12,19,2,3,16,37,15,26,5,24,8,39,5,16,15,36,13,7,1,45},{26,6,33,18,38,42,15,4,34,34,34,26,28,9,10,28,9,30,48,24,4,37,12,34,29,28,39,42,29,11,32,39,9,23,10,2,17,46,12},{10,41,27,37,41,17,29,31,30,13,28,28,18,50,15,23,49,41,3,26,40,2,28,20,2,36,31,37,17,44,18,16,30,46,30,24,34,40,30},{43,16,36,35,11,30,19,49,24,27,8,33,44,16,48,42,43,25,8,28,39,30,40,34,30,6,48,25,29,40,50,46,45,48,24,36,23,11,10},{15,43,42,12,27,29,32,46,47,12,27,17,21,37,26,20,42,46,17,43,21,43,1,26,38,3,14,30,7,8,1,24,21,39,21,47,26,12,48},{21,6,34,39,31,26,40,16,29,7,39,2,23,2,20,32,9,46,46,4,1,22,26,31,42,40,1,31,41,37,14,15,48,40,21,11,22,20,50},{26,37,39,47,32,30,49,18,6,33,14,37,24,16,24,24,12,16,35,42,47,40,15,14,38,30,16,26,18,38,14,33,11,1,26,50,31,48,24},{42,12,44,13,47,45,39,12,32,40,1,47,9,14,46,14,1,40,6,30,50,41,13,48,12,18,26,40,2,1,24,8,20,3,37,24,31,25,8},{5,30,12,10,50,30,42,5,18,10,31,35,5,34,46,19,19,2,36,36,14,5,27,9,12,38,20,30,13,3,45,22,30,4,10,15,40,23,41},{20,45,42,7,13,10,15,2,21,8,18,7,24,50,5,33,46,40,9,23,9,28,47,48,13,20,36,49,2,49,2,22,41,10,47,5,35,49,4},{9,48,32,27,44,23,31,43,19,20,5,41,10,48,8,1,6,10,23,46,10,20,50,37,44,35,9,6,15,37,47,50,48,15,22,6,12,43,28}};
   	int target = 145;
   	vector<vector<int>> mat = ArrayTo2dVector(array);
	cout<<mysol.minimizeTheDifference(mat, target)<<endl;
	
}