/*
*
//**********************************************************141. Linked List Cycle.***************************************************

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[1]
[1,2,3,1]
[1,2,3]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based, we maintain two ptrs fast and slow ptr, slow ptr takes one step at a time, fast ptr takes two steps at a time.
// If there is a cycle they will meet certainly. If there is no loop either of the ptrs will reach the end ptr(NULL).





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* slow=head;															// Takes one step at a time.
        ListNode* fast=head;															// Takes two steps at a time.
        while(slow){																	// Until it reaches the end ptr(NULL).
            slow=slow->next;															// Taking a step ahead.
            if(fast->next ) fast=fast->next->next;										// Taking two steps if exists, if not return false.
            else return false;
			if(slow==NULL || fast==NULL) return false;									// If either of ptr reaches NULL, return false.
            if(slow == fast) return true;												// When both ptrs meet, return true.
        }
        return false;																	// Indicating NULL ptr is reached, return false.
    }
};