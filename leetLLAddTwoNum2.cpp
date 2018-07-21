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




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1]
[9,9,9,9]


[9,9,9,9]
[1]


[1,2,3]
[]


[]
[1,2,3]



[]
[]



[2,3,4]
[5,6,7,8,9]





//Time Complexity: O(n).
// Space Complexity: O(n).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/



//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).

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












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// This algo. is iteration based. This is Follow UP of the question. Here, first we calculate the length of two LLs.In the second iteration, we 
// first travel diff. length in longer LL, then later we also iterate smaller LL along with longer LL, upto the end of both LLs(now they end in 
// same iteration). We sum the values from longer LL, smaller length LL(if curr. depth>=diff)+carry from the recursive call, we assign the curr.
// res node, this value and make the result node of recursive call it's next node. We update the carry variable. If at th end of recursive 
// calls, if we have a carry>0, then we create a new node with this value and the result node of recursive call it's next node.








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
    ListNode* findSum(ListNode* lt, ListNode* rt,int depth, int diff, int &carry){
        
        if(lt==NULL) return NULL;											// When both LLs end.
        // cout<<"Curr. left node: "<<lt->val<<" and right node: "<<rt->val<<endl;
        ListNode* res;														// Stores root of result LL obtained from recursive call.
        if(depth>=diff){													// When both LLs have node with same dist. from end(same psn value).
            res=findSum(lt->next,rt->next,depth+1,diff,carry);
        }
        else																// If there is no bit in smaller LL with this psn value.
            res=findSum(lt->next,rt,depth+1,diff,carry);
        
        int sum=lt->val+carry;												// Add, curr. and carry.
        if(depth>=diff)														// If, smaller LL has node with this psn value.
            sum+=rt->val;
        
        carry=sum/10;														// Calc. carry to be passed onto prev. node.
        ListNode* temp= new ListNode(sum%10);								// Create node with curr. sum's curr. psn value.
        temp->next=res;														// Make recurisve call's result, new node's next node.
        res=temp;															// Make new node the root of the result LL.
        return res;															// Return root of the result LL.
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1, *temp2=l2,*res;
        int len1=0, len2=0;
        while(temp1){														// Calc. length of two LLs.
            len1++;
            temp1=temp1->next;
        }
        while(temp2){
            len2++;
            temp2=temp2->next;
        }
        temp1=l1; temp2=l2;
        int carry=0;
        if(len1>=len2){														// Passing longer LL as first argument to fn.
            res=findSum(l1,l2,0, len1-len2,carry);
            if(carry==0) return res;										// If carry =0 for last addn return obtained result.
            else{															// If carry>0, create new node, make result node the next node of it.
                ListNode* fin=new ListNode(carry);
                fin->next=res;
                return fin;
            } 
        }
            
        else{
            res=findSum(l2,l1,0, len2-len1,carry);
            if(carry==0) return res;
            else{
                ListNode* fin=new ListNode(carry);
                fin->next=res;
                return fin;
            }
        }
            
    }
};