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
6356. Substring XOR Queries

You are given a binary string s, and a 2D integer array queries where queries[i] = [firsti, secondi].

For the ith query, find the shortest substring of s whose decimal value, val, yields secondi when bitwise XORed with firsti. In other words, val ^ firsti == secondi.

The answer to the ith query is the endpoints (0-indexed) of the substring [lefti, righti] or [-1, -1] if no such substring exists. If there are multiple answers, choose the one with the minimum lefti.

Return an array ans where ans[i] = [lefti, righti] is the answer to the ith query.

A substring is a contiguous non-empty sequence of characters within a string.

 

Example 1:

Input: s = "101101", queries = [[0,5],[1,2]]
Output: [[0,2],[2,3]]
Explanation: For the first query the substring in range [0,2] is "101" which has a decimal value of 5, and 5 ^ 0 = 5, hence the answer to the first query is [0,2]. In the second query, the substring in range [2,3] is "11", and has a decimal value of 3, and 3 ^ 1 = 2. So, [2,3] is returned for the second query. 

Example 2:

Input: s = "0101", queries = [[12,8]]
Output: [[-1,-1]]
Explanation: In this example there is no substring that answers the query, hence [-1,-1] is returned.

Example 3:

Input: s = "1", queries = [[4,5]]
Output: [[0,0]]
Explanation: For this example, the substring in range [0,0] has a decimal value of 1, and 1 ^ 4 = 5. So, the answer is [0,0].

 

Constraints:

    1 <= s.length <= 104
    s[i] is either '0' or '1'.
    1 <= queries.length <= 105
    0 <= firsti, secondi <= 109


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
   vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int sLen = s.length();
        int FirstZeroLocation = 0;
        for(int i= 0; i<sLen; i++)
        	if(s[i]=='0'){
        		FirstZeroLocation = i;
        		break;
        	}
        vector<vector<int>> res;
        //we list out all possible substrings and corresponding value
        //let us use ordered map here
        map<long long, vector<int>> AllPossibleSubstrings; //key is the value, value is <left i, right i>
        AllPossibleSubstrings[0]=vector<int>{FirstZeroLocation, FirstZeroLocation};
        
        
        //notice that we need at most 32 bits binary string, besides, starting bit is always 1
        long long temp = 0;
        for(int left=0; left< sLen; left++){
        	if((s[left]-'0')==0)
        		continue;
        
        	temp = 0;
        	for(int right = left; right< min(sLen, left+32); right++){
				temp = (temp<<1) + (s[right]-'0');	
				if(AllPossibleSubstrings.find(temp)==AllPossibleSubstrings.end())
				{
					AllPossibleSubstrings[temp]=vector<int>{left, right};
				}
				
        	}
        }
        



        for(auto query:queries)
        {
        	//verify that second XOR first == first?
        	long long target = query[0]^query[1];
        	// printf("target:%ld\n",target);
        
        	if(AllPossibleSubstrings.find(target)!=AllPossibleSubstrings.end())
        		res.push_back(AllPossibleSubstrings[target]);
        	else
        		res.push_back(vector<int>{-1,-1});

        }
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
	string s= "0";
	int inputs[][2]={{0,0},{1,1},{2,2},{0,1}};
	// TLE
	// "1010000110011000110000001110111001010111111001100000110011011001001110101001011011110101011101111011001000011000000000010110001000101000110001101000010101010101011010010000100100000010100111100011100000100010111000101111100100111101011000011001101100101100001001011111111100111100101000001110011111111101011000010100111111001111000010111110101110000110110010010101011000010110101111000101110010011111110010110100110101010000010111000110011100010101100010110010010111101110000010001111001101101111101100100011001000110000000100100111000101101010001011110110111100011001011100101110000011100011010111101010101111101010101100100011010101001101010001001010000001011101011000010001010101100111011010010011101000000000010001001010110100110001111000111000000011000111111001001111001110001110111110101011110101001001100111111101000101001100100111011101101001010010000011000010110100111001110110100010110011000111110010011000100100110001110111110000111100001000011101000111101011110101100000110110010100000010011011001011001111111001111011011101001101101100011111101001101001111110011001011110000110110100101110010010111000101110001110110011100101011101001100101000110101011001100001001011110100100011110010111111000101010110000001100011110100110010111001101100110010010111011101100111101101110101001100000111010111111111011010010000100000001010110011011000001001000100000010010011000001001010111111001000100101011110010111101101111101101010100011010110101000010101111111101111110100100000101010101100110001101001010001111011100011011110001011100111000110101111000111110111110101101110100101000000010000001110001000100010110001110100100000001010111011001001101010110110001001111011010000101001010000011011010010010101111001101010001000101000000111010111001101100110000100001111010111110000011010101110101110100010000100100011010101010110100111100110011001101001110010010110001110110000110110000100101000011010101111010001110111110111101100110011011111111100011010110100010011101010101100110000100111110001101010101010010001001101011110011010001111100111000000111110011001100000000000111101101100100011010000101111100101111111100100010111010000101101110100001100101110101100100100010111110100000011111001011110101101110101100111000000111001110111111001111010100100110100111110100110000100101111101111101000000100101110110010100010011010000100011111101010010010111101011111101010010101110001100010001101110111100111001011000011101000000111001110101110010111101001001110001011101011001000111010101101101001100100001010101011111010011001111010101001100011001110100010000101010010111000111110110011111101110100100101011010110101111010010011110011111000111111100011011000000111110000011100110001101110111011001011101100001000001001000010101100010100110011011010101101001100000000101101011010001010110010001111110011101110000111000010100110001111001101010010001011111000010111011000010101110010101000110011001011101101011101000010100100010101110101111100010101111011011111010100000100100111100010101111001011011110001111110101011111110111101101000010110000010011010101111100101101010100001100110101110100110011010111010101111010101001111001101001011000011101110111101110111001110001000010011010101010100010000001010110001100101010011101001101110001111100101011001011011001100010111100011111100111010010101111000101101111100000100110110001011110000111000000010101010101001000110101010001000001101111001010000100011011100000101100010000010001101101101111010100111011111100110011001111100110011100101101101010000110100010100110000011000001100010100100000011101000011010001000101001111101100010111101001100011000101001001000001001010110111101100111010001010110110100101100010000001101000111100110000101001110101110011110111010011101000101110001111001110000100101001001110000001011000100010011100100111110000100010011011011110001111100010110101111111001110000110001001010101011000001110010010100000010100011000110011110000100101001110001010000010010001010111110111101101110000011011110001110001001010111110111011001010011001010111111011001110000010011010101101110000010111110111110100011011100100111011100111000000001111001110000111010010010011100000010001110110101011001110001111100100101100110000011001100010010000100000111110100011010010101101011101000010110010111111011001001100000110011010110111000111110110011100001101000011001111100101001101001110010111000011000001000100010001000010000000000011100010101001110010101111101110010001101010011000011111010111100101110011000111101010001111110011110010100110010111011110010000001101010011011110000011111011011101001011011011010011110001001000010100111101001101011110101101010011010011011001111000010111100111010001001010100010011010001100011110010101001000001100100000001001010110111001110001010001101011101110011010011010111000000110110110110010101000100001110110111010111101011101010111001110000000001011001110001010010010110110010011111110101010000100111111111010100010001011010000111111001001110011101111001001101110100010101111111010100000000011110001111110001001110110001000110100101100100100111101101011001111010100000101111101100011110101001111101100011011110101010111110001101000110010111111101100011001100101110110000101100011101011100000011110101110111000011110001110010111001010111001111101100011101011111100100111101100011001011011100011110001111000111101001011010000111001101111011011111110010011011100001101010101000101001100000101101111100011011100001101011101001101011000010111101110011111111110111110100111111000011110100101011110111111010101001001001011110110011011011101011010111100000111010101000111111011101001010001111110100000011010001100001111101111000101111111000001111110111100001110110101011001000000010000100011101011100101011011111110100000001100111111100001011011110101011010000011101111011001100011101001001001110111111001101110110010110101011110101111001011011101110001011010110000001111101101011001100101111000110011100111101101001010001111001000101010100011001111000100010011001001111000110110110111011100111000001110101111101001100001110001110000100100111010101001011110111000001010001101101000110100000000101101001101100110111111101100111010011110100111000010101010110100110111011100001101011110101001001011110111100110000011111100011010111000100111100010101100100010100010000111101011101100000111010110010100010100000001010110001001001010010010101110000000101100000101101000011011110011100111011101101100001000001100000101011101011100010010110010010010011110011101011100101101011101001000101100100110100000100100000001101010100111000011100111001001111110001100010011000100010000011100110100111100011110111001000110100111100010010110011010010110100001001101001010101111111111100100100111110011011010110111010000101001001011100111100001100101001111001010011011101000110101001010010110011100001010101111111100001100011000000111000111101011100110101010101111011111111110110110110111001101111110011100000111000010000011010100101100110110000111011011101000100001101111001001111111000001001100000111101111110001100011001001111100000111001000101001101110110101010000110011010000001100000111110001101101011000010100101010100101110011010101010011011110100101100101111001111000100110011001101010001010000110000101111001100000011010011100110011011100111100110111111100001001011100100111000010111000000100101000010100000101010100110011100011111110000011111101101011101011010011101100000011000011111111000111111110110011010000111000001000100100100010000010110011001110100110010011001001010111011010010000001000100010100001101001000000110100100111010110001110000100101100101100110111011111001000001000000000000111010010101101100010100011111010010010101101001100001100110011010111100001111001111011010110010101000000110110010000110100000101010101111001110100000001010101001010100101111010011011000100110011011100000100010101000001101110110010001000100100100100000110110010111111111000001111011110101011001110101010100110001001010001110010011001000101101001100010010110000101001101110001111010100001110011001010111001011100001101101001000100101010101000011100110010010000100101110010001001111000000010010111110111100110001100011011000110111010000101010001010100001110111001001000010101000110110000000010001001111111110000011110100001001010000011011010001101010101000100010001000101110110000000001110010011001011001000101001010010001110011000110011101000111111111100110111100001011000100001100010010110010100100000101010101000001111011110110100110000001100010100001011101101000101111101101100111101001001110110110100001110101100110111001000000011111010111100001110100000011110100010110011110010011100110000001000001010111001011110100010001111010111111101100000110110101001100111001111010011101110011100111110110110011011000111100100111101100101110100101001010011000000111110011010011000101011101110110010101110100110100111000001100101001100010001100101111101010101000010011001010101110001110000000111101100010001001101100001001010101010010100011100011010000100011010000111110001000110100001001111001001100100001100111111010010000111010011101101111101100010001001101100000010011110100000101001010110110100010101111001111001110000011100001000011011010001111010101101111111011100101101100001010111101011110100100011100111110111001001100011001001001100100000100101101000010110101100101100010110100001100111001111111000011001011001001000001010001000101010001010110100111011110000110010011101100000000000110000001010011001011000111100000101001001100111000001000110111111101110111100000001001110110001010101101100110111000111001101011011010100000010000100001101110000101101001100010000100111100110000101010100101000000101000101010101000111011010111101111011011111100001111101010000101100011001100010000111000000100011000100101111111000000010111111110110000100111111010010001000111111100111110001011101101010010011111101001101010110011011000010000110001101001000100111010001110111101010001010100010011000011101000101001110101100010100110101000100010111110010110011110011110101010111011100011110110000111111000010000001100011100001100111001111101110111111101"
	vector<vector<int>> queries = ArrayTo2dVector(inputs);
	vector<vector<int>> res= mysol.substringXorQueries(s, queries);
	for(int i=0; i<res.size(); i++){
		printvector(res[i]);
	}
  	
  	// cout<<mysol.countFairPairs(nums, lower, upper)<<endl;
 	return(0);	
}