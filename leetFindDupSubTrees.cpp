/*
*
//*********************************************************652. Find Duplicate Subtrees.************************************************

Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1: 
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4
Therefore, you need to return above trees' root in the form of a list.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[1,2,3,4,5,6,7,8,9,10]
[1,2,1,4,null,2,4,5,null,4,null,null,null,null,null,5]
[]

// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algorithm does Inorder Traversal, and saves all subtrees info. from a node and pushes the root of that subtree into map, after complete
// iteration. All the subtrees having > 1 root nodes are duplicates, which are furthur pushed into final result vector array of TreeNodes.
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
    vector<TreeNode*> v;
    string  findDup(TreeNode* temp, unordered_map<string, vector<TreeNode*>> &m){
        if(temp==NULL) return "";
        string s;
        string temp1=findDup(temp->left, m);						//Extract string returns from left child and all it's child.
        string temp2=findDup(temp->right, m);						//Extract string returns from right child and all it's child.
        s="("+temp1+to_string(temp->val)+temp2+")";					// Getting the Inorder traversal form.
        m[s].push_back(temp);										//Pushing val. of curr. node and all it's child.
        return s;													// Getting the Inorder traversal form of that node to the parent child.
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> v;
        unordered_map<string,vector<TreeNode*>>m;					// Checks nodes subtree's node of same type.
        findDup(root,m);
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second.size()>1) v.push_back(it->second[0]);		// If there are two nodes of same type.
        }
        return v;													// Returning all the duplicate subtrees.
		
    }
};