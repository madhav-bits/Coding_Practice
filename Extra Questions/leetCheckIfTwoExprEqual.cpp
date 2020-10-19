/*
*
//******************************************1612. Check If Two Expression Trees are Equivalent.*****************************************

https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

Worked on test cases provided with the question.




// Time Complexity: O(n+m).  												// n, m- #nodes in both the trees.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// n, m- #nodes in both the trees.
// Space Complexity: O(1).	
// This algorithm is HashMap based. Here, for the two expressions to be equal, same chars has to be in them. This can be translated
// to fact the variables in both expressions has to be anagrams. We use a 26 length array to count of #occur. of each var and check
// if both tree's variables are anagrams or not.








/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void getExpression(Node* node, vector<int>&occur, int dx){
        if(!node) return ;
        if(!node->left && !node->right){									// Updating count array with vars count.
            occur[node->val-'a']+=dx;
            return ;
        }
        getExpression(node->left, occur, dx);
        getExpression(node->right, occur, dx);
        return ;
    }
    
    bool checkEquivalence(Node* root1, Node* root2) {
        vector<int>occur(26,0);
        getExpression(root1,occur, 1);
        getExpression(root2, occur, -1);
        for(int i=0;i<26;i++){												// Check if both tree's vars are anagrams or not.
            if(occur[i]!=0) return false;
        }
        return true;
        
    }
};