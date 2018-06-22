/*
*
//******************************************************285. Inorder Successor in BST.***********************************************

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.

Example 1:

Input: root = [2,1,3], p = 1

  2
 / \
1   3

Output: 2
Example 2:

Input: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /   
1

Output: null




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


No Test Cases allowed. But, I worked on this:
[10,8,20,4,9,17,29,1,5,null,null,15,9,null,null,null,null,null,6,null,16,null,null]

various nodes in this Tree as Target Node.



// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the array, we do a Inorder traversal. On reaching the target value, we set a var next=true. Then, the next value
// iterated with next=true, would be returned that, if any value isn't obtained in the while loop, then NULL is returned.







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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool next=false;
        stack<TreeNode*> st;												// Stores all nodes, used for Inorder traversal.
        while(root){														// Pushing all childs leftwise till NULL is reached.
            st.push(root);
            root=root->left;
        }
        while(!st.empty()){
            TreeNode* curr=st.top();										// Extract curr. node.
            st.pop();
            if(next==true) return curr;										// If target had been already visited, then return curr. value.
            if(curr->val==p->val) next=true;								// If target value is reached, then next var is set to true.
            curr=curr->right;												// Go to right child of curr. node, traverse and push all it's child
            while(curr!=NULL){												// leftwise until NULL is reached.
                st.push(curr);
                curr=curr->left;
            }
        }
        return NULL;														// If No. result obtained earlier, then return NULL.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algo. is Binary Search based.
// This algorithm is Recursive implementation/(Iteration wise by using while instead of recur. calls). At each step, we check whether curr. value<
// target->value, then we move to right child(which passes the prev. result value it received). If curr. val>= target->value, then we pass the 
// curr. value as the result value. Once, we reach NULL, we return the result value.


// Instead of Recur. calls, we can direclty implement traversal  using while loop. But, Recursion gives us clarity.


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
    TreeNode* findValue(TreeNode* node,  TreeNode* target, TreeNode* prev){
        if(node==NULL) return prev;												// On reaching NULL, return result value.
        if(node->val<=target->val) return findValue(node->right, target,prev);	// If curr. <target, we move to right child, with same result.
																				// being forwarded into the right child's call.
        else return findValue(node->left, target, node);						// If curr. val>= target val., we pass curr. value as result value.
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root==NULL) return NULL;												// If Empty tree is given, return NULL.
        return findValue(root,p,NULL);											// Call. fn. to get the Successor value.
    }
};