/*
*
//************************************************************Reverse Link List Recursion.**************************************************

https://www.interviewbit.com/problems/reverse-link-list-recursion/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1 1


2 1 2


4 1 2 3 4


5 1 2 3 4 5



0



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Recursion/Backtracking based. We reverse nodes drn at each step. We stop recursion when next node of a node is NULL, we 
// return that node. We make the next of first node as NULL. We return the received NODE from the recursive call(root of the reversed LL) to 
// the curr. call's caller. Thus, we return the root of the reversed LL from the recursive calls.








/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* root) {
    if(!root) return root;													// If empty LL given, return it.
    ListNode* temp=root->next;												// Temp. storing the next node.
    if(root->next==NULL) return root;										// If next node is NULL, we return curr. node.
    ListNode* res=reverseList(root->next);									// Recursive call to Reverse the following nodes.
    root->next=NULL;													// We set the next of curr. node as NULL, which would be set in prev. call.
    temp->next=root;														// We make curr. node as next of curr. node's next node.
    return res;																// Return the node from recursive call(root of reversed LL).
}
