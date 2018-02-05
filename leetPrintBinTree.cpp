/*
*
//***********************************************************655. Print Binary Tree.*******************************************

Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
Note: The height of binary tree is in the range of [1, 10].

//These are the examples I had created, tweaked and worked on.
[1,2,3,null,5,null,7]
[1,null,3]



// Time Complexity: O(n).
// Space Complexity: O(2^n).			//Even more than this, it depends on the target value.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(2^n).			//Even more than this, it depends on the target value.
// We first calc. the height and breadth of the tree, and create a vector of that size. We iterate through the tree, then choose the indexes to 
// place values calculatedly.First height=1, we need to move pow(2,height-1-1) steps both sides for left and right childs.


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
    int maxHeight(TreeNode* root){
        if(root==NULL) return 0;
        int lHeight=maxHeight(root->left);
        int rHeight=maxHeight(root->right);
        return (lHeight>rHeight)?lHeight+1:rHeight+1;
    }
    
    void printBinTree(TreeNode* root, vector<vector<string>>&v, int level, int index, int height){
        if(root==NULL) return ;
        //cout<<"The root vlaue is: "<<root->val<<" and height is: "<<level<<" index is: "<<index<<endl;
        v[level][index]=to_string(root->val);											//Placing value in the vector.
        printBinTree(root->left,v,level+1,index-pow(2,height-1-level-1),height);		//Moving into right child.
        printBinTree(root->right,v,level+1,index+pow(2,height-1-level-1),height);		// Moving into right child.
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int height=maxHeight(root);														//Calc. the height of the tree.
        int breadth=pow(2,height)-1;													//Calc. the breadth/width of the tree.
        //cout<<"the height of the tree is: "<<height<<endl;
        vector<vector<string>> v(height,vector<string>(breadth,""));					//Creating the vector of that size.
        printBinTree(root,v,0,breadth/2, height);										//Passing the indices,vector to the pring Function.
        //cout<<"Out of recur. call."<<endl;
        return v;																		//Returning the vector containing all the valeus.
    }
};