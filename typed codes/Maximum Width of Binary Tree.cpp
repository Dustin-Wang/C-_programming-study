include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
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
typedef int int ll;
typedef pair<int, int> pii;
// END NO SAD
// REMEMBER CLEAR GLOBAL STATE


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 struct NodeAndPos{
 	TreeNode* node;
 	unsigned long long pos;
 };

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
	    if (root==NULL){
	    	return 0;
	    }
	    NodeAndPos st;
	    st.node=root;
	    st.pos=1;	
	    vector<NodeAndPos> cur;
	    cur.push_back(st);
	    vector<NodeAndPos> next;
	    unsigned long long res=1;
	    unsigned long long l=0;
	    unsigned long long r=0;
	    while(!cur.empty()){
	    	l=cur.front().pos;r=0;
	    	next.clear();
	    	for(auto const&c: cur){
	    		r=c.pos;
	    		if (c.node->left!=NULL){
	    			NodeAndPos tmp;
	    			tmp.node=c.node->left;
	    			tmp.pos=2*c.pos-1;
	    			next.push_back(tmp);
	    		}
	    		if (c.node->right!=NULL){
	    			NodeAndPos tmp;
	    			tmp.node=c.node->right;
	    			tmp.pos=2*c.pos;
	    			next.push_back(tmp);
	    		}
	    	}
	    	//cout<<r<<" "<<l<<endl;
	    	if (r-l+1>res)
	    		res=r-l+1;
	    	cur=next;
	    }
	    return res;
    }
};