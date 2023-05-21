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
6442. Modify Graph Edge Weights


You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.

Some edges have a weight of -1 (wi = -1), while others have a positive weight (wi > 0).

Your task is to modify all edges with a weight of -1 by assigning them positive integer values in the range [1, 2 * 109] so that the shortest distance between the nodes source and destination becomes equal to an integer target. If there are multiple modifications that make the shortest distance between source and destination equal to target, any of them will be considered correct.

Return an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from source to destination equal to target, or an empty array if it's impossible.

Note: You are not allowed to modify the weights of edges with initial positive weights.

 

Example 1:

Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
Explanation: The graph above shows a possible modification to the edges, making the distance from 0 to 1 equal to 5.

Example 2:

Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
Output: []
Explanation: The graph above contains the initial edges. It is not possible to make the distance from 0 to 2 equal to 6 by modifying the edge with weight -1. So, an empty array is returned.

Example 3:

Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
Explanation: The graph above shows a modified graph having the shortest distance from 0 to 2 as 6.

 

Constraints:

    1 <= n <= 100
    1 <= edges.length <= n * (n - 1) / 2
    edges[i].length == 3
    0 <= ai, bi < n
    wi = -1 or 1 <= wi <= 107
    ai != bi
    0 <= source, destination < n
    source != destination
    1 <= target <= 109
    The graph is connected, and there are no self-loops or repeated edges


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

template <typename First, typename Second>
void printvectorofpairs(std::vector< std::pair<First,Second> > vector_of_pairs)
{
  for (const auto& p : vector_of_pairs)
  		std::cout << p.first << ", " << p.second << std::endl;
  	printf("\n");
	fflush(stdout);
}


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
// auto cmp =[](const std::pair<int,int>& a, const std::pair<int,int>& b){
//     		if(a.first>b.first)
//     			return(true);
//     		else if(a.first<b.first)
//     			return(false);
//     		else
//     			return(a.second>b.second);
//     	};
// priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);//minpriority queue

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
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        
    }
private:
	int ShouldIPunished(int i){
		int iSquare = i*i;
		vector<int> DigitsOfSquareReversed;
		int temp = iSquare;
		while(temp>0)
		{
			int Digit = temp%10;
			DigitsOfSquareReversed.push_back(Digit);
			temp = (temp-Digit)/10;
		}
		vector<int> DigitsOfSquare;
		// int DigitSum = 0;
		for(int i=DigitsOfSquareReversed.size()-1;i--; i>=0){
			// DigitSum += DigitsOfSquareReversed[i];
			DigitsOfSquare.push_back(DigitsOfSquareReversed[i]);
		}
		// printvector(DigitsOfSquareReversed);
		// printf("i:%d\n",i);
		return(DFSPossibleSum(DigitsOfSquareReversed, 0, i));
	}
	int DFSPossibleSum(vector<int>& DigitsOfSquareReversed, int FirstPartition, int target){
		int n=DigitsOfSquareReversed.size();
		//if n =3, first partition can happen at FirstPartition+1, Until n
		if(FirstPartition == n ){
			if(target == 0)
				return(1);
			else
				return(0);//GG

		}
		else{
			// int res = 0;

			for(int NextPartition = FirstPartition+1; NextPartition<=n; NextPartition++)
			{
				int temp = target;
				for(int l=FirstPartition; l<NextPartition; l++)
					temp = temp - DigitsOfSquareReversed[l]*pow(10,l-FirstPartition);
				// cout<<"target:"<<temp<<"NextPartition:"<<NextPartition<<endl;
				if(target<0)
					break;
				if( DFSPossibleSum(DigitsOfSquareReversed, NextPartition, temp) )
					return(1);
			}
			return(0);
		}
	}
	int AbsoluteDistance(vector<int> StartNode, vector<int> EndNode)
	{
		return(abs(StartNode[0]-EndNode[0])+abs(StartNode[1]-EndNode[1]));
	}
	map<int,vector<int>> PrimeFactorsMap;
	vector<int> PrimeGetFactor(int n)
	{
		if(PrimeFactorsMap.find(n)== PrimeFactorsMap.end())
		{
			if(n==2)
				PrimeFactorsMap[2]=vector<int>{2};
			else
			{
				PrimeFactorsMap[n]= vector<int>();
				int IsPrime=1;
				for(int j=2; j<=floor(sqrt(n)); j++)
				{
					if(n%j==0){
						PrimeFactorsMap[n]=PrimeGetFactor(n/j);
						PrimeFactorsMap[n].push_back(j);
						IsPrime=0;
					    break;
					}
				}
				if(IsPrime==1)
					PrimeFactorsMap[n]=vector<int>{n};	
			}
			
		}
		return(PrimeFactorsMap[n]);
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
	

	int IsPrimeSimple(char c)
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
	// int inputs[][4]={{2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15}};
	// int inputs[][3]={{3,2,4},{2,1,9},{1,1,7}};
	// int n=4;
	// int inputs[][2]={{0,100000}};
	// int n=1;
	// vector<vector<int>> grid = ArrayTo2dVector(inputs);
	// string s="ABFCACDB";
	
	cout<<mysol.punishmentNumber(37)<<endl;
	
	// vector<vector<int>> res= mysol.substringXorQueries(s, queries);
	// 
	

	
  	
 	return(0);	
}