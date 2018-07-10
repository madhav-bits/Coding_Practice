/*
*
//******************************************************366. Find Leaves of Binary Tree.***********************************************

Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:

          1
         / 
        2          
2. Now removing the leaf [2] would result in this tree:

          1          
3. Now removing the leaf [1] would result in the empty tree:

          []         
Returns [4, 5, 3], [2], [1].

Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,5,null,null,6]



[1,2,3,4,5,null,10,6,null,7,null,null,11,null,7]


[1,2,null,3,null,4,null,5]


[1,null,2,null,3,null,4,null,5]





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is recursion based. We accumulate the node values from Bottom to Top. Each node returns it's maxm dist. to leaf. If we 
// don't that index(Curr. node's max. height from leaf) available in final result vector. We create an empty array at that psn and push the 
// curr. node's value. If the index in final result is available for that height, then we add curr. node value to that index directly.








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
    vector<vector<int>>res;													// Final result vector.
    
    int findResult(TreeNode*node){
        if(node==NULL) return 0;											// If node is NULL, return 0.
        int lt=findResult(node->left);										// Get maxm. dist to leaf from left child.
        int rt=findResult(node->right);										// Get maxm. dist to leaf from right child.
        int maxm=max(lt,rt);												// Get max. of two heights.
        if(maxm==res.size()) res.push_back({node->val});		// If maxm. height not avaiable, we create a array with node's value at that index.
        else res[maxm].push_back(node->val);								// If maxm. height index available, add curr. value to that list.			
        return maxm+1;														// Return maxm. height+1 to the parent.
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        findResult(root);													// Call. fn. to extract Leaves.
        return res;															// Returning the final result vector.
    }
};