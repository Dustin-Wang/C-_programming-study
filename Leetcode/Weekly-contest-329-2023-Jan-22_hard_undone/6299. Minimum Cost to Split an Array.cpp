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
6299. Minimum Cost to Split an Array
You are given an integer array nums and an integer k.

Split the array into some number of non-empty subarrays. The cost of a split is the sum of the importance value of each subarray in the split.

Let trimmed(subarray) be the version of the subarray where all numbers which appear only once are removed.

    For example, trimmed([3,1,2,4,3,4]) = [3,4,3,4].

The importance value of a subarray is k + trimmed(subarray).length.

    For example, if a subarray is [1,2,3,3,3,4,4], then trimmed([1,2,3,3,3,4,4]) = [3,3,3,4,4].The importance value of this subarray will be k + 5.

Return the minimum possible cost of a split of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,1,2,1,3,3], k = 2
Output: 8
Explanation: We split nums to have two subarrays: [1,2], [1,2,1,3,3].
The importance value of [1,2] is 2 + (0) = 2.
The importance value of [1,2,1,3,3] is 2 + (2 + 2) = 6.
The cost of the split is 2 + 6 = 8. It can be shown that this is the minimum possible cost among all the possible splits.

Example 2:

Input: nums = [1,2,1,2,1], k = 2
Output: 6
Explanation: We split nums to have two subarrays: [1,2], [1,2,1].
The importance value of [1,2] is 2 + (0) = 2.
The importance value of [1,2,1] is 2 + (2) = 4.
The cost of the split is 2 + 4 = 6. It can be shown that this is the minimum possible cost among all the possible splits.

Example 3:

Input: nums = [1,2,1,2,1], k = 5
Output: 10
Explanation: We split nums to have one subarray: [1,2,1,2,1].
The importance value of [1,2,1,2,1] is 5 + (3 + 2) = 10.
The cost of the split is 10. It can be shown that this is the minimum possible cost among all the possible splits.

 

Constraints:

    1 <= nums.length <= 1000
    0 <= nums[i] < nums.length
    1 <= k <= 109

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

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
     	int sLen = s.size();
     	//notice 00 always to 00, 01 will be changed to 11, 10, 11, 10
     	//10 11 10 ... and 11 10 11 ...
     	int sHas1 = 0;
     	int targetHas1 = 0;
     	for(int i=0; i<sLen; i++){
     		if(s[i]=='1')//then we can do 10 11 10...
     			sHas1 = 1;
     		if(target[i]=='1')
     			targetHas1 = 1;
     		if(sHas1 && targetHas1)
     			return true;
     	}  
     	if(sHas1 == 0 && targetHas1 == 0)
     		return true;
     	return false;
    }
private:
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
	// string word1 = "aabccc",  word2 = "bbbccc"; //1
	// string word1 = "aabccc", word2 = "cccca";//1
	// string word1 = "ab", word2 = "abcc";//0
	// string word1 = "aa", word2 = "ab";//0
	int n = 3;
	vector<vector<int>> score;
	score.push_back(vector<int>{10,6,9,1});
	score.push_back(vector<int>{7,5,11,2});
	score.push_back(vector<int>{4,8,3,15});
	
	vector<vector<int>> res= mysol.sortTheStudents(score, 2);
	for(int i=0; i<n; i++){
		printvector(res[i]);
	}
  
 	return(0);	
}