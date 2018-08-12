/*
*
//**********************************************************890. Possible Bipartition.***************************************************

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4
[[1,2],[1,3],[2,4]]


7
[[1,4],[3,7],[4,7]]



// Time Complexity: O(edges).  
// Space Complexity: O(edges).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(edges).
// Space Complexity: O(edges).	
// This algorithm is Depth First Search based. Here, we form a edge b/w the nodes which dislike each other and color them 1,-1. We do a DFS for all
// connected nodes, once we encounter two nodes of a edge with same color. Then, they are on the same side, which is not supposed to be, so we 
// return false. We iter. through all nodes, we skip nodes which had been already colored. If not colored, we color it with 1 and start DFS on it.
// If we haven't encountered any issues, we return true.








class Solution {
public:

    bool dfs(vector<vector<int>>&edges, vector<int>&color,int node){
        for(int i=0;i<edges[node].size();i++){								// Iter. through all edges of a node.
            int curr=edges[node][i];										// Storing adj. node.
            if(color[curr]==0){												// If it's not colored. 
                color[curr]=-color[node];									// Color it and do DFS starting from it.
                dfs(edges,color,curr);										
            }
            else{															// If already colored, check whether have diff colors or not?
                if(color[curr]==color[node]) return false;					// If they have same color, then return false(Doesn't form edge).
            }
        }    
        return true;														// If no issues occur, return true.
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& v) {
        vector<vector<int>>edges(2004);										// Stores edges info. of a node.
        vector<int>color(2005);												// Stores color of nodes.
        for(auto arr:v){													// Forming edges based on the dislikes given.
            edges[arr[0]].push_back(arr[1]);
            edges[arr[1]].push_back(arr[0]);
        }
        for(int i=1;i<=N;i++){
            if(color[i]!=0) continue;										// If a node had been already colored, skip it(As DFS on it is done).
            color[i]=1;														// Color the node.
            if(!dfs(edges,color,i)) return false;						// If not colored, color it and start DFS on it. If cycle found ret. false.
        }
        
        return true;														// If no issues/cycles found, return true.
    }
};