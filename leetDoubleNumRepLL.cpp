/*
*
//*****************************************2816. Double a Number Represented as a Linked List.*****************************************

https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,8,9]
[9,9,9]
[2,5,9]
[1,3,2,2]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is recursion based. As, we need carry from later nodes after doubling each node value, we use recursion to get carry from the later nodes.
// We add carry from the recursive fn and add with 2*curr. node val, we assign this total%10 to curr. node and assign total/10 to carry and return it.
// If we get non-zero carry from the first recursive fn. we create new node and make the given head as it's next node and return the new node.
// If we get zero carry, we simply return the head node provided in the question.





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    int doubleLL(ListNode* node) {
        if(!node) return 0;													// Terminating condition.
        int carry=doubleLL(node->next);										// Get carry form the later nodes.
        carry+=2*node->val;													// Add carry with 2*curr. node val.
        node->val=carry%10;													// Assign LSDigit to curr. node.
        return carry/10;													// Assign MSDigit to carry and return it. 
    }
    
    ListNode* doubleIt(ListNode* head) {
        if(!head) return head;
        int carry= doubleLL(head);											// Get carry from the recursive fn.
        if(carry==0) return head;											// If carry=0, we simply return the given node.
        ListNode* temp=new ListNode(carry);									// For non-zero carry, we create a new node.
        temp->next=head;													// We make the given head node-> new node's next node.
        return temp;														// Return the head node of the modified LL.
    }
};



