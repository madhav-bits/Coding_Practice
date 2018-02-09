/*
*
//****************************************************515. Find Largest Value in Each Tree Row.*******************************************

You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]


//These are the examples I had created, tweaked and worked on.
[1,2,3,4,5,null,6,null, null,8,null,9]
[1,2,3,4,5,null,7,null,null,8]
[1,2,3,4,5,10,6,null, null,8,null,19,null,9,null,20,null,null,2]
[1,2,3,-4,5,-10,-6,null, null,-8,null,-19,null,9,null,-20,null,null,-2]
[-2,-3,-5]
[-2,-3,5]
[-2,3,-5]
[-2,3,5]
[2,-3,-5]
[2,-3,5]
[2,3,-5]
[2,3,5]
[-2,-1]
[-1,5,null,4,null,null,2,-4]


// Time Complexity: O(n).
// Space Complexity: O(logn).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(logn).			
// This is making a Inorder Traversal, while maintaining the highest values in each level in a vector. If the curr. level = size of vector add
// a new elem. to vector and make it the max. value in that level iterated till then and update the max. values as we keep on iterating.



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
    void findLargeValRow(TreeNode* temp,vector<int> &v,int height){
        if(temp==NULL) return ;
        if(v.size()==height)
            v.push_back(temp->val);													// Pushing the first val. in that level and make it max.
        
        else
            v[height]=max(v[height], temp->val);									//Maintains the max. value at each level.
        
        findLargeValRow(temp->left,v,height+1);										// Calling the left child.
        findLargeValRow(temp->right,v,height+1);									// Calling the right child.
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;																// Stores the max. value of each row/level.
        findLargeValRow(root,v,0);
        return v;																	// Returning the vector containing each row's max. values.
    }
};
