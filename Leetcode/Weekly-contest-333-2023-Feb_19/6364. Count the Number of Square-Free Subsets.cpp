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

6364. Count the Number of Square-Free Subsets


You are given a positive integer 0-indexed array nums.

A subset of the array nums is square-free if the product of its elements is a square-free integer.

A square-free integer is an integer that is divisible by no square number other than 1.

Return the number of square-free non-empty subsets of the array nums. Since the answer may be too large, return it modulo 109 + 7.

A non-empty subset of nums is an array that can be obtained by deleting some (possibly none but not all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

 

Example 1:

Input: nums = [3,4,4,5]
Output: 3
Explanation: There are 3 square-free subsets in this example:
- The subset consisting of the 0th element [3]. The product of its elements is 3, which is a square-free integer.
- The subset consisting of the 3rd element [5]. The product of its elements is 5, which is a square-free integer.
- The subset consisting of 0th and 3rd elements [3,5]. The product of its elements is 15, which is a square-free integer.
It can be proven that there are no more than 3 square-free subsets in the given array.

Example 2:

Input: nums = [1]
Output: 1
Explanation: There is 1 square-free subset in this example:
- The subset consisting of the 0th element [1]. The product of its elements is 1, which is a square-free integer.
It can be proven that there is no more than 1 square-free subset in the given array.

 

Constraints:

    1 <= nums.length <= 1000
    1 <= nums[i] <= 30


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
    int squareFreeSubsets(vector<int>& nums) {
 		
 		//2,3,5,7,11,13,17,19,23, 29 totally 10 primes, so we need 2^10 entries for records
		//actually 2^10-1, we dont' need record how many subset got all 10 prime factors, we need to kick out these cases
 		vector<int> temp{2,3,5,7,11,13,17,19,23, 29};
 		map<int,int> PrimeWithIndex;
 		for(int i=0;i<temp.size();i++)
 			PrimeWithIndex[temp[i]] = 1<<i;
 		vector<int> NumWithPrimeFactors;
 		NumWithPrimeFactors.push_back(0);//for 1, no prime factors in above 10 primes
		NumWithPrimeFactors.push_back(PrimeWithIndex[2]);//for 2, 1<<0 = 1
		NumWithPrimeFactors.push_back(PrimeWithIndex[3]); 		       
		NumWithPrimeFactors.push_back(1<<11);//this means it is a square number
		NumWithPrimeFactors.push_back(PrimeWithIndex[5]);//5
		NumWithPrimeFactors.push_back(PrimeWithIndex[2]+PrimeWithIndex[3]);//6
		NumWithPrimeFactors.push_back(PrimeWithIndex[7]);//7
		NumWithPrimeFactors.push_back(1<<11);
		NumWithPrimeFactors.push_back(1<<11);
		NumWithPrimeFactors.push_back(PrimeWithIndex[2]+PrimeWithIndex[5]);// 2 5
		NumWithPrimeFactors.push_back(PrimeWithIndex[11]);//1
		NumWithPrimeFactors.push_back(1<<11);
		NumWithPrimeFactors.push_back(PrimeWithIndex[13]);
		NumWithPrimeFactors.push_back(PrimeWithIndex[2]+PrimeWithIndex[7]);
		NumWithPrimeFactors.push_back(PrimeWithIndex[3]+PrimeWithIndex[5]);
		NumWithPrimeFactors.push_back(1<<11);
		NumWithPrimeFactors.push_back(PrimeWithIndex[17]);
		NumWithPrimeFactors.push_back(1<<11);
		NumWithPrimeFactors.push_back(PrimeWithIndex[19]);
		NumWithPrimeFactors.push_back(1<<11);
		NumWithPrimeFactors.push_back(PrimeWithIndex[3]+PrimeWithIndex[7]);
		NumWithPrimeFactors.push_back(PrimeWithIndex[2]+PrimeWithIndex[11]);
		NumWithPrimeFactors.push_back(PrimeWithIndex[23]);
		NumWithPrimeFactors.push_back(1<<11);
		NumWithPrimeFactors.push_back(1<<11);
		NumWithPrimeFactors.push_back(PrimeWithIndex[2]+PrimeWithIndex[13]);//26
		NumWithPrimeFactors.push_back(1<<11);
		NumWithPrimeFactors.push_back(1<<11);
		NumWithPrimeFactors.push_back(PrimeWithIndex[29]);
		NumWithPrimeFactors.push_back(PrimeWithIndex[2]+PrimeWithIndex[3]+PrimeWithIndex[5]);//for 30


		int numsLen= nums.size();
		int res = 0;
		
		vector<int> SubsetWithPrimeFactors(1<<10, 0);//index is refers to the prime factors subset, value is number of subsets whose product got prime factors = this prime factors subset
		//0 means no prime factors here
		SubsetWithPrimeFactors[0]=1;
		for(int i=0; i<numsLen; i++){
			if(NumWithPrimeFactors[nums[i]-1] != (1<<11))
			{
				vector<int> NextSubsetWithPrimeFactors = SubsetWithPrimeFactors;
				int PrimeFactorsForThisNum = NumWithPrimeFactors[nums[i]-1];
				// printf("nums[i]:%d\n", nums[i]);
				// printvector(PrimeFactorsForThisNum);

				for(int i=0; i<(1<<10); i++){
					if( (i & PrimeFactorsForThisNum) == 0)//no overlap, great
					{
						int newPrimeFactorSet = (i|PrimeFactorsForThisNum);
						NextSubsetWithPrimeFactors[newPrimeFactorSet] =
							(NextSubsetWithPrimeFactors[newPrimeFactorSet]+SubsetWithPrimeFactors[i])%LargePrime;
					}

				}
				SubsetWithPrimeFactors = NextSubsetWithPrimeFactors;

				// printf("hello\n");
				// for(auto temp:SubsetWithPrimeFactors)
					// printvector(temp);
			}
		}
		// printvector(SubsetWithPrimeFactors);
		for(auto temp:SubsetWithPrimeFactors){
			res = (res+temp)%LargePrime;
		}
		res = (res - 1)%LargePrime;
		return(res);
    }
private:
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
  	// vector<int> nums{3,4,4,5};//
  	// vector<int> nums{1};
  	vector<int> nums{1,2,6,15,7,19,6,29,28,24,21,25,25,18,9,6,20,21,8,24,14,19,24,28,30,27,13,21,1,23,13,29,24,29,18,7};//9215
  	cout<<mysol.squareFreeSubsets(nums)<<endl;
 	return(0);	
}