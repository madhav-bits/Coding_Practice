/*
*
//**************************************************549. Binary Tree Longest Consecutive Sequence II.*******************************************

Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the 
path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

Example 1:
Input:
        1
       / \
      2   3
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
Example 2:
Input:
        2
       / \
      1   3
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
Note: All the values of tree nodes are in the range of [-1e7, 1e7].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,1,3]


[10,5,11,4,6,null,null,null,3,7]


[6,5,11,4,6,null,null,null,3,7]


[6,5,7,4,6,8,null,null,3,7,null,null,9]


[1,234,2,6,3,6,3,2,4,6,null,null,null,4]



[1,2,null,3,null,4]


[4,null,3,null,2,null,1]


[1,3,4]


[24,25,25,26,24,26,24,25,27,23,23,25,25,23,23,26,24,26,28,24,22,22,24,26,26,26,26,22,24,22,22,null,27,null,25,null,25,null,27,null,25,null,21,null,23,23,23,null,25,null]



[25,26,24,null,27,23,null,null,28,null,22,null,null,null,21]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the tree in recursive fashion. We extract the inc. and dec. length in the child, we compare their value to curr. node's
// value and inc. the inc/dec length sequence. As, the inc./dec. sequence can be in  a single path or curvd path(child-parent-child), we 
// add inc./dec seq. len from one end, dec/inc. sequence from other end, and try to update the overall sequence length.



// I had written some redundant code as when both childs exist, I had compared values for existence of seq. and added those lens(which is waste,
// as getting the values assigned to incLen/decLen vars mean they form a conse sequence).




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
    int res=1;
    void findLen(TreeNode* node, int &incLen, int &decLen){
        if(!node) return ;
        if(!node->left && !node->right){									// If leaf reached, make inc/dec. sequence len=1.
            incLen=1; decLen=1;
            return ;
        }
        int incL=0, decL=0, incR=0, decR=0;									// Set temp vars.
        findLen(node->left,incL, decL);										// Call left and right child with these values.
        findLen(node->right, incR,decR);	
        incLen=1; decLen=1;													// Default value of inc/dec. sequence incl. this node is 1.
        if(node->left && node->left->val+1==node->val) incLen=incL+1;		// If left child can be used to form inc seq, get inc. seq. len.
        else if(node->left && node->left->val-1==node->val) decLen=decL+1;
        
        if(node->right && node->right->val+1==node->val) incLen=max(incLen,incR+1);// If right child can form inc. seq with curr. node.
        else if(node->right && node->right->val-1==node->val) decLen=max(decLen,decR+1);
        
        // if(node->left && node->right){									// If two nodes exist, we try to from inc./dec seq. with those child.
        //     if(node->left->val+1==node->val && node->right->val-1==node->val) res=max(res,incL+decR+1);
        //     if(node->left->val-1==node->val && node->right->val+1==node->val) res=max(res, decL+incR+1);
        // }
        
        // res=max(res,max(incLen,decLen));									// As seq. can be a single straight path.
        res=max(res,incLen+decLen-1);										// This handles all cases(straight path, curved path).
        // cout<<"At node: "<<node->val<<" inc. len: "<<incLen<<" and decLen: "<<decLen<<endl;   
        
    }
    
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;													// If empty tree given, return 0.
        int inc=0, dec=0;													// Default values of inc/dec seq. len=0.
        findLen(root,inc,dec);												// Call fn. to extract len of sequences.
        return res;															// Returning the max. len of consec. sequence.
    }
};