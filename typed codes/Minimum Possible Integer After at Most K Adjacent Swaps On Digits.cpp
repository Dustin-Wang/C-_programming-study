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

class Solution {
public:
    string minInteger(string num, int k) {
    // int l=num.size();
    // vector<int> minid{10,l};
    // for(int i=0;i<l;i++){
    // 	if (minid[num[i]-'0']>i){
    //         minid[num[i]-'0']=i;
    //     }
    // }
    // string res;
    // while(k>0){
    // 	map<int,list<int>>::iterator it=dict.begin();
    // 	int lead=it->first;
    // 	int sum=0;
    // 	for()
    // }
        int l=num.size();
        int s=0;
        //int tmp;
        while(k>0 && s<l){
            while(num[s]=='0'){
                s++;
            }
            int mini=10;
            int minid=l;
            for(int i=s;i< min(l,s+k+1);i++){
                //cout<<num[i]<<" "<<mini<<endl;
                if (num[i]-'0'<mini){
                    mini=num[i]-'0';
                    //cout<<"here";
                    minid=i;
                }
            }
            //cout<<s<<" "<<mini<<" "<<minid<<endl;
            if(minid>s){
               //swap(num[s],num[minid]);
               //char tmp=mini+'0';
               num.erase(minid,1);
               num.insert(s,1,mini+'0');
               k-=minid-s;
            }
            //cout<<k<<" "<<num<<endl;
            s++;
        }
        return num;

    }
};

int main(){
	Solution* m=new Solution();
	string num="9438957234785635408";int k=23;
	cout<<m->minInteger(num,k)<<endl;
}