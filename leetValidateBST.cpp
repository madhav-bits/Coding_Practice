/*
*
//******************************************************98. Validate Binary Search Tree.***********************************************

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[16,8,24,4,12,20,28,2,6,10,14,18,22,29,30]
[16,8,24,4,12,20,28,2,6,7]
[1]



// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This is making a Inorder Traversal and finding at each node, checking whether the value is satisfying the range limitations or not. Ranges
// are obtained from the parent node. The left child has same min value limi. as parent and parent value as max limi.. The right child has parent
// node val as min. limi. and parent's right limi. as it's right limitation. The moment a false is encountered, all further iterations won't 
// be entered. Thus as a whole, the fn. call returns false. If no such instance occurs, then the curr. is following BST rules(return true). 

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
    
    bool checkBST(TreeNode* temp, long long int lmin, long long int rmax){
            if(temp==NULL) return true;							// NULL node, returns true.
        //cout<<"temp. val is: "<<temp->val<<endl;
            if(temp->val<=lmin || temp->val >=rmax) return false;// If range limitations not satisfied, then return false.
            bool res=checkBST(temp->left,lmin, temp->val);
            if(res) 											// If left iter. is true, then only go into right child.
                res=checkBST(temp->right, temp->val, rmax);		// Improv. to return checkBST(temp->left) && checkBST(temp->right);
            else 												// If left is false, then return false imme. 
                return res;
            return res;											// This is the result of right call.
        
    }
    
    bool isValidBST(TreeNode* root) {
        long long int minm=-2147483649;//-2147483649			// Setting the min. value 1 less than INT_MIN.
        long long int maxm=2147483648;//2147483648				// Setting the min. value 1 greater than INT_MAX.
        bool res=checkBST(root,minm,maxm);
        
        //cout<<"INt min is; "<<minm<<endl;
        //cout<<"INt max is; "<<maxm<<endl;
        return res;
    }
};