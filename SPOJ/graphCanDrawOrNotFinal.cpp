/*

//**************************************************DRAWIT - Can you draw it or not?.************************************************
https://www.spoj.com/problems/DRAWIT/




Time Complexity:O(n).                                                       // n is #edges.                                           
Space Complexity:O(n).

*/


//*****************************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                    // n is #edges. 
// Space Complexity:O(n).
// This is Observation/Logic based Graph solution. Graphs have a property that



// 1) If the network has no odd vertices, then the network is traversable and any point is a starting point. The starting point 
// will also turn out to be the ending point. 

// 2) If the network has exactly one odd vertex, then the network is traversable. The iteration starts at the odd vertex 
// and ends at some other vertex.


// 3) If the network has two odd vertices, then the network is traversable. One odd vertex must be the starting point and the 
// other odd vertex must be the ending point


// 4) If the network has more than two odd vertices, then the NETWORK IS NOT TRAVERSABLE. A network cannot have more than one 
// starting point and one ending point. 











#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>


using namespace std;


void iterGraph(int node, vector<vector<int>>&graph, vector<bool>&visited, int &ct){
    if(visited[node]) return ;
    visited[node]=true;
    ct++;
    for(int i=0;i<graph[node].size();i++){
        iterGraph(graph[node][i],graph,visited,ct);
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
    // cout<<tests<<endl;
    for(int a=0;a<tests;a++){
        int nodes;
        cin>>nodes;
        int info;
        cin>>info;
        vector<int>inside(nodes+1,0);
        vector<vector<int>>graph(nodes+1);
        for(int b=0;b<info;b++){
            int node1,node2, edges;
            cin>>node1>>node2>>edges;
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            inside[node1]+=edges;
            inside[node2]+=edges;
        }
        int ct=0;
        vector<bool>visited(nodes+1,false);
        iterGraph(1,graph, visited,ct);
        // cout<<"nodes: "<<nodes<<" count: "<<ct<<endl;
        if(ct!=nodes){
            cout<<"NO"<<endl;
            continue;
        }
        int odd=0;
        for(int i=1;i<=nodes;i++){
            if(inside[i]%2==1) odd++;
        }
        // cout<<"odd: "<<odd<<endl;
        if(odd>2) cout<<"NO"<<endl;
        else if(odd==0){
            cout<<"YES "<<1<<endl;
        }else{
            for(int i=1;i<=nodes;i++){
                if(inside[i]%2==1){
                    cout<<"YES "<<i<<endl;
                    break;
                }
            }
        }        
    }
    return 0;
}