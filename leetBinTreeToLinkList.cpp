/*
*
//*********************************************************114. Flatten Binary Tree to Linked List.************************************************

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[1,2,3,4,5,6,7,8,9,10]
[1,2,1,4,null,2,4,5,null,4,null,null,null,null,null,5]
[]
[1,2,3,4,5,6,7,8,9,10,11,12,14,15,16,18]
[1,2,3,4,5,6,7,null,8,9,10]
[1,2,3,4,5,6,7,8,null,9,10,null,11,null,12]


// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algorithm does an Inorder Traversal, stores the last right child of every node and passes it to the parent node. The parent makes the left
// child's last right child 's right child the parent node's right child. Finally returns the root node, which contains the modified tree. 





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
    
    TreeNode* remLeft(TreeNode* temp){
        if(temp==NULL) return temp;
        //cout<<"Current elem.is: "<<temp->val<<endl;
        if(temp->left==NULL && temp->right==NULL) return temp;			// If it's a leaf, return the curr. node.
        
        TreeNode* temp1=remLeft(temp->left);
        if(temp1!=NULL){												// If it's a NULL left child, then modifying the last child of left 
            temp1->right=temp->right;									// subtree to the curr. node's right child.
            temp->right=temp->left;
            temp->left=NULL;											// Making the left child NULL.
        }
        
        TreeNode* temp2=remLeft(temp->right);							// Extracts the last elem. in the right subtree.
        if(temp2==NULL) return temp1;									// Finding the Last child of the curr. node.
        return temp2;													// Returning the last child of the curr. node.
        
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return ;
        remLeft(root);													// Calling the function to iterate the tree.
        return ;
    }
};