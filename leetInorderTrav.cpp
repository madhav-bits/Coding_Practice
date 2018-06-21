/*
*
//******************************************************94. Binary Tree Inorder Traversal.***********************************************

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3]
[1,null,2,3]
[1,2,3,4,null,null,5]
[1,2,3,4,5,null,4,null,6,null,null,null,7]





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Recursive implementation of Inorder Traversal of a Binary Tree. We take in a node, we iterate through all elem. in left child
// by giving a recusive call to left child, then print curr. node value and give to recursive call to right child to traverse all elem. in right
// child.




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
    void inOrderPrint(TreeNode* root, vector<int>& v){// This is passing vector by reference.
        //v.push_back(1);
        if (root==NULL)
            return ;
        else{
            if(root->left!=NULL)											// Traversing the left child's elem.
                inOrderPrint(root->left, v);	
            v.push_back(root->val);											// Pushing the curr. value into final result vector.
            if(root->right!=NULL)											// Traversing the right child elem.
                inOrderPrint(root->right,v);
        }
        return ;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;														// Final result vector containning Inorder traversed values.
        inOrderPrint(root, v);												// This is passing vector by reference.
        return v;															// Returning final result vector.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Iterative implementation of Inorder Traversal of a Binary Tree. We take in a node, we push all childs in the stack left child
// wise, until we reach null. Then we extract nodes from stack, print that value, move to right child, and push traverse left child wise, till 
// null is reached, now extract the value from the stack, go over the same process again, until stack gets empty.





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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;												// Final result vector containning Inorder traversed values.
        if(root==NULL) return res;									// If empty tree is given, return empty result vector.
        stack<TreeNode*> st;
        while(root!=NULL){											// Pushing all leftwise childs until null is reached.
            st.push(root);
            root=root->left;
        }
        while(!st.empty()){
            TreeNode* curr=st.top();								// Extracting node from stack.
            st.pop();
            res.push_back(curr->val);								// Push curr. value into result vector.
            curr=curr->right;										// Now, push the right child's elem. left child wise until null is reached.
            while(curr){									
                st.push(curr);
                curr=curr->left;
            }
        }
        
        return res;													// Returning the final result vector.
    }
};




