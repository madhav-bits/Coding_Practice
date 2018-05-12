/*
*
//********************************************************173. Binary Search Tree Iterator.*************************************************

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[10,5,15,2,7,12,18]




// Time Complexity: O(1).  
// Space Complexity: O(h).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(h).	
// This algorithm sets up all vars(stack) filled with all the left childs to the root), upon call the top value is returned, as the next smallest
// will be in the right child of the curr. node we store all left childs in the right child of the curr. node in the stack for further calls.
// As we store only one value from each height at any pt. of time, the space complexity is O(h). The ammortized time complexity is O(1).





/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* temp;
    stack<TreeNode*>s;
    BSTIterator(TreeNode *root) {											// Setting up the vars, when BSTIterator obj. is created.
        while(root){														// Storing all the left child in stack.(As val inc. order is req.)
            s.push(root);
            root=root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(!s.empty()) return true;											// If stack empty, no more values in tree to be extracted.
        return false;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* temp=s.top();												// Least unextracted val. till now.
        s.pop();															// Removing that val. from stack.
        int res=temp->val;
        temp=temp->right;													// Next smallest val. will be in right child of curr. node if exists.
        while(temp!=NULL){													// The next smal. will be leftmost child in the right child of curr.
            s.push(temp);
            temp=temp->left;
        }
        
        return res;															// Returning the curr. extracted value.
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */