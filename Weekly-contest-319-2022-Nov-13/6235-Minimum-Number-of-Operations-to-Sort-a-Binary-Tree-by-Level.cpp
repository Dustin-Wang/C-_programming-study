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


You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their values.

Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.

The level of a node is the number of edges along the path between it and the root node.

 

Example 1:

Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
Output: 3
Explanation:
- Swap 4 and 3. The 2nd level becomes [3,4].
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.

Example 2:

Input: root = [1,3,2,7,6,5,4]
Output: 3
Explanation:
- Swap 3 and 2. The 2nd level becomes [2,3].
- Swap 7 and 4. The 3rd level becomes [4,6,5,7].
- Swap 6 and 5. The 3rd level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.

Example 3:

Input: root = [1,2,3,4,5,6]
Output: 0
Explanation: Each level is already sorted in increasing order so return 0.

 

Constraints:

    The number of nodes in the tree is in the range [1, 105].
    1 <= Node.val <= 105
    All the values of the tree are unique.



*/
#include <iterator>
template<typename T>
void printvector(vector<T> vector)
{
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


void PrintQueueInIntBinaryTree(queue<TreeNode*> queue)
{
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

TreeNode* ArrayToBinaryTree(vector<string> input)
{
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
			PrintQueueInIntBinaryTree(NextLevel);
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
		PrintQueueInIntBinaryTree(NextLevel);
		prevLevel = NextLevel;
	}
	return(root);
}


class Solution {
public:
    int minimumOperations(TreeNode* root) {
        vector<queue<TreeNode*>> LevelArrays = BFS(root);
        int count = 0;
        for( auto Level : LevelArrays)
        {
            vector<int> LevelArray;
            while(!Level.empty())
            {
                LevelArray.push_back(Level.front()->val);
                Level.pop();   
            }
            // printvector(LevelArray);
            count += MinimumSwapsToSort(LevelArray);
        }
        return(count);
    }
    int MinimumSwapsToSort( vector<int> A )
    {
        
        int length = A.size();
        map<int, int> ValueToIndex;
        for(int i=0; i<length; i++)
            ValueToIndex[A[i]] = i;

        sort(begin(A), end(A));
        //constrct permuation
        vector<int> permuation;
        for(auto it : A)
            permuation.push_back(ValueToIndex[it]);

        //https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
        vector<int> visited(length,0);

        int MinSwap = 0;
        for(int i=0; i< length; i++)
        {
            if(visited[i])
                continue;
            else
            {
                //walk over the cyle
                int prev = i;
                int cyclelength = 0;
                while(visited[prev]==0)
                {
                    visited[prev] = 1;
                    prev = permuation[prev];
                    cyclelength++;
                }
                MinSwap += cyclelength - 1 ;
            }
        }
        return(MinSwap);
    }
private:
	vector<queue<TreeNode*>> BFS(TreeNode* root)
    {
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
	
};
template <size_t rows, size_t cols>
vector<vector<int>> ArrayTo2dVector(int (&array)[rows][cols])
{
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
    // vector<int> sampleInput = {8,2,3,5};
    // cout<<mysol.MinimumSwapsToSort(sampleInput)<<endl;

  //   TreeNode* ll = new TreeNode(7);
  //   TreeNode* lr = new TreeNode(6);
  //   TreeNode* l = new TreeNode(4,ll,lr);
  //   TreeNode* rll = new TreeNode(9);
  //   TreeNode* rlr = nullptr;
  //   TreeNode* rl = new TreeNode(8,rll,rlr);

  //   TreeNode* rrl = new TreeNode(10);
  //   TreeNode* rrr = nullptr;
  //   TreeNode* rr = new TreeNode(5,rrl, rrr);

  //   TreeNode* r = new TreeNode(3, rl, rr);
 	// TreeNode* root = new TreeNode(1, l, r);



    // vector<string> tree2 = {"1","3","2","7","6", "5", "4"};
    // TreeNode* root = ArrayToBinaryTree(tree2);
    // cout<<mysol.minimumOperations(root)<<endl;

	vector<string> tree2 = {"1","2","3","4","5", "6"};
    TreeNode* root = ArrayToBinaryTree(tree2);
    cout<<mysol.minimumOperations(root)<<endl;
	// int array[][4] ={{1,3,1,15},{1,3,3,1}};
    //vector<vector<int>> mat = ArrayTo2dVector(array);
	
    
    
}