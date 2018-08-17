/*
*
//**********************************************************250. Count Univalue Subtrees.***************************************************

Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

Example :

Input:  root = [5,1,5,5,5,null,5]

              5
             / \
            1   5
           / \   \
          5   5   5

Output: 4



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,1,5,null,5,null,6]

[]

[1,null,1,2,null]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iterate through all nodes, if we reach a leaf, we return true. If we have left, right child active,
// we traverse both of them. If both of them are of univalue subtrees, they return true, if either or both of them return false, return false
// from curr. node. If both are true, then compare left, right child values(if they exist) with curr. node's val, if all are equal, return 
// true from this node also. Whenver we have a true result at a node, we inc. the count by one. At the end of iteration, we return the total 
// count of uinvalue subtrees.








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
    int count=0;															// Tracks univalue subtrees.
    bool findSubtrees(TreeNode* node){
        if(!node->left && !node->right){									// If it's a leaf, return true and inc. the count.
            count++;
            return true;
        }
        bool lt=true, rt=true;												// Default values as true.
        if(node->left) lt=findSubtrees(node->left);							// Extracting whether left child is univalue or not?
        if(node->right) rt=findSubtrees(node->right);
        if(!lt || !rt) return false;										// If any of them or not univalue, return false.
        
        if(node->left && node->right){										// If both children exist.
            if(node->left->val==node->right->val && node->left->val==node->val){// Compare their values.
                count++;													// If equal, return true and inc. the count.
                return true;    
            }
            else return false;												// If vlaue is not equal, then return false.
        } 
        else if(node->left){												// If only left child exist.
            if(node->left->val==node->val){									// If left child value is equal to curr. node value.
                count++;
                return true;
            }
            else return false;												// If vlaue is not equal, then return false.
        }
        else if(node->right){												// If only right child exist.
            if(node->right->val==node->val){
                count++;
                return true;
            }
            else return false;												// If vlaue is not equal, then return false.
        }
    }
	
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return 0;													// If empty tree given return 0.
        findSubtrees(root);													// Calling fn. to extract #univalue subtrees.
        return count;														// Return the count of univalue subtrees.
    }
};