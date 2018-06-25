/*
*
//**********************************************************333. Largest BST Subtree.***************************************************

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[10,5,15,1,8,null,7]

[10,5,15,1,8,12,17]

[]

[1]

[3,2,4,null,null,1]


[1,3,2,4,null,null,5]


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the tree in a recursive way. At each step, it gives recurive calls to it's children to find whether it's a BST or not?
// If both of them are BST, we add their sizes with curr. node(size:1) and pass it to curr. node's parent, we also update the global var.
// res, that tracs max. size of BST encountered. At the end of iteration, we have the largest valid BST in res var.
// If any child is not BST, curr. node isn't part of a BST, we return a Tri ptr with "-1" as first value. In case of NULL node, we form a 
// Tri prt with 0 size, INT_MAX as it's min. value, INT_MIN as it's max value, as they gets nullified by it's parent.

// Tri Data Structure has size of BST with curr. node has root, Min. value in the BST as second, Max. value in BST as third. When a node isn't 
// part of BST, -1 for first, we have INT_MAX for second, we have INT_MIN for third( though second, third values in this case doesn't matter),
// as we know that child isn't BST, we neglect these values.






/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {															// New Data Structure.
    struct Tri{	
        int first;															// Stores size of BST with curr. node as root.
        int second;															// Stores Min. value in this BST.
        int third;															// Stores Max. value in this BST.
        Tri(int a, int b,int c): first(a), second(b), third(c){}			// Constructors with passed min,max values.
        Tri(int a): first(a), second(INT_MAX), third(INT_MIN){}
        
    };
    
    
public:
    // int res=0;
    Tri* findBST(TreeNode* node, int minm, int maxm, int res){
        if(node==NULL) return new Tri(0);									// If empy node is encountered, pass 0 as size.
        Tri* lt=findBST(node->left, minm, node->val, res);					// Calling child recursively, to find whether they are BST's are not.
        Tri* rt=findBST(node->right, node->val,maxm, res);
        if( lt->first==-1 || rt->first==-1) return new Tri(-1);				// If any child isn't BST, return -1 to curr. node's parent.
        if((node->left==NULL || lt->third< node->val) && (node->right==NULL || rt->second>node->val)){// When both child are BST.
            // if(node->left && node->right) cout<<"BST at node: "<<node->val<<" left: "<<node->left->val<<" and right: "<<node->right->val<<endl;
            res=max(res,lt->first+rt->first+1);								// Updating the max. BST size.
            // cout<<"Returning from node: "<<node->val<<" with size: "<<lt->first+rt->first+1<<endl;
            return new Tri(lt->first+rt->first+1, min(node->val,lt->second), max(node->val,rt->third));// Passing results to curr. node's parent.
        }
        return new Tri(-1);													// If curr. node can't form a BST with child BST's return -1.
    }
    
    int largestBSTSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        findBST(root, INT_MIN, INT_MAX);									// Calling fn. to extract Max. BST size.
        return res;															// Returning the max. possible BST subtree size.
    }
};