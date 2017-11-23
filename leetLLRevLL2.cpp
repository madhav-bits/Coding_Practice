/*

//*****************************************************92. Reverse Linked List II********************************************

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.


//Time Complexity: O(n).
// Space Complexity: O(1).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* temp1=head, *temp2=head, *temp3, * temp4, * temp5, * prev=NULL;
        int psn=1;
        while(psn<m-1){
            temp1=temp1->next;
            psn++;
        }
        //cout<<" psn is: "<<temp1->val<<endl;
        temp3=temp1;//Storing the ptr of position (m-1).
        if(m!=1)//Handling exception case.
            temp1=temp1->next;
        temp5=temp1;//Calculaing elem. at psn m.   
        int a=(n-m),b=0;
        while(b<=a){
            //cout<<"Reversing right of : "<<temp1->val<<endl;
            temp2=temp1->next;
            temp1->next=prev;
            prev=temp1;
            temp1=temp2;
            b++;
        }
        //cout<<"prev. value is: "<<prev->val<<endl;
        if(m==1){
            head=prev;//
            temp5->next=temp1;
        }
        else{
            temp3->next=prev;//Stores elem. at psn "n", it is next to elem. at psn "m-1".
            temp5->next=temp1;//Changing the next elem of value at psn. "m" to elem. at psn "n+1".
        }
        return head;//Returning the head of the LL.
    }
};