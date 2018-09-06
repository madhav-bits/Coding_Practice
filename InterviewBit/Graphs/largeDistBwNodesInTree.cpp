/*
*
//******************************************************Largest Distance between nodes of a Tree.***********************************************


https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


10 -1 0 0 0 2 2 4 5 3 8


8 -1 0 0 0 2 2 4 5


3 -1 0 0


2 -1 0

1 -1


100 -1 0 0 0 1 4 5 4 6 4 5 5 0 10 8 4 5 9 16 9 9 0 8 8 15 1 8 8 18 1 17 28 16 8 11 8 33 28 36 14 6 24 18 39 31 11 0 41 25 11 48 20 43 1 24 24 53 43 11 17 47 51 58 0 50 45 29 12 19 9 67 42 68 37 16 37 18 68 44 56 75 70 47 3 60 35 43 6 39 54 18 2 86 73 7 34 73 87 91 36



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DFS based. We construct a tree from the information provided in the array. We start iteration from the root, do a DFS iter.
// into each child until the DFS iter. reaches leaf, where we return 1. We collect the max. depth collected from all the children. We sum the 
// max. depth obtained till now from the children +height from curr. child and try to obtain the max. dist. A node might have only one children,
// then node would be the second node to form the dist, so, we also use the max. dist to update the result max. dist. Thus, at the end, we get
// the max. dist b/w two nodes.







int findDist(unordered_map<int,vector<int>>&parent, int node, int &res){
    int maxm=0;																// Max. depth of a child.
    for(int i=0;i<parent[node].size();i++){									// Iter. over all children.
        int len=findDist(parent,parent[node][i],res);						// Obtain max depth from curr. child.
        res=max(res,maxm+len);												// Form a dist. get prev. max. and curr. child's depth.
        maxm=max(maxm,len);													// Update the max. depth.
    }
    return maxm+1;															// Return the max. depth +1(Including curr. node).
}


int Solution::solve(vector<int> &v) {
    unordered_map<int,vector<int>>parent;									// Stores parent to child relation.
    int res=0,root=-1;														// Stores the final result, root of the tree.
    for(int i=0;i<v.size();i++){											// Form a tree from the array's information.
        if(v[i]==-1) root=i;
        else parent[v[i]].push_back(i); // Marking non-leafs.
    }
    findDist(parent,root,res);												// Start the iter. from the root.
    return res;																// Return the max. dist b/w any two nodes.
}
