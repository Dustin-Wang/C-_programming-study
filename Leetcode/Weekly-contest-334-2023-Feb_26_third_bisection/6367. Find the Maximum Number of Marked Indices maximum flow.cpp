#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <list>
#include <map>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <vector>


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
6367. Find the Maximum Number of Marked Indices
You are given a 0-indexed integer array nums.

Initially, all of the indices are unmarked. You are allowed to make this operation any number of times:

    Pick two different unmarked indices i and j such that 2 * nums[i] <= nums[j], then mark i and j.

Return the maximum possible number of marked indices in nums using the above operation any number of times.
Example 1:

Input: nums = [3,5,2,4]
Output: 2
Explanation: In the first operation: pick i = 2 and j = 1, the operation is allowed because 2 * nums[2] <= nums[1]. Then mark index 2 and 1.
It can be shown that there's no other valid operation so the answer is 2.

Example 2:

Input: nums = [9,2,5,4]
Output: 4
Explanation: In the first operation: pick i = 3 and j = 0, the operation is allowed because 2 * nums[3] <= nums[0]. Then mark index 3 and 0.
In the second operation: pick i = 1 and j = 2, the operation is allowed because 2 * nums[1] <= nums[2]. Then mark index 1 and 2.
Since there is no other operation, the answer is 4.

Example 3:

Input: nums = [7,6,8]
Output: 0
Explanation: There is no valid operation to do, so the answer is 0.

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 109

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
 
template<typename Q>
void print_queue(Q q) {
    // NB: q is passed by value because there is no way to traverse
    // priority_queue's content without erasing the queue.
    while(!q.empty()){
        auto x = q.top();
        printf("(%d,%d) ", x.first, x.second);
        q.pop();
    }
    cout<<"\n";
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


bool comparePairs(const pair<int,vector<int>>& lhs, const pair<int,vector<int>>& rhs)
{
	return (lhs.first < rhs.first);
}




struct CompareFuncWithParams{
    explicit CompareFuncWithParams(vector<vector<int>> grid_) 
    : grid(grid_) {}

    bool operator ()(const pair<int,int>& a, const pair<int,int>& b) const {
        return (grid[a.first][a.second]>grid[b.first][b.second]);
    }
    vector<vector<int>> grid;
};

typedef priority_queue<pair<int,int>, vector<pair<int,int>>, CompareFuncWithParams> myPriorityQueue;

int quick_pow10(int n)
{
	static int pow10[10]={
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 1000000000
    };
    return pow10[n];
}
int LargePrime = pow(10,9)+7;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int numsLen = nums.size();
        //collect all possible pairs
        vector<vector<int>> Neighbors(numsLen,vector<int>());//well we construct a bipartite graph here.
        //now the key is to find the maximum bipartite matching, which is essentially a max flow issue
        //assuming that we have source node on the left of all left bipartite
        // and target node on the right of all right bipartitie
        // unsigned long long count = 0;
        map<vector<int>,int> EdgesBetweenPartitieInvertible;
        vector<int> LeftNodesUsed(numsLen,2);
        vector<int> RightNodesUsed(numsLen, 2);
        for(int i=0; i< numsLen; i++){
        	// int thisIConnnectedToTarget = 0;
        	for(int j=i+1; j< numsLen; j++){
        		if(2* nums[i] <= nums[j] || 2*nums[j]<= nums[i]){
        			//this means i on the left is connected to j on the right, also means j is connected to i on the right
        			//j on the left is connected to i on the right.
        			Neighbors[i].push_back(j);
        			// Neighbors[j+numsLen].push_back(i);
        			vector<int> key1{i, j};
        			EdgesBetweenPartitieInvertible[key1] = 0;
        			Neighbors[j].push_back(i);
        			// Neighbors[i+numsLen].push_back(j);
        			vector<int> key2{j, i};
        			EdgesBetweenPartitieInvertible[key2] = 0;
        			// thisIConnnectedToTarget = 1;
        			LeftNodesUsed[i] = 0;//candidate for flows
        			RightNodesUsed[i] = 0;//candidate for flows
        			LeftNodesUsed[j] = 0;//candidate for flows
        			RightNodesUsed[j] = 0;//candidate for flows
        		}
        	}
        	// if(thisIConnnectedToTarget){
        		// Neighbors[2*numsLen].push_back(i);
        		// Neighbors[2*numsLen+1].push_back(i);

        	// }
        }
        // printf("hello\n");
        // fflush(stdout);
        // for(auto test:Neighbors)
        // 	printvector(test);
        // printvector(LeftNodesUsed);
        // printvector(RightNodesUsed);
        // printf("hello2\n");
        // fflush(stdout);

        int res = 0;
        //the key is to make any picked edge to be revertible, that is, can be unpicked.
        //that is, each time we use BFS to find the shortest path from 2*numsLen to 2*numsLen+1
        //notice that when we find the shortest path, we will first check whether the current node i on the left 
        //or node j+numslen on the right used or not
        for(int i=0; i< numsLen; i++)
        {
        	// printf("i:%d, start\n", i);
        	// fflush(stdout);
        	int temp = DFS_Bipartite_MaxFlow(i, Neighbors, LeftNodesUsed, RightNodesUsed, EdgesBetweenPartitieInvertible, 0);
        	// printf("i:%d, temp: %d\n", i, temp);
        	// fflush(stdout);
        	// printvector(LeftNodesUsed);
        	// printvector(RightNodesUsed);
        	if(temp )
        		res++;
        	
        }



        return(res);
    }
private:
	int DFS_Bipartite_MaxFlow(int Node, vector<vector<int>>& Neighbors, //here Left partite and right partite are both same 0, 1,..., numslen-1.
		vector<int>& LeftNodesUsed, vector<int>& RightNodesUsed, map<vector<int>,int>& EdgesBetweenPartitieInvertible, int LeftOrRight){
		//LeftOrRight even means that we are on the left, odd means that we are on the right.
		//return 1 means that this Node has a flow going to the target node on the right of the right bipartite
		if( LeftOrRight%2 == 0 )
		{
			// if(LeftNodesUsed[Node] !=0)//this node already used before, so return 0 means this is end
				// return(0);
			// else
			// {
				LeftNodesUsed[Node] = 1;//we mark this node as used
				//now we go to right;
				
				for(auto RightNode:Neighbors[Node])
				{
					vector<int> key{Node, RightNode};
					if(EdgesBetweenPartitieInvertible[key] == 1)
						continue;

					int res = DFS_Bipartite_MaxFlow(RightNode, Neighbors, LeftNodesUsed, RightNodesUsed, EdgesBetweenPartitieInvertible, LeftOrRight+1);
					if( res ){
						// printf("LeftOrRIght: %d we used LeftNode: %d RightNode: %d \n", LeftOrRight, Node, RightNode);
						// fflush(stdout);
						//if this rightnode can reach the target, then we mark this edge as invertible
						vector<int> key{Node, RightNode};
						EdgesBetweenPartitieInvertible[key]=1;
						return(1);
					}
				}//if no node reach target, then we are dead
				return(0);
			// }

		}
		else//that means we are on the right
		{
			if(RightNodesUsed[Node] == 0)//this node has not been used
			{
				RightNodesUsed[Node] = 1;
				// printf("we use RightNode 2: %d\n", Node);
				// fflush(stdout);
				return(1);//we reach target 
			}
			else//we turn left
			{
				// printf("we plan to turn left on the RightNode:%d\n", Node);
				for(auto LeftNode:Neighbors[Node])
				{
					vector<int> key{LeftNode, Node};
					// printf("LeftOrRIght: %d we are trying to check leftNode:%d, Node: %d\n", LeftOrRight, LeftNode, Node);
					// fflush(stdout);
					if(EdgesBetweenPartitieInvertible[key]==1)//we only revert previous covered edge to see whether our life become easier
					{
						// printf("LeftOrRIght: %d revert the edge LeftNode: %d, RightNode: %d\n", LeftOrRight, LeftNode, Node);
						// fflush(stdout);
						EdgesBetweenPartitieInvertible[key] = 0;
						int res = DFS_Bipartite_MaxFlow(LeftNode, Neighbors, LeftNodesUsed, RightNodesUsed, EdgesBetweenPartitieInvertible, LeftOrRight+1);
						if(res){
							//if turn left can reach the target, then we revert this edge
							
							// printf("we revert the edge LeftNode: %d, RightNode: %d\n", LeftNode, Node);
							// fflush(stdout);
							return(1);
						}
						else
						{
							EdgesBetweenPartitieInvertible[key] = 1;
						}
					}
				}
				return(0);
			}
		}

	}
	long long concate(int a, int b){
		long long res = 0;
		int digitsOfb = 0;
		vector<int> test ={1,10,100,1000,10000};
		for(int i=4; i>=0; i--){
			if(b/test[i]){
				digitsOfb = test[i]*10;
				break;
			}
				
		}
		res = res + a*digitsOfb + b;
		return(res);
	}
	int score;

    void DFSForMultipleQueryOnGrid(int startx, int starty, int m, int n, vector<vector<int>>& gridVisited, vector<int>& res,
             vector<int> SortedQueries, int NoQueries, vector<vector<int>>& grid, int ValidQueryIndex,
               CompareFuncWithParams& CompareFunc) 
    {
                // int (*func)(int, int)
        int k = ValidQueryIndex;
        printf("ValidQueryIndex: %d: querying: %d\n", ValidQueryIndex, SortedQueries[ValidQueryIndex]);
        printf("startx: %d; starty: %d\n", startx, starty);
        fflush(stdout);
        for(k=ValidQueryIndex;k<NoQueries;k++){
            if(SortedQueries[k]>grid[startx][starty])
            {
                ValidQueryIndex = k;
                break;
            }
        }
        if(k==NoQueries)
            return;
        for(k=ValidQueryIndex; k<NoQueries; k++){
            res[k]++;
        }
        gridVisited[startx][starty]=1;
        //now we need to find the next smallest box around this box that is not yet visited
        vector<pair<int,int>> Neighbors;
        if(startx-1>=0)
            Neighbors.push_back(pair<int,int>{startx-1, starty});
        if(startx+1<n)
            Neighbors.push_back(pair<int,int>{startx+1, starty});

        if(starty-1>=0)
            Neighbors.push_back(pair<int,int>{startx, starty-1});
        if(starty+1<m)
            Neighbors.push_back(pair<int,int>{startx, starty+1});

        sort(Neighbors.begin(), Neighbors.end(), CompareFunc);

        for(auto &Neighbor:Neighbors){
            int nextx=Neighbor.first;
            int nexty=Neighbor.second;
            if(gridVisited[nextx][nexty]==0)
                DFSForMultipleQueryOnGrid(nextx, nexty, m, n, gridVisited, res, SortedQueries, NoQueries, grid, ValidQueryIndex, CompareFunc);
        }
        gridVisited[startx][starty]=2;
    }

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
	// string word1 = "aabccc",  word2 = "bbbccc"; //1
	// string word1 = "aabccc", word2 = "cccca";//1
	// string word1 = "ab", word2 = "abcc";//0
	// string word1 = "aa", word2 = "ab";//0
	// int n = 3;
	// vector<vector<int>> score;
	// score.push_back(vector<int>{10,6,9,1});
	// score.push_back(vector<int>{7,5,11,2});
	// score.push_back(vector<int>{4,8,3,15});
	
	
	// string s = "101101";
	// int inputs[][2] = {{0,5},{1,2}};
	// string s = "111010110";
	// int inputs[][2] = {{4,2},{3,3},{6,4},{9,9},{10,28},{0,470},{5,83},{10,28},{8,15},{6,464},{0,3},{5,8},{7,7},{8,8},{6,208},{9,15},{2,2},{9,95}};
	// string s = "010011001001111100001111100001010010010100100";
	// int inputs[][2] = {{6,1315},{2,126},{8,14},{10,174},{4,10183},{7,252675362},{3,7945},{6,5021449},{8,63578},{9,26},{2,8142358},{1,5},{0,75715},{0,658},{1,3},{4,160},{10,174},{10,162868},{9,1565}};
	// int inputs[][2]={{7,252675362}};
	// string s= "0";
	// int inputs[][2]={{1,2},{2,3},{4,5}};
	// vector<vector<int>> queries = ArrayTo2dVector(inputs);
	// vector<vector<int>> res= mysol.substringXorQueries(s, queries);
	// for(int i=0; i<res.size(); i++){
	// 	printvector(res[i]);
	// }
  	// string word = "998244353";
  	// int m = 3;
  	// string word = "1010";
  	// int m = 10;
  	
  	// vector<int> nums{3,5,2,4};
  	// vector<int> nums{9,2,5,4};
  	// vector<int> nums{7,6,8};
  	vector<int> nums{1,78,27,48,14,86,79,68,77,20,57,21,18,67,5,51,70,85,47,56,22,79,41,8,39,81,59,74,14,45,49,15,10,28,16,77,22,65,8,36,79,94,44,80,72,8,96,78,39,92,69,55,9,44,26,76,40,77,16,69,40,64,12,48,66,7,59,10};
  	// vector<int> nums{1,78,27,48,14};
  	cout<<mysol.maxNumOfMarkedIndices(nums)<<endl;
 	return(0);	
}