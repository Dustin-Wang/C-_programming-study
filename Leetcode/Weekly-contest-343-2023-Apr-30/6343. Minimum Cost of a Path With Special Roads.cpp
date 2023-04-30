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
6343. Minimum Cost of a Path With Special Roads


You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 2D space. You are also given the array target where target = [targetX, targetY] represents your target position (targetX, targetY).

The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1| + |y2 - y1|.

There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, costi] indicates that the ith special road can take you from (x1i, y1i) to (x2i, y2i) with a cost equal to costi. You can use each special road any number of times.

Return the minimum cost required to go from (startX, startY) to (targetX, targetY).

 

Example 1:

Input: start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
Output: 5
Explanation: The optimal path from (1,1) to (4,5) is the following:
- (1,1) -> (1,2). This move has a cost of |1 - 1| + |2 - 1| = 1.
- (1,2) -> (3,3). This move uses the first special edge, the cost is 2.
- (3,3) -> (3,4). This move has a cost of |3 - 3| + |4 - 3| = 1.
- (3,4) -> (4,5). This move uses the second special edge, the cost is 1.
So the total cost is 1 + 2 + 1 + 1 = 5.
It can be shown that we cannot achieve a smaller total cost than 5.

Example 2:

Input: start = [3,2], target = [5,7], specialRoads = [[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]
Output: 7
Explanation: It is optimal to not use any special edges and go directly from the starting to the ending position with a cost |5 - 3| + |7 - 2| = 7.

 

Constraints:

    start.length == target.length == 2
    1 <= startX <= targetX <= 105
    1 <= startY <= targetY <= 105
    1 <= specialRoads.length <= 200
    specialRoads[i].length == 5
    startX <= x1i, x2i <= targetX
    startY <= y1i, y2i <= targetY
    1 <= costi <= 105


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
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
		int NoSpecialRoads = specialRoads.size();
		// set<int> Nodes;
		map<vector<int>,int> NodesToIndex;
		if(start==target)
			return(0);

    	// int Multi = 100000+1;


    	// int StartNode = start[0]*Multi+start[1];
    	// int EndNode = target[0]*Multi + target[1];
    	NodesToIndex[start]=0;
    	NodesToIndex[target]=1;


    	
    	int count = 2;
    	map<pair<int,int>, int> specialRoads2;
    	for(int i=0; i<NoSpecialRoads; i++)
    	{
    		vector<int> Node1{specialRoads[i][0], specialRoads[i][1]};
    		vector<int> Node2{specialRoads[i][2], specialRoads[i][3]};
    		int temp = AbsoluteDistance(Node1, Node2);
    		if(specialRoads[i][4]<temp)//it is a short cut, so this might be useful
    		{
    			if(NodesToIndex.find(Node1)==NodesToIndex.end()){
    				NodesToIndex[Node1]=count;
    				count++;
    			}
    			if(NodesToIndex.find(Node2)==NodesToIndex.end()){
    				NodesToIndex[Node2]=count;
    				count++;
    			}	
    			specialRoads2[pair<int,int>{NodesToIndex[Node1], NodesToIndex[Node2]}]=specialRoads[i][4];//Special Road are just single direction

    			// specialRoads2[pair<int,int>{NodesToIndex[Node2], NodesToIndex[Node1]}]=specialRoads[i][4];
    		}
    	}

    	vector<vector<int>> Nodes(count,vector<int>());
    	for(auto it=NodesToIndex.begin(); it!= NodesToIndex.end();it++)
    		Nodes[it->second]=it->first;

    	map<int, vector<pair<int,int>>> Adj;
    	for(int i=0; i< count; i++)
    	{
    		Adj[i]=vector<pair<int,int>>();
    		for(int j=0; j<count; j++)
    		{
    			if(j==i)
    				continue;
    			int temp = AbsoluteDistance(Nodes[i], Nodes[j]);
    			pair<int,int> thisPair = pair<int,int>{i,j};
    			
    			if(specialRoads2.find(thisPair)!=specialRoads2.end())
    				temp = specialRoads2[thisPair];//we have a shortcut here
    			
    			pair<int,int> thisEdge{j, temp};
    			Adj[i].push_back(thisEdge);
    		}
    		// printf("i: %d, coordinate: %d, %d\n", i, Nodes[i][0], Nodes[i][1]);
    		// printvectorofpairs(Adj[i]);
    	}


    	//now use BFS to find the shortest path from StartNode 0 to EndNode 1
    	vector<int> distance(count, INT_MAX);
    	distance[0]=0;
    	vector<int> visited(count,0);

    	auto cmp =[](const std::pair<int,int>& a, const std::pair<int,int>& b){
    		if(a.first>b.first)
    			return(true);
    		else if(a.first<b.first)
    			return(false);
    		else
    			return(a.second>b.second);
    	};
    	priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);//minpriority queue
    	q.push(pair<int,int>{0,0});
    	while(!q.empty())
    	{
    		pair<int,int> mindistanceNode = q.top();
    		int dist = mindistanceNode.first;
    		int cur = mindistanceNode.second;
    		q.pop();
    		if(visited[cur]) continue;

    		for(const auto u: Adj[cur])
    		{
    			int next = u.first;
    			int cost = u.second;
    			if(distance[next]>distance[cur]+cost){
    				distance[next]=distance[cur]+cost;
    				// printf("current: %d; next:%d;distance[%d]: %d, cost: %d\n", cur, next, next, distance[next], cost);
    				q.push(pair<int,int>{distance[next], next});
    			}
    		}
    		visited[cur]=1;
    		// printvector(distance);
    	}
    	return(distance[1]);       
    }
private:	

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
	// vector<int> arr{2,8,7,4,1,3,5,6,9};
	// int inputs[][5]={{1,2,3,3,2},{3,4,4,5,1}};
	// vector<int> start{1,1};
	// vector<int> target{4,5};
	// int inputs[][5]={{3,2,3,4,4},{3,3,5,5,5},{3,4,5,6,6}};
	// vector<int> start{3,2};
	// vector<int> target{5,7};
	int inputs[][5]={{4,2,1,1,3},{1,2,7,4,4},{10,3,6,1,2},{6,1,1,2,3}};
	vector<int> start{1,1};
	vector<int> target{10,4};
	vector<vector<int>> mat = ArrayTo2dVector(inputs);
	cout<<mysol.minimumCost(start, target, mat)<<endl;
	
	// vector<vector<int>> res= mysol.substringXorQueries(s, queries);
	// 
	

	
  	
 	return(0);	
}