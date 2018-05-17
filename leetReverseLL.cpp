/*
*
//******************************************************206. Reverse Linked List.***********************************************

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[]
[1]
[1,2]
[1,2,3,4,5,6,7,8,9,10]
[1,2,3,4,5]


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We maintain three ptrs prev, curr, later. At each step we reverse the next of curr. node, we update all 3
// ptrs for the next iterartion. We stop when later/curr->next is NULL and reverse the drn of last node outside the loop and return last node.




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
    ListNode* reverseList(ListNode* head) {
		if(head==NULL) return NULL;
        ListNode* prev=NULL;												// Initital prev. node.
        ListNode* curr=head;												// Intital curr. node.
        ListNode* later=head->next;											// Initial later node/curr.node's next node.
        while(curr->next!=NULL){											// Runs. till curr->next/later ==NULL
            ListNode* temp2=later->next;									// Storing the later->next node.
            curr->next=prev;												// Updating the curr. node's next ptr.
            prev=curr;														// Updating prev., curr. and later nodes.
            curr=later;
            later=temp2;
        }
        curr->next=prev;													// After all terations updating next ptr of last node.
        return curr;														// Returning new head of LL.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is recursion based. At each call the next ptr of the curr. node is updated to the prev. node. We recursively call the fn
// with later of the curr. node with curr. node as the later's prev. node. When we encounter curr==NULL, we return prev node, which gets
// returned by all functions in tail recursive manner.






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
    
    ListNode* recursionLL(ListNode* temp, ListNode* prev){
        if(temp==NULL) return prev;													// If NULL encountered, return last(prev.) node.
        ListNode* later=temp->next;													// Storing curr. node's next node.
        temp->next=prev;															// Updating next of curr. node.				
        return recursionLL(later,temp);												// Calling the fn. with later node.
    }
    
    
    ListNode* reverseList(ListNode* head) {									
        return recursionLL(head, NULL);												// Calling the fn with head as curr. node and NULL as prev.
    }																				// Returns new head of LL.
};




