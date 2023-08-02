/*
*
//***********************************************2196. Create Binary Tree From Descriptions.**********************************************

https://leetcode.com/problems/create-binary-tree-from-descriptions/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
[[1,2,1],[2,3,0],[3,4,1]]
[[1,3,1]]
[[1,3,1],[3,4,1],[4,5,1]]
[[1,3,0]]
[[1,3,0],[3,4,0],[4,5,0],[5,6,1]]
[[20,15,1],[80,17,0],[50,20,1],[50,80,0],[80,19,1],[19,32,1],[15,33,0],[17,49,0]]



// Time Complexity: O(n+m).													//n-#nodes in the graph, m-range of node values.  
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													//n-#nodes in the graph, m-range of node values. 
// Space Complexity: O(m).	
// This algorithm is Map based. Here, we maintain two maps, one maps values to it's nodes and other marks whether a node value is a child or not. We iterate over nodes of the 
// graph, if the curr. parent hasnt been created and updated in map, we create one and update map, same with child node too. We link parent with child based on isLeft for this 
// index. We also mark the curr. child as a child map. Later, we iter. over all parents of the graph and we return the parent which is not a child of any node, as this would be 
// root of the tree.









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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        vector<bool>child(100001, false);									// Marks true if a node is children.
        vector<TreeNode*>nodes(100001, NULL);								// Maps node value with TreeNode* ptr.
        for(vector<int>&v:descriptions) {
            if(nodes[v[0]]==NULL) nodes[v[0]]=new TreeNode(v[0]);			// Create a new ptr for parent if not present yet.
            if(nodes[v[1]]==NULL) nodes[v[1]]=new TreeNode(v[1]);			// Create a new ptr for child node if not present yet.
            child[v[1]]=true;												// Marking the curr. child node.
            if(v[2]==1) nodes[v[0]]->left=nodes[v[1]];						// Linking parent and child node.
            else nodes[v[0]]->right=nodes[v[1]];
        }
        for(vector<int>&v:descriptions) {
            if(child[v[0]]==false) return nodes[v[0]];						// A parent which is not a child of any node is the root of the tree.
        }
        return NULL;														// Corner case which we don't get for the given Constraints.
    }
};

