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
You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

    A path is a sequence of roads between two cities.
    It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
    The test cases are generated such that there is at least one path between 1 and n.

 

Example 1:

Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.

Example 2:

Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
Output: 2
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.

 

Constraints:

    2 <= n <= 10^5
    1 <= roads.length <= 105
    roads[i].length == 3
    1 <= ai, bi <= n
    ai != bi
    1 <= distancei <= 104
    There are no repeated edges.
    There is at least one path between 1 and n.
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
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> Neighbors;
        for(int i=0;i<n;i++){
        	Neighbors.push_back(vector<pair<int,int>>());
        }
        for(auto &road: roads){
        	int City1=road[0]-1;
        	int City2=road[1]-1;
        	int distance=road[2];
        	Neighbors[City1].push_back(pair<int,int>{City2,distance});
        	Neighbors[City2].push_back(pair<int,int>{City1,distance});
        	// printf("City1: %d; City2: %d; distance: %d\n", City1, City2, distance);
        	// fflush(stdout);
        }

        vector<int> CitiesVisited(n,0);
        score = 10001;
        
        DFS(0, n, Neighbors, CitiesVisited);
        return(score);
    }
    
private:
	int score;
	void DFS(int root, int NoOfCities, vector<vector<pair<int,int>>>& Neighbors, vector<int>& CitiesVisited){
        CitiesVisited[root]=1;
        for(const auto &i:Neighbors[root])
        {
        	int City=i.first;
        	int RoadDistance = i.second;
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
	int n = 4;
	vector<vector<int>> roads;
	roads.push_back(vector<int>{1,2,9});
	roads.push_back(vector<int>{2,3,6});
	roads.push_back(vector<int>{2,4,5});
	roads.push_back(vector<int>{1,4,7});
	cout<<mysol.minScore(n,roads)<<endl;
	return(0);
    
}