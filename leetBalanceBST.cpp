/*
*
//**************************************************1382. Balance a Binary Search Tree.***********************************************


https://leetcode.com/problems/balance-a-binary-search-tree/description/


Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

 

Example 1:



Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.
 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The tree nodes will have distinct values between 1 and 10^5.


*************************************************************TEST CASES:******************************************************
//These are the examples I had created, tweaked and worked on.


[1,null,2,null,3,null,4,null,null]





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Logic/Observation based one. In order to get BST which is balanced, we have to divide he sorted nodes into equal halves at 
// each step, as a result the diff. in heights of children at any level won't be >1 as a result it will be balanced. We get sorted 
// nodes from given tree by doing a Inorder traversal over the tree and storing them in an array.






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
    
    void inOrderTraversal(TreeNode* node, vector<TreeNode*>&v){				// Storing node values from an Inorder traversal.
        if(node==NULL) return ;
        inOrderTraversal(node->left, v);
        v.push_back(node);
        inOrderTraversal(node->right, v);
        return ;
    }
    
    
    TreeNode* formTree(vector<TreeNode*>&v, int low, int high){
        if(low>high) return NULL;											// If it's empty subarray, return NULL.
        int mid=(low+high)/2;												// Finding the mid node in the curr. range of nodes.
        TreeNode* node=v[mid];
        // cout<<"low: "<<low<<" and high: "<<high<<" and val: "<<node->val<<endl;
        node->left=NULL; node->right=NULL;
        if(low==high) return node;											// If it's the only node, return the node.
        node->left=formTree(v, low, mid-1);									// Caling func. on left and right halves of subarray.
        node->right=formTree(v, mid+1, high);
        return node;														// Returning the root node for this subarray.
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>v;
        inOrderTraversal(root, v);											// Calling fn. to perform Inorder traversal.
        return formTree(v,0, v.size()-1);									// Calling fn. to form a balanced BST and return it's root.
    }
};



