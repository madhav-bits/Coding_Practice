/*
*
//******************************************************958. Check Completeness of a Binary Tree.***********************************************

Given a binary tree, determine if it is a complete binary tree.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as 
possible. It can have between 1 and 2h nodes inclusive at the last level h.

 

Example 1:



Input: [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are 
as far left as possible.
Example 2:



Input: [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
 
Note:

The tree will have between 1 and 100 nodes.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,null,4,5]


[1,2,3,4,5,6,null,7]


[1,2,3,4,5,6,8,7,9,10]


[1,2,3,4,5,6,7,8,null,9]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, the main conditions are that left child's depth is >=right child's depth or Left child's depth is
// within 1 height greater than right child's min depth as last row need not be completely filled. If any of these conditions aren't satisfied
// we return {-1,-1} to the parent, and if the parent observe -1 in returned pair, it returns -1 directly. At the end, if root returns -1, then
// we return false else we return true.








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
    
    pair<int,int> checkComplete(TreeNode* node){
        if(!node) return {0,0};												// If leaf reached, return {0,0}.
        pair<int,int> lt=checkComplete(node->left);							// Get min,max. depth reached through left child.
        pair<int,int> rt=checkComplete(node->right);						// Get min,max. depth reached through right child.
        // cout<<"node val: "<<node->val<<" lt: "<<lt.first<<" and rt: "<<rt.second<<endl;
        if(lt.first==-1 || rt.first==-1) return {-1,-1};					// If any child doesn't satisfy Complete BSTs cdns, return {-1,-1}.
        if(rt.first>lt.second || lt.first>rt.second+1) return {-1,-1};		// If BSTs cdns aren't satisfied, return {-1,-1}.
        return {lt.first+1,rt.second+1};									// Returns Max. depth, Min. depth reached form curr. node's child+1.
    }

    bool isCompleteTree(TreeNode* root) {
        pair<int,int> res=checkComplete(root);								// Calling fn. to calculate whether tree is Complete BST or not.
        // cout<<"res: "<<res.first<<endl;
        return (res.first==-1)?false:true;									// Return false, if -1 observed else return true.
    }
};