/*
*
//**************************************************1448. Count Good Nodes in Binary Tree.*******************************************

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value 
greater than X.

Return the number of good nodes in the binary tree.

 

Example 1:



Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
Example 2:



Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.
 

Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


Worked with cases provided in the question.



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, since good nodes depend on the values encountered in the path from the root. So, we keep
// track of maxm. node value encountered in the path. If curr. node is >= maxm. node encountered in the path, then we inc. the good
// nodes count. We also update the maxm. node value at every node. At the end of iter., we return the good nodes count.






/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void findGoodNodes(TreeNode* node, int &res, int maxm){
        if(!node) return ;
        if(node->val>=maxm){												// If curr. nodes is >= all nodes in the path from root.
            res++;															// Inc. the count of good Nodes.
            maxm=max(maxm, node->val);										// Update the maxm. node value in the path.
        } 
        findGoodNodes(node->left, res, maxm);								// Iter. left subtree.
        findGoodNodes(node->right, res, maxm);								// Iter. right subtree.
        return ;
    }
    
    int goodNodes(TreeNode* root) {
        int res=0;															// Tracks Good Nodes.
        findGoodNodes(root,res,-10001);										// Iterate tree and count Good Nodes.
        return res;
    }
};