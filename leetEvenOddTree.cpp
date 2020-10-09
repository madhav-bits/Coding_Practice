/*
*
//******************************************************1609. Even Odd Tree.******************************************************

https://leetcode.com/problems/even-odd-tree/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,10,4,3,null,7,9,12,8,6,null,null,2]

[1,10,1,3,null,7,9,1,9,1,null,null,23]
[1,10,4,3,null,7,9,12,8,6,null,null,2]
[5,4,2,3,3,7]
[11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
[5,9,1,3,5,7]
[1]
[2,12,8,5,9,null,null,18,16]



// Time Complexity: O(n). 													// n- #nodes of the tree. 
// Space Complexity: O(logn).												// Depth of the tree.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- #nodes of the tree.
// Space Complexity: O(logn).												// Depth of the tree.
// This algorithm is DFS iterration based. Here, we iter. over entire tree while keeping track of depth of the curr. node. If the curr. 
// depth is even, we check if the val. is odd and it's in strictly inc. order or if it's even we return false, same goes for odd depth
// nodes. If a node receives a false from child, we return false from curr. node. If we true from all child and curr. node meets given
// requirements. We return true.








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
    
    bool iterateTree(TreeNode* node, int depth, vector<int>&lastOccur){
        if(!node) return true;
        if(lastOccur.size()==depth){										// Conditions the qsn asked for.
            if(depth%2==0 && node->val%2==0) return false;					// If cdn not satisfied return false.
            if(depth%2==1 && node->val%2==1) return false;
                                                    // Even depth-Strictly increasing.    
            lastOccur.push_back(node->val);         //  Odd depth- Strictly decreasing.
        }else{
            // cout<<10<<endl;
            if(depth%2==0 && (node->val%2==0 || node->val<=lastOccur[depth])) return false;
            if(depth%2==1 && (node->val%2==1 || node->val>=lastOccur[depth])) return false;
        }
        lastOccur[depth]=node->val;
        if(!iterateTree(node->left, depth+1, lastOccur)) return false;		// If child returns false, we return false.
        if(!iterateTree(node->right, depth+1, lastOccur)) return false;
        return true;														// If node and it's children meet cdn, we return true.
    }	
    
    bool isEvenOddTree(TreeNode* root) {
        vector<int>lastOccur;												// Keeps track of last val encountered in each level of tree.
        return iterateTree(root, 0, lastOccur);								// Call recur. fn. to check tree for given cdn.
    }
};
