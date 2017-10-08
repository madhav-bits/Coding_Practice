/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

******************************THIS QUESTION IS NOT SOLVED COMPLETELY. NOT UNDERSTOOD THE QUESTION PROPERLY.***************

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
    ListNode *detectCycle(ListNode *head) {
      ListNode* temp1=head;
	  ListNode* temp2=head;
	  ListNode* temp3=NULL;
	  //cout<<"head element is: "<<temp2->val<<endl;
	  if( temp2==NULL || temp2->next==NULL)// These are base cases.
		  return NULL;
	  //temp2=temp2->next;
	  int count=0;
	  while(temp2!=head || count>=0){
		  count++;
		  temp2=temp2->next;
		  //cout<<"CUrrent value is: "<<temp2->val<<endl;
		  if(temp2==NULL)
			return temp3;
		  if(temp2->next==head)
			  return temp2;
	  }
	  //return temp3;
    }
};