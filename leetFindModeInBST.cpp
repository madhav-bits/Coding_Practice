/*
*
//******************************************************501. Find Mode in Binary Search Tree.********************************************

Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,null,2,2]


[2,2,2,1,2,2,3]


[2,2,3,1,2,3,3]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Traversal based. We do Inorder traversal and keep track of count of diff. nums in the tree. We extract max. count of 
// a num in the tree. In the second iteration, we push all the nums with count equal to max. count, into final result vector.








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
    
    void calcMode(TreeNode* node,int &count,int &maxm,int &prev){			// Inc. the count of curr. node.
        if(!node) return ;
        calcMode(node->left,count,maxm,prev);								// Iter. left child. Does Inorder Traversal.
        if(prev!=node->val){												// If diff. value than prev. encountered.
            count=1;														// Update count.
            prev=node->val;													// Change the prev. var.
        }
        else count++;														// Else, inc. the count.
        if(count>maxm) maxm=count;											// Update the maxm. var.
        calcMode(node->right,count,maxm,prev);								// Iter. right child.
    }
    
    void extractMode( TreeNode* node,vector<int>&res,int maxm,int&count,int&prev ){// Extract values with max. count.
        if(!node) return ;
        extractMode( node->left, res,maxm,count,prev);						// Iter. the left child.
        if(prev!=node->val){												// If curr. val is diff. to prev. val.
            count=1;														// Renew count to 1.
            prev=node->val;													// Update the prev. value.
        }
        else count++;														//  Inc. the count of curr. val.	
        if(count==maxm) res.push_back(node->val);							// If count of a val equals maxm var, then store it.
        extractMode( node->right, res,maxm,count,prev);						// Iter. the right child.
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int>res;														// Final result vector.
        int count=0,maxm=0,prev=INT_MIN;
        calcMode(root,count,maxm,prev);										// Does Inorder traversal to extract max count of nums in Tree.
        // cout<<"maxm: "<<maxm<<endl;
        count=0; prev=-1;
        extractMode( root, res,maxm,count,prev);							// Extracts Nums with max. count.
        return res;															// Return the Modes.
        
    }
};