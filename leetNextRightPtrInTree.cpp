/*
*
//****************************************************116. Populating Next Right Pointers in Each Node.*******************************************

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL


//These are the examples I had created, tweaked and worked on.
No, test cases are allowed for this question.



// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(logn).			
//This is Inorder Traversal while saving the previously visited node in the same level in an vector and connecting that elem. to curr. elem. in
// the same level. This takes same as the below algorithm but the Solution 2 takes O(1) time.


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<TreeLinkNode*>> v;									// Declaring as global variable to avoid passing as parameters in func.
    void rightConnect(TreeLinkNode* temp, int height){
        if(temp==NULL) return ;
        if(v.size()==height)											// If the vector row is not created for that level, then create a empty row.
            v.push_back({NULL});
        else															// If not empty, then next of that elem.is the curr. elem.
            v[height][0]->next=temp;
        v[height][0]=temp;												// Updating the elem. at index-"0".
        if(temp->left!=NULL) rightConnect(temp->left,height+1);			// Calling the left child.
        if(temp->right!=NULL) rightConnect(temp->right,height+1);		// Calling the right child.
    }
    
    void connect(TreeLinkNode *root) {
        if(root==NULL) return ;											// If the root is NULL, return the NULL.				
        rightConnect(root,0);											// Calling the function.
    }
};



//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
//This is Inorder Traversal while saving the previously visited node in the same level in an vector and connecting that elem. to curr. elem. in
// the same level. This takes same as the below algorithm but the below algorithm takes O(1) time.


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void rightConnect(TreeLinkNode* temp){
        if(temp==NULL) return ;
        if(temp->left)
            temp->left->next=temp->right;
        if(temp->right)												// Connecting the right child to it's right elem.
            temp->right->next=temp->next?temp->next->left:NULL;
        rightConnect(temp->left);									// Calling the left child.
        rightConnect(temp->right);									// Calling the right child.
        
    }
    
    void connect(TreeLinkNode *root) {
        if(root==NULL) return ;										// If the root is NULL, return the NULL.
        rightConnect(root);											// Calling the function.
    }
};