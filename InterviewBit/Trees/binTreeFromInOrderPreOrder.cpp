/*
*
//**************************************************Construct Binary Tree From Inorder And Preorder.*******************************************


https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



3 1 2 3   
3 2 1 3


5 4 2 1 6 5
5 1 2 4 5 6


6 4 2 1 3 6 5
6 1 2 3 4 5 6



// Time Complexity: O(n).  													// As Unordered Maps have lookup time of O(1).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// As Unordered Maps have lookup time of O(1).
// Space Complexity: O(n).	
// This algorithm is HashMap/Observation based. As, we iterate through PreOrder array, we encounter Parent Nodes in the Tree, in preOrder
// fashion, we set them as node and give recursive calls to get Left/Right child of that node. We get to know whether there exists or not
// from the range of values in the Inorder array. If a range of values are from [i,j] in inOrder array. All values of left of curr. node[index k],
// [i,k-1] are of left children of curr. node, [k+1,j] are right children of curr. node. If we don't have any left child, then interval doesn't 
// exist. Then, we dec. the inIndex value, to accomodate other ranges. At the end, we get Tree.







/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
TreeNode* constructTree(vector<int>&pre unordered_map<int,int>&m, int &preIndex, int start, int close){
    if(preIndex==pre.size() || start>close){								// If no intervals exist.
        preIndex--;															// To save this node for later recursive calls.
        return NULL;    
    } 
    if(start==close) return new TreeNode(pre[preIndex]);					// If only one node, create it and return.
    TreeNode* node= new TreeNode(pre[preIndex]);							// Create curr. node.
    int mid=m[pre[preIndex]];												// Find the curr. node's val in Inorder array.
    preIndex++;																// Moving ahead in PreOrder array.
    node->left=constructTree(pre, m,preIndex, start, mid-1);				// Recursive call to get left child.
    preIndex++;						
    node->right=constructTree(pre, m,preIndex, mid+1, close);				// Recursive call to get right child.
    return node;															// Returning curr. node.
} 


TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &inOrder) {
    unordered_map<int,int>m;												// Pushing Inorder values into Map to get faster access to indices.
    for(int i=0;i<inOrder.size();i++){
        m[inOrder[i]]=i;													// Pushing values and indices into Map.
    }
    int index=0;															// Index of curr. node in preOrder array.
    return constructTree(pre, m, index,0,inOrder.size()-1);					// Call fn. to get Tree.
    
}
