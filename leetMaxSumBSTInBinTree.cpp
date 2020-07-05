/*
*
//***********************************************1373. Maximum Sum BST in Binary Tree.***********************************************

https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/


Given a binary tree root, the task is to return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:



Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
Example 2:



Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
Example 4:

Input: root = [2,1,3]
Output: 6
Example 5:

Input: root = [5,4,8,3,null,6,3]
Output: 7
 

Constraints:

The given binary tree will have between 1 and 40000 nodes.
Each node's value is between [-4 * 10^4 , 4 * 10^4].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]


[4,3,null,1,2]


[-4,-2,-5]


[2,1,3]


[5,4,8,3,null,6,3]


[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is DFS based. We iter. over tree, in the process we check whether that subtree is BST or not, if it is we get the total of
// subtrees and maximize the subtree total encountered till then. At the end, we get maxm. total of BST subtree.


/*

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
    
    int res=0;
    vector<int> findMaxSum(TreeNode* node){
        
        vector<int>lt({node->val, node->val-1, 0});							// Default values of array from left child.
        vector<int>rt({node->val+1, node->val, 0});
        if(node->left) lt=findMaxSum(node->left);							// Give left child call, only if it exists.
        if(node->right) rt=findMaxSum(node->right);
        if(lt[1]<node->val && rt[0]>node->val){								// If it is BST, add values from left, right child.
            res=max(res, node->val+lt[2]+rt[2]);							// Updating the maxm. total sum.
            return {lt[0], rt[1], node->val+lt[2]+rt[2]};					// Returning arr. from curr. node.
        }
        return {INT_MIN, INT_MAX, res};										// If curr. subtree is not BST, return this arr.
    }
    
    int max_sum = 0;
    array<int, 3> dfs(TreeNode* n) {										// Slightly diff. denotion of func. defn.
        auto l = n->left ? dfs(n->left) : array<int, 3>{0, n->val, n->val - 1};
        auto r = n->right ? dfs(n->right) : array<int, 3>{0, n->val + 1, n->val};
        if (l[2] < n->val && n->val < r[1]) {
            max_sum = max(max_sum, n->val + l[0] + r[0]);
            return {n->val + l[0] + r[0], l[1], r[2]};        
        }
        return {max_sum, INT_MIN, INT_MAX};
    }
    
    int maxSumBST(TreeNode* root) {
        // findMaxSum(root);												// Giving call to func. to calc. maxm. total sum of BST.
        // return res;
        return dfs(root)[0];
    }
};
