/*
*
//******************************************************95. Unique Binary Search Trees II.***********************************************

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

1
2
7



// Time Complexity: O(n^logn).  // Not exactly.
// Space Complexity: O(n^2).	// Not exactly.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^logn).	// Not exactly.
// Space Complexity: O(n^2).	// Not exactly.
// This extracts all possible combinations of trees at each level and return their root to the parent node, which creates as many parent nodes
// and return it to it's parent. Thus, we get all possible BST trees.


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
    
    vector<TreeNode*> genTree(int begin, int end){
        
        if(begin>end) return vector<TreeNode*>(1,NULL);								// When there is no element.
        else if(begin==end)return vector<TreeNode*>(1,new TreeNode(begin));			// When, we have only one elem.
        vector<TreeNode*> v;
        for(int i=begin;i<=end;i++){
            vector<TreeNode*> lt=genTree(begin,i-1);								// Extracting all possible trees in left subtree.
            vector<TreeNode*> rt=genTree(i+1, end);									// Extracting all possible trees in right subtree.
            //cout<<"For curr. node value of: "<<i<<" lt values are: "<<lt.size()<<" and rt sizes are: "<<rt.size()<<endl;
            for(int j=0;j<lt.size();j++){											// Extracting all combi. of left and right subtrees.
                for(int k=0;k<rt.size();k++){
                    TreeNode* temp2=new TreeNode(i);								// Creating all possi. combinations number of roots.
                    temp2->left=lt[j];
                    temp2->right=rt[k];
                    v.push_back(temp2);
                }
            }
        }
        return v;																	// Returning all possible combi. of left and right subtrees.
    }
    
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> v;
        if(n==0) return v;
        v=genTree(1,n);																// Gets a TreeNode* array of roots.
        return v;																	// Returning all possible BST trees roots.
    }
};