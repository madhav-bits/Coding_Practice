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
//This is done using Hash Maps, can also be solved in O(n) Time, as the LL is a sorted one.
// The other method is in leetLLRemDup2_2.cpp file. That's done in a single iteration.

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
        map<int, int> m;
        ListNode* temp1=head, *prev, *temp2=head, *temp3;
        while(temp2!=NULL){
            m[temp2->val]+=1;
            temp2=temp2->next;
        }
        while( temp1!=NULL && m[temp1->val]>1)//Remvoing the dupli. int, ahead of whom there can't be unique integers.
            temp1=temp1->next;
        
        if(temp1==NULL)
            return temp1;
        temp3=temp1;
        prev=temp1;
        temp1=temp1->next;
        while(temp1!=NULL){
            //cout<<"The current val is: "<<temp1->val<<" and prev. val is: "<<prev->val<<endl;
            if(m[temp1->val]>1){// If a duplicate exists eliminating it from the LL.
                temp2=temp1->next;
                prev->next=temp2;
                temp1=temp2;
            }
            else{// If a Unique elem. then moving ahead in iteration without any changes.
                prev=temp1;
                temp1=temp1->next;
            }
        }
        return temp3;
    }
};