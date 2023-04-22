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


You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.

Example 3:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.

 

Constraints:

    bloomDay.length == n
    1 <= n <= 10^5
    1 <= bloomDay[i] <= 10^9
    1 <= m <= 10^6
    1 <= k <= n


*/
#include <iterator>
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
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        //first verify that it is possible to make m bouquets, each consisting of k adjacent flowers
        int NoOfFlowers = bloomDay.size();
       
        //let us use bisection method
        int UpperBound = pow(10,9);

        int LowerBound = 0;

        while( LowerBound <= UpperBound)
        {
            int Mid = (UpperBound + LowerBound)/2;
            //for this Mid, try to see how many bouquets we could make
            int NoOfFlowerBloomedAdjacent = 0;
            int NoOfBouquets = 0;
            for(int i=0; i<NoOfFlowers; i++)
            {
                
                if(bloomDay[i]<=Mid){
                    NoOfFlowerBloomedAdjacent++;
                }
                else{
                    //well we come across a flower that didn't bloom.
                    //now we need to check how many bouquets can be made from this block
                    NoOfBouquets += NoOfFlowerBloomedAdjacent/k;
                    NoOfFlowerBloomedAdjacent = 0;//qing 0
                }
            }
            NoOfBouquets += NoOfFlowerBloomedAdjacent/k;
            // printf("NoOfBouquets: %d\n", NoOfBouquets);
            fflush(stdout);
            if(NoOfBouquets>=m){
                UpperBound = Mid-1;//Upper Bound might not be able to generate m bouquets in the end
                // printf("UpperBound: %d; LowerBound: %d\n", UpperBound, LowerBound);
                
            }
            else{
                LowerBound = Mid +1;//Upper Bound wil be able to generate m bouquets in the end
                // printf("UpperBound: %d; LowerBound: %d\n", UpperBound, LowerBound);
            }
            // fflush(stdout);
        }
        if(LowerBound>pow(10,9))
            return(-1);
        return(LowerBound);
    }
    
private:
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
    
    // vector<int> bloomDay ={1,10,3,10,2};
    // int m = 3;
    // int k =1;

    vector<int> bloomDay ={1,10,3,10,2};
    int m = 3;
    int k = 2 ;

    // vector<int> bloomDay ={7,7,7,7,12,7,7};
    // int m = 2;
    // int k = 3 ;
    cout<<mysol.minDays(bloomDay, m, k)<<endl;

	   
	// int array[][4] ={{1,3,1,15},{1,3,3,1}};
    //vector<vector<int>> mat = ArrayTo2dVector(array);
	
    
    
}