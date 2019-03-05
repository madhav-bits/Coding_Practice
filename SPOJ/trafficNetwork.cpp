/*

//**************************************************TRAFFICN - Traffic Network.******************************************************
https://www.spoj.com/problems/TRAFFICN/




Time Complexity:O(n^2).                                                     // n-nodes in the graph.                                                                                                                                                                                      
Space Complexity:O(edges+nodes).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).                                                  // n-nodes in the graph.      
// Space Complexity:O(edges+nodes).                                                   
// This is Dijkstra based solution. Here, we find the shortest distance b/w src and dest. We can use one more extra edge in the 
// shortest path, since we are involving edge, adding this extra edge won't disturb the shortest path from src to all else nodes
// that we calculated earlier. So, we use add min dist. from src to one node of new edges +value of edge+ min. dist. to dest. node
// from other node of new edges and reverse the given edge and try to minimize the min. dist. with reverse edge and return the min.
// dist. from src. to dest. at the end.






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



void dijkStra(vector<vector<pair<int,long long int>>>&graph, int src, vector<long long int>&v){
    v[src]=0;
    // priority_queue<pair<int,int>, vector<pair<int,int>>, comp>pq;
    queue<pair<long long int,int>>q;
    q.push({0,src});

    while(!q.empty()){
        int node=q.front().second;
        long long int dist=q.front().first;
        q.pop();

        for(int i=0;i<graph[node].size();i++){
            int fol=graph[node][i].first, gap=graph[node][i].second;
            if(v[fol]<=dist+gap) continue;
            v[fol]=dist+gap;
            q.push({dist+gap, fol});
        }
        while(!q.empty() && v[q.front().second]<q.front().first) q.pop();
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

    int nodes, edges, newEdges, src, dest;
    for(int a=0;a<tests;a++){
        cin>>nodes>>edges>>newEdges>>src>>dest;
        vector<vector<pair<int,long long int>>>graph(nodes+1), revGraph(nodes+1);
        vector<long long int>srcDist(nodes+1, INT_MAX), sinkDist(nodes+1, INT_MAX);
        int node1, node2, dist;
        for(int i=0;i<edges;i++){
            cin>>node1>>node2>>dist;
            graph[node1].push_back({node2,dist});
            revGraph[node2].push_back({node1,dist});
        }
        dijkStra(graph, src, srcDist);
        dijkStra(revGraph, dest, sinkDist);
        long long int res=INT_MAX;
        for(int i=1;i<=nodes;i++){
            res=min(res, srcDist[i]+sinkDist[i]);
        }
        for(int i=0;i<newEdges;i++){
            cin>>node1>>node2>>dist;
            res=min(res, srcDist[node1]+dist+sinkDist[node2]);
            res=min(res, srcDist[node2]+dist+sinkDist[node1]);
        }
        if(res==INT_MAX) cout<<-1<<endl;
        else cout<<res<<endl;
    }
    return 0;
}