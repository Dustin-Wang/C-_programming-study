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
6455. Minimum Cost to Make All Characters Equal


You are given a 0-indexed binary string s of length n on which you can apply two types of operations:

    Choose an index i and invert all characters from index 0 to index i (both inclusive), with a cost of i + 1
    Choose an index i and invert all characters from index i to index n - 1 (both inclusive), with a cost of n - i

Return the minimum cost to make all characters of the string equal.

Invert a character means if its value is '0' it becomes '1' and vice-versa.

 

Example 1:

Input: s = "0011"
Output: 2
Explanation: Apply the second operation with i = 2 to obtain s = "0000" for a cost of 2. It can be shown that 2 is the minimum cost to make all characters equal.

Example 2:

Input: s = "010101"
Output: 9
Explanation: Apply the first operation with i = 2 to obtain s = "101101" for a cost of 3.
Apply the first operation with i = 1 to obtain s = "011101" for a cost of 2. 
Apply the first operation with i = 0 to obtain s = "111101" for a cost of 1. 
Apply the second operation with i = 4 to obtain s = "111110" for a cost of 2.
Apply the second operation with i = 5 to obtain s = "111111" for a cost of 1. 
The total cost to make all characters equal is 9. It can be shown that 9 is the minimum cost to make all characters equal.

 

Constraints:

    1 <= s.length == n <= 105
    s[i] is either '0' or '1'


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
auto cmp =[](const std::pair<int,int>& a, const std::pair<int,int>& b){
    		if(a.first>b.first)
    			return(true);
    		else if(a.first<b.first)
    			return(false);
    		else
    			return(a.second>b.second);
    	};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);//minpriority queue

int quick_pow10(int n)
{
	static int pow10[10]={
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 1000000000
    };
    return pow10[n];
}
int LargePrime = pow(10,9)+7;



struct Trienode{
    char val;
    int endsHere;
    int count;
    Trienode* child[26];
};
Trienode* getNode(char c){
    Trienode* res=new Trienode();
    res->val=c;
    res->endsHere=0;
    res->count=0;
    for(int i=0;i<26;i++){
        res->child[i]=nullptr;
    }
    return res;
}





#define MAX_NODES 10000
class Trie {
    Trienode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        //ios_base::sync_with_stdio(false);
        //cin.tie(NULL);
        root = getNode('/'-'a');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trienode *curr = root;
        int index;
        for(int i=0;word[i]!='\0';++i)
        {
            index = word[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index] = getNode(index);
            curr->child[index]->count +=1;
            curr = curr->child[index];
        }
        curr->endsHere +=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trienode *curr = root;
        int index;
        for(int i=0;word[i]!='\0';++i)
        {
            index = word[i]-'a';
            if(curr->child[index]==NULL)
                return false;
            curr = curr->child[index];
        }
        return (curr->endsHere > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trienode *curr = root;
        int index;
        for(int i=0;prefix[i]!='\0';++i)
        {
            index = prefix[i]-'a';
            if(curr->child[index]==NULL)
                return false;
            curr = curr->child[index];
        }
        return (curr->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Solution {
public:
    long long minimumCost(string s) {
     	int sLen = s.size();
     	
     	
     	vector<long long> PrefixFlipToAllOnes{0};
     	vector<long long> PrefixFlipToAllZeros{0};

     	long long AccumulatedCostAllOnes = 0;
     	long long AccumulatedCostAllZeros = 0;
     	int Prev = s[0];
     	if(Prev=='0')
     		AccumulatedCostAllOnes++;
     	else
     		AccumulatedCostAllZeros++;
     	PrefixFlipToAllOnes.push_back(AccumulatedCostAllOnes);
     	PrefixFlipToAllZeros.push_back(AccumulatedCostAllZeros);
     	int i=1;
     	while(i<sLen)
     	{
     		if(s[i]==Prev)
     		{
     			if(s[i]=='0')
     				AccumulatedCostAllOnes++;
     			else
     				AccumulatedCostAllZeros++;
     		}
     		else
     		{
     			if(Prev=='0')//we run into .....01 case
     				AccumulatedCostAllZeros += 2*i+1;
     			else//....10
     				AccumulatedCostAllOnes += 2*i+1;
     			Prev = s[i];
     		}
     		PrefixFlipToAllOnes.push_back(AccumulatedCostAllOnes);
     		PrefixFlipToAllZeros.push_back(AccumulatedCostAllZeros);
     		i++;
     	}   
     	// PrefixFlipToAllZeros.push_back(AccumulatedCostAllZeros);
     	// PrefixFlipToAllOnes.push_back(AccumulatedCostAllOnes);

     	vector<long long> SuffixFlipToAllOnes{0};
     	vector<long long> SuffixFlipToAllZeros{0};

     	AccumulatedCostAllOnes = 0;
     	AccumulatedCostAllZeros = 0;
     	Prev = s[sLen-1];
     	if(Prev=='0')
     		AccumulatedCostAllOnes++;
     	else
     		AccumulatedCostAllZeros++;
     	SuffixFlipToAllOnes.push_back(AccumulatedCostAllOnes);//from right to left, first entry is for flipping sLen-1 entry.
     	SuffixFlipToAllZeros.push_back(AccumulatedCostAllZeros);


     	i=sLen-2;
     	while(i>=0)
     	{
     		if(s[i]==Prev)
     		{
     			if(s[i]=='0')
     				AccumulatedCostAllOnes++;
     			else
     				AccumulatedCostAllZeros++;
     		}
     		else
     		{
     			if(Prev=='0')//we run into 10... case
     				AccumulatedCostAllZeros += 2*(sLen-i-1)+1;
     			else//01......
     				AccumulatedCostAllOnes += 2*(sLen-i-1)+1;
     			Prev = s[i];
     		}
     		SuffixFlipToAllOnes.push_back(AccumulatedCostAllOnes);
     		SuffixFlipToAllZeros.push_back(AccumulatedCostAllZeros);
     		i--;
     	}
     	// SuffixFlipToAllOnes.push_back(AccumulatedCostAllOnes);
     	// SuffixFlipToAllZeros.push_back(AccumulatedCostAllZeros);
     	long long res = LLONG_MAX;
     	
     	for(int i=0; i<=sLen;i++)
     	{//for 0:i-1, we use prefixflip, for i:
     		res = min(res, PrefixFlipToAllZeros[i]+SuffixFlipToAllZeros[sLen-i]);
     		res = min(res, PrefixFlipToAllOnes[i]+SuffixFlipToAllOnes[sLen-i]);
     	}
     	return(res);

    }
private:
	Trie* dic;
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
	// int input[][1]={{1}};
	// auto grid = ArrayTo2dVector(input);
	// string s = "0011";
	string s = "010101";
	cout<<mysol.minimumCost(s)<<endl;
	
	// vector<vector<int>> res= mysol.substringXorQueries(s, queries);
	// 
	

	
  	
 	return(0);	
}