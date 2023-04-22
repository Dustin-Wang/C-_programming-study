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
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int s1=count(firstWord);
        int s2=count(secondWord);
        int s3=count(targetWord);
        if((s1+s2)!=s3)
        	return false;
        else
        	return true;

    }
private:
	int count(string Word){
		int sum=0;
		for(const auto&c:Word){
			sum=sum*10+c-'a';
		}
		return sum;
	}
};

int main(){
	Solution mysol;
	string firstWord="j";
	string secondWord="j";
	string targetWord="bi";
	printf("%d",mysol.isSumEqual(firstWord,secondWord,targetWord));
}