/*
*
//******************************************************203. Remove Linked List Elements.***********************************************

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[6,2,6,3,6,4,5,6]
6


[1,2,6,3,6,4,5,6]
6


[]
3


[6]
6



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the array, at each step, we check whether curr. node's val is target  value or not? If it is, we make curr. node's next
// as prev. node's next, thus removing curr. node from LL. After the entire iteration, we return the root of the new LL.


// Instead of using two prts(Prev.and curr.), we can do this using single ptr, but for readability purpose, I solve it using two ptrs.


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
    ListNode* removeElements(ListNode* curr, int value) {
        ListNode* dup= new ListNode(1);
        dup->next=curr;												// Taking a dummy ptr and make root it's next.
        //ListNode* curr=head;
        ListNode* prev=dup;											// Take a dup of dummy ptr.
        while(curr!=NULL){												
            if(curr->val==value){									// If val. found in curr. node, we make curr. node's next as prev. node's next 
                curr=curr->next;									// Updating curr.
                prev->next=curr;									// Removig curr. node from LL.
            }
            else{													// Moving the ptrs ahead.
                prev=curr;
                curr=curr->next;
            }
        }
        // cout<<"The value is: "<<dup->next->val<<endl;
        return dup->next;											// Returning the root of new LL.
        
    }
};