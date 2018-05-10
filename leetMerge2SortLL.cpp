/*
*
//*********************************************************21. Merge Two Sorted Lists.**************************************************

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1, 2
2->4, 3
1->3->5, 2->4





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates through both linkes lists and chooses the smallest of the two beginning values from both LLs. When one of LL is empty
// we append the head of the other LL to the final answer LL.



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
    ListNode* mergeTwoLists(ListNode* temp1, ListNode* temp2) {
        ListNode* temp= new ListNode(0);
        ListNode* res=temp;
        while(temp1!=NULL && temp2!=NULL){												// Comparing start values from both LLs to add to res. LL.
            if(temp1->val<=temp2->val){													// If head of LL1 is chosen.
                //cout<<"Curr. scan vlaue is: "<<temp1->val<<endl;
                temp->next=temp1;
                temp1=temp1->next;
            }
            else{																		// If head of LL2 is chosen.
                //cout<<"Curr. scan vlaue is: "<<temp2->val<<endl;
                temp->next=temp2;
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        
        temp->next=temp1!=NULL?temp1:temp2;												// When one of LL is empty, append other LL head to res. LL.
        
        return res->next;																// Returning the result LL.
    }
};

