/*
*
//******************************1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance.***************************

https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


Worked on test cases provided with the question.
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
// Time Complexity: O(n^3).
// Space Complexity: O(n^2).	
// This algorithm is Bellman Ford based. Here, we use the algorithm to calc. the dist. b/w all pairs of nodes, we count #nodes with
// dist.<=threshold and keep track of source node with minm # adj. nodes and return it.








class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<int>>graph(n, vector<int>(n,100000));
        for(int i=0;i<edges.size();i++){									// Init. the DP array with edge values.
            int node1=edges[i][0], node2=edges[i][1], cost=edges[i][2];
            if(cost>threshold) continue;									// If edge is >threshold then this path isn't needed.
            graph[node1][node2]=cost;
            graph[node2][node1]=cost;
        }
        for(int i=0;i<n;i++) graph[i][i]=0;
        for(int mid=0;mid<n;mid++){											// Bellman Ford algo. to calc. dist. b/w all pairs of nodes.
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(graph[i][mid]>threshold || graph[mid][j]>threshold) continue;// If subpath>threshold then path is unneccasary.
                    graph[i][j]=min(graph[i][j], graph[i][mid]+graph[mid][j]);
                }
            }
        }
        int minCities=n, res=-1;
        for(int i=0;i<n;i++){												// Calc. #adj. cities for each city.
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i==j || graph[i][j]>threshold) continue;
                cnt++;
            }
            // cout<<"i: "<<i<<" and maxCities: "<<cnt<<endl;
            if(cnt<=minCities){												// Tracking city with minm. #adj. cities.
                minCities=cnt;
                res=i;
            }
        }
        return res;															// Return city with minm. #adj. cities.
    }
};