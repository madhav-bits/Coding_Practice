/*
*
//**************************************************109. Convert Sorted List to Binary Search Tree.*******************************************

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never 
differ by more than 1.


Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[]
[-10,-3,0,2,5,9]
[1]


// Time Complexity: O(n).  
// Space Complexity: O(nlogn).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(nlogn).	
// This algorithm forms a vector from the given Linked List, passes the vector to fn. to extract the Binary Tree. At any call, it extracts the mid
// index's value and forms node with it, and calls left and right subtrees with the mid's left and right subarrays. Thus we form a Bin. Tree.

// Can also be done directly using LL, using fast and slow ptrs to get the mid index. But for having clarity, I did it in Vectors.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    
    TreeNode* constTree(vector<int> v,int begin, int end){
        if(begin>end) return NULL;									// If, there is no subarray return NULL.
        if(begin==end) return new TreeNode(v[begin]);				// If, we have only one elem. in subarray.
        int mid=(begin+end)/2;
        TreeNode* temp= new TreeNode(v[mid]);						// Forming the root node for the curr. subarray.
        
        temp->left=constTree(v,begin, mid-1);						// Calling the fn. for left child with the left part of subarray.
        temp->right=constTree(v,mid+1,end);							// Calling the fn. for right child with the right part of subarray.
        return temp;
    }
	
	
	
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        vector<int> v;
        //ListNode* temp=head;
        while(head!=NULL){											// Converting LL to Vector.
            v.push_back(head->val);
            head=head->next;
        }
        //for(auto num:v)											// Checking whether, values properly extracted from LL.
        //    cout<<"Numbers are: "<<num<<endl;
        TreeNode* root= constTree(v,0,v.size()-1);					// Calling the fn. to extract the BST.
        return root;												// Returning the root of the extracted BST.
    }
};