/*
*
//**********************************************************101. Symmetric Tree.***************************************************

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,2,null,3,null,3]
[1,2,3,null,3,2,null]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm uses slightly modified PreOrder, NLR, NRL and checks whether they are equal or not. This is lengthier space complexity wise.



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
    vector<int> pre1, pre2;
    void findPath1(TreeNode* root){
        
        if(root->left==NULL && root->right==NULL){											// Avoding unnecc. calls.
            pre1.push_back(root->val);
            return ;
        } 
        pre1.push_back(root->val);
        if(root->left!=NULL) 																// Pushing the val. into vector.
            findPath1(root->left);
        else pre1.push_back(-1);															// Else push -1.
        
        if(root->right!=NULL) 																// Pushing the val. into vector.
            findPath1(root->right);
        else pre1.push_back(-1);															// Else push -1.
        
    }
    
    void findPath2(TreeNode* root){
        
        if(root->left==NULL && root->right==NULL){											// Avoding unnecc calls.
            pre2.push_back(root->val);
            return ;
        } 
        pre2.push_back(root->val);
        if(root->right!=NULL) 																// Pushing the val. into vector.
            findPath2(root->right);
        else pre2.push_back(-1);															// Else push -1.
        
        if(root->left!=NULL) 																// Pushing the val. into vector.
            findPath2(root->left);
        else pre2.push_back(-1);															// Else push -1.
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        findPath1(root);
        findPath2(root);
        if(pre1==pre2) return true;															// If same, return true.
        return false;																		// If not same, return false.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is PreOrder Checking, we take two symmetrical psn nodes from both the sides of root and check they are equal or not. If not return
// false.







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
    
    bool findSym(TreeNode* temp1, TreeNode* temp2){
        if(temp1==NULL && temp2==NULL) return true;
        if(temp1==NULL || temp2==NULL) return false;
        //cout<<"Curr. scanning val is; "<<temp1->val<<endl;
        if(temp1->val==temp2->val && findSym(temp1->left, temp2->right) && findSym(temp1->right, temp2->left)) return true;
        
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return findSym(root->left, root->right);
        
    }
};