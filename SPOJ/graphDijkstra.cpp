/*

//*****************************************************************SHPATH - The Shortest Path.************************************************************
https://www.spoj.com/problems/SHPATH/




Time Complexity:O(n).                                                       
Space Complexity:O(n).

*/


//*****************************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                    
// Space Complexity:O(n).
// This is Dijkstra based solution. Here, we used Priority Queue to extract min. dist. travelled for every step. We push duplicates entries for
// different paths to reach a node as each path might lead to diff. distance to reach that node. We extract the min. path of all those avai. paths.
// While extracting nodes, dist. from Priority Queue we ignore nodes which had been already considered, that way we ensure we won't enter infinite
// loop. In the process, the instant we extract target from the PQ, then that's the min. dist to target node and return the distance.








#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>



using namespace std;




struct comp{
    bool operator()(pair<int,int>&lt, pair<int,int>&rt){
        return lt.second>rt.second;
    }
};




int findMinDist(vector<vector<pair<int,int>>>&graph, int src,int dest){
    if(src==dest) return 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
    unordered_set<int>st;
    pq.push({src,0});
    while(!pq.empty()){
        while(!pq.empty() && st.count(pq.top().first)==1) pq.pop();
        pair<int,int> curr=pq.top();
        if(curr.first==dest) return curr.second;
        st.insert(curr.first);
        pq.pop();
        for(int i=0;i<graph[curr.first].size();i++){
            int other=graph[curr.first][i].first,dist=graph[curr.first][i].second;
            if(st.count(other)==1) continue;
            pq.push({other,curr.second+dist});
        }
    }
    return -1;
}





int main() {
    // your code goes here
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");
    int tests;
    cin>>tests;
    for(int a=0;a<tests;a++){
        int cities;
        cin>>cities;
        // unordered_map<int,vector<pair<int,int>>>graph;
        vector<vector<pair<int,int>>>graph(cities+1);
        unordered_map<string,int>m;
        for(int b=1;b<=cities;b++){
            string str;
            cin>>str;
            m[str]=b;
            int neigh;
            cin>>neigh;
            for(int c=0;c<neigh;c++){
                int other,dist;
                cin>>other>>dist;
                graph[b].push_back({other,dist});
            }
        }
        int paths;
        cin>>paths;
        // cout<<"paths: "<<paths<<endl;
        for(int b=0;b<paths;b++){
            string s1,s2;
            int city1,city2;
            cin>>s1>>s2;
            city1=m[s1];
            city2=m[s2];
            // cout<<"city1: "<<city1<<" and city2: "<<city2<<endl;
            int res=findMinDist(graph, city1,city2);
            cout<<res<<endl;
        }
    }
    return 0;
}