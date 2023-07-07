/*
*
//******************************************************1976. Number of Ways to Arrive at Destination.******************************************************

https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


7
[[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
2
[[1,0,10]]



// Time Complexity: O(nodes+edges+edges*log(nodes))=O(v+e+elogv).
// Space Complexity: O(nodes+edges)=O(v+e)

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nodes+edges+edges*log(nodes))=O(v+e+elogv).
// Space Complexity: O(nodes+edges)=O(v+e)
// This algorithm is Dijkstra Algorithm based. Here, we form Adjacency Matrix first for smoothly running algorithm. We modify Dijkstra where we iter. over 
// edges of node we are working on, we add curr. #ways to adj. node to adj. node if the minDist to adj. node is same as currDist+edge, if currDist+edge is
// smaller than minDist stored, we update minDist and also rewrite the #ways to adj. node in corres. array. Thus, at every step we ensure minDist first, 
// if same dist we inc. the #ways by adding #ways to curr. node to adj. node's #ways. We stop the process, once target node becomes the node we work on. We
// return #ways to target node form the corres. array








class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int target=n-1, mod=1000000007;
        vector<vector<pair<int,int>>>graph(n);								// Adjacency Matrix.
        for(vector<int>&v:roads) {
            graph[v[0]].push_back({v[1], v[2]});
            graph[v[1]].push_back({v[0], v[2]});
        }
        vector<pair<long long int,int>>minDist(n,{LONG_MAX, 0});//{minDist, #ways}
        auto comp=[](pair<int,long long int>&lt, pair<int,long long int>& rt) {
            return lt.second>rt.second;
        };
        priority_queue<pair<int, long long int>, vector<pair<int,long long int>>, decltype(comp)>pq(comp);//{node, dist}
        pq.push({0,0});
        minDist[0]={0,1};
        while(!pq.empty()) {
            int node=pq.top().first;
            long long int currDist=pq.top().second;
            pq.pop();
            if(node==target) return minDist[target].second;					// If target node found, return #ways to target node.
            if(minDist[node].first<currDist) continue;						// Avoids revisiting nodes with greater dist.
            for(pair<int,int>&adj:graph[node]) {
                if(currDist+adj.second>minDist[adj.first].first) continue;	// If curr. dist>minDist already stored, we ignore curr. path.
                if(currDist+adj.second==minDist[adj.first].first) 			// If curr. dist=minDist, we inc. the #ways to adj. node.
                    minDist[adj.first].second=(0ll+minDist[adj.first].second+minDist[node].second)%mod;
                else {														// If curr. dist<minDist, we update minDist, rewrite the #ways to adj. node.
                    minDist[adj.first]={currDist+adj.second, minDist[node].second};
                    pq.push({adj.first, currDist+adj.second});
                }
            }
        }
        return -1;
    }
};

