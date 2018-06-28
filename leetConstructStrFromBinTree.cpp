/*
*
//******************************************************606. Construct String from Binary Tree.***********************************************

You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the 
one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example, 
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,null,5]

[1,2, null,3,null,4,null,5]

[1,null,2,null,3,null,4,null,5]





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm recursively iterates the entire tree. At each step, we add the curr. node to final result str, we call fn. on left and right 
// child's values to extract values in those child.






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
    void extractStr(TreeNode* node, string& res){
        if(node==NULL) return ;												// If empty node passed, just return.
        res+='('+to_string(node->val);										// Append curr. val to final resutl str.
        if(node->left) extractStr(node->left, res);							// Call fn. to extract values in left child.
        if(node->left==NULL && node->right) res+="()";						// If left is NULL, right is !NULL, then append () to result.
        if(node->right) extractStr(node->right, res);						// Call fn. to extract values in right child.
        res+=')';															// Append ')' to final result.
    }
    
    
    string tree2str(TreeNode* t) {
        string res="";														// Final result str.
        if(t==NULL) return res;												// If empty tree given, return empty string.
        res+=to_string(t->val);												// Apend root's val to final str.
        extractStr(t->left,res);											// Call. fn. to extract left child values.
        if(t->left==NULL && t->right) res+="()";							// If left is NULL, but right is !NULL, add () to result.
        extractStr(t->right, res);											// Call fn. to extract right child values.
        return res;															// Return result str.
    }
};