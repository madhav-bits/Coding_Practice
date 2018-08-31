/*
*
//******************************************************671. Second Minimum Node In a Binary Tree.***********************************************

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero 
sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[2,2,5,null,null,5,7]


[2,2,2,2,6,2,7]


[2]

[]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack/Queue based. As, a node is the min. value among it's child if present. We don't visit the nodes, whose value>root val
// and store the min. of those node's values, by comparing the minm. with the node's val>root val and updating the minm. value. We push only
// nodes whose value==root value, as there might be children to them, whose values are most closely greater than root value. We iter. over 
// entire tree, if after the entire iter. the min. value>root val is INT_MAX, then we return -1, else we return the obtained value.





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
    int findSecondMinimumValue(TreeNode* root) {
		if(!root) return -1;												// If empty tree provided, return -1.
        int least=root->val;												// Temp. storing root val.
        int ans=INT_MAX;													// Tracking minm. value>root val.
        stack<TreeNode*>st;													// Stores nodes to be visited.
        st.push(root);														// Pushing root into Stack.
        while(!st.empty()){													// Until all nodes with root val are visited.
            TreeNode* curr= st.top();										// Extracting the top node.
            st.pop();
            if(curr->left && curr->left->val==least) st.push(curr->left);	// If left child has root val, then push it into stack.
            else if(curr->left && curr->left->val>least) ans=min(ans,curr->left->val);// Updating the minm. value>root val.
            
            if(curr->right && curr->right->val==least) st.push(curr->right);// If right child has root val, then push it into stack.
            else if(curr->right && curr->right->val>least)ans=min(ans,curr->right->val);// Updating the minm. value>root val.
            
        }
        return (ans==INT_MAX)?-1:ans;										// If minm. val>root val obtained, then return it, else return -1.
    }
};

