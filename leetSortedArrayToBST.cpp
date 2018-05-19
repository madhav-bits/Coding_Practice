/*
*
//**************************************************108. Convert Sorted Array to Binary Search Tree.*******************************************

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never 
differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[-10,-3,0,5,9,12]

[]

[1]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is split based. At each instant we chose curr. subarray's mid index value as node then call fn. to create left and right child.
// All the subarrays size down either two/single sized subarrays, which were individually. Instead a single cdn(begin>end) return NULL would also
// work.



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
    
    TreeNode* formTree(vector<int> &v, int begin, int end){
        if(begin==end){																	// When we have only single elem. in subarray.
            TreeNode* node= new TreeNode(v[begin]);										// Form a node and return it.
            return node;
        }    
        if(begin+1==end){																// When we have only two elem. in subarray.
            TreeNode* node=new TreeNode(v[end]);										// Form left child and parent and return parent.
            node->left= new TreeNode(v[begin]);
            return node;
        }
        
		//if(begin>end) return NULL;													// This cdn would do the same as above two if cdns.
        int mid=(begin+end)/2;															// Calc. mid index.
        TreeNode* node=new TreeNode(v[mid]);											// Form node using mid index's value.
        node->left=formTree(v,begin,mid-1);												// Form left and right childs.
        node->right=formTree(v,mid+1,end);
        return node;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;													// If empty vector is given, return empty tree/NULL.
        return formTree(nums,0,nums.size()-1);											// Calling fn. to form Tree with vector's contents.
    }
};