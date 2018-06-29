/*
*
//******************************************************314. Binary Tree Vertical Order Traversal.***********************************************

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples 1:

Input: [3,9,20,null,null,15,7]

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7 

Output:

[
  [9],
  [3,15],
  [20],
  [7]
]
Examples 2:

Input: [3,9,8,4,0,1,7]

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7 

Output:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Examples 3:

Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

Output:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,9,20,null,null,15,7]


[1,null,5,3,null,2,4]


[3,9,8,4,0,1,7]





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm recursively iterates the entire Tree. At each node, it tries to update the min. and max. offset of the tree, using the curr.
// node's offset. After the entire iteration. We create a vector of size maxm-minm+1, to accomodate nodes of all offsets in it. Then we do a
// Lever Order Traversal, to get the elem. in the desired fashion.


// As, we need to extract min, max offsets for the whole tree. We can do it just maintaining global vars to track them. I had unnecc. used
// local vars to compare all extracted values to get global min. and max. offsets.





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
    void findWidth(TreeNode* node, int &left, int&right, int offset){
        if(!node) return ;
        // cout<<"Curr. node: "<<node->val<<endl;
        int leftL=INT_MAX,leftR=INT_MIN, rightL=INT_MAX,rightR=INT_MIN;
        findWidth(node->left,leftL,leftR,offset-1);
        findWidth(node->right,rightL,rightR,offset+1);
        left=min(leftL,rightL);												// Gets the min, max offsets of the left subtree.
        right=max(leftR,rightR);											// Gets the min, max offsets of the right subtree.
        // cout<<"At node prior: "<<node->val<<" Child's left: "<<left<<" and right: "<<right<<endl;
        left=min(offset,left);
        right=max(offset,right);
        // cout<<"At node: "<<node->val<<" the Left: "<<left<<" and right: "<<right<<endl;
    }
    

    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        int left=0,right=0;
        findWidth(root,left, right,0);										// Get min. and max. offsets.
        // cout<<"left: "<<left<<" and right: "<<right<<endl;
        vector<vector<int>>v(right-left+1);									// Create result vector of length maxm-minm+1.
        // extractNodes(root,v,0,left);
        pair<TreeNode*, int>p=make_pair(root,0);
        queue<pair<TreeNode*,int>>q;
        q.push(p);
        while(!q.empty()){													// Do, a Level Order Traversal.
            pair<TreeNode*, int>curr=q.front();
            q.pop();
            v[curr.second-left].push_back(curr.first->val);					// Pushing the curr. node's val. into result vector.
            if(curr.first->left) q.push(make_pair(curr.first->left,curr.second-1));// Push left child into vector, if exists.
            if(curr.first->right) q.push(make_pair(curr.first->right,curr.second+1));// Push right child into vector, if exists.
            
        }
        return v;															// Return the result vector with Vertical Order Traversal values.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm recursively iterates the entire Tree. At each node, it tries to update the min. and max. offset of the tree, using the curr.
// node's offset. After the entire iteration. We create a vector of size maxm-minm+1, to accomodate nodes of all offsets in it. Then we do a
// Lever Order Traversal, to get the elem. in the desired fashion.


// As, we need to extract min, max offsets for the whole tree. I had used global vars to track them. 


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
    int left=INT_MAX, right=INT_MIN;										// Tracks global min. and max. offsets.
    
    void findWidth(TreeNode* node, int offset){
        if(!node) return ;
        // cout<<"Curr. node: "<<node->val<<endl;
        left=min(offset,left);												// Extracting min. offset.
        right=max(offset,right);											// Extracting max. offset.
        findWidth(node->left,offset-1);										// Calling left child for extracting it's offsets.
        findWidth(node->right,offset+1);
    }
    
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        findWidth(root,0);
        // cout<<"left: "<<left<<" and right: "<<right<<endl;
        vector<vector<int>>v(right-left+1);
        pair<TreeNode*, int>p=make_pair(root,0);
        queue<pair<TreeNode*,int>>q;
        q.push(p);
        while(!q.empty()){
            pair<TreeNode*, int>curr=q.front();
            q.pop();
            v[curr.second-left].push_back(curr.first->val);
            if(curr.first->left) q.push(make_pair(curr.first->left,curr.second-1));
            if(curr.first->right) q.push(make_pair(curr.first->right,curr.second+1));
            
        }
        return v;
    }
};