/*
*
//******************************************************Convert Sorted List to Binary Search Tree.***********************************************

https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


9 1 2 3 4 5 6 7 8 9


7 1 2 3 4 5 6 7


1 1


// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is iteration based. We divide the given LL into two parts in each step by forming node with middle index, then recursively 
// form nodes in both halves(By changing index ranges accordingly). Thus, at the end we get the BST with given values.








/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int findLen(ListNode* node){												// calc. length of Linked List.
    int count=0;
    while(node){
        count++;
        node=node->next;
    }
    return count;
} 

ListNode* findNode(ListNode* root, int len){								// Find Node at certain psn.
    int count=1;
    while(count<len){														// Iter. till given psn is reached.
        count++;															// Inc. the count of nodes visited.
        root=root->next;
    }
    return root;															//  Return the node at given psn.
}

TreeNode* formTree(ListNode* node, int start, int end){
    if(start>end) return NULL;												// If exists with this psn, return NULL.
    int mid=(start+end)/2;													// Calc. the mid index.
    ListNode* res= findNode(node,mid);   									// Find the node at mid psn.
    TreeNode* curr= new TreeNode(res->val);									// Create a TreeNode with that value.
    curr->left=formTree(node,start,mid-1);									// Call fn. to get left child.
    curr->right=formTree(res->next,1,end-mid);								// Call fn. to get right child.
    return curr;															// Return the curr. node.
}

TreeNode* Solution::sortedListToBST(ListNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int len=findLen(root);													// Call fn. to find length of LL.
    return formTree(root,1,len);											// Call fn. to get BST with elem. between following indices.
}
