/*
*
//**************************************************998. Maximum Binary Tree II.***********************************************

https://leetcode.com/problems/maximum-binary-tree-ii/description/


We are given the root node of a maximum tree: a tree where every node has a value greater than any other value in its subtree.

Just as in the previous problem, the given tree was constructed from an list A (root = Construct(A)) recursively with the following 
Construct(A) routine:

If A is empty, return null.
Otherwise, let A[i] be the largest element of A.  Create a root node with value A[i].
The left child of root will be Construct([A[0], A[1], ..., A[i-1]])
The right child of root will be Construct([A[i+1], A[i+2], ..., A[A.length - 1]])
Return root.
Note that we were not given A directly, only a root node root = Construct(A).

Suppose B is a copy of A with the value val appended to it.  It is guaranteed that B has unique values.

Return Construct(B).

 

Example 1:



Input: root = [4,1,3,null,null,2], val = 5
Output: [5,4,null,1,3,null,null,2]
Explanation: A = [1,4,2,3], B = [1,4,2,3,5]
Example 2:


Input: root = [5,2,4,null,1], val = 3
Output: [5,2,4,null,1,null,3]
Explanation: A = [2,1,5,4], B = [2,1,5,4,3]
Example 3:


Input: root = [5,2,3,null,1], val = 4
Output: [5,2,4,null,1,3]
Explanation: A = [2,1,5,3], B = [2,1,5,3,4]
 

Note:

1 <= B.length <= 100




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked with examples provided with question.



// Time Complexity: O(n).													// n- #nodes in the tree(In case of skewed tree).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- #nodes in the tree(In case of skewed tree).
// Space Complexity: O(1).	
// This algorithm is iteration based. As the new number is added at the end. We iter. down the tree until we find a node whose value
// is less than new value. We move to right child, as this num. added at the end. If we find a node with lesser value, this node would
// be left child and this new node would be right child of prev. node.








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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* prev=root, *node=root;
        TreeNode* lat=new TreeNode(val);									// Create new node.
        // if(!root) return lat;
        if(!root || root->val<val){											// Base case.
            lat->left=root;
            return lat;
        }
        while(node && node->val>val){										// Iter. through higher value parents.
            prev=node;
            node=node->right;
        }
        if(!node) prev->right=lat;											// If no child exists, new node is right child of prev. node.
        else{
            // TreeNode* temp=prev-
            prev->right=lat;
            lat->left=node;													// Child node would be left child of new node.
        }
        return root;														// Return the root node of the updated tree.
    }
};