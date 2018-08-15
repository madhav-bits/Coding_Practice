/*
*
//******************************************************637. Average of Levels in Binary Tree.***********************************************

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,9,20,15,7,3]

[]

[1]

[1,2,null,3,null,4]



// Time Complexity: O(n).  
// Space Complexity: O(logn).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(logn).	
// This algorithm is iteration/Queue based. We deal with each row in each iteration. We first push root into queue. In the iteration, we take the
// size of the queue/#elem. in that level. We pop all those elem. sum their values, we also push their non NULL children into queue for next iter.
// Upon completion of iteration, we divide the sum of curr. level elem. by their size to get avg. sum of that level. This way, we iterate over 
// all levels, calc. their avg. and push them into final result vector.








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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;													// Final result vector.
        if(!root) return res;												// If empty tree given, return empty vector.
        queue<TreeNode*>q;													// Stores next level nodes to be visited.
        q.push(root);														// We push root into the queue.
        while(!q.empty()){													// Until all levels are iterated.
            int len=q.size();												// #elem. in curr. level.
            double sum=0;													// Stores sum of elem. form curr. level.
            for(int i=0;i<len;i++){											// Iter. through all elem. in curr. level.
                TreeNode* curr=q.front();									// Temp. storing a node from curr. level.
                q.pop();
                sum+=curr->val;												// Accumulating sum of vals of nodes of curr. level.
                if(curr->left) q.push(curr->left);							// Pushing valid child into queue.
                if(curr->right) q.push(curr->right);
            }
            res.push_back(sum/len);											// Calc. avg and push into final result vector.
        }
        return res;															// Returning final result vector.
    }
};