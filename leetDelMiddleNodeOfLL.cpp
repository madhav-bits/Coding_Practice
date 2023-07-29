/*
*
//******************************************************2095. Delete the Middle Node of a Linked List.******************************************************

https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,4,7,1,2,6]
[1,2,3,4]
[2,1]
[1]
[1,2,3,4,5,6,7,8]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is slow, fast pointer method. We use slow, fast pointers and iterate over LL. By the time fast ptr reaches end of LL, slow ptr reaches middle
// of the LL, we delete this node by connecting it's prev. and following node and return the head of the modified LL.







class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        // if(head->next->next==NULL) return head->next;
        ListNode* prev=NULL, *fast=head, *slow=head;
        while(fast && fast->next) {											// Iter. until fast node reaches end of LL.
            // cout<<"slow: "<<slow->val<<endl;
            prev=slow;														// Storing the prev. node of slow node.
            slow=slow->next;												// Slow node takes one step in one loop.
            fast=fast->next->next;											// Fast node takes two steps in one loop.
            // cout<<"nxt fast: "<<fast->val<<endl;
        }
        prev->next=slow->next;												// Connecting prev. and following node of slow node. 
        return head;														// Returning the head of the modified LL.
    }
};

