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
#include <deque>

using namespace std;
// BEGIN NO SAD
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
// END NO SAD
// REMEMBER CLEAR GLOBAL STATE
using namespace std;

/*
 * Complete the 'receivedText' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING S as parameter.
 */
// faile one test case

string receivedText(string S) {
    // WRITE DOWN YOUR CODE HERE
    deque<char> res;
    deque<char>::iterator it=res.begin();//iterator will point to the index where new character will be on
    int numlock=0;
    for(char& c:S){
    	if (c=='*'&& it!=res.begin())
    		it=res.erase(it-1);
    	else if (c=='<')
    		it=res.begin();
    	else if (c=='>')
    		it=res.end();
    	else if (c=='#')
    		numlock=1-numlock;
    	else{
    		if (!(numlock==1 && c>='0' && c<='9'))
    			it=res.insert(it,c)+1;
    	}
    }
    string s;
    for(char&c :res)
        s+=c;
    return s;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string S;
    getline(cin, S);

    string result = receivedText(S);

    fout << result << "\n";

    fout.close();

    return 0;
}
