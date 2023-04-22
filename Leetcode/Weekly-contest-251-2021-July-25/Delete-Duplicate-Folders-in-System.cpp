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
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int NoOfPairs=students.size();
        int NoOfQuestions=students[0].size();
        vector<vector<int>> CompatilityScore;
        for(int i=0;i<NoOfPairs;i++){
        	CompatilityScore.push_back(vector<int>(NoOfPairs,0));
        	for(int j=0;j<NoOfPairs;j++){
        		int Score=0;
        		for(int k=0;k<NoOfQuestions;k++){
        			if(students[i][k]==mentors[j][k]){
        				Score++;
        			}
        		}
        		CompatilityScore[i][j]=Score;
        	}
        }
        //now it becomes a problem on a square table of length 
        //NoOfPairs crossing NoOfPairs
        //each row pick one, and their column index is different
        //how to maximize the sum
        //this becomes dynamic programming?

        vector<int> ColOccupied(NoOfPairs,0);
        int maxScore=-1;
        DFS(0,NoOfPairs,0,maxScore, CompatilityScore, ColOccupied);
        return maxScore;


    }
private:
	void DFS(int row, int NoOfPairs, int Score, int& maxScore,
	 vector<vector<int>>& CompatilityScore,
	 vector<int>& ColOccupied){
		if(row==NoOfPairs){
			if(Score>maxScore){
				maxScore=Score;
			}
		}
		for(int col=0;col<NoOfPairs;col++){
			if(ColOccupied[col])
				continue;
			ColOccupied[col]=1;
			DFS(row+1,NoOfPairs,Score+CompatilityScore[row][col]
				,maxScore, CompatilityScore, ColOccupied);
			ColOccupied[col]=0;
		}
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
   	//int students[][3]={{1,1,0},{1,0,1},{0,0,1}}; vector<vector<int>> Stu=ArrayTo2dVector(students);
   	//int mentors[][3]={{1,0,0},{0,0,1},{1,1,0}}; vector<vector<int>> Men=ArrayTo2dVector(mentors);
   	int students[][2]={{0,0},{0,0},{0,0}}; vector<vector<int>> Stu=ArrayTo2dVector(students);
   	int mentors[][3]={{1,1},{1,1},{1,1}}; vector<vector<int>> Men=ArrayTo2dVector(mentors);
    cout<<mysol.maxCompatibilitySum(Stu, Men)<<endl;
	
}