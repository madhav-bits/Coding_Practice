/*
*
//****************************************1457. Pseudo-Palindromic Paths in a Binary Tree.****************************************

https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/



Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least 
one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

 

Example 1:



Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red 
path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths 
since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] 
(palindrome).
Example 2:



Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green 
path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be 
rearranged in [1,2,1] (palindrome).
Example 3:

Input: root = [9]
Output: 1
 

Constraints:

The given binary tree will have between 1 and 10^5 nodes.
Node values are digits from 1 to 9.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[9]
[2,3,1,3,1,null,1]
[2,1,1,1,3,null,null,null,null,null,1]


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is HashMap based. Here, we look whether the path till leaf's permutation is palindrome or not? For a perm to be
// palin. # digits with odd number of occurrences has to be <=1. We maintain the cnt of digits in map. We keep track of #odds through
// another variable. At the tail, we check if #digits with odd occurrences is <=1, if it is we inc. the res. We return the res at
// the end of iteration.






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
    
    void iterateTree(TreeNode* node, vector<int>&occur, int odds, int&res){
        if(!node) return ;
        
        occur[node->val-1]++;												// Inc. the cnt of curr. num.
        if(occur[node->val-1]%2==1) odds++;									// If #occurrences is odd, we inc. the cnt.
        else odds--;														// If it is even, as it was odd earlier, we dec. the cnt.
        
        if(node->left==NULL && node->right==NULL){							// If it is leaf and #odds<=1 inc. the result.
            if(odds<=1) res++;
        }
        iterateTree(node->left, occur, odds, res);							// Iterate the left child.
        iterateTree(node->right, occur, odds, res);							// Iterate the right child.
        
        occur[node->val-1]--;												// As, map is passed as reference, we dec. the cnt. of num.
        if(occur[node->val-1]%2==0) odds--;									// If it is even, it is odd earlier, we dec. the odds cnt.
        else odds++;														// If it is odd, we inc. the cnt.
        
        return ;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>occur(9,0);												// Keeps tracks of #occurrences of each digit.
        int res=0;															// Tracks #pseudo palin. paths.
        iterateTree(root, occur, 0, res);									// iterate tree and check paths.
        return res;															// Return the #paths.
    }
};

