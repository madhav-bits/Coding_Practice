/*
*
//******************************************************83. Remove Duplicates from Sorted List.***********************************************

Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,1,2,2]
[1,1,2]
[]
[1,2,3,4,5]
[1,1,2,3,4,4]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We maintain two ptrs. one skips all duplicate values and other connects the unique values. After the entire
// iteration, we return the root.





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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode *temp1=head,*temp2=head;
        while(temp2->next!=NULL){
            while(temp2->next!=NULL && temp2->val==temp2->next->val) temp2=temp2->next;			// Skips the duplicate values.
            temp2=temp2->next;																	// Reaching to new value.
            temp1->next=temp2;																	// Connects unique values.
            temp1=temp1->next;																	// Moving the ptr. ahead.
            if(temp2==NULL) break;																// If new ptr is NULL break;
        }
        return head;
    }
};