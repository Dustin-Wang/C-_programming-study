#include <algorithm>
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


class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
    	Node* res=head;
    	while(head!=NULL){
    		if (head->child==NULL)
    			head=head->next;
    		else{
    			Node* tmp=head->next;
    			head->next=head->child;
    			head->next->prev=head;
    			head->child=NULL;
    			if (tmp!=NULL)
    	   			tmp->prev=findEnd(head->next,tmp);
    			head=head->next;
    		}
    	}
    	//test
    	Node* s=res;
    	while(s->next!=NULL){
    		cout<<s->val<<" ";
    		s=s->next;
    	}
    	while(s->prev!=NULL){
    		cout<<s->val<<" ";
    		s=s->prev;
    	}
    	return res;
    }
private:
	Node* findEnd(Node* head,Node* son){
		while(head->next!=NULL){
			head=head->next;
		}
		head->next=son;
		return head;
	}
};