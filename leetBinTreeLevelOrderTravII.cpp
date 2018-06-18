/*
*
//******************************************************107. Binary Tree Level Order Traversal II.***********************************************

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,9,20,3,null,null,4]

[3,9,20,null,null,null,null]

[]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the tree. At each step, we push the row's elem. into stack. After the entire iteration. We extract values from 
// stack and push them into final result vector.







/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        stack<vector<int>>st;												// Stores elem. from all levels.
        queue<TreeNode*> q;													// Stores the iterator nodes.
        q.push(root);														// Starting the iteration from the root.
        while(!q.empty()){
            int len=q.size();												// No. of nodes in curr. level.
            vector<int>temp;												// Stores values in curr. level.
            for(int i=0;i<len;i++){											// Iterates through all nodes in curr. level.
                TreeNode* curr=q.front();
                temp.push_back(curr->val);									// Storing val. in vector.
                q.pop();
                if(curr->left!=NULL) q.push(curr->left);					// If child exists, push into queue.
                if(curr->right!=NULL) q.push(curr->right);
            }
            st.push(temp);													// Pushing all of curr. node's values into stack.
        }
        
        while(!st.empty()){													// Pushing elem. from stack into final result vec.
            res.push_back(st.top());
            st.pop();
        }
        return res;															// Returning the final result vector.
    }
};