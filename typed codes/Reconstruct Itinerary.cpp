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

class Ticket{
public:
    string des; 
    int tid;
    Ticket(string des1,int tid1){
        des=des1;
        tid=tid1;
    }
};

bool compareTicket(Ticket t1,Ticket t2){
    return (t1.des<t2.des);
}

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //cout<<sz(tickets)<<endl;
    	map<string,vector<Ticket>> nei;
    	for(int i=0;i<sz(tickets);i++){
            nei[tickets[i][0]].push_back(Ticket(tickets[i][1],i));
    	}
        for(auto it=nei.begin();it!=nei.end();it++){
            sort(all(it->second),compareTicket);
        }
        map<int,vector<int>> edges;
        for(int i=0;i<sz(tickets);i++){
            for(auto const&b: nei[tickets[i][1]]){
                edges[i].push_back(b.tid);
            }
        }
        // for(auto const&c: edges[0]){
        //     cout<<c<<tickets[c][0]<<" "<<tickets[c][1]<<endl;
        // }
    	map<int,int> visited;
        for(int i=0;i<sz(tickets);i++){
            visited[i]=0;
        }
        //vector<string> path;
        //path.push_back("JFK");
        stack<int> path;
        for(auto const &c:nei["JFK"]){
            int start=c.tid;
            if (visited[start]==0){
                //auto it=next(path.begin());
                DFS(start,edges,visited,path,tickets);
                /*cout<<"start"<<endl;
                for(int i=0;i<sz(visited);i++){
                    if (visited[i]!=2)
                        cout<<tickets[i][0]<<","<<tickets[i][1]<<" ";
                }*/
                //cout<<"here"<<endl;
            
            }
            
        }
        vector<string> res;
        res.push_back("JFK");
        while(!path.empty()){
            auto id=path.top();
            path.pop();
            res.push_back(tickets[id][1]);
        }
        return res;
        
        //cout<<nei["JFK"].front()<<endl;
        
    	/*for(auto const&k: nei){
    		for(auto const&l: k.second)
    			cout<<l<<endl;
    	}*/
    	
    }
private:
    void DFS(int &start,map<int,vector<int>> &edges, map<int,int> &visited, stack<int> &path,vector<vector<string>>& tickets){
        visited[start]=1;
        //cout<<start[1]<<endl;
        //cout<<*it<<"nani"<<endl;
        //auto ne=path.insert(it,tickets[start][1]);
        //cout<<*(ne)<<endl;
        //for(auto const&l: path)
         //           cout<<l<<" ";
        //cout<<endl;
        for(auto itt=edges[start].begin();itt!=edges[start].end();++itt){
            // if (*itt==6){
            //     cout<<visited[*itt]<<"diu nei laomu"<<*(ne)<<endl;
            // }
            if (visited[*itt]==0){
                DFS(*itt,edges,visited,path,tickets);
            }
            
        }

        visited[start]=2;
        path.push(start);
        // for(auto const&cc: visited){
        //     cout<<cc.second<<" ";
        //     if (cc.second==2){
        //         cout<<tickets[cc.first][0]<<","<<tickets[cc.first][1]<<" ";
        //     }
        // }
        //cout<<endl;
        return;
    }
};

int main(){
	vector<vector<string>> tickets={{"JFK","SFO"}, {"JFK","ATL"}, {"SFO","ATL"}, {"ATL","JFK"},{"ATL","SFO"}};
	//vector<vector<string>> tickets={{"JFK","ATL"}, {"ATL","JFK"}};
	//vector<vector<string>> tickets={{"JFK","KUL"}, {"JFK","NRT"}, {"NRT","JFK"}};
    //vector<vector<string>> tickets={{"EZE","AXA"}, {"TIA","ANU"}, {"ANU","JFK"}, {"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"}};
    //vector<vector<string>> tickets={{"EZE","TIA"},{"EZE","HBA"},{"AXA","TIA"},{"JFK","AXA"},{"ANU","JFK"},{"ADL","ANU"},{"TIA","AUA"},{"ANU","AUA"},{"ADL","EZE"},{"ADL","EZE"},{"EZE","ADL"},{"AXA","EZE"},{"AUA","AXA"},{"JFK","AXA"},{"AXA","AUA"},{"AUA","ADL"},{"ANU","EZE"},{"TIA","ADL"},{"EZE","ANU"},{"AUA","ANU"}};
	//{"AXA","TIA"} {"TIA","AUA"},{"AUA","AXA"}
    Solution mysol;
	vector<string> res=mysol.findItinerary(tickets);
	for(auto const&c: res)
		cout<<c<<" ";
}