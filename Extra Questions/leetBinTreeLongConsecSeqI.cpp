/*
*
//****************************************************298. Binary Tree Longest Consecutive Sequence.*********************************************

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest 
consecutive path need to be from parent to child (cannot be the reverse).

Example 1:

Input:

   1
    \
     3
    / \
   2   4
        \
         5

Output: 3

Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
Example 2:

Input:

   2
    \
     3
    / 
   2    
  / 
 1

Output: 2 

Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,null,3,2,4,null,null,null,5]


[2,null,3,2,null,1]



[2,3,3,4,null,1,null,null,5]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the tree in a recursive fashion, we do a bottom to top approach. We get the longest conse. seq. length from the child,
// we compare whether child is 1 greater than node value, if it is, we add 1 to leng. that child already accumulated and try to update the final
// result with new value(child's length+1). 



// Instead of getting the len. of consec. sequence from child as a returned value, here I am passing a new var as pass by reference into
// the fn. call, after the fn. call I work on this value passed as reference.





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
    int res=1;																// Tracks the longest conse. seq. in the tree.
    void findLen(TreeNode* node, int&decLen){
        if(!node->left && !node->right){									// If leaf reached, we start a sequence from there.
            decLen=1;
            return ;
        }
        decLen=1;															// Default value of seq. starting from curr. node towards the leaf.
        int decL=0, decR=0;													// Vars to extract long. consec. seq in the child.
        if(node->left){														// Calling left child to extract long. consec. seq. in it.
            findLen(node->left,decL);
            if(node->left->val-1== node->val) decLen=max(decLen,decL+1);// Try to update the long consec seq. by using seq. starting from curr node.
        }
        if(node->right){													// Calling right child.
            findLen(node->right,decR);
            if(node->right->val-1== node->val) decLen=max(decLen,decR+1);
        }
        
        res=max(res,decLen);												// Try to update the overall result.
        
    }
    
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;													// If empty is given, return 0(no seq. can be formed).
        int dec=0;															// Tracks long. conse. seq. starting from root.
        findLen(root,dec);													// Calls fn. to extract Longest consec. seq.
        return res;															// Returning the Longest consec. seq. in the tree.
    }
};