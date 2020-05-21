/*
*
//******************1430. Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree.***********************

https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/description/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,1,0,0,1,0,null,null,1,0,1]
[0,1,1,1]


[0,1,0,0,1,0,null,null,1,0,1]
[0,1,1]

[0,1,0,0,1,0,null,null,1,0,1]
[]

// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We use index to keep track of numbers we had encountered and number we are currently looking for.
// If node's val is different, we return false. If we had reached NULL node, we return false. If we had a leaf and end of array, then
// we return true. If we get true from any of the children, we return true, else return false.







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
    
    bool findSequence(TreeNode* node, vector<int>&arr, int index){
        if(!node) return false;
        if(index>=arr.size() || node->val!=arr[index]) return false;		// Not the scenarios we are looking for.
        if(node->left==NULL && node->right==NULL && index==(int)arr.size()-1) return true;// If we reach leaf and end of arr, return true.
        if(findSequence(node->left, arr, index+1)) return true;				// If child gives true, return true.
        return findSequence(node->right, arr, index+1);						// Return what right child returns.
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        int index=0;
        return findSequence(root, arr, index);								// Iterate tree to find the path.
    }
};