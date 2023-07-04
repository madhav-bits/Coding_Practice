/*
*
//******************************************************2385. Amount of Time for Binary Tree to Be Infected.******************************************************

https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,5,3,null,4,10,6,9,2]
3
[1]
1
[1,2,3,4,5,6,7,8,null,9,null,null,10,null,11,null,12,null,null,13,14]
5



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. We have to max dist. from target node to rest other nodes, when we find the target node, we pass posi. value in function
// indicating that they are chidren of target value, it's a value we inc. in every step for their children, we try to maximize the dist. in every step. If we
// encounter target node, we return -1, indicating that we found target node in the dfs call from the parent node else we return the maxDepth of the child 
// from the node. If a parent node -1 from one child and some depth from other node, we subtract to get gap b/w, we do abs to get actual dist b/w them and try 
// to maximize the dist., if we get neg. value (-x) from one of the children, we retur n(-x-1) from that node, inc. the dist. of parent node to target node in
// neg. number line. Thus, we visit each node only once and cover all cases and maximizes the max. dist from target node and return it at the end of iter.







/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int iterateTree(TreeNode* node, int source, int childDist, int&res) {
        if(!node) return 0;
        if(res<childDist) res=childDist;									// Track max. dist of the children of the target node.
        if(node->val==source || childDist) childDist++;						// If target node is an ancestor/curr. node, we inc. the childDist value negatively. 
        int lt=iterateTree(node->left, source, childDist, res);				// DFS call to left child.
        int rt=iterateTree(node->right, source, childDist, res);
        if(lt<0 || rt<0) {													// If any of the child node has the target node.
            if(abs(rt-lt)>res) res=abs(rt-lt);								// We calc. dist b/w target node and the maxDepth on the other child and max. res.
            return lt<0?lt-1:rt-1;											// We return neg. dist. b/w curr. node and target node-1
        }
        return (node->val==source)?-1:max(lt, rt)+1;						// If curr. is target node, return -1 else return maxChildDist+1. 
    }
    
    int amountOfTime(TreeNode* root, int start) {
        int res=0;
        iterateTree(root, start, 0, res);									// DFS call to get max. dist from target node.
        return res;
    }
};

