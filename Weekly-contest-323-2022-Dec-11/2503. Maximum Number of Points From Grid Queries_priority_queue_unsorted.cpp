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




You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queres[i] you start in the top left cell of 
the matrix and repeat the following process:

    If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
    Otherwise, you do not get any points, and you end this process.

After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.

 

Example 1:

Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
Output: [5,8,1]
Explanation: The diagrams above show which cells we visit to get points for each query.

Example 2:

Input: grid = [[5,2,1],[1,1,2]], queries = [3]
Output: [0]
Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.

 

Constraints:

    m == grid.length
    n == grid[i].length
    2 <= m, n <= 1000
    4 <= m * n <= 10^5
    k == queries.length
    1 <= k <= 10^4
    1 <= grid[i][j], queries[i] <= 10^6



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


bool comparePairs(const pair<int,int>& lhs, const pair<int,int>& rhs)
{
	return (lhs.second < rhs.second);
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

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int NoQueries = queries.size();
        int m = grid.size();
        int n = grid[0].size();

        //notice that we start from the top left one, then the whole grid is similar a graph
        //under the idea of BFS with root = top left corner, we could pick this one.
        //notice that m might not be equal to n, so we want to make it inside a triangle, where extra boxes are 0;
        //actually we should use DFS here, because we are allowed to move in any of 4 directions, the only solution is to use DFS
        //for each query, we will have a visited grid, where grid[k][i][j]=0 means grid[i][j] < queries[k] is unknown to us, 
        //=1, means grid[i][j]<queries[k] is true, 2 means false.
        //actually we don't need to be such complicated
        // a normal mxn dimension grid should be enough here
        //actually DFS will not work here either, the key is to keep track of the surrounding boxes around the current graph, and pick 
        //the smallest one among these surrounding boxes.
        //here we need a priority queue.
        // }

        
        vector<vector<int>> gridVisited;
        
        for(int j=0;j<m;j++){
            gridVisited.push_back(vector<int>(n,0));
        }
        vector<int> StoppedOrNot(NoQueries,0);
        vector<int> res(NoQueries,0);
        // comparePairsWithParams* myCompare = new comparePairsWithParams(grid);
        // auto CompareFunc = CompareFuncWithParams(grid);
        // cout<<typeid(CompareFunc).name()<<endl;
        // fflush(stdout);
        
        // DFSForMultipleQueryOnGrid(0,0,m,n, gridVisited, res, queries, NoQueries, grid, ValidQueryIndex, CompareFunc);

        // vector<pair<int,int>> Neighbors=vector<pair<int,int>>{pair<int,int>{0,0}};
        
        myPriorityQueue minNeighbors((CompareFuncWithParams(grid)));
        minNeighbors.push(pair<int,int>{0,0});
        gridVisited[0][0]=1;
        int countOfPointsWhenValidIndexUnchanged = 0;
        // priority_queue<pair<int,int>, std::vector<pair<int,int>, CompareFunc>minNeighbors(Neighbors.begin(), Neighbors.end());
        while( minNeighbors.size()>0){
            //pull out the minumum entry of the Neighboring boxes
            auto minNeighbor = minNeighbors.top();
            int minNeighborX = minNeighbor.first;
            int minNeighborY = minNeighbor.second;
            int minNeighborValue = grid[minNeighbor.first][minNeighbor.second];
            // printf("minNeighborValue: %d\n", minNeighborValue);
            // print_queue(minNeighbors);
            int UnFinishedQuery = 0;
            for(int j=0; j<NoQueries; j++){
            	if(StoppedOrNot[j]==0 ){
            		if( queries[j] > minNeighborValue ){
            			res[j]++;
            			UnFinishedQuery = 1;
            		}
            		else
            			StoppedOrNot[j]=1;
            	}
            }
            
            if(UnFinishedQuery == 0){               
                break;
            }
            // for(int k = ValidQueryIndex; k<NoQueries; k++){
            //     res[QueriesWithLoc[k].first]++;
            // }
            
            
            // printf("ValidQueryIndex: %d\n", ValidQueryIndex);
            //now we needs to handle the current minNeighbor
            //remove it and insert its neighbors that have not been visited currently
            minNeighbors.pop();
            gridVisited[minNeighborX][minNeighborY]=2;//mark this node as visited
            if(minNeighborX-1>=0 && gridVisited[minNeighborX-1][minNeighborY]==0 ){
                minNeighbors.push(pair<int,int>{minNeighborX-1, minNeighborY});
                gridVisited[minNeighborX-1][minNeighborY]=1;

            }

            if(minNeighborX+1<m && gridVisited[minNeighborX+1][minNeighborY]==0 ){
                minNeighbors.push(pair<int,int>{minNeighborX+1, minNeighborY});
                gridVisited[minNeighborX+1][minNeighborY]=1;
            }

            if(minNeighborY-1>=0 && gridVisited[minNeighborX][minNeighborY-1]==0 ){
                minNeighbors.push(pair<int,int>{minNeighborX, minNeighborY-1});
                gridVisited[minNeighborX][minNeighborY-1]=1;
            }

            if(minNeighborY+1<n && gridVisited[minNeighborX][minNeighborY+1]==0 ){
                minNeighbors.push(pair<int,int>{minNeighborX, minNeighborY+1});   
                gridVisited[minNeighborX][minNeighborY+1]=1;         
            }

        }

        //need to get back the previous 
        return(res);    
    
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
	int input[][3] = {{1,2,3},{2,5,7},{3,5,1}};
    vector<int> queries{5,6,2};
	
    
    // int input[][12] ={{249472,735471,144880,992181,760916,920551,898524,37043,422852,194509,714395,325171},{295872,922051,900801,634980,644237,912433,857189,98466,725226,984534,370121,399006},{618420,573065,587011,298153,694872,12760,880413,593508,474772,291113,852444,77998},{67650,426517,146447,190319,379151,184754,479219,106819,138473,865661,799297,228827},{390392,789371,772048,730506,7144,862164,650590,21524,879440,396198,408897,851020},{932044,662093,436861,246956,128943,167432,267483,148325,458128,418348,900594,831373},{742255,795191,598857,441846,243888,777685,313717,560586,257220,488025,846817,554722},{252507,621902,87704,599753,651175,305330,620166,631193,385405,183376,432598,706692},{984416,996917,586571,324595,784565,300514,101313,685863,703194,729430,732044,349877},{155629,290992,539879,173659,989930,373725,701670,992137,893024,455455,454886,559081},{252809,641084,632837,764260,68790,732601,349257,208701,613650,429049,983008,76324},{918085,126894,909148,194638,915416,225708,184408,462852,40392,964501,436864,785076},{875475,442333,111818,494972,486734,901577,46210,326422,603800,176902,315208,225178},{171174,458473,744971,872087,680060,95371,806370,322605,349331,736473,306720,556064},{207705,587869,129465,543368,840821,977451,399877,486877,327390,8865,605705,481076}};
    // vector<int> queries{690474,796832,913701,939418,46696,266869,150594,948153,718874};
    
    vector<vector<int>> grid = ArrayTo2dVector(input);

    vector<int> output = mysol.maxPoints(grid, queries);
    printvector(output);
  
 	return(0);	
}