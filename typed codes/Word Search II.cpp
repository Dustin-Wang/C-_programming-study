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

define MAX_NODES 10000
class Trie {
    struct Trienode
    {
        char val;
        int count;//how many words pass through this Trienode
        int wordindex;
        Trienode *child[26];
    };
    Trienode *root;
    
    Trienode *getNode(int index)
    {
        Trienode *newnode = new Trienode;
        newnode->val = 'a'+index;
        newnode->count = newnode->endsHere = 0;
        for(int i=0;i<26;++i)
            newnode->child[i] = NULL;
        return newnode;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        //ios_base::sync_with_stdio(false);
        //cin.tie(NULL);
        root = getNode('/'-'a');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word, int i) {
        Trienode *curr = root;
        int index;
        for(int i=0;word[i]!='\0';++i)
        {
            index = word[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index] = getNode(index);
            curr->child[index]->count +=1;
            curr = curr->child[index];
        }
        curr->wordindex =i;
    }
    
    /** Returns if the word is in the trie. */
    int search(string word) {
        Trienode *curr = root;
        int index;
        for(int i=0;word[i]!='\0';++i)
        {
            index = word[i]-'a';
            if(curr->child[index]==NULL)
                return false;
            curr = curr->child[index];
        }
        return curr->wordindex;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trienode *curr = root;
        int index;
        for(int i=0;prefix[i]!='\0';++i)
        {
            index = prefix[i]-'a';
            if(curr->child[index]==NULL)
                return false;
            curr = curr->child[index];
        }
        return (curr->count > 0);
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        string allword="";
        int rs=sz(board);
        if (rs==0)
            return vector<string>();
        int cs=sz(board[0]);
        vector<vector<bool>> visited;
        for(int i=0;i<rs;i++){
            visited.push_back(vector<bool>(cs,false));
        }
        Trie bt;
        for (int i=0;i<sz(words);i++){
            bt.insert(words[i],i);
        }
        for(int i=0;i<rs;i++){
            for(int j=0;j<rs;j++){
                string cand="";

            }
        }
        
    }
private:
    int DFSvariant(int rs, int cs,vector<vector<char>>& board,vector<vector<bool>> visited,int i,int j,string& cand, Trie& bt){
        cand.push_back(board[i][j]);
        if (!bt.startsWith(cand)){
            return 0;
        }
        else{
            
        }

    }
};