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


A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

    For example, "Hello World", "HELLO", "hello world hello world" are all sentences.

Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.

A sentence is circular if:

    The last character of a word is equal to the first character of the next word.
    The last character of the last word is equal to the first character of the first word.

For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.

Given a string sentence, return true if it is circular. Otherwise, return false.

 

Example 1:

Input: sentence = "leetcode exercises sound delightful"
Output: true
Explanation: The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
- leetcode's last character is equal to exercises's first character.
- exercises's last character is equal to sound's first character.
- sound's last character is equal to delightful's first character.
- delightful's last character is equal to leetcode's first character.
The sentence is circular.

Example 2:

Input: sentence = "eetcode"
Output: true
Explanation: The words in sentence are ["eetcode"].
- eetcode's last character is equal to eetcode's first character.
The sentence is circular.

Example 3:

Input: sentence = "Leetcode is cool"
Output: false
Explanation: The words in sentence are ["Leetcode", "is", "cool"].
- Leetcode's last character is not equal to is's first character.
The sentence is not circular.

 

Constraints:

    1 <= sentence.length <= 500
    sentence consist of only lowercase and uppercase English letters and spaces.
    The words in sentence are separated by a single space.
    There are no leading or trailing spaces.


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

class Fancy {
	/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */

public:
    bool isCircularSentence(string sentence) {
    	int sLen = sentence.length();
    	if(sLen==0)
    		return(1);
    	for(int i=0; i<sLen; i++){
    		if(sentence[i]==' ' && i+1<sLen){
    			if(sentence[i-1] != sentence[i+1])
    				return(0);
    		}
    	}
    	if(sentence[sLen-1]!=sentence[0])
    		return(0);
    	return(1);  
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
	

	return(0);
    
}