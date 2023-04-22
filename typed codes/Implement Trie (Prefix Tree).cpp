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

class Node{
private:
	map<char,Node*> n;
	bool end;
public:
	Node(){
		end=false;
	}
	void Nodeend(){
		end=true;
	}
	bool Nodeendornot(){
		return end;
	}
	Node* Nodefind(char c){
		if (n.find(c)==n.end()){
			return nullptr;
		}
		return n[c];
	}
	Node* Nodeinsert(char c){
		if(n.find(c)==n.end()){
		   n[c]=new Node();
		}
		return n[c];
	}
	bool Nodemapempty(){
		return n.empty();
	}
};

class Trie {
private:
	Node root;
public:
    /** Initialize your data structure here. */
    Trie(){
    	//cout<<"hell"<<endl;
    	Node root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
    	Node* start;
    	start=&root;
        for(auto const&c: word){
        	//cout<<c<<endl;
        	start=(*start).Nodeinsert(c);
        }
        (*start).Nodeend();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* start;
    	start=&root;
        for(auto const&c: word){
        	start=(*start).Nodefind(c);
        	if (start==nullptr){
        		return false;
        	}
        }
        if ((*start).Nodeendornot()){
        	return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* start;
    	start=&root;
        for(auto const&c: prefix){
        	start=(*start).Nodefind(c);
        	if (start==nullptr){
        		return false;
        	}
        }
        return true;
    }


};


int main(){
	Trie* obj=new Trie();
	//cout<<"h"<<endl;
	string word1="apple";
	string word2="app";
	obj->insert(word1);
	cout<<obj->search(word1)<<endl;
	cout<<obj->search(word2)<<endl;
	cout<<obj->startsWith(word2)<<endl;
	obj->insert(word2);
	cout<<obj->search(word2)<<endl;
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */