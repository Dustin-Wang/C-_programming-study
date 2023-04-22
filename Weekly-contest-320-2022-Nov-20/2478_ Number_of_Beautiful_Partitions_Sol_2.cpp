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
#include <unordered_set>
#include <climits>
#include <iterator>

using namespace std;
// BEGIN NO SAD
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

// END NO SAD
// REMEMBER CLEAR GLOBAL STATE

// struct myclass{
// 	bool operator()(string a, string b){
// 		if(a.size()<b.size())
// 			return false;
// 		else if(a.size()>b.size())
// 			return true;
// 		else
// 			return(a>b);
// 	}
// } myobject;

/*


You are given a string s that consists of the digits '1' to '9' and two integers k and minLength.

A partition of s is called beautiful if:

    s is partitioned into k non-intersecting substrings.
    Each substring has a length of at least minLength.
    Each substring starts with a prime digit and ends with a non-prime digit. Prime digits are '2', '3', '5', and '7', and the rest of the digits are non-prime.

Return the number of beautiful partitions of s. Since the answer may be very large, return it modulo 109 + 7.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "23542185131", k = 3, minLength = 2
Output: 3
Explanation: There exists three ways to create a beautiful partition:
"2354 | 218 | 5131"
"2354 | 21851 | 31"
"2354218 | 51 | 31"

Example 2:

Input: s = "23542185131", k = 3, minLength = 3
Output: 1
Explanation: There exists one way to create a beautiful partition: "2354 | 218 | 5131".

Example 3:

Input: s = "3312958", k = 3, minLength = 1
Output: 1
Explanation: There exists one way to create a beautiful partition: "331 | 29 | 58".

 

Constraints:

    1 <= k, minLength <= s.length <= 1000
    s consists of the digits '1' to '9'.


*/

template<typename T>
void printvector(vector<T> vector){
 //    int arraysize = array.size();
	// for(int k=0; k<arraysize; k++)
	// 	printf("%d  ",array[k]);
	// printf("size: %d\n",arraysize);
	copy(vector.begin(), vector.end(), std::ostream_iterator<T>(std::cout, " "));
	printf("\n");
	fflush(stdout);
};

 // * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void PrintQueueInIntBinaryTree(queue<TreeNode*> queue){
    int queuesize = queue.size();
	while(!queue.empty())
	{
		auto it = queue.front();
		if(it!=nullptr)
			printf("%d  ",it->val);
		queue.pop();
	}
	printf("queue size: %d\n",queuesize);
	fflush(stdout);
};

TreeNode* ArrayToBinaryTree(vector<string> input){
	int length = input.size();
	int depth = ceil(log2(double(length)));
	//fill in the extra nullptr leaves in the given input
	for(int i = length; i< pow(2, depth)-1; i++)
	{
		input.push_back("null");
	}

	printvector(input);
	TreeNode* root = new TreeNode(stoi(input[0]));
	queue<TreeNode*> prevLevel;
	prevLevel.push(root);
	int index = 1;
	for(int k = 1; k<depth; k++)
	{
		queue<TreeNode*> NextLevel;
		PrintQueueInIntBinaryTree(prevLevel);
		while(!prevLevel.empty())
		{
			TreeNode* s = prevLevel.front();
			prevLevel.pop();
			
			if(s == nullptr)
			{
				index +=2;
				NextLevel.push(nullptr);
				NextLevel.push(nullptr);
				continue;
			};
			
			if(input[index] == "null")
			{
				s->left = nullptr;
				NextLevel.push(s->left);
			}
			else
			{
				s->left = new TreeNode(stoi(input[index]));
				NextLevel.push(s->left);
			};
			index++;
			// PrintQueueInIntBinaryTree(NextLevel);
			if(input[index] == "null")
			{
				s->right = nullptr;
				NextLevel.push(s->right);
			}
			else
			{
				s->right = new TreeNode(stoi(input[index]));
				NextLevel.push(s->right);
			};
			index++;
			// PrintQueueInIntBinaryTree(NextLevel);
		}
		// PrintQueueInIntBinaryTree(NextLevel);
		prevLevel = NextLevel;
		printf("k: %d\n", k);
		fflush(stdout);
	}

	return(root);
}


class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
    	int sLength = s.size();
    	vector<int> TransitionFromUnPrimeToPrime={-1};
    	if( (IsPrime(s[0])==0) || IsPrime(s[sLength-1]) )
    		return(0);
    	for(int i=1;i<sLength;i++){
    		if( (IsPrime(s[i-1]) == 0) && IsPrime(s[i]))
    			TransitionFromUnPrimeToPrime.push_back(i-1);//notice that i-1>=1, because s must starts with prime
    	}
    	TransitionFromUnPrimeToPrime.push_back(sLength-1);
    	// printvector(TransitionFromUnPrimeToPrime);
    	//NoOfTransitions are at most 501, 
    	int NoOfTransitions = TransitionFromUnPrimeToPrime.size();
        if(k>NoOfTransitions-1)
            return(0);
        if(k==NoOfTransitions-1)
        {
            for(int i=0; i<NoOfTransitions-1; i++)
            {
                if(TransitionFromUnPrimeToPrime[i+1]-TransitionFromUnPrimeToPrime[i]<minLength)
                    return(0);
            }
            return(1);
        }
    	//Now we will use memoimization
    	//for a range of [a,b], where a,b are in TransitionFromUnPrimeToPrime,
    	//we want to know the beautiful partitions bewteen this range
    	//and store it into some dictionary
    	//so here a and b are indices in TransitionFromUnPrimeToPrime
        //Notice that we need to make it into k partitions, this is disgusting.
        //instead we will consider all possible partitions that is below k.
        //the dynamic table will be iterating over k

    	//starting with k=1;
    	// int DynamicTableWidth = NoOfTransitions * (NoOfTransitions - 1)/2;

    	//actually we don't need to know the answer for each subrange of the string
    	//suffices to know the range from index a to index NoOfTransitions-1, where a\in[0, NoOfTransitions-2]
    	// map<pair<int,int>, int> DynamicRow;
        vector<int> DynamicRow(NoOfTransitions-1,0);
    	for(int i=0; i<NoOfTransitions-1; i++){
            int j = NoOfTransitions - 1;
            if(TransitionFromUnPrimeToPrime[j] - TransitionFromUnPrimeToPrime[i] >= minLength)
                // DynamicRow.insert(pair<pair<int,int>, int>{pair<int,int>{i,j}, 1});
                DynamicRow[i] = 1;
            else
                // DynamicRow.insert(pair<pair<int,int>, int>{pair<int,int>{i,j}, 0});
                DynamicRow[i] = 0;
        }
        // if(k==NoOfTransitions-1)

    	// cout<<DynamicRow[pair<int,int>{0,4}]<<endl;
    	for(int n=2; n<=k; n++){
    		// map<pair<int,int>, int> NextDynamicRow;
            vector<int> NextDynamicRow(NoOfTransitions-1, 0);
    		for(int i=0; i<NoOfTransitions-1; i++){
    			int j = NoOfTransitions -1;
    			//given start index i and end index j, we need to know the no of beautiful paritions of divividing this substring to 
    			//n partitions
    			//give we already know the answer to n-1 partitions
    			int temp = 0;
    			for(int k=i+1; k<j; k++){
    				//for the n partitions, assume that the 1st partition happens at the transition place k
    				//of course we need to satisfy the mininum length for i and k
    				if( TransitionFromUnPrimeToPrime[k] - TransitionFromUnPrimeToPrime[i] >= minLength &&
    					TransitionFromUnPrimeToPrime[j] - TransitionFromUnPrimeToPrime[k] >= minLength)
    					temp = (temp + DynamicRow[k])%LargePrime;
    			}
    			// NextDynamicRow.insert(pair<pair<int,int>, int>{pair<int,int>{i,j}, temp});
                NextDynamicRow[i]=temp;
                if(n==k && i==0)
                    return(NextDynamicRow[0]);
    		}
    		DynamicRow = NextDynamicRow;
    		// cout<<DynamicRow[pair<int,int>{0,4}]<<endl;	
    	}
    	

    	// pair<int,int> key{0, NoOfTransitions-1};
    	return(DynamicRow[0]);


    }
    
private:
	
	int LargePrime = pow(10,9)+7;

	int IsPrime(char c)
	{
		if( c == '2' || c == '3' || c == '5' || c == '7' )
			return(1);
		else
			return(0);
	}
	
	vector<queue<TreeNode*>> BFS(TreeNode* root){
        queue<TreeNode*> q1;
        // cout<<"Starting BFS\n"<<endl;
        // fflush(stdout);
        vector<queue<TreeNode*>> Res;
        q1.push(root);
        do{
            Res.push_back(q1);
            queue<TreeNode*> q2;
            while(!q1.empty()){
                TreeNode* s = q1.front();
                q1.pop();
                if(s->left != nullptr)
                    q2.push(s->left);
                if(s->right != nullptr)
                    q2.push(s->right);
            }
            q1 = q2;  
            // PrintQueueInIntBinaryTree(q1);
        }while(!q1.empty());
        return(Res);
    }
	
	long long fuels = 0;
	
	int DFS(int root, int NoOfCities, vector<vector<int>>& NeighborsOfCities, vector<int>& CitiesVisited, int seats){
        CitiesVisited[root]=1;
        int NoOfPplInThisCity = 1;
        for(const auto &i:NeighborsOfCities[root])
        {
        	if(CitiesVisited[i]==0)
        	{
        		NoOfPplInThisCity = NoOfPplInThisCity + DFS(i, NoOfCities, NeighborsOfCities, CitiesVisited, seats);
        	}	
        }
        CitiesVisited[root]=2;
        if(NoOfPplInThisCity%seats)
        	fuels = fuels + NoOfPplInThisCity/seats+1;
        else
        	fuels = fuels + NoOfPplInThisCity/seats;
        return(NoOfPplInThisCity);
    }


};
template <size_t rows, size_t cols>
vector<vector<int>> ArrayTo2dVector(int (&array)[rows][cols]){
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
	// string s = "23542185131";
	// int k = 3;
	// int minLength = 2;

	// string s = "23542185131";
	// int k = 3;
	// int minLength = 3;

	// string s = "3312958";
	// int k = 3;
	// int minLength =1;

	// string s = "729852992687486265668477896177579456254254899874352895541618737989265536736998595242549357183142531171469787694947173595283871938636589875149946196173557627376732771482478316339784285325422441545891251396713433647643278494162873375215457434129798923228274147645522234624573746757451123695639785267881669895261999851194176877622152537756168463982877422387475943297763971484655114887335457991324976693286172424553759";
	// int k = 59;
	// int minLength = 6;

    // string s = "3635246533686763993377154676498171752697938929978542576827836626829846492399763527572326544233926867934956882118121841682342778615732874949913542699786225284919823563261222766938762546982528958658151982527934161512448358532684857764448149283262796957695711518954658938361482117649929319521741393315219798179661227132796645591766391244184665497987372122242916334361342763929111689781821453631948764328285369928495376558669376662129999275389949454234894558932755656951266819883724515475376982621226552599394951433414365212289243966268486951886461644369696918199232255346725133686463776665648554212833369374286718451745646272729811687951337536463272376936195869732291237663753555153712987387842894941779122792799328938995658262194111333612886873116274177842761";
    // int k = 139;
    // int minLength = 5;

    string s = "7828745959293979512154292859512679792934793978763959293424767156567959567139745429797456597826382958243929397958285978247839397971587976762854797874585179263974393179217971597439267159597174393871767671292159395179582476397626797436717821212956297951545621597478797459797974347929767971385629717134587854787636597824217679245426583626717679797958517626567429792659582971795878397428782871215676787159382674265429392651743151717658343676212659747676797859795456262139245436742471292959793176587124217926395829793976592938382158793878715456262659342951587126282478795679742174345154397679717674383971212978743478397156265928597621213829742426762674795929793878767421313671297124717679345676512879783159367478347159767959787951765934387429792978787429793459717439382626543179787456343978783851247174765979715458765129765629362426797954342859317871587979395851762979362151397659795951715936347978792154397971547624247474513859563976397479295879515959293159367179765876787426317174315936763976597179595826";
    int k = 500;
    int minLength = 1;
	cout<<mysol.beautifulPartitions(s,k,minLength)<<endl;
	return(0);
    
}