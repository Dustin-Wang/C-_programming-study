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
#include <unordered_map>

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
    string maximumNumber(string num, vector<int>& change) {
    	string res="";
    	int NumLen=num.size();
    	int flag=0;
    	for(int i=0;i<NumLen;i++){
    		int Digit=num[i]-'0';
    		if(flag==0 && change[Digit]<=Digit){
    			res.push_back('0'+Digit);
    			continue;
    		}
    		else if(flag==0 && change[Digit]>Digit){
    			flag=1;
    			res.push_back('0'+change[Digit]);
    			continue;
    		}
    		if(flag==1){
    			if(change[Digit]<Digit){
    				flag==0;
    				res.append(num,i,NumLen-i);
    				i=NumLen;
    			}
    			else if(change[Digit]>=Digit){
    				res.push_back('0'+change[Digit]);
    			}
    		}
    	}
    	if(res!=""){
    		return res;
    	}
    	else{
    		return num;
    	}
    	       
    }
};



template <size_t rows, size_t cols>
vector<vector<int>> ArrayTo2dVector(int (&array)[rows][cols])
{
    vector<vector<int>> res;
    for (size_t i = 0; i < rows; ++i)
    {
        vector<int> row;
        for (size_t j = 0; j < cols; ++j)
            row.push_back(array[i][j]);
        res.push_back(row);
    }
    return res;
};
int main(){
	Solution mysol;
    //string num="132"; vector<int> change={9,8,5,0,3,6,4,2,6,8};
    //string num="021"; vector<int> change={9,4,3,5,7,2,1,9,0,6};
    // string num="5"; vector<int> change={1,4,7,5,3,2,5,6,9,4};
    //string num="330"; vector<int> change={9,3,6,3,7,3,1,4,5,8};
    string num="3013"; vector<int> change={5,4,2,3,5,1,1,6,1,5};
    cout<<mysol.maximumNumber(num,change)<<endl;
	
}