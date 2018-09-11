/*
*
//******************************************************Binary Tree From Inorder And Postorder.***********************************************

https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


8 3 4 5 7 10 15 20 23
8 4 3 7 5 15 23 20 10


4 1 2 3 4
4 1 2 3 4


4 4 3 2 1
4 1 2 3 4


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Iteration/HashMap based. Here, we at every stage, we form a node with the rightmost unused node of postOrder, as it's the
// root of the right child of the node which had been previously created. We stop, whenenver entire list is finished iteration. Upon creating
// a node(After looking for it's index in Inorder Traversal) based on the right most index of postOrder, we move in right drn if there are indices
// available to right of curr. index in Inorder vector. If at any stage, we have close index of curr. node>start index, then return NULL, also
// inc. the index, as we haven't created any node based on the curr. index of postOrder vector. At the end, we return the root of the Tree.


// If we Linearly search for Postorder's curr. index's value in Inorder vector, it's throwing TLE error, so, I had used maps to keep track of 
// values in Inorder vector.





/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// int findIndex(vector<int>&inOrder,int val){								// Linear search for postOrder index's val in Inorder vector.
//     int ind=0;
//     while(ind<inOrder.size() && inOrder[ind]!=val)
//      ind++;
//     return ind;
    
// } 

TreeNode* formTree(vector<int>&inOrder, vector<int>&post, int start, int close,int &index, unordered_map<int,int>&m){
    if(close<start){														// If no valid node exists, return NULL.
        index++;															// As, we haven't formed a node, inc. the index value.
        return NULL;													
    } 
    if(index<0) return NULL;												// Breaking cdn.
    // cout<<"curr. index: "<<index<<endl;
    // int ind=findIndex(inOrder,post[index]);								// Get the curr. index's value in Inorder vector.
    int ind=m[post[index]];													// Get the curr. index's value in Inorder vector.
    TreeNode* node= new TreeNode(post[index]);								// Create a node with the curr. value.
    index--;																// Dec. the iterator/index.
    node->right=formTree(inOrder, post, ind+1,close, index,m);				// Call the fn. to form right child to curr. node.
    index--;																// Dec. the iterator.
    node->left=formTree(inOrder, post, start,ind-1, index,m);				// Call the fn. to form left child to curr. node.
    return node;															// Return the created node.
} 

TreeNode* Solution::buildTree(vector<int> &inOrder, vector<int> &post) {
    int index=post.size()-1;												// Store the last index of postOrder vector.
    unordered_map<int,int>m;												// Links Inorder values with their indices.
    for(int i=0;i<post.size();i++) m[inOrder[i]]=i;							
    return formTree(inOrder,post,0,post.size()-1,index,m);					// Call fn. to extract tree.
    
}
