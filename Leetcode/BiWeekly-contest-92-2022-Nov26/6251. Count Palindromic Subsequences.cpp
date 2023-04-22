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

Given a string of digits s, return the number of palindromic subsequences of s having length 5. Since the answer may be very large, return it modulo 109 + 7.

Note:

    A string is palindromic if it reads the same forward and backward.
    A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

 

Example 1:

Input: s = "103301"
Output: 2
Explanation: 
There are 6 possible subsequences of length 5: "10330","10331","10301","10301","13301","03301". 
Two of them (both equal to "10301") are palindromic.

Example 2:

Input: s = "0000000"
Output: 21
Explanation: All 21 subsequences are "00000", which is palindromic.

Example 3:

Input: s = "9999900000"
Output: 2
Explanation: The only two palindromic subsequences are "99999" and "00000".

 

Constraints:

    1 <= s.length <= 104
    s consists of digits.



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
	int m = input.size();
	int depth = ceil(log2(double(m)));
	//fill in the extra nullptr leaves in the given input
	for(int i = m; i< pow(2, depth)-1; i++)
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
    int countPalindromes(string s) {
        //here we only need length 5 subseequence
        int sLength = s.length();
        if(sLength<5)
            return(0);
        int res = 0;
        vector<int> CandidatesForPalindromes(10,0);//index i, means the subsequence of length 4
        //that will become palindrome if we add i to the end, that is, satsify abcb form
        map<pair<int,int>, int> ABC;//index i,j, means the number of subsequence that is in the form of ABC, A= i,B=j
        for(int i=0;i<10;i++)
            for(int j=0;j<10; j++){
                ABC.insert(pair<pair<int,int>,int>{pair<int,int>{i,j}, 0});
            }
        
        map<pair<int,int>, int> AB;//index i,j, means the number of subsequence that is in the form of AB, A= i,B=j
        for(int i=0;i<10;i++)
            for(int j=0;j<10; j++){
                AB.insert(pair<pair<int,int>,int>{pair<int,int>{i,j}, 0});
            }

        vector<int> A(10,0);//number of As


        // if(s[1]==s[3])
        //     CandidatesForPalindromes[s[0]-'0']++;

        // ABC[s[1]-'0']=2;
        

        // ABC[s[2]-'0']=2;
        
        
        for(int i=0; i<sLength; i++ ){
            res = (res+ CandidatesForPalindromes[s[i]-'0'])%bigprime;
            //need to change candidates for Palindromes too
            //count how many abc we have where b= s[i]
            for(int k=0;k<10;k++)
            {
                CandidatesForPalindromes[k] = (CandidatesForPalindromes[k] + ABC[pair<int,int>{k,s[i]-'0'}])%bigprime;    
            }
            
            for(int a=0;a<10;a++)
                for(int b=0; b<10;b++){
                    ABC[pair<int,int>{a,b}] = (ABC[pair<int,int>{a,b}]+AB[pair<int,int>{a,b}])%bigprime;
                }

            for(int a=0;a<10;a++){
                AB[pair<int,int>{a,s[i]-'0'}] = (AB[pair<int,int>{a,s[i]-'0'}]+A[a])%bigprime;
            }

            A[s[i]-'0']++;
                
            
            // printvector(CandidatesForPalindromes);
            // printvector()
            // ABC[s[i-1]-'0'] = (ABC[s[i-1]-'0']+i-1)%bigprime;

        }
        return(res);
    }
    
private:
	int bigprime=pow(10,9)+7;
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
	// string customers = "103301";
    // string customers = "0000000";
    string customers = "9999900000";
    cout<<mysol.countPalindromes(customers)<<endl;
	return(0);
    
}