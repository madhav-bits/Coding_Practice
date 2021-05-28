/*
*
//*************************************************************Path With Good Nodes.***************************************************

https://www.interviewbit.com/problems/path-with-good-nodes/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


6 0 1 0 1 1 1
5 2 1 2 1 5 1 6 2 3 2 4
1



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DFS based. We traverse through the tree while keeping count of GoodNodes along the way. If #goodnodes touched is >C, we stop 
// traversing that path. If we had reached tail and #goodnodes<=C, we inc. the val of res. We use bool array to keep track of visited nodes, which
// prevents visiting nodes more than once. We return the val of res at the end of traversal.







void findPaths(vector<vector<int>>&graph, int currNode, vector<int>&isGood, vector<bool>&visited, int goodNodes, int&res){
    if(isGood[currNode]==1) goodNodes--;									// If curr. node is good node, we dec. the #goodnodes allowed.
    if(goodNodes<0) return ;												// If curr. path has more than allowed #goodnodes, we stop traversal.
    // cout<<"Curr Node: "<<currNode<<endl;
    // cout<<"last node: "<<currNode<<endl, 
    if(graph[currNode].size()==1) res++;									// If we had reached tail, we inc. the val of #paths.
    
    visited[currNode]=true;													// Marking curr. node as visited.
    for(int adj:graph[currNode]){
        if(visited[adj]) continue;											// If adj. node is visited, we skip traversal.
        findPaths(graph, adj, isGood, visited, goodNodes, res);
    }
    return ;
}

int Solution::solve(vector<int> &isGood, vector<vector<int> > &v, int C) {
    if(C==0) return 0;
    vector<vector<int>>graph(isGood.size());
    for(int i=0;i<v.size();i++){											// Creating Adj. list for bidirectional graph.
        graph[v[i][0]-1].push_back(v[i][1]-1);
        graph[v[i][1]-1].push_back(v[i][0]-1);
    }
    int res=0;										
    vector<bool>visited(isGood.size(),false);								// Keeps track of visited nodes.
    findPaths(graph, 0, isGood, visited, C, res);							// Starts traversal of the graph from node-0.
    return res;																// Returning #paths with #goodnodes<=C.
}


