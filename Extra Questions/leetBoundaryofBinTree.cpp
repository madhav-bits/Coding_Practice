/*
*
//******************************************************545. Boundary of Binary Tree.***********************************************

Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, 
leaves, and right boundary in order without duplicate nodes.

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. 
If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only 
applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to 
the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1
Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].
Example 2
Input:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
Ouput:
[1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,null,2,3,4]

[1,2,3,4,5,6,null,null,7,8,9,10]

[1,2,3,4,5,6,null,null,null,7,8,9,10]

[1,2,null,3,4]

[1,null,2,null,3,4]

[1,null,2,3,4]





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, we do a Leftwise Border Traversal using traversals focusing on leftwise, rightwise movements. We also have 
// a Inorder traversal to get the leaves of the tree, we remove few overlapping nodes b/w leftwise traversal & Leaf Traversal, also b/w Leaf Tr-
// -aversal and Rightwise traversal.







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
    
    bool isLeaf(TreeNode* node){											// Says whether a node is leaf or not.
        return (node->left==NULL && node->right==NULL);
    }
    
    void extractLeftSide(TreeNode* node, vector<int>&res){					// Extracts Leftwise Border.
        if(node==NULL) return ;
        res.push_back(node->val);
        if(node->left) extractLeftSide(node->left, res);					// Traverse left child as first priority.
        else extractLeftSide(node->right, res);								// If left is NULL, traverse right child.
    }
    
    void extractRightSide(TreeNode* node, vector<int>&res){					// Extracts Rightwise Border.
        if(node==NULL) return ;
        if(node->right) extractRightSide(node->right, res);					// Traverse Rightchild as first priority.
        else extractRightSide(node->left,res);								//  If right child is NULL, traverse left child.
        res.push_back(node->val);
    }
    
    void extractLeaf(TreeNode* node, vector<int>&res){						// Extract Leaves in Tree.
        if(node==NULL) return ;
        if(isLeaf(node))
            res.push_back(node->val);
        extractLeaf(node->left, res);										// Extract Leaves left to right wise.
        extractLeaf(node->right, res);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root==NULL) return vector<int>();
        if(isLeaf(root)) return vector<int>(1,root->val);					// If only one elem. present.
        vector<int>res;
        res.push_back(root->val);											// Pushing root's value into final res.
        if(root->left){														// Extract Left Border elem. in left child.
            extractLeftSide(root->left,res);
            res.pop_back();													// Removing the last left border elem./ child from the list.
        }
        extractLeaf(root,res);												// Extract all leaves.
        if(root->right){													// Extract Right Border elem. in right child.
            res.pop_back();													// Removing last leave, if it from right child, and push all rightmost
            extractRightSide(root->right, res);								// node values into final result vector.
        }
        return res;															// Return the final result vector.
    }
};



