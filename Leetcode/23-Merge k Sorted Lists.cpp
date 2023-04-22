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
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
// REMEMBER CLEAR GLOBAL STATE



struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		vector<ListNode*> heappointer;
		for(const auto &c : lists){
            if(c!=nullptr)
                heappointer.push_back(c);
		}
        if(heappointer.size()==0)
            return nullptr;
		buildminheap(heappointer);
        
        ListNode* res=new ListNode(heappointer[0]->val);
        ListNode* cur=res;
       // printf("\n cur->value: %d\n", cur->val);    
		while(heappointer.size()>0){
			if(heappointer[0]->next==nullptr){
                if(heappointer.size()==1){
                    //cur=new ListNode(heappointer[0]->val);
                    //printf("\n cur->value: %d\n", cur->val);
                    //printf("\n res->value: %d\n", res->val);
                    break;
                }
				heappointer[0]=heappointer[heappointer.size()-1];
				heappointer.pop_back();
			}
			else{
				heappointer[0]=heappointer[0]->next;
			}
            minheapify(heappointer,1);
            /*for(const auto &test:heappointer)
                printf("%d  ",test->val);
            printf("\n");*/
			cur->next=new ListNode(heappointer[0]->val);
            cur=cur->next;
            //printf("\n cur->value: %d\n", cur->val);      
		}
        
		return res;
        
    }
private:
	int parent(int i){
		return i/2;
	}
	int left(int i){
		return 2*i;
	}
	int right(int i){
		return 2*i+1;
	}
	void minheapify(vector<ListNode*>& heappointer, int i){
		int l=left(i);
		int r=right(i);
        //printf("i:%d l: %d r: %d\n",i, l,r);
		int smallest=i;
		if (l<=heappointer.size() && heappointer[l-1]->val<heappointer[smallest-1]->val){
			smallest=l;
		}
		if (r<=heappointer.size() && heappointer[r-1]->val<heappointer[smallest-1]->val){
			smallest=r;
		}
        //printf("i: %d smallest: %d\n",i,smallest);
		if(smallest!=i){
			ListNode* tmp=heappointer[i-1];
			heappointer[i-1]=heappointer[smallest-1];
			heappointer[smallest-1]=tmp;
			minheapify(heappointer,smallest);
		}
	}
	void buildminheap(vector<ListNode*>& heappointer){
		for(int i=heappointer.size()/2;i>=1;i--){
            //printf("%i  ",i);
			minheapify(heappointer,i);
		}
	}
};