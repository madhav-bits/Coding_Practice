/*
*
//**********************************************************404. Sum of Left Leaves.***************************************************

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,1,4,5,6,7,8,null,null,4]


[]

[1,null,3]


[1,2,3,4,null,6,null]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack/Queue based. We store the next to be iterated nodes in the stack/queue. We extract the curr. node from the stack/queue.
// We check for it's left child and also check if it's left leaf or not? If it is, we add it's val to result sum, we also push the left child
// into the stack/queue. Thus, we iterate the entire tree and return the sum of left leaves.








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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;													// If empty tree provided, return 0.
        int res=0;
        queue<TreeNode*>s;													// Stores next to be iterated nodes.
        s.push(root);														// Push root into Stack/Queue.
        while(!s.empty()){
            TreeNode* curr=s.front();										// Extarct the curr. node to be scanned.
            s.pop();
            if(curr->left){													// If the left chidl is valid.
                if(!curr->left->left && !curr->left->right)					//If it's a left leave, then inc. the result sum.
                    res+=curr->left->val;		
                s.push(curr->left);											// We push the child into Stack/Queue.
            }
            if(curr->right) s.push(curr->right);							// If right child is valid, then push it into Stack/Queue.
        }
        return res;															// Return the sum of left leaves.
    }
};