/*
*
//************************************************************Max Sum Path in Binary Tree.*****************************************************

https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


9 -200 -100 -1 -300 -400 -1 -1 -1 -1






// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration/Dynamic Progrmming based. We extract seq. of max. sum from each child, we extract the max. of the two childs. If we
// encounter a NULL, we return INT_MIN. If the returned vals. from two child are not INT_MIN, then the seq. involving two child and curr. node 
// might be answer, so compare the sum with the maxm var. Only the curr. node can be answer, so we compare curr. node with maxm. var. If max. of 
// two child is positive then the max child and curr. node, so we compare that sum with maxm var. If the max. is child is>0, we return max. of child
// + node->val else we return only node->val to it's parent. Thus, we get max. path at the end of iter.







/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxm=INT_MIN;															// Tracks max. path/seq. sum.

int findMin(TreeNode* node){
    if(!node) return INT_MIN;												// IN case of NULL, return INT_MIN.
    
    int lt=findMin(node->left);
    int rt=findMin(node->right);
    int res=max(lt,rt);														// Get max. of two child.
    maxm=max(maxm,res);														// Try to update the maxm var.
    maxm=max(maxm,node->val);
    if(lt!=INT_MIN && rt!=INT_MIN)											// If both child aren't INT_MIN,then check for two child and curr. combi
        maxm=max(maxm,lt+rt+node->val);
    if(res>0)																// Checking for combi. of max. child and curr. node.
        maxm=max(maxm,res+node->val);
    // cout<<"CUrr. node: "<<node->val<<" and ret: "<<res+node->val<<endl;
    if(res>0) return res+node->val;											// If max. child >0, return sum of child and curr. node.
    else return node->val;													// Else, return only curr. node.
    
}

int Solution::maxPathSum(TreeNode* root) {
    maxm=INT_MIN;															// INit. maxm var.
    findMin(root);															// Call fn. to get max. path sum.
    return maxm;															// Return the max. path sum.
}
