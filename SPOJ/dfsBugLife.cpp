/*

//*****************************************************************BUGLIFE - A Bug’s Life*************************************************************
https://www.spoj.com/problems/BUGLIFE/



Time Complexity:O(n).                                                       // max(#Edges in the graph,#Nodes in graph).
Space Complexity:O(n).

*/


//*****************************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                    // max(#Edges in the graph,#Nodes in graph).
// Space Complexity:O(n).
// This is DFS based problem. As the given graph can be combination of multiple independent grpups, we try to do a DFS search form all nodes. For every
// DFS search, we start from a node, assigning it as gender 1(it's opposite gender is -1). For every node in DFS, we check for adj. nodes, if they are 
// already visited and have same gender as curr. node, we return true, or if we get true from any DFS calls, we return true. Before giving DFS call,
// we assign that node the oppo. gender of curr. node. This way we cover all nodes and check for same gender adj. nodes.








#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>


using namespace std;



bool findDiff(vector<vector<int>>& graph, vector<bool>&visited, int node, vector<int>&gender){
    
    // cout<<"curr. in node: "<<node<<endl;
    visited[node]=true;
    int gen=-gender[node];
    for(int i=0;i<graph[node].size();i++){
        int adj=graph[node][i];
        if(visited[adj] && gender[node]==gender[adj]) return true;
        if(visited[adj]) continue;
        gender[adj]=-gender[node];
        if(findDiff(graph, visited, adj,gender)) return true;
    }
    return false;
}


int main() {
    // your code goes here
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");
    int tests;
    cin>>tests;
    vector<int>dirs({0,-1,0,1,0});
    for(int k=0;k<tests;k++){
        int bugs,actions;
        cin>>bugs>>actions;
        // cout<<"actions: "<<actions<<endl;
        vector<vector<int>>graph(bugs+1);
        for(int j=0;j<actions;j++){
            int bug1,bug2;
            cin>>bug1>>bug2;
            graph[bug1].push_back(bug2);
            graph[bug2].push_back(bug1);
        }
        vector<bool>visited(bugs+1,0);
        vector<int>gender(bugs+1,0);
        bool error=false;
        for(int j=1;j<=bugs;j++){
            // cout<<"node: "<<k<<endl;
            if(graph[j].size()>0 && visited[j]==false){
                // cout<<"started at node: "<<k<<endl;
                gender[j]=1;
                if(findDiff(graph, visited, j, gender)){
                    error=true;
                    cout<<"Scenario #"<<k+1<<":"<<endl;
                    cout<<"Suspicious bugs found!"<<endl;
                    break;
                } 
            }
               
        }
        if(!error){
            cout<<"Scenario #"<<k+1<<":"<<endl;
            cout<<"No suspicious bugs found!"<<endl;    
        } 
        
    }
    return 0;
}