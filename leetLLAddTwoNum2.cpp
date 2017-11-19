/*

//***************************************************445. Add Two Numbers II*************************************************

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each 
of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

//Solution 3: is accepted.
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
        ListNode *temp1, *temp2, *temp3, *temp4, *temp5,*temp6, *res, ** addr;
        //addr=&res;
        if(l2==NULL)
            return l1;
        if(l1==NULL)
            return l2;
        temp2=l1;//Reversing the first LL.
        temp3=temp2->next;
        temp2->next=NULL;
        while(temp3!=NULL){//Reversing a LinkedList and storing it in another LL.
            //cout<<"Current scanned elem. is: "<<temp2->val<<endl;
            if(temp3==NULL)
              break;
            temp4=temp3->next;// Storing the next of next in temp address.
            temp3->next=temp2;//Reversing the dirn of next val.
            temp2=temp3;//Moving ahead with the LL's contents(curr. value).
            temp3=temp4;//Saving the next val for next iteration.
        }
        //cout<<"The first elem. of reversed LL is: "<<temp2->val<<endl;
        
        temp5=l2;//Reversing the second LL.
        temp3=temp5->next;
        temp5->next=NULL;
        while(temp3!=NULL){//Reversing a LinkedList and storing it in another LL.
            //cout<<"Current scanned elem. is: "<<temp5->val<<endl;
            if(temp3==NULL)
              break;
            temp4=temp3->next;// Storing the next of next in temp address.
            temp3->next=temp5;//Reversing the dirn of next val.
            temp5=temp3;//Moving ahead with the LL's contents(curr. value).
            temp3=temp4;//Saving the next val for next iteration.
        }
        //cout<<"The first elem. of reversed LL is: "<<temp5->val<<endl;/
        int result=0, rem=0;
        res=new ListNode(0);
        temp6=res;
        while(temp2!=NULL || temp5!=NULL){//Summing the two elements.
            //cout<<"Inside summation loop."<<endl;
            if(temp2==NULL){
                int sum=rem+temp5->val;
                //result=sum%10;
                res->val=(sum%10);
                rem=sum/10;
                temp5=temp5->next;
                res->next=new ListNode(0);
                res=res->next;
            }
            else if(temp5==NULL){
                int sum=rem+temp2->val;
                //result=sum%10;
                res->val=(sum%10);
                rem=sum/10;
                temp2=temp2->next;
                res->next=new ListNode(0);
                res=res->next;
            }
            else{
                int sum=rem+temp2->val+temp5->val;
                //result=sum%10;
                res->val=(sum%10);
                rem=sum/10;
                temp2=temp2->next;
                temp5=temp5->next;
                res->next=new ListNode(0);
                res=res->next;
            }
        }
        int a=0;
        if(rem!=0){// This is to make sure any remainder after the last point of multiplication.
            res->val=rem;
            a=1;
        }
        //cout<<"the first val. of resul is: "<<temp6->val<<endl;
        
        // Reversing the obatinaed result.
        
        temp5=temp6;//Reversing the result LL.
        temp3=temp5->next;
        temp5->next=NULL;
        while(temp3!=NULL){//Reversing a LinkedList and storing it in another LL.
            //cout<<"Current scanned elem. is: "<<temp5->val<<endl;
            if(temp3==NULL)
              break;
            temp4=temp3->next;// Storing the next of next in temp address.
            temp3->next=temp5;//Reversing the dirn of next val.
            temp5=temp3;//Moving ahead with the LL's contents(curr. value).
            temp3=temp4;//Saving the next val for next iteration.
        }
        //cout<<"The final result's first elem. is: "<<temp5->val<<endl;
        
        if(a==1)//If there is any rem. after last int. multipli., then pass the result as it is.
            return temp5;
        else// If there is no rem. then return from the second elem. of LL. as the first elem. is "0" which is of no value.
         return temp5->next;
    }
};