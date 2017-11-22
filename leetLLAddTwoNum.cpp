/*

//***************************************************************2. Add Two Numbers**************************************************************

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their 
nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8


//Time Complexity: O(n).
// Space Complexity: O(n).

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root1=l1, *root2=l2, *temp1, *temp2, *temp4;
        int carry=0, sum=0, rem;
        temp1=new ListNode(0);
        temp2=temp1;
        while(root1!=NULL || root2!=NULL){
            if(root1!=NULL && root2!=NULL){
                sum=carry+root1->val+root2->val;
                rem=sum%10;
                carry=sum/10;
                //cout<<"Pushing val is: "<< rem<<endl;
                temp1->next=new ListNode(rem);
                root1=root1->next;//Passing through iterator for next iteration.
                root2=root2->next;//Passing through iterator for next iteration.
                temp1=temp1->next;//Passing through iterator for next iteration.
            }
            else if(root1==NULL){
                sum=carry+root2->val;
                rem=sum%10;
                carry=sum/10;
                //cout<<"Pushing val is: "<< rem<<endl;
                temp1->next=new ListNode(rem);
                root2=root2->next;//Passing through iterator for next iteration.
                temp1=temp1->next;//Passing through iterator for next iteration.
            }
            else{
                sum=carry+root1->val;
                rem=sum%10;
                carry=sum/10;
                //cout<<"Pushing val is: "<< rem<<endl;
                temp1->next=new ListNode(rem);
                root1=root1->next;//Passing through iterator for next iteration.
                temp1=temp1->next;//Passing through iterator for next iteration.
            }
            
        }
        if(carry!=0)
            temp1->next=new ListNode(carry);
        /*
        temp4=temp2;
        while(temp4!=NULL){//Prints the contents of newly created answer LL.
            cout<<"result is: "<<temp4->val<<endl;
            temp4=temp4->next;
        }
        */
        return temp2->next;//Passing from the second value, as the first one is zero(from Line 14).
    }
};