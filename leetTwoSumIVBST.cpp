/*
*
//******************************************************653. Two Sum IV - Input is a BST.***********************************************

Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the 
given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,3,9,2,4,null,17]
10


[5,3,6,2,4,null,7]
9

[5,3,6,2,4,null,7]
7



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm traverses the Tree in Inorder Traversal method. We store the travesed path(inc. sequence of nums) in a vector. On, which
// we perform the 2 Sum Search.






//InOrder Traversal Method.

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
    
    void inOrder(TreeNode* node, vector<int>& v){							// Does Inorder Traversal.
        if(node==NULL) return ;
        inOrder(node->left, v);
        v.push_back(node->val);
        inOrder(node->right, v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;														// Stores the elem. of tree in sorted form.
        inOrder(root, v);													// Extracts values from BST in Inorder Fashion.
        int start=0, close=v.size()-1;										// Setting indices for two ptrs.
        while(start<close){													// Performing the 2 Sum on the sorted array.
            if(v[start]+v[close]==k) return true;							// Sum of two nums. is target, return true.
            if(v[start]+v[close]<k) start++;
            else close--;
        }
        return false;														// If after entire iteration, the target not found, return false.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm traverses the tree. At each node, we calc. the value of the next elem. in pair to make the target value and call fn. to find
// the next one in (logn) time. We also have to make sure, the next chosen isn't the first value chosen of the pair.






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
    
    bool findPair(TreeNode* root, TreeNode* node, int sum){					// Selects the first elem. of pair and calls fn. to find second one.
        if(node==NULL) return false;										// Make sure that the second is not the first one while searching.
																			// node->val*2!=sum, makes sure, same value isn't chosen for both.
        return ((node->val*2!=sum && findNum(root,sum-node->val)) ||findPair(root, node->left, sum) || findPair(root,node->right, sum));
    }
    
    bool findNum(TreeNode* node, int target){								// Find the second number in the BST.
        if(node==NULL) return false;
        if(node->val==target) return true;
        if(node->val<target) return findNum(node->right, target);
        else return findNum(node->left, target);
    }
    
    bool findTarget(TreeNode* root, int k) {
        return findPair(root,root,k);										// Finds a pair whose sum is equal to target.
    }
};