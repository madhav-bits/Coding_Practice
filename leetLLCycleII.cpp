/*
*
//******************************************************142. Linked List Cycle II.***********************************************

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,5,6,1]
[1,2,3,4,5,6,7,8,9,10,3]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. When the slow and ptrs meet, if Loop exists, If we observe, the fast ptr travelled twice the length of 
// slow ptr. It had travelled twice those edges in Loop, which slow ptr had travelled. It had traveled those edges which are prior to loop's start,
// Since, it travels twice that length, it indicates the rest of Loop which slow ptr haven't traveled has the length of edges prior to loop's start.

// Thus, we take another ptr starting from the begin and iterate the new and slow ptr until they meet, they meet at the beginning of the loop.








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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;																	// Takes one step at a time.
        ListNode* fast=head;																	// Takes two steps at a time.
        while(slow){																			// Finds whether Loop exists or not?
            slow=slow->next;
            if(fast->next) fast=fast->next->next;
            else return NULL;
            if(slow==NULL || fast==NULL) return NULL;											// Loop doesn't exist.
            if(slow==fast) break;																// Slow and fast ptrs met, showing Loop exist.
        }
        ListNode* temp=head;																	// Taking new ptr, start from the head.
        //slow=slow->next;
        while(slow!=temp){																		// These are iterated until they met.
            slow=slow->next;
            temp=temp->next;
        }
        return slow;																			// Their meeting is the start of the Loop.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dyeing/ Masking based. We maske all the visited nodes with designated value(INT_MIN), when we visit a already visited NODE,
// then that's the pt. where the Loop begins.





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
    ListNode *detectCycle(ListNode *head) {
        while(head){																			// Iterating till end of LL, if present.
            if(head->val==INT_MIN) return head;													// Reaching the Loop begin.
            else{
                head->val=INT_MIN;																// Masking the visiting node.
                head=head->next;																// Inc. the iterator value.
            }
        }
        return NULL;																			// If LL is ended, then return NULL.
    }
};