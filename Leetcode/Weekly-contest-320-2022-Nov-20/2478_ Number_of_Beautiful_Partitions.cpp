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


You are given a string s that consists of the digits '1' to '9' and two integers k and minLength.

A partition of s is called beautiful if:

    s is partitioned into k non-intersecting substrings.
    Each substring has a length of at least minLength.
    Each substring starts with a prime digit and ends with a non-prime digit. Prime digits are '2', '3', '5', and '7', and the rest of the digits are non-prime.

Return the number of beautiful partitions of s. Since the answer may be very large, return it modulo 109 + 7.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "23542185131", k = 3, minLength = 2
Output: 3
Explanation: There exists three ways to create a beautiful partition:
"2354 | 218 | 5131"
"2354 | 21851 | 31"
"2354218 | 51 | 31"

Example 2:

Input: s = "23542185131", k = 3, minLength = 3
Output: 1
Explanation: There exists one way to create a beautiful partition: "2354 | 218 | 5131".

Example 3:

Input: s = "3312958", k = 3, minLength = 1
Output: 1
Explanation: There exists one way to create a beautiful partition: "331 | 29 | 58".

 

Constraints:

    1 <= k, minLength <= s.length <= 1000
    s consists of the digits '1' to '9'.


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


class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
    	int sLength = s.size();
    	vector<int> TransitionFromUnPrimeToPrime={-1};
    	if( (IsPrime(s[0])==0) || IsPrime(s[sLength-1]) )
    		return(0);
    	for(int i=1;i<sLength;i++){
    		if( (IsPrime(s[i-1]) == 0) && IsPrime(s[i]))
    			TransitionFromUnPrimeToPrime.push_back(i-1);//notice that i-1>=1, because s must starts with prime
    	}
    	TransitionFromUnPrimeToPrime.push_back(sLength-1);
    	// printvector(TransitionFromUnPrimeToPrime);
    	//NoOfTransitions are at most 501, 
    	int NoOfTransitions = TransitionFromUnPrimeToPrime.size();
    	//Now we will use memoimization
    	//for a range of [a,b], where a,b are in TransitionFromUnPrimeToPrime,
    	//we want to know the beautiful partitions bewteen this range
    	//and store it into some dictionary
    	//so here a and b are indices in TransitionFromUnPrimeToPrime
        //Notice that we need to make it into k partitions, this is disgusting.
        //instead we will consider all possible partitions that is below k.
        //the dynamic table will be iterating over k

    	//starting with k=1;
    	// int DynamicTableWidth = NoOfTransitions * (NoOfTransitions - 1)/2;

    	//actually we don't need to know the answer for each subrange of the string
    	//suffices to know the range from index a to index sLength-1, where a\in[0, sLength-2]
    	map<pair<int,int>, int> DynamicRow;
    	for(int i=0; i<NoOfTransitions; i++)
    		for(int j=i+1; j<NoOfTransitions; j++){
    			if(TransitionFromUnPrimeToPrime[j] - TransitionFromUnPrimeToPrime[i] >= minLength)
    				DynamicRow.insert(pair<pair<int,int>, int>{pair<int,int>{i,j}, 1});
    			else
    				DynamicRow.insert(pair<pair<int,int>, int>{pair<int,int>{i,j}, 0});
    		}

    	// cout<<DynamicRow[pair<int,int>{0,4}]<<endl;
    	for(int n=2; n<=k; n++){
    		map<pair<int,int>, int> NextDynamicRow;
    		for(int i=0; i<NoOfTransitions; i++)
    			for(int j=i+1;j<NoOfTransitions; j++){
    				//given start index i and end index j, we need to know the no of beautiful paritions of divividing this substring to 
    				//n partitions
    				//give we already know the answer to n-1 partitions
    				int temp = 0;
    				for(int k=i+1; k<j; k++){
    					//for the n partitions, assume that the 1st partition happens at the transition place k
    					//of course we need to satisfy the mininum length for i and k
    					if( TransitionFromUnPrimeToPrime[k] - TransitionFromUnPrimeToPrime[i] >= minLength &&
    						TransitionFromUnPrimeToPrime[j] - TransitionFromUnPrimeToPrime[k] >= minLength)
    						temp = (temp + DynamicRow[pair<int,int>{k,j}])%LargePrime;
    				}
    				NextDynamicRow.insert(pair<pair<int,int>, int>{pair<int,int>{i,j}, temp});
    			}
    		DynamicRow = NextDynamicRow;
    		// cout<<DynamicRow[pair<int,int>{0,4}]<<endl;	
    	}
    	

    	pair<int,int> key{0, NoOfTransitions-1};
    	return(DynamicRow[key]);


    }
    
private:
	
	int LargePrime = pow(10,9)+7;

	int IsPrime(char c)
	{
		if( c == '2' || c == '3' || c == '5' || c == '7' )
			return(1);
		else
			return(0);
	}
	
	vector<queue<TreeNode*>> BFS(TreeNode* root){
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
	
	long long fuels = 0;
	
	int DFS(int root, int NoOfCities, vector<vector<int>>& NeighborsOfCities, vector<int>& CitiesVisited, int seats){
        CitiesVisited[root]=1;
        int NoOfPplInThisCity = 1;
        for(const auto &i:NeighborsOfCities[root])
        {
        	if(CitiesVisited[i]==0)
        	{
        		NoOfPplInThisCity = NoOfPplInThisCity + DFS(i, NoOfCities, NeighborsOfCities, CitiesVisited, seats);
        	}	
        }
        CitiesVisited[root]=2;
        if(NoOfPplInThisCity%seats)
        	fuels = fuels + NoOfPplInThisCity/seats+1;
        else
        	fuels = fuels + NoOfPplInThisCity/seats;
        return(NoOfPplInThisCity);
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
	// string s = "23542185131";
	// int k = 3;
	// int minLength = 2;

	// string s = "23542185131";
	// int k = 3;
	// int minLength = 3;

	// string s = "3312958";
	// int k = 3;
	// int minLength =1;

	string s = "729852992687486265668477896177579456254254899874352895541618737989265536736998595242549357183142531171469787694947173595283871938636589875149946196173557627376732771482478316339784285325422441545891251396713433647643278494162873375215457434129798923228274147645522234624573746757451123695639785267881669895261999851194176877622152537756168463982877422387475943297763971484655114887335457991324976693286172424553759";
	int k = 59;
	int minLength = 6;
	cout<<mysol.beautifulPartitions(s,k,minLength)<<endl;
	return(0);
    
}