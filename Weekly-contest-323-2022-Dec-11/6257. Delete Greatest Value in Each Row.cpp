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


You are given an m x n matrix grid consisting of positive integers.

Perform the following operation until grid becomes empty:

    Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
    Add the maximum of deleted elements to the answer.

Note that the number of columns decreases by one after each operation.

Return the answer after performing the operations described above.

 

Example 1:

Input: grid = [[1,2,4],[3,3,1]]
Output: 8
Explanation: The diagram above shows the removed values in each step.
- In the first operation, we remove 4 from the first row and 3 from the second row (notice that, there are two cells with value 3 and we can remove any of them). We add 4 to the answer.
- In the second operation, we remove 2 from the first row and 3 from the second row. We add 3 to the answer.
- In the third operation, we remove 1 from the first row and 1 from the second row. We add 1 to the answer.
The final answer = 4 + 3 + 1 = 8.

Example 2:

Input: grid = [[10]]
Output: 10
Explanation: The diagram above shows the removed values in each step.
- In the first operation, we remove 10 from the first row. We add 10 to the answer.
The final answer = 10.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    1 <= grid[i][j] <= 100


 
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

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
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


ListNode* VectorToLinkedList(vector<int> input){
	int VectorLength = input.size();
	if(VectorLength ==0 ){
		return(nullptr);
	}
	ListNode* res= new ListNode(input[0]);
	ListNode* tmp = res;
	for(int i=1; i< VectorLength; i++){
		tmp->next = new ListNode(input[i]);
		tmp = tmp->next;
	}
	return(res);
}

void printLinkedList(ListNode* input){
	ListNode* tmp = input;
	while(tmp!=nullptr){
		printf("%d ", tmp->val);

		tmp = tmp->next;
	}
	fflush(stdout);
}
//we know that gcd(a,b)=ax+by for some x and y, here we try to keep track of the x and y
int gcd(int a, int b, int &x, int &y){
	if(b==0){
		x=1;
		y=0;
		return(a);
	}
	else{
		int c = a/b;
		int res = gcd(b,a%b, x, y);
		int tmp = x;
		x=y;
		y=tmp-c*y;
		return(res);
	}
}

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
    	vector<vector<int>> RowSortedGrid;
        for(auto &row:grid){
        	sort(row.begin(), row.end() );
        	RowSortedGrid.push_back(row);
        	// printvector(row);
        }
        int RowNos = grid.size();
        int ColNos = grid[0].size();
        int res = 0;
        int Max = 0;
        for(int j=ColNos-1; j>=0; j--){
        	Max = 0;
        	for(int i=0;i<RowNos; i++){
        		if(RowSortedGrid[i][j]>Max)
        			Max = grid[i][j];
        	}
        	// printf("Max: %d\n", Max );
        	res = res+Max;
        }
        return(res);

    
    }
    
private:
	int score;
	void DFS(int root, int NoOfCities, vector<vector<pair<int,int>>>& Neighbors, vector<int>& CitiesVisited){
        CitiesVisited[root]=1;
        for(const auto &i:Neighbors[root])
        {
        	int City=i.first;//the neighbor
        	int RoadDistance = i.second;//this is the weight assigned to this edge.
        	if(RoadDistance<score)
        		score = RoadDistance;
        	if(CitiesVisited[City]==0)
        	{
        		DFS(City, NoOfCities, Neighbors, CitiesVisited);
        	}	
        }
        CitiesVisited[root]=2;
        return;
    }
	int LargePrime = pow(10,9)+7;

	int IsPrime(char c)
	{
		if( c == '2' || c == '3' || c == '5' || c == '7' )
			return(1);
		else
			return(0);
	}
	
	vector<queue<TreeNode*>> TreeBFS(TreeNode* root){
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
	//CitiesColor should be initlized to all 2 vector.
	//MinimumDistance == 501 means that this node is not accessible 
	//minimumDistance is the distance between root and the current node
	//notice that this func will not go over whole graph unless the graph is connected.
	int BFS_Bipartite_Check(int root, int NoOfCities, vector<vector<int>>& Neighbors, vector<int>& MinimumDistanceFromRoot, int& MaximumDistance, vector<int>& CitiesVisited){
		queue<int> q1;
		q1.push(root);
		MinimumDistanceFromRoot[root]=0;//root to root distance is 0;
		
		do{
			queue<int> q2;
			while(!q1.empty()){
				int s= q1.front();
				
				q1.pop();
				for(auto &sNext:Neighbors[s]){
					CitiesVisited[sNext]=CitiesVisited[s];
					if(MinimumDistanceFromRoot[sNext]==501){//this means that this not has not yet been visited
						MinimumDistanceFromRoot[sNext] = MinimumDistanceFromRoot[s]+1; 
						if(MinimumDistanceFromRoot[sNext]>MaximumDistance)
							MaximumDistance = MinimumDistanceFromRoot[sNext];
						q2.push(sNext);	
					}
					if(MinimumDistanceFromRoot[sNext]%2 == MinimumDistanceFromRoot[s]%2){
						return(0);//this means that it is not a  bipartite graph
					}
				}
			}
			q1=q2;	
		}while(!q1.empty());
		return(1);
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
	int input[][3] = {{1,2,4},{3,3,1}};
	vector<vector<int>> grid = ArrayTo2dVector(input);
	cout<<mysol.deleteGreatestValue(grid)<<endl;
 	return(0);	
}