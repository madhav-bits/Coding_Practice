/*

//*****************************************************RTREE - Roger and tree.*******************************************************
https://www.spoj.com/problems/RTREE/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is DFS and Dynamic Programming based solution. Here, we do a DFS through the tree, and find max. path in each subtree, we try
// to update max. path length through each node, we return both max. path length and max. path length through each node to it's 
// parent. Thus, at every node, of all max. path lengths returned from all it's children, we assign max. length to that node and 
// return max. path in that subtree to it's parent. Since, we have only single tree and queries are based on single tree, we store 
// the results in an array, from which we return the results for each query directly.







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




pair<int,int> calcLen(vector<vector<int>>&graph, int node, vector<bool>&visited, vector<int>&maxLen){
    int res=0, maxDepth=0;
    visited[node]=true;
    for(int i=0;i<graph[node].size();i++){
        int fol=graph[node][i];
        if(visited[fol]) continue;
        pair<int,int> pr=calcLen(graph, fol, visited, maxLen);
        res=max(res, pr.second);
        res=max(res, maxDepth+pr.first+1);
        maxDepth=max(maxDepth, pr.first+1);
    }
    maxLen[node]=res;
    return {maxDepth,res};
}







int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    
    
    int nodes;
    cin>>nodes;
    vector<vector<int>>graph(nodes+1);
    vector<int>maxLen(nodes+1,0);
    vector<bool>visited(nodes+1, false);
    for(int a=0;a<nodes-1;a++){
        int node1, node2;
        cin>>node1>>node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    int root;
    cin>>root;
    calcLen(graph, root, visited, maxLen);
    int queries;
    cin>>queries;
    for(int a=0;a<queries;a++){
        int node1;
        cin>>node1;
        cout<<maxLen[node1]<<endl;
    }


    // Releasing Memory.
    vector<vector<int>>dup1;
    vector<int>dup2;
    vector<bool>dup3;
    graph.swap(dup1);
    maxLen.swap(dup2);
    visited.swap(dup3);


    return 0;
}