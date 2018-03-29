/*
*
//********************************************106. Construct Binary Tree from Inorder and Postorder Traversal.*************************************

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]


Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[9,5,1]
[9,1,5]


// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).   // Time taken to find the last elem in post order in order array.	
// Space Complexity: O(n).	
// This algorithm is DFS oriented. The approach is that we get the node of the curr. set of values from the last value in the post order array.
// We split all values to left of the num in inorder as subtree and to the right of it as right subtree, respectively split the same #elements in
// the Post Order into left and right subtrees. We stop when we encounter either 1 or 0 elements in the subarray in one of recursive calls.







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
    
    int findIndex(vector<int> &in, int val){					// Finds the psn of last elem. of post order array in the Inorder array.
        for(int i=0;i<in.size();i++){
            if(in[i]==val) return i;
        }    
    }
    
    TreeNode* calcTree(vector<int> &in, vector<int> & post, int pos){
        //cout<<"Size of in is: "<<in.size()<<" and post is: "<<post.size()<<endl;
        
        if(in.size()==0 ) return NULL;						// If there are 0 elem. in subarray, return NULL.
        int value=post[post.size()-1];						// Value of last elem. in subarray.
        TreeNode* curr= new TreeNode(value);
        if(in.size()==1) return curr;						// If there is 1 elem. in subarray, then return that elem.
        
        int ind=findIndex(in, value);						// Finding the num's psn in InOrder array.
        //cout<<"ind is: "<<ind<<endl;
        vector<int> temp1(in.begin(), in.begin()+ind);		// Splitting the Inorder into left and right subtrees.
        vector<int> temp2(in.begin()+ind+1, in.end());//in.begin()+(int)in.size()-1-ind
        
        vector<int> temp3(post.begin(), post.begin()+ind);	// Splitting the Post Order into left and right subtrees.
        vector<int> temp4(post.begin()+ind, post.begin()+(int)in.size()-1);//post.begin()+(int)in.size()-1-ind
        //cout<<"Calling the left subtree with root value: "<<curr->val<<endl;
        curr->left= calcTree(temp1, temp3,-1);				// Calling the left subarray's recursive call.
        //cout<<"Calling the right subtree."<<endl;
        curr->right= calcTree(temp2, temp4, 1);				// Calling the right subarray's recursive call.
        
        return curr;										// Returning the curr. node.
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        TreeNode* root;
        
        if(in.size()==0) return NULL;						// In case of empty list, return NULL.
        root= calcTree(in, post,0);
        return root;										// Returning the root of the tree.
    }
};