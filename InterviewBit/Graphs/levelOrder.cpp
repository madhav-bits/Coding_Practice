/*
*
//***************************************************************Level Order.*********************************************************

https://www.interviewbit.com/problems/level-order/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


11  1 2 3 -1 -1 4 -1 -1 5 -1 -1



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is BFS based. We start from the root, we push children into queue if they exist. We store the #elem. in curr. level before iter. 
// over it. Thus, we can extract vals from same level in a sequence.








/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* root) {
    vector<vector<int>>res;													// Stores the final result.
    if(!root) return res;													// If empty tree provided, return empty result vector.
    queue<TreeNode*>q;														// Stores nodes to be visited.
    q.push(root);															// Pushing root into queue.
    while(!q.empty()){
        int len=q.size();													// Store #elem. in curr. level.
		res.push_back({});													// Init. the curr. level in 2D vector.
        for(int i=0;i<len;i++){												// Iter. over nodes in curr. level.
            TreeNode* curr=q.front();										// Extracting the curr. node.
            q.pop();
            res[res.size()-1].push_back(curr->val);							// Pushing curr. node's val into final result vector.
            if(curr->left) q.push(curr->left);								// Pushing child into queue.
            if(curr->right) q.push(curr->right);
        }
    }
    return res;
}
