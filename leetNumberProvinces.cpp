/*
*
//**********************************************************547. Number of Provinces.***************************************************

https://leetcode.com/problems/number-of-provinces/



There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with 
city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and 
isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]






*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[1,1,0],[1,1,0],[0,0,1]]
[[1,0,0],[0,1,0],[0,0,1]]



// Time Complexity: O(n^2*logn).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2*logn).
// Space Complexity: O(n).	
// This algorithm is Union-Find based. Here, as cities connected directly or indirectly form a province, we use Union-Find approach. We init. each city 
// to be a province, we iter. over all possible pairs, if a pair exists, we get the core parent of both the provinces, if they are same it means these
// cities are already part of a province, if not same we join both the provinces, we make core parent of one of the group to be core parent of other group.
// In this merging we dec. the cnt of groups, and we return the #groups at the end of iteration.








class Solution {
public:
    
    int getParent(vector<int>&parent, int node){							// Get core parent of the node.
        if(parent[node]!=node)
            parent[node]=getParent(parent, parent[node]);
        return parent[node];
    }
    
    int findCircleNum(vector<vector<int>>& v) {
        vector<int>parent(v.size(),0);
        for(int i=0;i<v.size();i++) parent[i]=i;
        int groups=v.size();
        
        for(int i=0;i<v.size();i++){										// Get core parent of all the possible pairs.
            for(int j=i+1;j<v.size();j++){
                if(v[i][j]==0) continue;
                int parA=getParent(parent, i);
                int parB=getParent(parent, j);
                if(parA==parB) continue;									// If these nodes are already part of a province, we don't join.
                groups--;													// As we are joining provinces, we dec. the count by one.
                parent[parB]=parA;											// Making one core parent to be core parent of other group.
            }
        }
        return groups;														// Returning the total #provinces.
    }
};