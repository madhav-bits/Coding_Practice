/*
*
//*****************************************************************List Cycle.*******************************************************

https://www.interviewbit.com/problems/list-cycle/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


Strange input pattern, tough to write here.



// Time Complexity: O(n).  													// Not so sure, depends on the length of the Cycle.
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Pointers based. We take two pointers, fast, slow, we iter. until fast and slow ptrs meet/fast reaches NULL. If NULL is
// reached, there is no Cycle in the LL, we return NULL. Else, we found that this LL has cycle. 
// We now start a slow ptr from the root of the LL, we iter. both the new slow ptr starting from the root, prev. old slow ptr from where slow/
// fast met. These two ptrs now meet at start of the Loop.

// The logic is that as fast ptr has travelled two times the dist. that of slow ptr. If we solve that equation, we get length of LL, prior to 
// Beginning of Cycle= k*Length of Cycle-dist. from start of cycle to point where slow, fast ptrs met. Thus, by the time slow ptr from root would
// have reached the start of the Cycle, the old slow ptr would have made certain #rotations in the cycle and travelled from meeting pt to start
// of the cycle.

// Some more explantatin is available in photos in Phone.






/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!root|| !root->next) return NULL;									// If empty LL, LL with single node given return NULL(No Cycle).
    ListNode* slow=root;													// Init. slow, fast ptrs.
    ListNode* fast=root;
    while(fast){															// While fast node exists.
        slow=slow->next;													// Iter. a step ahead.
        fast=fast->next;
        if(fast)															// If fast ptr had reached NULL, return NULL.
            fast=fast->next;
        else return NULL;
        if(fast==slow) break;												// If fast and slow ptr met break from loop.
    }
    if(!fast) return NULL;													// If fast ptr had reached NULL, return NULL.
    slow=root;																// Reinit. slow ptr to start of LL.
    while(slow!=fast){														// Till these two slow ptrs meet.
        slow=slow->next;													// Moving a step ahead.
        fast=fast->next;
    }
    return slow;															// Returning their meeting pt(start of Cycle).
}
