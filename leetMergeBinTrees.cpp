/*
*
//******************************************************617. Merge Two Binary Trees.***********************************************

Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the 
others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the 
merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
Note: The merging process must start from the root nodes of both trees.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[1,3,2,5]
[2,1,3,null,4,null,7]

[]
[1]



[]
[]


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. At each step, we check each of the nodes is not NULL or not. If it is NULL, we assign non-NULL node to result.
// If not NULL, we sum those values. We move on to child nodes. 





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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* node= new TreeNode(0);
        if(t1==NULL && t2==NULL) return NULL;									// If both are NULL, return NULL.	
        if(t1==NULL){															// If t1==NULL, return t2.
            node=t2;
            return node;
        }
        else if(t2==NULL){														// If t2==NULL, return t1.
            node=t1;
            return node;
        } 
        else node->val=(t1->val+t2->val);										// If, t1,t2 are non-NULL, sum those values and fn. to add child.
        node->left=mergeTrees(t1->left,t2->left);
        node->right=mergeTrees(t1->right, t2->right);
        return node;															// Return node.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. At each step, we check each of the nodes is not NULL or not. If it is NULL, we assign non-NULL node to result.
// If not NULL, we sum those values. We move on to child nodes. We move the values into first tree and update it's nodes.




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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        //TreeNode* node= new TreeNode(0);
        //if(t1==NULL && t2==NULL) return NULL;									
        if(t1==NULL){															// If t1 is NULL, return t2.
            //node=t2;
            return t2;
        }
        else if(t2==NULL){														// If t2 is NULL, return t1.
            //node=t1;
            return t1;
        } 
        else t1->val=(t1->val+t2->val);											// If both are non-NULL, sum their values.
        t1->left=mergeTrees(t1->left,t2->left);									// Call. fn. to update left and right child values.
        t1->right=mergeTrees(t1->right, t2->right);
        return t1;																// Return the udpated node.
    }
};