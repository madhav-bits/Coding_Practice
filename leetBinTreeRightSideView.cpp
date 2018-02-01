/*
*
//*****************************************************199. Binary Tree Right Side View.**********************************************

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.

//These are the cases I had created, tweaked and worked on.
[1,3,2,5,null,null,9, 6,null,7,null, null,6,null,9]
[2,3,null,1,2,1,null,null,4]
[1,2,3,4,5,6,null,null,8,null,9]


// Time Complexity: O(n).
// Space Complexity: O(logn).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(logn).
// This algortihm is same as postOrder except that on entering into new height every time, we push the first elem.(right most elem.) into vector
// Thus we collect right side view of the Binary Tree.
// If we want is left side view, then do an preOrder Traversal and follow the same logic as above.



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
    vector<int> u;
    void postOrderTrav(TreeNode* temp, int height){
        if(temp==NULL) return ;
        if(u.size()==height)							//First encounter of an elem. in an new height, we push the value into vector.
            u.push_back(temp->val);
        postOrderTrav(temp->right,height+1);			// Doing a postOrder Traversal.
        postOrderTrav(temp->left, height+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        postOrderTrav(root,0);
        
        return u;
    }
};








//************************************************************Solution 2:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(logn).
// The algortihm pushes the elements into queue, pushing right child first if exists. When at a level, pushing all that's child while removing
// the nodes of that level. That all the nodes of a level are scanned in a single while loop iteration.




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
    void fillQueue(TreeNode* temp, queue<TreeNode*> &q){
        if(temp->right!=NULL)						//Collecting the child of the curr. level in postOrder Traversal way.
            q.push(temp->right);
        if(temp->left!=NULL)
            q.push(temp->left);
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        if(root==NULL)
            return v;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp;
            v.push_back(q.front()->val);			//Saving the first occurence of a level(right most node value).
            int levelSize=q.size();
            while(levelSize!=0){					//Collecting the child of the curr. level and removing nodes of curr. level.
                temp=q.front();
                fillQueue(temp,q);					//Collecting the child of the curr. level in postOrder Traversal way.
                q.pop();
                levelSize--;
            }
        }
        
        return v;
    }
};