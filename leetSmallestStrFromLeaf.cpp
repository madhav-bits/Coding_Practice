/*
*
//**************************************************988. Smallest String Starting From Leaf.*******************************************

Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 
represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller 
than "aba".  A leaf of a node is a node that has no children.)

 

Example 1:



Input: [0,1,2,3,4,3,4]
Output: "dba"
Example 2:



Input: [25,1,3,1,3,0,2]
Output: "adz"
Example 3:



Input: [2,2,1,null,1,0,null,0]
Output: "abc"
 

Note:

The number of nodes in the given tree will be between 1 and 8500.
Each node in the tree will have a value between 0 and 25.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[0,1,2,3,4,3,4]


[2,2,1,null,1,0,null,0]


[4,0,1,1]



[25,1,null,0,0,1,null,null,null,0]



// Time Complexity: O(nlogn).												// logn is the length of the str(Height of the tree.).
// Space Complexity: O(nlogn).												// logn is the length of the str(Height of the tree.).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// logn is the length of the str(Height of the tree.).
// Space Complexity: O(nlogn).												// logn is the length of the str(Height of the tree.).
// This algorithm is DFS based solution. Here, since we need minm. string starting from bottom, we start form root and iterate till
// leaf, we pass the string accumulated till then. When we reach leaf, we reverse accumulated string, to get original string, we 
// update the result str, if this is less than res str till then. We revert back the accumulated string to it's original position. 
// at the end of every recursive call, we all also pop the char we added in this call.







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
    
    void findStr(TreeNode* node, string&temp, string&res){
        if(!node) return ;													// If node is NULL, return from the call.
        temp+=(node->val+'a');												// Add. the curr. node's char.
        if(node->left==NULL && node->right==NULL){							// Reached the leaf.
            reverse(temp.begin(), temp.end());								// Reverse the accumulated str.
            if(res=="" || temp<res) res=temp;								// Update the minm. accumulated str.
            reverse(temp.begin(), temp.end());
        }
        
        findStr(node->left, temp, res);										// Calling the left child.
        findStr(node->right, temp, res);									// Calling the right child.
        temp.pop_back();													// Removing the char. added in this call.
		return ;
    }
    
    string smallestFromLeaf(TreeNode* node) {
        string temp="";														// Accumulates the str. along the path.
        string res="";														// Tracks the minm. str at the leafs.
        findStr(node, temp, res);											// Start the DFS call.
        return res;															// Return the minm. str at the leafs.
    }
};

