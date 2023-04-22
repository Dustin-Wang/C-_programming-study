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

using namespace std;
// BEGIN NO SAD
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
// END NO SAD
// REMEMBER CLEAR GLOBAL STATE

/**
 * Definition for a binary tree node.*/
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
    int sumNumbers(TreeNode* root) {
        if (root==nullptr){
        	return 0;
        }
        return sumIter(root, 0);
    }
    int sumIter(TreeNode* root, int pa){
    	if (root->left==nullptr && root->right==nullptr){
    		return pa*10+root->val;
    	}
    	else if (root->left==nullptr){
    		return sumIter(root->right, pa*10+root->val);
    	}
    	else if (root->right==nullptr){
    		return sumIter(root->left,pa*10+root->val);
    	}
    	else{
    		return sumIter(root->left, pa*10+root->val)+sumIter(root->right, pa*10+root->val)
    	}
    }
};