/*

//*****************************************************LASTSHOT - THE LAST SHOT.*****************************************************
https://www.spoj.com/problems/LASTSHOT/




Time Complexity:O(n^2).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).                                                  
// Space Complexity:O(n).                                                   
// This is DFS based solution. We iter. over bombs, for each bomb, we do a DFS calculating the maximum number of bombs it can trigger.
// We do a DFS for each bomb, as there are cycles in the relations, because of which we can't use any form of hashing. Making the 
// process longer.







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




int getCoverage(vector<vector<int>>&graph, int node, vector<bool>&visited){
    int res=0;
    for(int i=0;i<graph[node].size();i++){
        int fol=graph[node][i];
        if(visited[fol]) continue;
        visited[fol]=true;
        res+=getCoverage(graph, fol, visited);
    }
    return res+1;
}




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int bombs, links;
    cin>>bombs>>links;
    vector<vector<int>>graph(bombs+1);
    for(int a=0;a<links;a++){
        int src, dest;
        cin>>src>>dest;
        graph[src].push_back(dest);
    }
    int res=1;
    
    for(int i=1;i<=bombs;i++){
        if(graph[i].size()>0){
            vector<bool>visited(bombs+1, false);
            visited[i]=true;
            int val=getCoverage(graph, i, visited);                         // Starting a DFS for each bomb.
            res=max(res, val);
        }
    }
    cout<<res<<endl;

    return 0;
}