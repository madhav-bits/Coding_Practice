/*
*
//******************************************************82. Remove Duplicates from Sorted List II***********************************************

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/


Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return 
the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[1,2,3,3,4,4,5]
[1,1,2,2,3,3,4,4]
[]
[1,1,1,2,3]
[1,2,2]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, in every step in while loop, if a num has dup values, we iter. over all of them onto next diff. value. If the 
// num is unique, we add it to prev. uniq. node, while skipping duplicate values we also delete the memory allocated to them. We return LL of uniq. nums at
// the end of iter.









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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev=NULL, *res=NULL, *curr=head, *temp=NULL;
        while(curr){
            temp=curr->next;
            if(curr->next && curr->val==curr->next->val){					// If curr. num has duplicate values.
                while(curr->next && curr->val==curr->next->val){			// We skip and delete all the duplicate values.
                    temp=curr->next;
                    delete curr;											// Deleting nodes with duplicate values.
                    curr=temp;
                }
                temp=curr->next;
                delete curr;
            }else{
                if(!res) res=curr;
                else prev->next=curr;										// Making curr. uniq. val node next to prev. uniq. value node.
                prev=curr;
            }
            curr=temp;														// Moving to next node.
        }
        if(prev) prev->next=NULL;											// Setting next of last uniq. value to NULL.
        return res;															// Returning LL of uniq. value nodes.
    }
};

