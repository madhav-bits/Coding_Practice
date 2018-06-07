/*
*
//**********************************************************257. Binary Tree Paths.***************************************************

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2]

[1]

[1,2,3]

[1,2,3,4,null,nulll,5]


[1,2,3,4,5,6,null,null,7,8,null,null,9]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is recursion based. At each step, we check whether curr. node id leaf or not? If it's leaf we push the path that we have obtained
// till now into result vector. If the curr. node is not leaf, then we add curr. node's value to path from the root and pass it to non-NULL child.
// As the first node(root) wont' be having "->" prior to it in the result, it had to be dealt specially.








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
    
    void extractPath(TreeNode* node, vector<string>&res, string s){
        s+="->"+to_string(node->val);																// Adding curr. node's val. to path from root.
        if(node->left==NULL && node->right==NULL){													// If leaf reached, push path into res vector.
            res.push_back(s);
            return;
        }
        if(node->left!=NULL) extractPath(node->left, res, s);										// Travelling left child it non-NULL.
        if(node->right!=NULL) extractPath(node->right, res, s);										// Travelling right child it non-NULL.
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        if(root==NULL) return res;
        if(root->left==NULL && root->right==NULL) return vector<string> (1,to_string(root->val));	// Only root is in the tree.
        if(root->left!=NULL) extractPath(root->left,res,to_string(root->val));						// Travelling to left child.
        if(root->right!=NULL) extractPath(root->right,res,to_string(root->val));					// Travelling to right child.
        return res;																					// Returning the vector with all paths.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is recursion based. At each step, we check whether curr. node id leaf or not? If it's leaf we push the path that we have obtained
// till now into result vector. If the curr. node is not leaf, then we add curr. node's value to path from the root and pass it to non-NULL child.
// As the first node(root) wont' be having "->" prior to it in the result, it had to be dealt specially.

// This algorithm is same as above, except that it handles the root's value in path differently. Making readability easier.




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
    
    void extractPath(TreeNode* node, vector<string>&res, string s){
        if(s.length()==0) s+=to_string(node->val);													// If curr. node is root, add it to path.
        else																						// If curr. node is not NULL, then add
            s+="->"+to_string(node->val);															// "->"+curr. node's value to path.
        
        if(node->left==NULL && node->right==NULL){
            res.push_back(s);
            return;
        }
        if(node->left!=NULL) extractPath(node->left, res, s);
        if(node->right!=NULL) extractPath(node->right, res, s);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        if(root==NULL) return res;
        if(root->left==NULL && root->right==NULL) return vector<string> (1,to_string(root->val));
        extractPath(root,res,"");																	// Calling fn. to extract Path.
        return res;
    }
};