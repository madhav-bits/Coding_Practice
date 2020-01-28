/*
*
//**************************1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance***************************

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional 
and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most 
distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 

Example 1:



Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Example 2:



Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
 

Constraints:

2 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti, distanceThreshold <= 10^4
All pairs (fromi, toi) are distinct.



*****************************************************************TEST CASES:**********************************************************
//These are the examples I had created, tweaked and worked on.


4
[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]
4



5
[[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]]
2


// Time Complexity: O(n^3).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*elogn).								// n-nodes, e-edges in the graph.
// Space Complexity: O(e).	
// This algorithm is Dijkstra based. Here, since we need nodes with dist<threshold. We do Dijkstra from all nodes, in each iteration
// we only iterate nodes which are of dist<threshold. Once the Priority Queue is empty. We compare the count of visited nodes with the
// minm. neighbors for any nodes till then. We try to update it. At the end of entire process, we have node with minm. neighbors.


// Negative edges and cycles aren't allowed in this algorithm. 





class Solution {
public:
    
    struct comp{															// Comparator for the Priority Queue.
        bool operator()(pair<int,int>&lt, pair<int,int>&rt){				// Implementing Min priority Queue.
            return lt.second>rt.second;
        }    
    };
    
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        
        int res=-1, nearby=INT_MAX;
        vector<vector<pair<int,int>>>graph(n);								// Init. the graph-adjacency matrix.
        for(int i=0;i<edges.size();i++){									// Building the graph for the algorithm.
            int node1=edges[i][0], node2=edges[i][1];
            graph[node1].push_back({node2, edges[i][2]});
            graph[node2].push_back({node1, edges[i][2]});
        }
        
        for(int i=0;i<n;i++){
            priority_queue<pair<int,int>, vector<pair<int,int>>, comp>pq;
            vector<bool>taken(n,false);
            taken[i]=true;
            pq.push({i,0});
            int approachable=-1;
            while(!pq.empty()){												// Performing Dijkstra starting each node.
                int node=pq.top().first, dist=pq.top().second;
                approachable++;
                pq.pop();
                taken[node]=true;
                for(auto adj: graph[node]){
                    if(dist+adj.second>threshold || taken[adj.first]) continue;
                    pq.push({adj.first, dist+adj.second});
                }
                
                while(!pq.empty() && taken[pq.top().first]) pq.pop();
            }
            // cout<<"i: "<<i<<" and approachable is: "<<approachable<<endl;
            if(approachable<=nearby){										// Tracking node with minm. neighbors.
                nearby=approachable;
                res=i;
            }
        }
        return res;															// Returning the node with minm. neighbors.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).								// n-nodes, e-edges in the graph.
// Space Complexity: O(n^2).	
// This algorithm is Floyd Warshall based algorithm. Here, we run the algorithm to find the minm. dist b/w all pairs of nodes in the
// graph. After the run, we iter. over the matrix, for each start node, we count all neighbors which are of dist.<threshold. If a 
// node's neighbors count<=minm. neighbors till then, we update minm. neighbors and the start node.





// The advantage of Floyd Warshall is that it works even for Negative weights of edges. But, Negative cycles are not allowed.










class Solution {
public:
    
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        
        int res=-1, nearby=INT_MAX;
        vector<vector<long long int>>dp(n, vector<long long int>(n, INT_MAX));
        
        for(int i=0;i<n;i++) dp[i][i]=0;									// Setting base values in the matrix.
        
        for(int i=0;i<edges.size();i++){									// Setting base values in the matrix.
            int node1=edges[i][0], node2=edges[i][1], dist=edges[i][2];
            dp[node1][node2]=dist;
            dp[node2][node1]=dist;
        }
        
        for(int mid=0;mid<n;mid++){											// Running the Floyd Warshall algorithm.
            for(int i=0;i<n;i++){
                if(i==mid) continue;
                for(int j=0;j<n;j++){
                    if(j==mid || j==i) continue;
                    if(dp[i][j]>dp[i][mid]+dp[mid][j])
                        dp[i][j]=dp[i][mid]+dp[mid][j];
                }
            }
        }
        
        for(int i=0;i<n;i++){												// Counting neighbors with dist.<threshold.
            int approach=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(dp[i][j]<=threshold) approach++;
            }
            // cout<<"i: "<<i<<" and approach: "<<approach<<endl;
            if(approach<=nearby){											// Tracking the minm. neighbors among all start nodes.
                nearby=approach;
                res=i;
            }
        }
        return res;															// Returning the node with minm. neighbors.
    }
};