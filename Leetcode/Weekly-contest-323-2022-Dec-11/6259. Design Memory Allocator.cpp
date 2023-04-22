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


You are given an integer n representing the size of a 0-indexed memory array. All memory units are initially free.

You have a memory allocator with the following functionalities:

    Allocate a block of size consecutive free memory units and assign it the id mID.
    Free all memory units with the given id mID.

Note that:

    Multiple blocks can be allocated to the same mID.
    You should free all the memory units with mID, even if they were allocated in different blocks.

Implement the Allocator class:

    Allocator(int n) Initializes an Allocator object with a memory array of size n.
    int allocate(int size, int mID) Find the leftmost block of size consecutive free memory units and allocate it with the id mID. Return the block's first index. If such a block does not exist, return -1.
    int free(int mID) Free all memory units with the id mID. Return the number of memory units you have freed.

 

Example 1:

Input
["Allocator", "allocate", "allocate", "allocate", "free", "allocate", "allocate", "allocate", "free", "allocate", "free"]
[[10], [1, 1], [1, 2], [1, 3], [2], [3, 4], [1, 1], [1, 1], [1], [10, 2], [7]]
Output
[null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]

Explanation
Allocator loc = new Allocator(10); // Initialize a memory array of size 10. All memory units are initially free.
loc.allocate(1, 1); // The leftmost block's first index is 0. The memory array becomes [1,_,_,_,_,_,_,_,_,_]. We return 0.
loc.allocate(1, 2); // The leftmost block's first index is 1. The memory array becomes [1,2,_,_,_,_,_,_,_,_]. We return 1.
loc.allocate(1, 3); // The leftmost block's first index is 2. The memory array becomes [1,2,3,_,_,_,_,_,_,_]. We return 2.
loc.free(2); // Free all memory units with mID 2. The memory array becomes [1,_, 3,_,_,_,_,_,_,_]. We return 1 since there is only 1 unit with mID 2.
loc.allocate(3, 4); // The leftmost block's first index is 3. The memory array becomes [1,_,3,4,4,4,_,_,_,_]. We return 3.
loc.allocate(1, 1); // The leftmost block's first index is 1. The memory array becomes [1,1,3,4,4,4,_,_,_,_]. We return 1.
loc.allocate(1, 1); // The leftmost block's first index is 6. The memory array becomes [1,1,3,4,4,4,1,_,_,_]. We return 6.
loc.free(1); // Free all memory units with mID 1. The memory array becomes [_,_,3,4,4,4,_,_,_,_]. We return 3 since there are 3 units with mID 1.
loc.allocate(10, 2); // We can not find any free block with 10 consecutive free memory units, so we return -1.
loc.free(7); // Free all memory units with mID 7. The memory array remains the same since there is no memory unit with mID 7. We return 0.

 

Constraints:

    1 <= n, size, mID <= 1000
    At most 1000 calls will be made to allocate and free.


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

// struct MyClassLessThan{
	// template<typename K, typename V>
bool comparePairs(const pair<int,int>& lhs, const pair<int,int>& rhs)
{
	return (lhs.first < rhs.first);
}
// };


class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        
        int n = nums.size();
        int MaxNo = nums[n-1];
		// printf("MaxNo: %d\n", MaxNo);
        fflush(stdout);
        vector<int> PositionHash(MaxNo+1,0);
        // printf("hello\n");
        fflush(stdout);
        for(int i=0;i<n;i++){
        	PositionHash[nums[i]]=i+1;//this is postive
        }
        
        vector<int> PositionVisited(MaxNo+1,0);
        int res = -1;
        for(int i=2; (i<MaxNo) && (PositionVisited[i] == 0); i++){
        	int Candidate = 0;
        	unsigned long j = i;
        	while(j<=MaxNo && PositionHash[j]){
        		Candidate++;
        		PositionVisited[j] = 1;
        		j=j*j;
        	}
        	if(Candidate>=2 && Candidate>res)
        		res = Candidate;
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

class Allocator {
public:
    Allocator(int n) {
        
        MemoryLen = n;
        for(int i=0;i<=1000;i++){
        	BlocksForMID.push_back(vector<pair<int,int>>());
        }
 
        //this stored the blocks for each MID as vector of intervals.
        //MID =0 means that this block is empty.
        // BlocksForMID.insert(pair<int,vector<pair<int,int>>>{0, vector<pair<int,int>>()});
        BlocksForMID[0].push_back(pair<int,int>{0,n});//first entry means the starting index, second entry is the length of this empty block.
        //this EmptyBlocks must be sorted in terms of the starting index.
    }
    
    int allocate(int size, int mID) {
    	int res = -1;
    	printf("allocate:%d %d\n",size, mID);
        fflush(stdout);
        for(auto it = BlocksForMID[0].begin();it<BlocksForMID[0].end(); it++){

        	int EmptyBlockSize= it->second;
        	int EmptyBlockStart=it->first;
        	if(EmptyBlockSize>=size){
        		//find the place to insert this one
        		res = EmptyBlockStart;
        		// printf("EmptyBlockStart: %d\n", EmptyBlockStart );
        		if(EmptyBlockSize-size>0){
        			it->second = EmptyBlockSize-size;
        			it->first = EmptyBlockStart+size;	
        		}
        		else{
        			BlocksForMID[0].erase(it);
        		}
        		//try to find the correct loc for this new block under mID
        		auto loc = upper_bound(BlocksForMID[mID].begin(), BlocksForMID[mID].end(), pair<int,int>{res, size}, 
        			 comparePairs);//the first location that is strictly greater than this given value res.first.
        		BlocksForMID[mID].insert(loc,pair<int,int>{res, size});
        		
        		return(res);
        	}
        }
        return(res);
    }
    
    int free(int mID) {
        //we need to merge sort the elements in BlocksForMID[0] and BlocksForMID[mID]
        vector<pair<int,int>> res;
        printf("free: %d\n", mID);
        fflush(stdout);
        int NoOfBlocksForMID = BlocksForMID[mID].size();
        int NoOfEmptyBlocks = BlocksForMID[0].size();
        // printf("%d: %d\n", NoOfBlocksForMID, NoOfEmptyBlocks );
        if(NoOfBlocksForMID==0)
        	return(0);
        int i=0;
        int j=0;
        int ToReturn = 0;
        while(i<NoOfBlocksForMID && j<NoOfEmptyBlocks){
        	// printf("%d: %d\n", BlocksForMID[mID][i].first, BlocksForMID[0][j].first );
        	if(BlocksForMID[mID][i].first < BlocksForMID[0][j].first){
        		ToReturn += BlocksForMID[mID][i].second;
        		res.push_back(BlocksForMID[mID][i]);
        		i++;
        	}
        	else{
        		res.push_back(BlocksForMID[0][j]);
        		j++;
        	}
        }
        while(i<NoOfBlocksForMID){
        	ToReturn += BlocksForMID[mID][i].second;
        	res.push_back(BlocksForMID[mID][i]);
        	i++;
        }
        while(j<NoOfEmptyBlocks){
        	res.push_back(BlocksForMID[0][j]);
        	j++;
        }
        
        //now we need to connect the adjacent blocks in res into a single block
        int NoOfBlocksInRes = res.size();
        vector<pair<int,int>> NewRes;

        	
        
        int NewBlockStart = 1000;
    	int NewBlockSize = 1000;
        for(int i=0;i<NoOfBlocksInRes;i++){
    		if(res[i].first == NewBlockStart + NewBlockSize ){
    			//this means this block can be put into the previous consecutive block
    			NewBlockSize = NewBlockSize + res[i].second;
    		}
    		else{
    			if(i!=0)
    				NewRes.push_back(pair<int,int>{NewBlockStart, NewBlockSize});
    			NewBlockStart = res[i].first;
    			NewBlockSize = res[i].second;
    		}
        }
        if(NoOfBlocksInRes > 0){
        	NewRes.push_back(pair<int,int>{NewBlockStart, NewBlockSize});
        }
	    
	    BlocksForMID[0]=NewRes;
	    BlocksForMID[mID] = vector<pair<int,int>>();
    	
	    return(ToReturn);

    }
private:
	int MemoryLen;
	vector<vector<pair<int,int>>> BlocksForMID;
	// vector<int> EmptyBlockSizeStartFromN;
	// vector<int,vector<pair<int,int>>> MIDToBlocks;
	// vector<int> LeftmostAvailableForSize(1000,-1);
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
	// Solution mysol;
	// int input[][3] = {{1,2,4},{3,3,1}};
	// vector<vector<int>> grid = ArrayTo2dVector(input);
/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
	// ["Allocator", "allocate", "allocate", "allocate", "free", "allocate", "allocate", "allocate", "free", "allocate", "free"]
// [[10], [1, 1], [1, 2], [1, 3], [2], [3, 4], [1, 1], [1, 1], [1], [10, 2], [7]]
	// Output
// [null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]
	Allocator* myAllocator = new Allocator(10);
	cout<<myAllocator->allocate(1,1)<<endl;//0
	cout<<myAllocator->allocate(1,2)<<endl;//1
	cout<<myAllocator->allocate(1,3)<<endl;//2
	cout<<myAllocator->free(2)<<endl;//1
	cout<<myAllocator->allocate(3,4)<<endl;//3
	cout<<myAllocator->allocate(1,1)<<endl;//1
	cout<<myAllocator->allocate(1,1)<<endl;//6
	cout<<myAllocator->free(1)<<endl;//3
	cout<<myAllocator->allocate(10,2)<<endl;//-1
	cout<<myAllocator->free(7)<<endl;

 	return(0);	
}