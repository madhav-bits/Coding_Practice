/*

//**************************************************DRAWIT - Can you draw it or not?.************************************************
https://www.spoj.com/problems/DRAWIT/




Time Complexity:O(n!).                                                      // Depends on the edges connection b/w nodes.                                                                                                 
Space Complexity:O(n).                                                      // #Edges in the graph.

*/


//*****************************************************************Solution 1.*************************************************************
// Time Complexity:O(n!).                                                   // Depends on the edges connection b/w nodes.
// Space Complexity:O(n).                                                   // #Edges in the graph.
// This is DFS based solution. We iterate over all possible paths, while keeping track of edges travelled. If we are able to travel 
// all edges, we return true else we return false.








#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>


using namespace std;

bool iterGraph(unordered_map<int,unordered_map<int,int>>&graph, int node,int&ct){


    if(ct==0) return true;
    // cout<<"curr. in node: "<<node<<" with udpated count: "<<ct<<endl;
    for(auto it=graph[node].begin();it!=graph[node].end();it++){
        // if(graph[node][i]==0) continue;
        // int adj=graph[node][i].first, edges=graph[node][i].second;
        int adj=it->first, edges=it->second;
        if(edges==0) continue;
        graph[node][adj]--;
        graph[adj][node]--;
        ct--;
        if(iterGraph(graph,adj,ct)) return true;
        graph[node][adj]++;
        graph[adj][node]++;
        ct++;
    }
    return false;
}



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");
    int tests;
    cin>>tests;
    // cout<<tests<<endl;
    for(int a=0;a<tests;a++){
        int nodes;
        cin>>nodes;
        int info;
        cin>>info;
        int total=0;
        // vector<vector<pair<int,int>>>graph(nodes+1);
        unordered_map<int,unordered_map<int,int>>graph;
        for(int b=0;b<info;b++){
            int node1,node2, edges;
            cin>>node1>>node2>>edges;
            // graph[node1].push_back({node2,edges});
            // graph[node2].push_back({node1,edges});
            graph[node1][node2]=edges;
            graph[node2][node1]=edges;
            total+=edges;
        }
        bool found=false;
        for(int i=1;i<=nodes;i++){
            // vector<vector<int>>temp=graph;
            found=false;
            int ct=total;
            bool res=iterGraph(graph, i,ct);
            // cout<<"outside loop"<<endl;
            // cout<<"res: "<<res<<endl;
            if(res){
                cout<<"YES "<<i<<endl;
                found=true;
                break;
            }
        }
        if(!found) cout<<"NO"<<endl;
        
    }
    return 0;
}