/*

//***************************************************TFRIENDS - True Friends.*******************************************************
https://www.spoj.com/problems/TFRIENDS/




Time Complexity:O(nodes+edges).                                                                                                                                                                                             
Space Complexity:O(nodes).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nodes+edges).                                                  
// Space Complexity:O(nodes).                                                   
// This is Strongly Connected Graph based solution. Here, we need to find the number of strongly connected groups in given graph. 
// We use KOSARAJU'S ALGORITHM to find their count. In the first iteration, we iterate over entire graph, store the nodes in the
// stack if all it's adjacent nodes are visited, in this way we ensure atleast one node from source group is stored above sink
// groups in stack. So, as to get #connected groups, we need to work on sinks first followed by Source groups.
// Now, we reverse the graph making sinks as sources and sinks as sources. Now, we sinks are the sources earlier, since we have 
// atleast one node from each source above it's sink's nodes, we cover(DFS) sinks nodes first and mark them as visited.
// As a result, source groups can be differentiated from sink groups and can be separated easily.




// These links contain very good explanation regarding KOSARAJU'S algorithm:
// https://www.geeksforgeeks.org/strongly-connected-components/
// https://www.youtube.com/watch?v=RpgcYiky7uw
// https://en.wikipedia.org/wiki/Kosaraju%27s_algorithm




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




void iterGraph(vector<vector<int>>&graph, vector<bool>&visited,int node, stack<int>&st){
    visited[node]=true;
    for(int i=0;i<graph[node].size();i++){
        int adj=graph[node][i];
        if(visited[adj]) continue;
        iterGraph(graph, visited, adj, st);
    }
    st.push(node);
    return ;
}






void iterGraph2(vector<vector<int>>&revGraph, vector<bool>&visited, int node){
    visited[node]=true;
    for(int i=0;i<revGraph[node].size();i++){
        int adj=revGraph[node][i];
        if(visited[adj]) continue;
        iterGraph2(revGraph, visited, adj);
    }
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
        vector<vector<int>>graph(nodes);
        vector<vector<int>>revGraph(nodes);
        char ch='.';
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                cin>>ch;
                if(ch=='Y'){
                    graph[i].push_back(j);
                    revGraph[j].push_back(i);
                } 
            }
        }

        // for(int i=0;i<nodes;i++){
        //     for(int j=0;j<revGraph[i].size();j++){
        //         cout<<"i: "<<i<<" and adj: "<<revGraph[i][j]<<endl;
        //     }
        // }

        vector<bool>visited(nodes, false);
        stack<int>st;
        for(int i=0;i<nodes;i++){
            if(visited[i]) continue;
            iterGraph(graph, visited, i, st);
        }
        visited=vector<bool>(nodes, false);
        int res=0;
        // cout<<"stack size; "<<st.size()<<endl;
        while(!st.empty()){
            if(visited[st.top()]){
                st.pop();
                continue;
            }
            res++;
            iterGraph2(revGraph, visited, st.top());
            st.pop();
        }
        cout<<res<<endl;

    }

    return 0;
}
