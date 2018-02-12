/*
*
//*********************************************************113. Path Sum II.************************************************

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[5,4,9,11,null,13,4,7,2,null,null,5,1]
23



// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algorithm does Inorder Traversal and saves the nodes travelled till then temp. in a vector, also saves the sum of the path travelled
// till then and check whether the sum equals the target and the curr. node is leaf or not. If satisfied, then pushed into final res. vector.

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
    vector<vector<int>> v;
    void findPath(TreeNode* temp, int target, int sum, vector<int> u){
        if(temp==NULL) return;
        sum+=temp->val;													// Including the value of the curr. node.
        u.push_back(temp->val);											// As this node involves in the sum which aims to reach value of target.
        if(sum== target && temp->left==NULL && temp->right==NULL)		// If the sum is target and if it's a leaf, then push in final vector.
            v.push_back(u);
        findPath(temp->left,target,sum,u);								// Then call the left child.
        findPath(temp->right,target, sum,u);							// Then call the right child.
        u.pop_back();													// Pop the curr. node from the temp.vec as it wont be involved in the sum-
																		// here onwards.
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> u;
        findPath(root,sum,0,u);										// Calling the function.
        return v;
    }
};