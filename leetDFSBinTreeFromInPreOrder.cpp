/*
*
//*********************************************105. Construct Binary Tree from Preorder and Inorder Traversal.***************************************

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[9,5,1]
[9,1,5]



// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).	
// Space Complexity: O(n).	
// This algorithm is DFS Oriented. First we extract the node of the curr. set of values from the first index of preOrder array. We find it's index 
// in Inorder array and make all values to that index's left as left subtree and to the right as right subtree. We respectively divide same #elem.
// in preOrder into left and right subtrees, and approach left and right subtrees recursively.



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
    
    int findIndex(vector<int>&in, int val){							// Finds the psn of first elem. of pre order array in the Inorder array.
        for(int i=0;i<in.size();i++){
            if(in[i]==val) return i;
        }    
    }
    
    TreeNode* calcTree(vector<int> &in, vector<int>&pre, int begin1, int end1, int begin2){
        
        if(begin1>end1) return NULL;								// If there are no elem. in curr. array, then return NULL. 
        TreeNode* node= new TreeNode(pre[begin2]);					// Forming the curr. node.
        if(begin1==end1) return node;								// If there is only one elem. then return that node.
        int ind= findIndex(in, pre[begin2]);						// Extracting preOrder's first elem. index in InOrder array.
        node->left= calcTree(in ,pre , begin1, ind-1, begin2+1);//begin2+1+ind-begin1-1=>end2 if one wants to use.
        node->right= calcTree(in, pre, ind+1, end1, begin2+ind-begin1+1);	// Calling left and right subtrees.       	
        return node;												// Returning the curr. node.
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if(in.size()==0) return NULL;								// If there are zero elem. return NULL.
        TreeNode* root= calcTree(in, pre , 0, in.size()-1, 0);		// Calling the fn. to form the tree.
        return root;												// Returning the root of the Tree Formed.
    }
};