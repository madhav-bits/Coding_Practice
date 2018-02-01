/*
*
//*****************************************************144. Binary Tree Preorder Traversal.**********************************************

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?



//These are the cases I had created, tweaked and worked on.
[1,3,2,5,null,null,9, 6,null,7,null, null,6,null,9]
[2,3,null,1,2,1,null,null,4]
[1,2,3,4,5,6,null,null,8,null,9]
[1,null,2,3]

// Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// This algorithm pushes the encountered nodes children into queue and unqueues them which turns out to be preOrder Traversal.
// This is an iterative algorithm.



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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL) return v;
        TreeNode* temp=root;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){											// When there are no more nodes in the tree, then stop.
            TreeNode* temp2=s.top();
            v.push_back(temp2->val);
            s.pop();												//Removing from the queue an element, already scanned and pushed into vector.
            if(temp2->right!=NULL) s.push(temp2->right);
            if(temp2->left!=NULL) s.push(temp2->left);				//As we want preOrder we want the left child first.
        }
        return v;
    }
};