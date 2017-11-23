/*

//***************************************************82. Remove Duplicates from Sorted List II***************************************

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.


//Time Complexity: O(n).
// Space Complexity: O(n).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/
//This is done in a single pass.

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
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *temp1=head, *temp2=head, *temp3, *temp4;
        int i=0, a;
        temp3=new ListNode(0);
        temp4=temp3;

        while(temp1!=NULL){
            while(temp1!=NULL && temp1->next!=NULL){//Checking whether comparing values exist or not.
                if(temp1->val==temp1->next->val){//If its not a unique elem. gets into a loop.
                    temp1=temp1->next;
                    while( temp1!=NULL && temp1->next!=NULL && temp1->val==temp1->next->val)//Comparing seq. of duplicates.
                        temp1=temp1->next;
                    
                    temp1=temp1->next;//Moving on to next seq. of numbers.
                    if(temp1!=NULL)
                        head=temp1;
                }
                else
                    break;
            }// If breaks from this while loop, it means that temp1 contains a unique elem. 
            temp3->next=temp1;//Stitching up all the unique elem. in temp3 LL.
            temp3=temp3->next;
            if(temp1!=NULL)//Avoiding accessing NUll ptr's values.
                temp1=temp1->next;
        }
      
        return temp4->next;//Returning from second val. as first value contains zero.
    }
};