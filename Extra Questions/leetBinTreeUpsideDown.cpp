/*
*
//******************************************************156. Binary Tree Upside Down.***********************************************

Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, 
flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

Example:

Input: [1,2,3,4,5]

    1
   / \
  2   3
 / \
4   5

Output: return the root of the binary tree [4,5,2,#,#,3,1]

   4
  / \
 5   2
    / \
   3   1  
Clarification:

Confused what [4,5,2,#,#,3,1] means? Read more below on how binary tree is serialized on OJ.

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as [1,2,3,#,#,4,#,#,5].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,5]


[1,2,3,4,5,null,null,6,7]


[1,2,3,4,null,null,null,6,7]


[]

[1]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Recursion based. We call recursively until we have both left & right child for a node. At each step, we make the curr->right
// as left child of curr->left, and curr as right child of curr->left. Each fn. call returns the value returned from the recursive call given 
// from this loop.








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
    
    TreeNode* invertTree(TreeNode* node){
        // cout<<"Curr. node: "<<node->val<<endl;
        if(!node->left && !node->right) return node;  						// If leftmost node is reached. 
        
        TreeNode* temp2=invertTree(node->left);								// Call left child recursively.
        // cout<<"Returned val: "<<temp2->val<<endl;
        TreeNode* temp=node->left;											// Store the left child.
        temp->left=node->right;												// Make right child as left child's left child.
        temp->right=node;													// Make curr. node as left child's right child.
        node->left=NULL; node->right=NULL;									// Set left, right child of curr. node as NULL.
        return temp2;														// Return the leftmost child of orig. tree/root of modified tree.
        
    }
    
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) return root;												// If empty tree is given, return root provided.
        return invertTree(root);											// Call fn. to get reversed tree.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Iteraion based. We iterate till leftmost child is reached. Store left childs encountered on the way in a stack. 
// Now, we work on stack's elem. as stack's top elem. is left child of node under it in the stack. We work in the same way as in above sln.
// At each step, we make the curr->right as left child of curr->left, and curr as right child of curr->left. 







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
    
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* temp=root;
        stack<TreeNode*> st;												// Stores TreeNodes to be worked on.
        while(temp){														// Storing left childs in the stack.
            st.push(temp);
            temp=temp->left;
        }
        TreeNode* res=st.top();												// Storing the root of the modified tree.
        TreeNode*child,*par;
        child=st.top();
        st.pop();
        while(!st.empty()){													// Assigning children to left child of curr. node at each level. 
            par=st.top();													// Same as in prev. algo.
            st.pop();
            child->left=par->right;
            child->right=par;
            par->left=NULL; par->right=NULL;
            child=par;
        }
        return res;															//  Returning the root of the modified tree.
    }
};