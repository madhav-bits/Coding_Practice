#include<cstdlib>
#include<iostream>


using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* printList(ListNode* head, int val, int psn){
  ListNode* temp=head;
  ListNode* temp1=new ListNode(val);
  int count=1;
  while(1){
    if(count==psn)
      break;
  temp=temp->next;
  count++;
  }
  cout<<"previous value is: "<<temp->val<<endl;
  ListNode* temp2= temp->next;
  temp->next=temp1;
  temp1->next=temp2;
  return head;
  
}

//*****************************THIS IS USED TO INSERT A ELEMENT AT THE LAST POSITION(TAIL).
/*
ListNode* printList(ListNode* head, int val){
  ListNode* temp=head;
  ListNode* temp1=new ListNode(val);
  if(head==NULL)
    return temp1;
  while(temp->next!= NULL){
    temp=temp->next;
  }
  temp->next=temp1;
  return head;
  
}
*/

int main(){
  ListNode* temp1=new ListNode(1);
  temp1->next=new ListNode(2);
  temp1->next->next=new ListNode(3);
  temp1->next->next->next=new ListNode(4);
  temp1->next->next->next->next=new ListNode(5);
  cout<<"Hi"<<endl;
  ListNode* answer=printList(temp1,6,3);
  cout<<"Hi there"<<endl;
  while(answer!=NULL){
    cout<<answer->val<<endl;
    answer=answer->next;
  }
  //cout<<"The final output based on frequency is: "<<t<<endl;
  return 0;
}