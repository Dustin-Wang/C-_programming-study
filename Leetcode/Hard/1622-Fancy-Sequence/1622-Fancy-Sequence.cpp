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
Write an API that generates fancy sequences using the append, addAll, and multAll operations.

Implement the Fancy class:

    Fancy() Initializes the object with an empty sequence.
    void append(val) Appends an integer val to the end of the sequence.
    void addAll(inc) Increments all existing values in the sequence by an integer inc.
    void multAll(m) Multiplies all existing values in the sequence by an integer m.
    int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.

 

Example 1:

Input
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
Output
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

Explanation
Fancy fancy = new Fancy();
fancy.append(2);   // fancy sequence: [2]
fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
fancy.append(7);   // fancy sequence: [5, 7]
fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
fancy.getIndex(0); // return 10
fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
fancy.append(10);  // fancy sequence: [13, 17, 10]
fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
fancy.getIndex(0); // return 26
fancy.getIndex(1); // return 34
fancy.getIndex(2); // return 20

 

Constraints:

    1 <= val, inc, m <= 100
    0 <= idx <= 105
    At most 105 calls total will be made to append, addAll, multAll, and getIndex.


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
    Fancy() {
        n=0;
        Idx=0;
        return;
    }
    
    void append(int val) {
        IdxAndVal.push_back(val);
        IdxAndnMap.insert(pair<int,int>{Idx,n});
        // printvector(IdxAndVal);
        Idx++;
    }
    
    void addAll(int inc) {
        // An.push_back(1);
        // Bn.push_back(inc);
        n++;
        for(int i=0; i<n-1; i++){
        	// MultipliedFromJToN[i] = (MultipliedFromJToN[i]+inc)%LargePrime;
        	ToBeAddedFromJToN[i] = (ToBeAddedFromJToN[i]+inc)%LargePrime;
        }
        MultipliedFromJToN.push_back(1);
        ToBeAddedFromJToN.push_back(inc);
        // printvector(MultipliedFromJToN);
        // printvector(ToBeAddedFromJToN);
    }
    
    void multAll(int m) {
    	// An.push_back(m);
        // Bn.push_back(0);
        n++;

        for(int i=0; i<n-1; i++){
        	MultipliedFromJToN[i] = (MultipliedFromJToN[i]*m)%LargePrime;
        	ToBeAddedFromJToN[i] = (ToBeAddedFromJToN[i]*m)%LargePrime;
        }
        MultipliedFromJToN.push_back(m);
        ToBeAddedFromJToN.push_back(0);
        // printvector(MultipliedFromJToN);
        // printvector(ToBeAddedFromJToN);
    }
    
    int getIndex(int idx) {
    	if(idx >= IdxAndVal.size())
    		return(-1);
        int x = IdxAndVal[idx];
        int idxN = IdxAndnMap[idx];
        if(idxN == n)
        	return(x);
        int res = ((x*MultipliedFromJToN[idxN])%LargePrime + ToBeAddedFromJToN[idxN])%LargePrime;
        return(res);
    }
private:
	//a_3(a_2(a_1x+b_1)+b_2)+b_3 = a_3a_2a_1x+a_3a_2b_1+a_3b_2+b_3
	//each multiply: a_i = m; b_i =0;
	//each addition: a_i=1; b_i = inc;
	int n;
	int Idx;
	// vector<int> An;
	// vector<int> Bn;
	vector<long> ToBeAddedFromJToN;
	vector<long> MultipliedFromJToN;
	map<int,int> IdxAndnMap;
	vector<int> IdxAndVal;
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
	// Solution mysol;
	Fancy fancy;
	// int val = 3;
	// int inc = 3;
	// int m = 3;
	// int idx = 0;
 //   	
 //   	obj->append(val);
 //   	obj->addAll(inc);
 //   	obj->multAll(m);
 //   	int param_4 = obj->getIndex(idx);
 //    cout<<param_4<<endl;


	// fancy.append(2);   // fancy sequence: [2]
	// fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
	// fancy.append(7);   // fancy sequence: [5, 7]
	// fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
	// cout<<fancy.getIndex(0)<<endl;; // return 10
	// fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
	// fancy.append(10);  // fancy sequence: [13, 17, 10]
	// fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
	// cout<<fancy.getIndex(0)<<endl; // return 26
	// cout<<fancy.getIndex(1)<<endl; // return 34
	// cout<<fancy.getIndex(2)<<endl; // return 20


	// ["Fancy","append","getIndex","multAll","append","getIndex","append","addAll","getIndex"]
	// [[],[8],[0],[7],[5],[0],[3],[6],[0]]
	fancy.append(8);//8
	cout<<fancy.getIndex(0)<<endl;//8
	fancy.multAll(7);//8*7 = 56;
	fancy.append(5);//[8*7, 5]
	cout<<fancy.getIndex(0)<<endl;//56
	fancy.append(3);//[8*7,5,3]
	fancy.addAll(6);//[8*7+6, 5+6, 3+6]
	cout<<fancy.getIndex(0)<<endl;

	// ["Fancy","append","append","getIndex","getIndex","multAll","append","getIndex","getIndex"]
	// [[],[3],[2],[0],[0],[3],[2],[2],[2]]
	fancy.append(3);//3
	fancy.append(2);//3,2
	cout<<fancy.getIndex(0)<<endl;//3
	cout<<fancy.getIndex(0)<<endl;//3
	fancy.multAll(3);//
	fancy.append(2);
	cout<<fancy.getIndex(2)<<endl;//56
	fancy.append(3);//[8*7,5,3]
	fancy.addAll(6);//[8*7+6, 5+6, 3+6]
	cout<<fancy.getIndex(0)<<endl;
	return(0);
    
}