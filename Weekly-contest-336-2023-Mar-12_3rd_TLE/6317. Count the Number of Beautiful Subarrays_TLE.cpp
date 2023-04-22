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
6317. Count the Number of Beautiful Subarrays


You are given a 0-indexed integer array nums. In one operation, you can:

    Choose two different indices i and j such that 0 <= i, j < nums.length.
    Choose a non-negative integer k such that the kth bit (0-indexed) in the binary representation of nums[i] and nums[j] is 1.
    Subtract 2k from nums[i] and nums[j].

A subarray is beautiful if it is possible to make all of its elements equal to 0 after applying the above operation any number of times.

Return the number of beautiful subarrays in the array nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [4,3,1,2,4]
Output: 2
Explanation: There are 2 beautiful subarrays in nums: [4,3,1,2,4] and [4,3,1,2,4].
- We can make all elements in the subarray [3,1,2] equal to 0 in the following way:
  - Choose [3, 1, 2] and k = 1. Subtract 21 from both numbers. The subarray becomes [1, 1, 0].
  - Choose [1, 1, 0] and k = 0. Subtract 20 from both numbers. The subarray becomes [0, 0, 0].
- We can make all elements in the subarray [4,3,1,2,4] equal to 0 in the following way:
  - Choose [4, 3, 1, 2, 4] and k = 2. Subtract 22 from both numbers. The subarray becomes [0, 3, 1, 2, 0].
  - Choose [0, 3, 1, 2, 0] and k = 0. Subtract 20 from both numbers. The subarray becomes [0, 2, 0, 2, 0].
  - Choose [0, 2, 0, 2, 0] and k = 1. Subtract 21 from both numbers. The subarray becomes [0, 0, 0, 0, 0].

Example 2:

Input: nums = [1,10,4]
Output: 0
Explanation: There are no beautiful subarrays in nums.

 

Constraints:

    1 <= nums.length <= 105
    0 <= nums[i] <= 106


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
    long long beautifulSubarrays(vector<int>& nums) {
        //10^6 is roughly at most 21bits
        //we need to count how many 1 for each bits
        vector<int> NewNums= nums;

        sort(NewNums.begin(), NewNums.end(), greater<int>());
        
        int l=0;
        for(l=0; l<31; l++){
        	if(NewNums[0] < (1<<l))
        		break;
        }
        int Max = (1<<l);
        
        
        long long res =0;
        int numsLen= nums.size();
        
        vector<long long> XORSumValueCountsEndAtI(Max,0);
        XORSumValueCountsEndAtI[nums[0]]=1;
        res = res + XORSumValueCountsEndAtI[0];
        
        for(int i=1; i< numsLen; i++)
        {
        	vector<long long> NewXORSumValueCountsEndAtI(Max,0);
        	NewXORSumValueCountsEndAtI[nums[i]]=1;
        	for(int j=0; j<Max; j++)
        	{

        		NewXORSumValueCountsEndAtI[(j^nums[i])] += XORSumValueCountsEndAtI[j];
        	}
        	XORSumValueCountsEndAtI = NewXORSumValueCountsEndAtI;
        	res = res + XORSumValueCountsEndAtI[0];
        	
        }
        return(res);
        
    }
private:	
	int IsVowel(char c)
	{
		if( c== 'a' || c=='e' ||c=='i' || c=='o' || c=='u')
			return(1);
		else
			return(0);
	}
	//ax + by = gcd(a,b)
	int Simplegcd( int a , int b){
		if (b==0){
			return(a);
		}
		else{
			int res = Simplegcd(b, a%b );//the tricky part is that we don’t need to have a>b for the initial input
			return(res);
		}
	}
	int gcd( int a , int b, int &x , int &y){
		if (b==0){
			x=1;
			y=0;	
			return(a);
		}
		else{
			int c = a/b;
			int res = gcd(b, a%b, x , y );//the tricky part is that we don’t need to have a>b for the initial input
			int tmp = x;
			x=y;
			y=tmp-c*y;
			return(res);
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
	// int inputs[][2]={{1,2},{2,3},{4,5}};
	// vector<vector<int>> queries = ArrayTo2dVector(inputs);
	
	
	
	vector<int> nums{4,3,1,2,4};
	// vector<int> nums{1,10,4};
	// vector<int> nums{0,1,1,0};

	cout<<mysol.beautifulSubarrays(nums)<<endl; 

 	return(0);	
}