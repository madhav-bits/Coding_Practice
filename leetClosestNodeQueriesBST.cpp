/*
*
//*******************************************2476. Closest Nodes Queries in a Binary Search Tree.****************************************

https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[6,2,13,1,4,9,15,null,null,null,null,null,null,14]
[2,5,16]
[4,null,9]
[3]
[16,14,null,4,15,1]
[10,6,2,9]



// Time Complexity: O(mlogm+n).												// n-#nodes in the tree. m-#queries.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(mlogm+n).												// n-#nodes in the tree. m-#queries.
// Space Complexity: O(n).	
// This algorithm is BST based. As there are many queries for searching nums in BST, performing Binary Search for each of them in a tree form would be time 
// consuming in case of skewed trees, where time taken would be O(n) rather than O(logn), leading to TLE. So, we collect sorted nodes from BST using inorder
// traversal, we also sort the {queries,index} so that we can iterate over nodes array searching for greater node value as we iter. over sorted query values, 
// for every query value, we update the min, maxm value in it's corresponding index in the res array.






/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void gatherNodes(TreeNode* node, vector<int>&v) {						// Inorder Traversal to collect sorted nodes.
        if(!node) return ;
        gatherNodes(node->left, v);
        v.push_back(node->val);
        gatherNodes(node->right, v);
        return ;
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>>res(queries.size());
        vector<int>v;
        gatherNodes(root, v);
        vector<pair<int,int>>u;
        for(int i=0;i<queries.size();i++) u.push_back({queries[i], i});
        sort(u.begin(), u.end());											// Sort {query, index} pairs.
        int j=0;
        for(int i=0;i<u.size();i++) {										// We iter. over sorted queries and nodes simultaneously.
            int minm=-1, maxm=-1;
            while(j<v.size() && v[j]<u[i].first) j++;						// We skip nodes which are <curr. query value.
            if(j<v.size()) maxm=v[j];										// If >= node val. exists, we use it as maxm value.
            if(j<v.size() && v[j]==u[i].first) minm=v[j];					// If curr. node val==query, we also use this for minm value.
            else if(j>0) minm=v[j-1];										// If < node val exists, we use it as minm. value.
            res[u[i].second]={minm, maxm};
        }
        return res;															// Returning array with closet minm, maxm values for queries.
    }
};

