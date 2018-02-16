/*
*
//*************************************************************236. Lowest Common Ancestor of a Binary Tree.****************************************************

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node 
in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a 
descendant of itself according to the LCA definition.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

No option to provide custom test cases for this question.


// Time Complexity: O(n).
// Space Complexity: O(n).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).			
// It’s recursive and expands the meaning of the function. If the current (sub)tree contains both p and q, then the function result is 
//their LCA. If only one of them is in that subtree, then the result is that one of them. If neither are in that subtree, the result is 
// null/None/nil.



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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT A LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).			
// It goes through all nodes, returns the occurence of p->val by -1 and q->val by 1. Once, these two values are enocuntered, res TreeNode* is
// updated(We will update it only once). This had passed, 30/31 cases the last case was too lengthy, So, couldn't find the reason of failure.






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
    TreeNode* res=NULL;
    int findAncestor(TreeNode* temp, TreeNode* p, TreeNode* q){
        if(temp==NULL)
            return 0;
        int res1=findAncestor(temp->left, p, q);
        int res2=findAncestor(temp->right, p, q);
        if(p->val == q->val &&temp==p && temp==q && res==NULL)		//  If the curr. node value equals both target values, then return curr. node.
            res=temp;
        else if(min(res1,res2)==-1 && max(res1,res2)==1 && res==NULL)// If target values are in two subtrees of curr. node.
            res=temp;
        else if(temp->val == p->val && max(res1,res2)==1 && res==NULL|| temp->val == q->val && min(res1,res2)==-1 && res==NULL)
            res=temp;												// If the curr. node holds the other unmatched target value.
        
        if(temp->val==p->val) return -1;							// IF any of two is present in the subtree.
        if(temp->val==q->val) return 1;
        return res!=0?res1:res2;
        return 0;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || (root==p && root==q)) return root;			// If the root equals two target values, then return root.
        findAncestor(root, p, q);
        return res;
    }
};