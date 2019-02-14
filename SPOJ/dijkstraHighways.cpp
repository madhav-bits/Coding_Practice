/*

//*******************************************************HIGHWAYS - Highways.***********************************************************
https://www.spoj.com/problems/HIGHWAYS/



Time Complexity:O(mlogn.                                                    // m-edges, n- nodes.                                                                                                                                                   
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(mlogn).                                                // m-edges, n- nodes.                                                  
// Space Complexity:O(n).                                                   
// This is Dijkstra based solution. Here, we push distances into PQ if the minm. dist to that node is still not found, once found we 
// won't travel to that node as it was reached in shortest distance possile already. In the process, if dist. to dest. is least of all
// distances, then we print that distance. If dest. is not reached through any ways, then we print "NONE" for each test case.











#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>
#include<stack>
#include<string>
#include<cmath>




using namespace std;


struct comp{
    bool operator()(pair<int,int>&lt, pair<int,int>&rt){
        return lt.first>rt.first;
    }
};


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    cin>>tests;

    for(int a=0;a<tests;a++){
        int cities,ways, src, dest;
        cin>>cities>>ways>>src>>dest;

        vector<vector<pair<int,int>>>graph(cities+1);
        for(int b=0;b<ways;b++){
            int c1, c2, dist;
            cin>>c1>>c2>>dist;
            graph[c1].push_back({c2,dist});
            graph[c2].push_back({c1,dist});
        }

        unordered_set<int>st;
        // st.insert(src);
        priority_queue<pair<int,int>, vector<pair<int,int>>,comp>pq;
        pq.push({0,src});

        // cout<<"src: "<<src<<" and dest: "<<dest<<endl;
        bool found=false;
        while(!pq.empty()){
            pair<int,int>curr=pq.top();
            pq.pop();
            int dist=curr.first, town=curr.second;
            st.insert(town);
            if(town==dest){
                cout<<dist<<endl;
                found=true;
                break;
            }
            for(int i=0;i<graph[town].size();i++){
                int adj=graph[town][i].first, gap=graph[town][i].second;
                if(st.count(adj)==1) continue;
                pq.push({dist+gap, adj});
            }
            while(!pq.empty() && st.count(pq.top().second)==1) pq.pop();
        }
        if(!found) cout<<"NONE"<<endl;

    }
    

    return 0;
}