/*
*
//******************************************************1740. Find Distance in a Binary Tree.*************************************************


We have to find the distance between nodes with given values p,q. They will occur at most once in the tree.







*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,5,1,6,2,0,8,null,null,7,4,null,null,11]
5
0
[3,5,1,6,2,0,8,null,null,7,4]
5
7
[3,5,1,6,2,0,8,null,null,7,4]
5
5



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. The nodes with given values may occur at max once in the tree. So, we have to find the nodes and pass distance 
// up the tree in the recursion. When we find them we return 1 indicating edge it's attached to and in the path. If we get val !=-1 from any child,
// we inc. by 1 and return it to parent. If we don't have find the values in any subtree it returns -1. We return length of the path at the end of iter.












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
    
    int getDistance(TreeNode* node, int p, int q, int& res){
        if(!node) return -1;
        int lt=getDistance(node->left, p, q, res);
        int rt=getDistance(node->right, p, q, res);
        if(node->val==p || node->val==q){									// Curr. node has one of the values.
            if(lt!=-1) res=lt;// res=max(res, lt);							// If other val is in left child, the dist. b/w them is the path length.
            if(rt!=-1) res=rt;// res=max(res, rt);
            return 1;
        }
        if(lt!=-1 && rt!=-1) res=lt+rt;// res=max(res, lt+rt);				// If values are in left and right child, we add edges count to res.
        if(lt!=-1) return lt+1;												// If left child has one of values, we add to path length and return .
        if(rt!=-1) return rt+1;
        return -1;															// If vals not found in subtree, we return -1.
    }
    
    int findDistance(TreeNode* root, int p, int q) {
        int res=0;															// Stores path length.
        getDistance(root, p, q, res);										// Recursive call to find path length.
        return res;															// Returning the path length.
    }
};


