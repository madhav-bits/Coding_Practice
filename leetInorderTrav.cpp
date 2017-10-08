/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 /*
 This code prints inorder traversal of a tree given it's root.
 This is leet accepted code.
 */
class Solution {
public:
    void inOrderPrint(TreeNode* root, vector<int>& v){// This is passing vector by reference.
        //v.push_back(1);
        if (root==NULL)
            return ;
        else{
            if(root->left!=NULL)
                inOrderPrint(root->left, v);
            v.push_back(root->val);
            if(root->right!=NULL)
                inOrderPrint(root->right,v);
        }
        return ;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inOrderPrint(root, v);// This is passing vector by reference.
        return v;
    }
};