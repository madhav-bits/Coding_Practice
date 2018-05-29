/*
*
//******************************************************222. Count Complete Tree Nodes.***********************************************

Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left 
as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,5,6]

[1,2,3,4,5,6,7,8,9,10,11,12]

[1,2,3,4,5,6,7,8,9,10,11,12,13,14]

[]


[1]



// Time Complexity: O(logn)^2.  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn)^2.
// Space Complexity: O(1).	
// This algorithm is binary search based. We try to find the last elem. in the last level. In the process, we count all the nodes that we have
// eliminated searching in, in the process we count all the nodes in the tree and reach a NULL. Then we return #nodes in tree.

//The main logic is that:
// We calc. height to left most elem. in both the childs, if the height of leftmost node in right child has same height as left child, then last
// node is in right child else last node is in left child. Thus, we eliminate searching in half the nodes at each step.





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
    
    int calcHeight(TreeNode* node){													// Calc. Height of the tree.
        if(node==NULL) return 0;
        return 1+calcHeight(node->left);
        
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        TreeNode* temp=root;
        int sum=0;
        int h= calcHeight(root);												// Calc. Height of the tree.
        
        while(temp!=NULL){														// We iterate a NULL is reached.
            if(calcHeight(temp->right)==h-1){									// If right & left child's hei is same, last node is in right child.
                sum+=(1<<(h-1));												// We count all elem. in left child and curr. node.
                temp=temp->right;												// Moving to right child.
            }
            else{																// If left child's hei. is less, then last node is in left child.
                sum+=(1<<h-2);
                temp=temp->left;												// Moving to left child.
            }
            h--;																// Updating the height of the curr. node.
        }
        
        //cout<<"The no. of nodes: "<<sum<<endl;
        return sum;																// Returning the total #nodes.
    }
};