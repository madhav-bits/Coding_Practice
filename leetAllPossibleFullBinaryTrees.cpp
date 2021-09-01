/*
*
//******************************************************894. All Possible Full Binary Trees.***********************************************

https://leetcode.com/problems/all-possible-full-binary-trees/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.



1
3
17
19
7
16
18
20


// Time Complexity: O(2^n).  
// Space Complexity: O(2^n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).
// Space Complexity: O(2^n).	
// This algorithm is Dynamic Programming based. Here, since we work with full binary trees, each subtree consists of odd number of nodes. So, if 
// we have even number of nodes as input we return empty node. We follow Bottom To Top Approach. We first build smaller trees, then make them as
// the children in the larger trees. While forming larger trees, we iter. over diff. possible left and right child count and form all possible
// combinations and store them in dp.

// The solution page has a brief explanation about deriving Time and Space Complexity, which involves Catalan Number and is beyond the scope of
// the problem.









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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*>res;
        if(n%2==0) return res;
        vector<vector<TreeNode*>>dp(n+1);									// Stores Binary trees with 'i' nodes in 'i'th index.
        dp[1].push_back(new TreeNode(0));
        for(int i=3;i<=n;i+=2){												// Calc. all binary trees with 'i' nodes.
            for(int lt=1;lt<i;lt+=2){										// Iter. over all possible left child sizes.
                int rt=i-lt-1;
                for(int x=0;x<dp[lt].size();x++){							// Forming all combinations of left and right child trees.
                    for(int y=0;y<dp[rt].size();y++){
                        dp[i].push_back(new TreeNode(0));					// Storing all those trees in dp array.
                        dp[i].back()->left=dp[lt][x];
                        dp[i].back()->right=dp[rt][y];
                    }
                }
            }
            // cout<<"i: "<<i<<" and dp size: "<<dp[i].size()<<endl;
        }
        return dp[n];														// Returning all full binary trees with 'n' nodes.
    }
};

