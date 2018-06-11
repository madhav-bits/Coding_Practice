/*
*
//**************************************************************437. Path Sum III.*******************************************************

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[10,5,-3,3,2,null,11,3,-2,null,1]
8



[1,null,2,null,3,null,4,null,5]
3




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is recursion based. As the path might start from any node. We start our summation from all nodes. In the traversal, we keep
// adding node values encountered in the path. If target value reached, inc. the count.








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
    int count=0;														// Stores #paths with given Sum.
    
    void findPaths(TreeNode*node, int sum){
        if(node==NULL) return ;
        //cout<<"Inside the fn. with node val: "<<node->val<<" and sum: "<<sum<<endl;
        sum-=node->val;													// Decreasing the required sum.
        if(sum==0) count++;												// If req. sum is obtained, inc. the count.
        findPaths(node->left, sum);										// Traverse left and right child.
        findPaths(node->right, sum);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        findPaths(root,sum);											// Calling fn. to start checking from curr. node.
        pathSum(root->left,sum);										// Calling fn. to init. checking from left child.(This avoid dup. calls)
        pathSum(root->right,sum);
        return count;													// Returning the #paths with given Sum.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is recursion based. We maintain a Map, which stores the prefix Sums which we have encountered and gathered till now. We keep 
// on adding the values from the root to curr. node in its path. At each step, we check, whether prefixSum=sum till now(currSum)-target is encoun.
// anywhere till now. If encountered, it means, our path start somewhere after root till curr node consecutively whose sum is equal to target.
// As, currSum-target gives a prefix sum, whose sum we have accumulated prior entering our ans path.








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
    int count=0;														// Stores #paths with given Sum.
    
    void findPaths(TreeNode*node, unordered_map<int, int> &m, int currSum, int target){
        if(node==NULL) return ;
        currSum+=node->val;												// Inc. the summation of path from root.
        if(m.count(currSum-target)==1) count+=m[currSum-target];		// Checking if prefix encountered with this value.
        m[currSum]++;													// Inc. the count of prefixSum including curr. node.
        findPaths(node->left, m, currSum, target);						// Traversing left and right child.
        findPaths(node->right, m, currSum, target);
        m[currSum]--;													// Making sure that map contains only data related to curr. path from root.
    }
    
    int pathSum(TreeNode* root, int target) {
        if(root==NULL) return 0;
        unordered_map<int, int>m;										// Stores prefix Sums and their #occurances in a path.
        m[0]=1;															// Base case.
        findPaths(root,m,0,target);										// Calling fn. to extract #paths.
        return count;													// Returning the count of #paths with given Sum.
    }
};










