/*
*
//******************************************************530. Minimum Absolute Difference in BST.***********************************************

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[100,20,200,10,60, 110, 230,null,null,21,98,null,null,202,null,null,58,64,99]

[0,null,2236,1277,2776,519]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is reucrsion based, we iterate through the entire array, at each step, we pass the max(rightmost value in the left child  and 
// min. vlaue in right child to the ptr.As, they might form the least diff nodes with the parent node. We also get diff of child's returned values
// with the curr. node's value and check whether this is the least diff.








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
    int diff=INT_MAX;																// Stores the min. abs. diff.
    
    pair<int, int> getDiff(TreeNode* node){       // First val. of pair is minm, and second is maxm.
        //if(node==NULL) return make_pair(INT_MIN, INT_MAX);
        int minm, maxm;
        minm=node->val;																// Default min, max values in that subtree.
        maxm=node->val;
        
        pair<int, int> lt, rt;
        if(node->left!=NULL){														// If left child is not NULL, we extract min/max of that child.
            lt=getDiff(node->left);
            // cout<<"CUrr. comparing value at node val: "<<node->val<<" and left max: "<<lt.second<<endl;
            diff=min(node->val-lt.second, diff);									// Updating the min. diff value.
            minm=min(minm, lt.first);
            
        }
        if(node->right!=NULL){														// If right child is not NULL, we extract min/max of that child.
            rt=getDiff(node->right);
            // cout<<"CUrr. comparing value at node val: "<<node->val<<" and right min: "<<rt.first<<endl;
            diff=min(rt.first-node->val, diff);
            maxm=max(maxm, rt.second);
        }
        
        // cout<<"Curr.node value: "<<node->val<<" and minm: "<<minm<<" and maxm: "<<maxm<<endl;
        return make_pair(minm, maxm);												// Returning the max, min of this subtree.
        
    }
    
    int getMinimumDifference(TreeNode* root) {
        getDiff(root);																// Call the fn. to extract min. diff.
        //cout<<"The result is; "<<diff<<endl;
        return diff;																// Return the min. diff.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is reucrsion based, as the min. diff any one of diff b/w parent child and right most child in the left subtree or leftmost child
// in the right subtree. Which we can get from Inorder traversal, where we store previously visited value in global variable and compare that with 
// the curr. node's value and we try to update the min. diff.








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
    int diff=INT_MAX, prev=-2;															// Stores Diff min and first of two values to compare.
    
    void getDiff2(TreeNode* node){
        if(node->left!=NULL) getDiff2(node->left);										// Traversing the left child, to reach the rightmost child.
        //cout<<"Comparing node val: "<<node->val<<" and prev value: "<<prev<<endl;
        if(prev<0) prev=node->val;														// Assigning first value.
        else{
            diff=min(diff, node->val-prev);												// Calc. diff b/w prev. and curr. value.
            prev=node->val;
        }
        if(node->right!=NULL) getDiff2(node->right);									// Visiting the right child.
        return ;																		
    }
    
    int getMinimumDifference(TreeNode* root) {
        getDiff2(root);																	// Calling the fn. to extract min. diff.
        return diff;																	// Returning the min. diff.
    }
};