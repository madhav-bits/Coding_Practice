/*
*
//********************************************1376. Time Needed to Inform All Employees.********************************************

https://leetcode.com/problems/time-needed-to-inform-all-employees/description/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


1
0
[-1]
[0]


6
2
[2,2,-1,2,2,2]
[0,0,1,0,0,0]



7
6
[1,2,3,4,5,6,-1]
[0,6,5,4,3,2,1]



// Time Complexity: O(n).  													// n- #nodes in the graph.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- #nodes in the graph.
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we add time taken to inform all reporting empl. and pass added time to reporting empl. in 
// recur. call. At every step, we try to maximize the max. time taken to inform all empl. at every recur. call. So, the last node
// which actually has maxm. time will also try to maximize the val, thus we get the maxm. val.A node gives recur. call to reporting nodes
// with updated time(Adding time taken to inform them).








class Solution {
public:
    
    vector<vector<int>>graph;												// Stores the graph structure.
    void iterateTree(int node, vector<int>&informTime, int time, int&res){	// Iter. over all nodes in the tree.
        res=max(res, time);													// Trying to update the maxm. time needed.
        for(int i=0;i<graph[node].size();i++){								// Iter. over the directly reporting nodes.
            int adj=graph[node][i];
            iterateTree(adj, informTime, time+informTime[node], res);		// Giving recur. to reporting nodes with updated time.
        }
        return ;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res=0;
        graph.resize(n);													// Init. the graph array.
        
        for(int i=0;i<n;i++){												// Iter. over all nodes in the graph.
            if(headID==i) continue;
            graph[manager[i]].push_back(i);									// Linking manager to reporting nodes.
        }
        iterateTree(headID, informTime, 0, res);							// Func. call to iter. the graph/tree.
        return res;															// Returning the time needed to inform all empl.
        
    }
};
