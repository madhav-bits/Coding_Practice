/*
*
//**********************************************************669. Trim a Binary Search Tree.****************************************************

Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You 
might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:
Input: 
    1
   / \
  0   2

  L = 1
  R = 2

Output: 
    1
      \
       2
Example 2:
Input: 
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

Output: 
      3
     / 
   2   
  /
 1




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,0,2]
1
2



[3,0,4,null,2,null,null,1]
1
3



[6,2,20,1,5,15,25,null,null,null,null,10,19,null,30]
5
10


[1,0,2]
1
2


[1,null,2]
2
4


[]
2
4




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// In case of skewed comp. invalid nodes Trees, it is linear in time.
// Space Complexity: O(1).	
// This algorithm is Binary Search based. We approach the question in 2 steps, in the first step, we remove all nodes whose values are <L, in 
// second step, we remove all nodes with values>R. In the first step, since we are removing values<L, we make the curr. valid node as left child
// of prev. valid node. In second step, we make curr. valid node, the right child of prev. valid node.








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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        TreeNode* node=root, *prev=NULL;									// Prev. valid node.
        while(node){														// Iter. the path till leaf.
            if(node->val==L) break;											// If the curr. node is invalid.
            if(node->val<L) node=node->right;
            else{															// If the curr. node is valid.
                if(prev==NULL) {											// If prev. valid is still not set.
                    root=node;												// Make it as root, also set prev.
                    prev=node;
                }
                else prev->left=node;										// Make curr., the left child of prev. valid node.
                prev=node;													// Updating the prev. node.
                node=node->left;											// Moving to left child.Since, right child has valid nodes anyway.
            } 
        }
        if(node){															// This part is abt. last valid node. If last valid node exists.
            if(prev) prev->left=node;										// If prev. valid node exists, then set curr. node as it's left child.
            else root=node;													// Elese, set curr. as root node.
            
            prev=node;														// Update the prev. valid node.
        }
        if(prev==NULL) return NULL;											// If prev. is still not set(entire tree violates cdn), return NULL.
        prev->left=NULL;													// Setting the left child of prev. valid node as nULL.
        // cout<<"New root val: "<<root->val<<"and left node: "<<root->left->val<<endl;
        
		
		
		
																			// Setting the vars for second iter.
		
        node=root;
        prev=NULL;
        while(node){
            if(node->val==R) break;
            if(node->val>R) node=node->left;
            else{
                // cout<<"Matched with val: "<<node->val<<endl;
                if(prev==NULL) {
                    root=node;
                    prev=node;
                }
                else prev->right=node;										// Make curr.valid node, the right child of prev. valid node.
                prev=node;
                node=node->right;
            } 
        }
        if(node){
            if(prev) prev->right=node;
            else root=node;
            prev=node;
        }
        if(prev==NULL) return NULL;
        prev->right=NULL;
        return root;
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// If, we have all nodes of tree in the given range.
// Space Complexity: O(1).	
// This algorithm is Recursion based. Here, we work on only on valid nodes, if the node's val is <L, then all left child of that node would 
// be invalid anyway. If the node's val>R, then all right child of that node would be invalid anyway. If not, we extract the curr. node's left 
// valid child nodes from the left child, right valid child nodes from the right child.







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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return NULL;												// If empty tree is given, return NULL.
        if(root->val<L) return trimBST(root->right,L,R);					// Working only on valid nodes.
        if(root->val>R) return trimBST(root->left,L,R);						// Working only on valid nodes.
        root->left=trimBST(root->left,L,R);									// Extract valid nodes from left child.
        root->right=trimBST(root->right,L,R);								// Extract valid nodes from right child.
        return root;														// Return the root of the updated tree.
    }
};