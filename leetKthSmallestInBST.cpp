/*
*
//****************************************************230. Kth Smallest Element in a BST.*******************************************

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize 
the kthSmallest routine?

Credits:
Special thanks to @ts for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[7,2,10,null,4,8,14]
3



[20,10,40,5,15,20,null,null,null,14,18,null,25,11,14,17,19]
7


// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algorithm does PreOrderTraversal and gets the target ranked number. And ignores all further iterations by returning as soon as the 
// function is entered.

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
    int value;
    int findVal(TreeNode* temp, int rank, int target){
        if(temp==NULL) return rank;								// If NULL is encountered, rank is returned.
        if(rank>=target)										// This avoids all furthur iterations once target value is obtained.
            return INT_MAX;
        int sum1=findVal(temp->left, rank, target);				// Checking if the target value is in the left child's subtree.
        if(sum1+1==target)										// Checking if the target value is the current node.
            value=temp->val;
        
        sum1=findVal(temp->right, sum1+1,target);				// Checking if the target value is in the right child's subtree.
        return sum1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        findVal(root,0,k);										//Calling the function with the root value.
        return value;
    }
};