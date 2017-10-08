/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5

//**************************************** THIS IS LEET ACCEPTED CODE.********************************************
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
    ListNode* partition(ListNode* head, int value) {
          ListNode* temp2=head;
          ListNode* temp7=head;
          ListNode*temp6;
          if(head==NULL || head->next==NULL)
            return head;
          int length=1;
          while(temp2->next!=NULL){
            temp2=temp2->next;
              length++;
          }
          temp6=temp2;
          cout<<"Length is: "<<length<<endl;
          //cout<<"Before if condition"<<endl;
          int i=1;
          while(head->val >= value && i<=length){
            //cout<<"Inside first if condition"<<endl;
            ListNode* temp3=head;
            head=head->next;
            temp2->next=temp3;
            temp3->next=NULL;
            temp2=temp2->next;
            if(head== temp7)
                return head;
            i++;
          }

          ListNode* temp4;
          ListNode* temp1=head;
          cout<<"Before while"<<temp1->val<<endl;
          i=1;
          int j=0;
          while(temp1!=temp6 && i< length){
            cout<<"Inside while: "<<temp1->next->val<< "value is: "<<value<<endl;
            if(temp1->next->val >= value){
                cout<<"In second condition"<< " & Node val is: "<<temp1->next->val<<endl;
              if(temp1->next->next == NULL)
                  return head;
                if(j==1)
                    return head;
                if(temp1->next==temp6)
                    j=1;
              
              temp4=temp1->next;
              temp1->next=temp1->next->next;
              temp2->next=temp4;
              temp4->next=NULL;
              temp2=temp2->next;
            }
            else
              temp1=temp1->next;
            i++;
          }
          //cout<<"After while"<<endl;
         return head;
    }
};