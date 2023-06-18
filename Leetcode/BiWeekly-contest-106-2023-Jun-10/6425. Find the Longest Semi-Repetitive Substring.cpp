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
#include <iterator>

using namespace std;
// BEGIN NO SAD
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

// END NO SAD
// REMEMBER CLEAR GLOBAL STATE

// struct myclass{
// 	bool operator()(string a, string b){
// 		if(a.size()<b.size())
// 			return false;
// 		else if(a.size()>b.size())
// 			return true;
// 		else
// 			return(a>b);
// 	}
// } myobject;

/*

6425. Find the Longest Semi-Repetitive Substring


You are given a 0-indexed string s that consists of digits from 0 to 9.

A string t is called a semi-repetitive if there is at most one consecutive pair of the same digits inside t.

Return the length of the longest semi-repetitive substring inside s.

A substring is a contiguous non-empty sequence of characters within a string.

 

Example 1:

Input: s = "52233"
Output: 4
Explanation: The longest semi-repetitive substring is "5223", which starts at i = 0 and ends at j = 3. 

Example 2:

Input: s = "5494"
Output: 4
Explanation: s is a semi-reptitive string, so the answer is 4.

Example 3:

Input: s = "1111111"
Output: 2
Explanation: The longest semi-repetitive substring is "11", which starts at i = 0 and ends at j = 1.

 

Constraints:

    1 <= s.length <= 50
    '0' <= s[i] <= '9'


*/

template<typename T>
void printvector(vector<T> vector){
 //    int arraysize = array.size();
	// for(int k=0; k<arraysize; k++)
	// 	printf("%d  ",array[k]);
	// printf("size: %d\n",arraysize);
	copy(vector.begin(), vector.end(), std::ostream_iterator<T>(std::cout, " "));
	printf("\n");
	fflush(stdout);
};

 // * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void PrintQueueInIntBinaryTree(queue<TreeNode*> queue){
    int queuesize = queue.size();
	while(!queue.empty())
	{
		auto it = queue.front();
		if(it!=nullptr)
			printf("%d  ",it->val);
		queue.pop();
	}
	printf("queue size: %d\n",queuesize);
	fflush(stdout);
};

TreeNode* ArrayToBinaryTree(vector<string> input){
	int length = input.size();
	int depth = ceil(log2(double(length)));
	//fill in the extra nullptr leaves in the given input
	for(int i = length; i< pow(2, depth)-1; i++)
	{
		input.push_back("null");
	}

	printvector(input);
	TreeNode* root = new TreeNode(stoi(input[0]));
	queue<TreeNode*> prevLevel;
	prevLevel.push(root);
	int index = 1;
	for(int k = 1; k<depth; k++)
	{
		queue<TreeNode*> NextLevel;
		PrintQueueInIntBinaryTree(prevLevel);
		while(!prevLevel.empty())
		{
			TreeNode* s = prevLevel.front();
			prevLevel.pop();
			
			if(s == nullptr)
			{
				index +=2;
				NextLevel.push(nullptr);
				NextLevel.push(nullptr);
				continue;
			};
			
			if(input[index] == "null")
			{
				s->left = nullptr;
				NextLevel.push(s->left);
			}
			else
			{
				s->left = new TreeNode(stoi(input[index]));
				NextLevel.push(s->left);
			};
			index++;
			// PrintQueueInIntBinaryTree(NextLevel);
			if(input[index] == "null")
			{
				s->right = nullptr;
				NextLevel.push(s->right);
			}
			else
			{
				s->right = new TreeNode(stoi(input[index]));
				NextLevel.push(s->right);
			};
			index++;
			// PrintQueueInIntBinaryTree(NextLevel);
		}
		// PrintQueueInIntBinaryTree(NextLevel);
		prevLevel = NextLevel;
		printf("k: %d\n", k);
		fflush(stdout);
	}

	return(root);
}


class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int sLen = s.size();
        int LastRepetive = -1;
        int Repetive = 0;
        vector<int> RepetiveStart;
        vector<int> RepetiveEnd;
        for(int i=1; i<sLen; i++)
		{
			Repetive = 0;
			while(i<sLen && s[i]==s[i-1]){
				Repetive++;
				i++;
			}
			if(Repetive>0)
			{
				RepetiveEnd.push_back(i-1);
				RepetiveStart.push_back(i-Repetive-1);	
			}
		}   
		printvector(RepetiveStart);
		printvector(RepetiveEnd);
		int NoRepetives = RepetiveStart.size(); 
		if(NoRepetives==0)
			return(sLen);
		int res = 0;
		int Start = 0;
		int End = 0;
		int PrevEnd = 0;
		int NextStart = 0;
		for(int i=0; i< NoRepetives; i++)
		{
		 	Start = RepetiveStart[i];
		 	End = RepetiveEnd[i];
		 	if(End - Start +1 == 2)
		 	{
		 		if(i-1>=0)
			 		PrevEnd = RepetiveEnd[i-1];
			 	else
			 		PrevEnd = 0;

		 		if(i+1<NoRepetives)
		 			NextStart = RepetiveStart[i+1];
		 		else
		 			NextStart = sLen-1;

		 		res = max(res, NextStart-PrevEnd+1);
		 	}
		 	else
		 	{
				if(i-1>=0)
			 		PrevEnd = RepetiveEnd[i-1];
			 	else
			 		PrevEnd = 0;
			 	res = max(res, Start-PrevEnd+2);
				if(i+1<NoRepetives)
		 			NextStart = RepetiveStart[i+1];
		 		else
		 			NextStart = sLen-1;
		 		res = max(res, NextStart - End +2);			 			 		
		 	}
						 	
		}    	
		return(res);
    }
    
private:
	
	vector<queue<TreeNode*>> BFS(TreeNode* root){
        queue<TreeNode*> q1;
        // cout<<"Starting BFS\n"<<endl;
        // fflush(stdout);
        vector<queue<TreeNode*>> Res;
        q1.push(root);
        do{
            Res.push_back(q1);
            queue<TreeNode*> q2;
            while(!q1.empty()){
                TreeNode* s = q1.front();
                q1.pop();
                if(s->left != nullptr)
                    q2.push(s->left);
                if(s->right != nullptr)
                    q2.push(s->right);
            }
            q1 = q2;  
            // PrintQueueInIntBinaryTree(q1);
        }while(!q1.empty());
        return(Res);
    }
	
	long long fuels = 0;
	
	int DFS(int root, int NoOfCities, vector<vector<int>>& NeighborsOfCities, vector<int>& CitiesVisited, int seats){
        CitiesVisited[root]=1;
        int NoOfPplInThisCity = 1;
        for(const auto &i:NeighborsOfCities[root])
        {
        	if(CitiesVisited[i]==0)
        	{
        		NoOfPplInThisCity = NoOfPplInThisCity + DFS(i, NoOfCities, NeighborsOfCities, CitiesVisited, seats);
        	}	
        }
        CitiesVisited[root]=2;
        if(NoOfPplInThisCity%seats)
        	fuels = fuels + NoOfPplInThisCity/seats+1;
        else
        	fuels = fuels + NoOfPplInThisCity/seats;
        return(NoOfPplInThisCity);
    }


};
template <size_t rows, size_t cols>
vector<vector<int>> ArrayTo2dVector(int (&array)[rows][cols]){
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
	string s = "1111111";
	cout<<mysol.longestSemiRepetitiveSubstring(s)<<endl;
	return(0);
    
}