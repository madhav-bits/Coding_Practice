/*
*
//************************************************************110. Balanced Binary Tree.***************************************************


Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[3,9,20,null,null,15,null]


[1,2,2,3,null,null,null,4]

[]

[1,2]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is recursion based. At each node we extract height of left and right child. If the diff. is >1, then return INT_MAX to indicate
// to the higher level that the curr. node is not Balanced, So, it need not get Height from other child, so as to compare heights. If the
// result from a child is INT_MAX, then we directly return INT_MAX as a result. In case of right child, if we get INT_MAX, we direclty INT_MAX
// without comparing both left and right childs. At the end of all iteraions, we check we check whether the result is INT_MAX or not, if it is
// INT_MAX, we return false, we return true(As the root returned it's max Height expecting height from it's sibling to get compared, which also 
// confirms that the tree is Balanced).








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
    
    int findBalanced(TreeNode* node){
        if(node==NULL) return 0;												// If root is NULL, return 0.
        int lt=0,rt=0;															// Stores left and right child heights.
        lt=findBalanced(node->left);											// Get height from left chlid.
        if(lt==INT_MAX) return INT_MAX;											// If height is INT_MAX, return INT_MAX direclty.
        rt=findBalanced(node->right);											//  Get Height from right child.
        if(rt==INT_MAX) return INT_MAX;											// If height is INT_MAX, return INT_MAX direclty.
        return (abs(lt-rt)>1)?INT_MAX: max(lt,rt)+1;							// Else return maxHeight if diff<1, else return INT_MAX.
        
    }
    
    bool isBalanced(TreeNode* root) {
        int ans=findBalanced(root);												// Calling fn. to extract maxHeight from the tree.
        return (ans==INT_MAX)?false:true;										// If the ans is INT_MAX, return false else return true.
    }
};