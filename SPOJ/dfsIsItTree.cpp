
/*

//*****************************************************************PT07Y - Is it a tree************************************************************
https://www.spoj.com/problems/PT07Y/




Time Complexity:O(n).                                                       // #Edges in graph.
Space Complexity:O(n).

*/


//*****************************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                    // #Edges in graph.
// Space Complexity:O(n).
// This is DFS based problem. There are two main properties of a tree, #Edges have to be #nodes-1. All the nodes have to be connected. We start from 
// a node, we check for cycle as pruning, we also keep track of #nodes visited in the process. If we observe cycle/all nodes aren't visited, then print 
// "NO" else print "YES".








#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>


using namespace std;



bool findLoop(vector<int>&visited, vector<vector<int>>&graph, int node, int parent, int &count){
    visited[node]=true;
    // cout<<"node: "<<node<<endl;
    count++;
    for(int i=0;i<graph[node].size();i++){
        int adj=graph[node][i];
        if(adj==parent) continue;
        if(visited[adj]) return true;
        findLoop(visited,graph, adj,node, count);
    }
    visited[node]=false;
    return false;
}

int main() {
    // your code goes here
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");
    int nodes, edges;
    cin>>nodes>>edges;
    if(edges!=nodes-1){
        cout<<"NO"<<endl;
        return 0;    
    } 
    vector<vector<int>>graph(nodes+1);
    for(int j=0;j<edges;j++){
        int node1,node2;
        cin>>node1>>node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    vector<int>visited(nodes+1, false);
    int count=0;
    // cout<<"Giving call"<<endl;
    if(findLoop(visited,graph,1,-1, count) || count!=nodes) cout<<"NO"<<endl; 
    else cout<<"YES"<<endl;
        
    return 0;
}