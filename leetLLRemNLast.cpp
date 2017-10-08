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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* later=head;// Initializing to NULL also works out. But it's not pointing to any memory in the heap.
        ListNode* curr=head;
        ListNode* curr2=head;
        int length=0; int count=1;
        int target;
        while(curr2!=NULL){
            length++;
            curr2=curr2->next;
        }
        cout<<"Length is: "<<length<<endl;
        target=length-n+1;
        if(target==1){
            head=head->next;
            return head;
        }
        for(int i=1;i<target-1;i++)
            curr=curr->next;
        later=curr->next;
        if(later->next!=NULL)
            curr->next=later->next;
        else
            curr->next=NULL;
        
        return head;
    }
};