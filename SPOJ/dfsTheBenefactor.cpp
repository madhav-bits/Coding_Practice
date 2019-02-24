/*

//*****************************************************BENEFACT - The Benefactor.***************************************************
https://www.spoj.com/problems/BENEFACT/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is DFS based solution. The given graph is single/multiple trees, we iterate over tree using DFS and calc. max. depth child
// of each node and add it to curr. child depth and try to update the total length result. After entire iteration, we get the max. 
// path.







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





int calcDepth(vector<vector<pair<int,int>>>&graph, int node, vector<bool>&visited, int &res){
    int maxDepth=0;
    visited[node]=true;
    for(int i=0;i<graph[node].size();i++){
        int fol=graph[node][i].first, dist=graph[node][i].second;
        if(visited[fol]) continue;
        int val=calcDepth(graph, fol, visited, res);
        res=max(res, maxDepth+val+dist);
        maxDepth=max(maxDepth, val+dist);
    }
    return maxDepth;
}






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    cin>>tests;

    for(int a=0;a<tests;a++){
        int nodes;
        cin>>nodes;
        vector<vector<pair<int,int>>>graph(nodes+1);
        int node1, node2, dist;
        for(int i=0;i<nodes-1;i++){
            cin>>node1>>node2>>dist;
            graph[node1].push_back({node2, dist});
            graph[node2].push_back({node1, dist});
        }
        vector<bool>visited(nodes+1, false);
        int res=0;
        for(int i=1;i<=nodes;i++){
            if(visited[i]) continue;
            calcDepth(graph, i, visited, res);    
        }
        
        cout<<res<<endl;
    }
    

    return 0;
}