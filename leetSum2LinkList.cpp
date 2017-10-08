/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
 Sum the contents of two linked lists. The solution is for quite misunderstood question fo Leetcode.\
 
 */
 
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1=0; int num2=0;
        struct ListNode* root1=l1;
        root1=l1; 
        struct ListNode* root2=l2;
        root2=l2; 
        //ListNode* root3=new ListNode();
        //ListNode* temp= new ListNode();
        //root3  = (struct ListNode*)malloc(sizeof(struct ListNode));
        //temp  = (struct ListNode*)malloc(sizeof(struct ListNode)); 
        while(root1!=NULL){
            num1=(num1*10)+(root1->val);
            //cout<<"COunt is: "<<num1<<" value is: "<<root1->val<<endl;
            root1= root1->next;
        }
        while(root2!=NULL){
            num2=(num2*10)+(root2->val);
            root2= root2->next;
        }
        int num3= num1+ num2;
        cout<<"COunt is: "<<num3<<endl;
        int count=0; int num4=num3;
        while((num3/10)!=0){
            count++;
            num3=num3/10;
        }
        //temp=root3;
        int value=1;
        while(count!=0){
            value=value*10;
            count--;
        }
        cout<<"The value is: "<<value<<endl;
        struct ListNode* root3=new ListNode(num4/value);
        struct ListNode* temp=root3;
        num4=num4%value;
        value=value/10;
        //ListNode* root3=NULL;
        //ListNode* temp=root3;
        //int c=1;
        while(num4!=0){
            temp->next= new ListNode(num4/(value));
            //temp= new ListNode(num4/(value));
            //if(c==1)
            //    root3=temp;
            temp=temp->next;
            num4=num4%(value);
            value=value/10;
            //c=2;
        }
        return root3;   
    }
};



