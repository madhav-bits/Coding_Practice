/*
*
//*********************************************************226. Invert Binary Tree.***************************************************

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,2,4,null,5,6,null,null,10,9,6,7]
[]
[1]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is recursion based. At each node we invert it's child we call the fn. to invert left and right subtree. At each call, if the 
// node is NULL, just return.




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
    void flipVals(TreeNode* node){
        if(node==NULL) return ;																// If curr. node is NULL, return
        swap(node->left, node->right);														// Swap left and right child.
        flipVals(node->left);																// Calling fn. to invert left subtree.
        flipVals(node->right);																// Calling fn. to invert right subtree.
        
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;															// If root==NULL, return NULL.
        flipVals(root);																		// Calling. fn. to invert tree.
        return root;																		// Returning root of inverted tree.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. At each node we invert it's children, we push into queue iff the child is not NULL.





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
    
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;													// If root==NULL, return NULL.
        //flipVals(root);
        queue<TreeNode*> q;
        q.push(root);																// Pushing root into queue.
        while(!q.empty()){
            TreeNode* node=q.front();												// Extracting the first node.
            q.pop();
            TreeNode* temp=node->left;												// Inverting left and right children.
            node->left=node->right;
            node->right=temp;
            if(node->left!=NULL) q.push(node->left);								// Pushing child iff NULL.
            if(node->right!=NULL) q.push(node->right);								// Pushing child iff NULL.
        }
        return root;																// Returning root of inverted tree.
    }
};