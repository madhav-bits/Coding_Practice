/*

//*************************************************AKBAR - Akbar , The great.********************************************************
https://www.spoj.com/problems/AKBAR/




Time Complexity:O(n).
Space Complexity:O(n).

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).
// Space Complexity:O(n).
// This is BFS based solution. Here, we first form the Adjacency List of graph. Later, we create a vector to keep track of all nodes
// which we have visited. Now, we iterate over all soldier positions and do a BFS over nodes, which are reachable from it, while doing
// BFS if we encounter any nodes which we had already visited as part of previous BFS iterations, we return false. Once we find that
// all placements are't optimal, we skip all later BFS iter., by the end of all BFS iter, if we still haven't observed any overlappings,
// we count #nodes reachable by iter. over visited array, if we find that all nodes are reachable, we print "Yes" else we print "No".







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




bool markNodes(vector<vector<int>>&graph, vector<bool>&visited, int node, int limit){
        queue<int>q;
        q.push(node);
        int dist=0;
        unordered_set<int>st;
        visited[node]=true;
        st.insert(node);
        while(!q.empty()){
            if(dist==limit) break;
            dist++;
            int len=q.size();
            for(int i=0;i<len;i++){
                int curr=q.front();q.pop();
                for(int j=0;j<graph[curr].size();j++){
                    int fol=graph[curr][j];
                    if(st.count(fol)) continue;
                    if(visited[fol]) return false;
                    st.insert(fol);
                    visited[fol]=true;
                    q.push(fol);
                }
            }
        }
        return true;
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
        int nodes,edges, soldiers;
        cin>>nodes>>edges>>soldiers;
        vector<vector<int>>graph(nodes+1);
        for(int i=0;i<edges;i++){                                           // Forming the graph.
            int node1, node2;
            cin>>node1>>node2;
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        // vector<pair<int,int>>army;
        vector<bool>visited(nodes+1, false);
        int count=0;
        bool err=false;
        for(int i=0;i<soldiers;i++){                                        // Doing BFS over all soldiers.
            int node,strength;
            cin>>node>>strength;
            if(visited[node]) err=true;
            if(err) continue;
            if(!markNodes(graph, visited, node, strength)) err=true;
            // army.push_back({node, strength});
        }
        if(!err){
            for(int i=1;i<visited.size();i++){
                if(visited[i]) count++;
            }
        }

        if(count==nodes) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

        // Releasing Memory.
        vector<vector<int>>dup;
        vector<bool>dup2;
        graph.swap(dup);
        visited.swap(dup2);

    }

    return 0;
}
