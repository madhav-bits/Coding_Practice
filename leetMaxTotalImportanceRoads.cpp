/*
*
//************************************************2285. Maximum Total Importance of Roads.************************************************

https://leetcode.com/problems/maximum-total-importance-of-roads/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5
[[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
5
[[0,3],[2,4],[1,3]]
6
[[0,5],[2,3],[2,4],[3,5],[0,4],[4,5],[1,4]]
4
[[1,2]]



// Time Complexity: O(n+m+nlogn).											// n-#nodes, m-#edges in the graph.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m+nlogn).											// n-#nodes, m-#edges in the graph.
// Space Complexity: O(n).	
// This algorithm is Sorting+Greedy based. For us to get max. total of importance of all roads, every node has to contribute to their best, we observe that
// nodes which have greater #edges involving them should have a greater value assigned to them such that their contribution is high towards total. So, we 
// count #edges for every node, we later sort #edges array and assign lower value to nodes with lower #edges and assign higher value to #nodes with higher 
// edges and add their contribution towards the total and return it at the end of iter.







class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // vector<int>occur(n, 0);
        int occur[n];														// Tracks #edges for each node.
        memset(occur, 0, sizeof(occur));
        for(vector<int>&u:roads) {											// Iter. over all edges.
            occur[u[0]]++;													// Updating #edges for curr. node.
            occur[u[1]]++;
        }
        sort(occur, occur+n);												// Sort #edges array.
        long long int res=0;
        for(int i=1;i<=n;i++) {												// Iter. and assign greater val to nodes with greater #edges, same for lower #edges.
            res+=(1ll*i*occur[i-1]);										// Add the contribution of curr. node towards total.
        }
        return res;															// Returning the max possible total of importance of roads.
    }
};

