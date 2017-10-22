/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

//**********************************************************THIS IS LEET ACCEPTED CODE.**********************************************
//***********************************************************************************************************************************
*/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0)
            return head;
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp1=head; ListNode* temp2=head; ListNode* temp3=NULL; int count=0;
        while(temp1->next!=NULL){
            temp1=temp1->next;
            count++;
        }
        count++;
        cout<<"count is: "<<count<<endl;
        if(k>=count)// This makes sure that we won't make unnecessary rotations.
            k=k%count;
        k=count-k;// Converting moves to the right to the moves to the left.
        for(int i=0;i<k;i++){
            temp3=temp2->next;// temp3 is the temporary ListNode storing the pointer to the next elem. which will be head.
            temp2->next=NULL;// temp1 is the last elem. in the LL.
            temp1->next=temp2;// temp2 is the which deals with the head of the LL.
            temp1=temp1->next;
            temp2=temp3;
        }
        cout<<"First elem. of result is: "<<temp2->val<<endl;
        return temp2;
    }
};