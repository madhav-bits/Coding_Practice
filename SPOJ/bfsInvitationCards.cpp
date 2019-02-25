/*

//*************************************************INCARDS - Invitation Cards.******************************************************
https://www.spoj.com/problems/INCARDS/




Time Complexity:O(edges).
Space Complexity:O(nodes).

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(edges).
// Space Complexity:O(nodes).
// This is Dijkstra based solution. Here, we first find the minm. dist from 1 to all else nodes and for finding the minm. dist.
// from all nodes to 1, we reverse the graph drns and find the minm. dist from 1 to all else nodes. We sum the minm. cost to all
// else nodes in both scenarios and print the total cost.







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



void reachDest(vector<vector<pair<int,int>>>&graph, int &total){
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > >pq;
  vector<int>dist(graph.size(), INT_MAX);
  vector<bool>visited(graph.size(), false);
  dist[1]=0;

  // visited[src]=true;
  pq.push({0, 1});
  while(!pq.empty()){
    int gap=pq.top().first, node=pq.top().second;
    pq.pop();
    if(visited[node]) continue;
    visited[node]=true;
    total+=gap;
    for(int i=0;i<graph[node].size();i++){
        int fol=graph[node][i].first, dx=graph[node][i].second;
        if(gap+dx>=dist[fol]) continue;
        dist[fol]=gap+dx;
        pq.push({gap+dx, fol});
    }
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
    int nodes, edges;
    for(int a=0;a<tests;a++){
      cin>>nodes>>edges;
      vector<vector<pair<int,int> > >graph(nodes+1), revGraph(nodes+1);
      int src, dest, dist;
      for(int i=0;i<edges;i++){
        cin>>src>>dest>>dist;
        // cout<<"src: "<<src<<" dest: "<<dest<<" and dist: "<<dist<<endl;
        graph[src].push_back({dest, dist});
        revGraph[dest].push_back({src, dist});
      }
      int total=0;
      reachDest(graph, total);
      reachDest(revGraph, total);
      cout<<total<<endl;
    }


    return 0;
}
