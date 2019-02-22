/*

//*******************************************************CAM5 - prayatna prayatna.***************************************************
https://www.spoj.com/problems/CAM5/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is DFS based solution. Here, we need min. people to start with such that message reaches all people in the graph. As it is 
// undirected graph, we iter. over nodes, if a node isn't visited, we start from this node and mark all nodes reachable from this 
// node as visited. As a result we will be touching only one node from a connected portion of the graph, so as a result we will be 
// getting min. people to interact with so as to spread the news.










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



void reachNodes(vector<vector<int>>&graph, int node, vector<bool>&visited){
    visited[node]=true;
    for(int i=0;i<graph[node].size();i++){
        int fol=graph[node][i];
        if(visited[fol]) continue;
        reachNodes(graph, fol, visited);
    }
}




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    
    int tests;
    cin>>tests;
    // cout<<"tests: "<<tests<<endl;
    for(int a=0;a<tests;a++){
        int nodes, edges;
        cin>>nodes>>edges;
        // cout<<"nodes: "<<nodes<<" and edges: "<<edges<<endl;
        vector<vector<int>>graph(nodes);
        for(int i=0;i<edges;i++){
            int node1, node2;
            cin>>node1>>node2;
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        int res=0;  
        vector<bool>visited(nodes, false);
        for(int i=0;i<nodes;i++){
            if(visited[i]) continue;
            res++;
            reachNodes(graph, i,visited);
        }
        cout<<res<<endl;

    }
    

    return 0;
}