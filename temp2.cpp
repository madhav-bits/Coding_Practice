#include<cstdlib>
#include<iostream>

using namespace std;

//////////////This temp file mainly contains the code related to the linked list.
/*
This code swaps the contents of an linked list two elements each time.
** Leetcode accepted code.
*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swap(ListNode* head){
  if(head==NULL)
    return head;
   ListNode* head1=head;
   ListNode* head2=NULL;
   if(head->next!=NULL) 
     head2=head->next;
   else
     return head;
   cout<<"Hi"<<endl;
   int tempval;
   while(1){
       tempval=head2->val;
       head2->val=head1->val;
       head1->val=tempval;
       cout<<"Head1 value is: "<<head1->val<<endl;
       cout<<"Head2 value is: "<<head2->val<<endl;
       if(head2->next== NULL || head2->next->next==NULL){
          //cout<<"xxxxxxxxxxxx: "<<head2->val<<endl;  
          break;
       }
       head1=head1->next->next;
       head2=head2->next->next;  
   }
  return head;
}

int main(){
  cout<<"Hi"<<endl;
  ListNode* head=NULL;
  //ListNode* head=new ListNode(2);
  //head->next=new ListNode(1);
  //head->next->next=new ListNode(4);
  //head->next->next->next=new ListNode(3);
  head=swap(head);
  cout<<"Hiiii"<<endl;
  while(head!=NULL){
    cout<<head->val<<endl;
    head=head->next;
  }
  return 0;
}