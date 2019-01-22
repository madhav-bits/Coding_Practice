/*
*
//******************************************************979. Distribute Coins in Binary Tree.***********************************************

Given the root of a binary tree with N nodes, each node in the tree has node.val coins, and there are N coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to another.  (The move may be from parent to child, or from child to 
parent.)

Return the number of moves required to make every node have exactly one coin.

 

Example 1:



Input: [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
Example 2:



Input: [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves].  Then, we move one coin from the root of the tree to 
the right child.
Example 3:



Input: [1,0,2]
Output: 2
Example 4:



Input: [1,0,0,null,3]
Output: 4
 

Note:

1<= N <= 100
0 <= node.val <= N




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,0,0,0,0,0,0,null,null,7,null,null,null,null,0,null,null,1]






// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Traversal based. Here, we iterate over tree. We collect #coins needed from both child and add it to the #coins needed at curr.
// node and forward the total needed coins to it's parent. If a node has 'k+1' coins placed in it, then it has 'k' extra coins and this value is passed
// to it's parent. If a node doesn't have coin placed in it, then it has '1' defi. coin, so '-1' is passed to it's parent. While transferrig coins 
// req. we add the abs. value of passing #coins to the #coins displaced var. So, at the end of iter. we get the total distace of coins.







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
    
    int giveCoins(TreeNode* node, int &res){								// Finds #coins req. at curr. subtree.
        if(!node) return 0;													// Base case.
        int lt=giveCoins(node->left, res);									// Get #coins req. in left child.
        int rt=giveCoins(node->right, res);									// Get #coins req. in right child.
        int rem=node->val-1;												// Get extra coins needed at this node.
        rem+=lt+rt;															// Add extra coins to extra coins that of both child.
        res+=abs(rem);														// Adding the extra coins to coins displ.
        // cout<<"node val: "<<node->val<<" and Adding coins: "<<rem<<endl;
        return rem;															// Passing the extra coins to parent.
    }
    
    int distributeCoins(TreeNode* root) {
        int res=0;															// Tracks total coins displacement in the process.
        giveCoins(root, res);												// Call fn. to calculate coins displacement.
        return res;															// Returning the total coins displacement in the process.
    }
};