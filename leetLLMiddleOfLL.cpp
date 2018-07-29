/*
*
//**********************************************************876. Middle of the Linked List.***************************************************

Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Note:

The number of nodes in the given list will be between 1 and 100.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[]
[1]
[1,2]
[1,2,3,4]
[1,2,3,4,5]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. This is classic Slow/Fast pointer based question. Here, we maintain two ptrs, fast and slow, which take 
// two, 1 step each time respectively. By the time fast pointer reaches end of LL, slow ptr would have reached middle of LL. We need to make 
// slight changes to work for Even/Odd lengthed LLs, in case of even length LLs, we need to take a step further ahead to reach middle LL node.








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
    ListNode* middleNode(ListNode* head) {
        if(!head) return head;												// If empty list provided, return empty LL.
        ListNode* slow,*fast;												// Two ptrs which take 1, 2 steps each time while iterating.
        slow=head;fast=head;												// Init. the two ptrs.
        while(fast->next && fast->next->next){								// Checking next step for fast ptr exists.
            fast=fast->next->next;											// Fast ptr taking 2 steps ahead.
            slow=slow->next;												// Slow ptr taking 1 step ahead.
        }
        if(fast->next) return slow->next;						// If we still have next node valid for fast ptr(even length LL).return slow->next
        else return slow;													// If it is odd length LL, return curr. slow ptr. 
    }
};