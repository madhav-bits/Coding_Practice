/*
*
//*****************************************************103. Binary Tree Zigzag Level Order Traversal.**********************************************

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left 
for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]


//These are the examples I had created, tweaked and worked on.
[3,9,20,6,null,15,7]
[3,9,7,null,2,4,null,1,null,null,6]

// Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// This algorithm pushes the nodes into stack, such that last pushed node is accesssed first. We push from left side, if height is even, from
// the right side(right child first) if the height value in function is odd. Thus leading to Zigzag printing of Binary Tree.


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
    vector<vector<int>> v;
    void orderTrav2(stack<TreeNode*>s, int height){
        if(s.size()==0) return ;
        stack<TreeNode*> t;
        //cout<<"The stack size: "<<s.size()<<endl;
        v.push_back({});									// Initializing the vector array for nodes at this height.
        if(height%2==0){									//If height is even, then start pushing from the left child.
            while(!s.empty()){
                TreeNode* temp=s.top();
                v[height].push_back(temp->val);				// Pushing the nodes as encountered into vector.
                if(temp->left!=NULL) t.push(temp->left);	// Here the nodes are being from right to left into the vector, as they- 
                if(temp->right!=NULL) t.push(temp->right);	//- are of even height.
                s.pop();
            }
        }
        else{
            while(!s.empty()){								//If height is even, then start pushing from the right child.
                TreeNode* temp=s.top();
                v[height].push_back(temp->val);				// Pushing the nodes as encountered into vector.
                if(temp->right!=NULL) t.push(temp->right);	// Here the nodes are being from left to right into the vector, as they-
                if(temp->left!=NULL) t.push(temp->left);	//- are of odd height.
                s.pop();
            }
        }
        orderTrav2(t,height+1);								// Calling the function for the next level.
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return v;
        TreeNode* temp=root;
        stack<TreeNode*> s;
        s.push(root);
        //orderTrav(temp,0);
        orderTrav2(s,0);									// Calling the function with root in the stack.
        return v;
    }
};