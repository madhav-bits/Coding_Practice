/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
 This code calculates the sum of tow linked lists. The question was asked in leetcode.
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned long int num1=0; unsigned long int num2=0;
        struct ListNode* root1=l1;
        root1=l1; 
        struct ListNode* root2=l2;
        root2=l2; 
        unsigned long int base=1;
        //int num5=23234234345345345345;
        while(root1!=NULL){
            num1=(num1)+(root1->val*(base));
            //cout<<"COunt is: "<<num1<<" value is: "<<root1->val<<endl;
            root1= root1->next;
            base*=10;
        }
        base=1;
        while(root2!=NULL){
            cout<<"Number 2 is: "<<num2<<" value is: "<<root2->val<<" base is:"<<base<<endl;
            num2=(num2)+(root2->val*(base));
            root2= root2->next;
            base*=10;
        }
        unsigned long int num3= num1+ num2;
        cout<<"Num1 is: "<<num1<<endl;
        cout<<"Num2 is: "<<num2<<endl;
        cout<<"The total is: "<<num3<<endl;
        
        unsigned long int count=0; unsigned long int num4=num3;
        while((num3/10)!=0){
            count++;
            num3=num3/10;
        }
        //temp=root3;
        unsigned long int value=1;
        while(count!=0){
            value=value*10;
            count--;
        }
        cout<<"The value is: "<<value<<endl;
        if(value==1){
                ListNode* root3= new ListNode(num4);
                return root3;
        }
        struct ListNode* root3=new ListNode(num4%10);
        struct ListNode* temp=root3;
        num4=num4/10;
        cout<<"The vvvvv is: "<<num4<<endl;
        value=value/10;
        
        while(num4!=0){
            cout<<"Num4 is: "<<num4<<" value is: "<<value<<endl;
            if(value ==1)
                temp->next=new ListNode(num4);
            else
                temp->next= new ListNode(num4%(10));
            temp=temp->next;
            num4=num4/(10);
            value=value/10;
        }
        return root3;   
    }
};