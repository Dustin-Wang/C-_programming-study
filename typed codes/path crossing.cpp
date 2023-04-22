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
    bool isPathCrossing(string path) {
    	set<pii> pos;
    	pii p(0,0);
    	pos.insert(p);
    	pii pn;
    	for(char &c:path){
            //cout<<c;
    		switch (c){
    			case 'N':
    			     pn=pii(p.first,p.second+1);
                     break;
    			case 'W':
    			     pn=pii(p.first-1,p.second);
                     break;
    			case 'E':
    			     pn=pii(p.first+1,p.second);
                    break;
    			case 'S':
    			     pn=pii(p.first,p.second-1);
                    break;
    		}
            //cout<<pn.first<<' '<<pn.second<<endl;
    		if (pos.find(pn)!=pos.end())
    			return true;
    		pos.insert(pn);
    		p=pn;
    	}
    	return false;
    }
};