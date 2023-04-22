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
using namespace std;
// BEGIN NO SAD
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
// END NO SAD
// REMEMBER CLEAR GLOBAL STATE


//  Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
	    vector<vector<int>> levelOrderBottom(TreeNode* root) {
	    queue<TreeNode*> tlq;
	    tlq.push(root);
	    queue<TreeNode*> nlq;
	    vector<vector<int>> res;
	    vector<int> tl;
	    while(!tlq.empty()){
	        while(!tlq.empty()){
	    	   root=tlq.front();
	    	   tlq.pop();
	    	   if (root!=NULL){
	    		   nlq.push(root->left);
	    		   nlq.push(root->right);
	    		  tl.push_back(root->val);
	    	   }
	       }
	       tlq.swap(nlq);
	       res.push_back(tl);  
	       tl.clear();
	    }
	    res.pop_back();
	    reverse(all(res));
	    return res;
	    }
};