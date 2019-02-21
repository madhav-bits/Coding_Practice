/*

//*******************************************************PYRA - Treeramids.***********************************************************
https://www.spoj.com/problems/PYRA/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is DFS based solution. Here, at each step we we give recurisve calls to children in the graph, which recursively reach the 
// leafs, from where we return 1, at each node, we sum the results of each child and we also count #children each node has, total
// volume of all children+children+1 gives volume of curr. node which is forwarded to it's parent. At every step, we add each 
// node's volume to final volume. We return this final volume at end of iteration.







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




int getVolume(vector<vector<int>>&graph, int node, vector<bool>&visited, int &ans){
    int res=0;
    visited[node]=true;
    int child=0;
    for(int i=0;i<graph[node].size();i++){
        int fol=graph[node][i];
        if(visited[fol]) continue;
        child++;
        int val=getVolume(graph, fol, visited, ans);
        res+=val;
    }
    // cout<<"returning from node: "<<node<<" with child: "<<child<<" and vol of: "<<res<<endl;
    if(res==0){
        ans+=1;
        return 1;    
    } 
    
    
    ans+=res+child+1;
    return child+1+res;
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
        vector<vector<int>>graph(nodes);
        for(int i=0;i<nodes-1;i++){
            int node1, node2;
            cin>>node1>>node2;
            // cout<<"node1: "<<node1<<" and node2: "<<node2<<endl;
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        vector<bool>visited(nodes, false);
        int res=0;
        getVolume(graph,0, visited, res);
        cout<<res<<endl;
    }
    
    

    return 0;
}