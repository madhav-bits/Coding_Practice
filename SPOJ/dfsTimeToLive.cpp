/*

//****************************************************GCPC11J - Time to live.********************************************************
https://www.spoj.com/problems/GCPC11J/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is DFS based solution. Here, we are trying to find the optimal position of Router such that all nodes are covered with minimum 
// hops. SO, we have to place the router in the middle node of longest path connecting two nodes. So, we calculate 
// longest path/diamater of the tree, and return longest path/2 as result.







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




int getMaxDepth(unordered_map<int,vector<int>>&graph, int node, unordered_set<int>&visited, int &res){
    // cout<<"Inside fn. with node: "<<node<<endl;
    int ans=0;
    visited.insert(node);
    for(int i=0;i<graph[node].size();i++){
        int adj=graph[node][i];
        if(visited.count(adj)==1) continue;
        int maxDepth=getMaxDepth(graph, adj, visited, res);
        res=max(res, ans+maxDepth+1);
        ans=max(ans, maxDepth);
    }
    // cout<<"node: "<<node<<" and depth: "<<ans+1<<endl;
    res=max(res, ans+1);
    return ans+1;
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, nodes;
    cin>>tests;
    for(int a=1;a<=tests;a++){
        cin>>nodes;
        unordered_map<int,vector<int>>graph;
        int node1, node2;
        for(int i=0;i<nodes-1;i++){
            cin>>node1>>node2;
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        int res=INT_MIN;
        unordered_set<int>visited;
        getMaxDepth(graph,1, visited, res);
        // cout<<"depth: "<<res<<endl;
        cout<<res/2<<endl;
    }

    return 0;
}
