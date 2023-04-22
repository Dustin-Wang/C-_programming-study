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

class solution{
public:
  int valid(string s){
    if (s.size()==0)
      return 1;
    stack<char> process;
    for(const auto c: s){
      if(c!='('&& c!='{'&&c!='['&&c!=')'&&c!='}'&&c!=']') continue;
      if(c=='(' || c=='{'||c=='[')
        process.push(c);
      else if(c==')'&&process.top()=='(')
        process.pop();
      else if(c=='}'&&process.top()=='{')
        process.pop();
      else if(c==']'&&process.top()=='[')
        process.pop();
      else
        return 0;
    }
    if(process.size()!=0)
      return 0;
    return 1;
  }
};


// To execute C++, please define "int main()"
int main() {
  string s="{ [] ( ) }";
  string s1="{ [(] ) }";
  string s2="{ [ }";
  solution* mysol=new solution();
  printf("test s: %d; test s1: %d; test s2: %d\n",mysol->valid(s),mysol->valid(s1),mysol->valid(s2));
  return 0;
}

//-'(', '{', '[' are called "_openers_."
//- ')', '}', ']' are called "_closers_."

