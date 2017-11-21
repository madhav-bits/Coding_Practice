/*

//***************************************************328. Odd Even Linked List*************************************************

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about 
the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...

Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.


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
    void deleteNode(ListNode* node) {
        node->val=node->next->val;//Copying the next value to the current position.
        node->next=node->next->next;// Making the next's next address as the next address of the current node.
    }
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp1=head, *temp2=head, * temp3, *temp4;//
        if(head==NULL || head->next== NULL || head->next->next== NULL)// If there are 0,1,2 values return head.
            return head;
        temp2=temp2->next;
        while(temp2!=NULL && temp2->next!=NULL){
            //cout<<"temp1 val is: "<<temp1->val<<endl;
            //cout<<"temp2 val is: "<<temp2->val<<endl;
            temp4=temp2->next->next;//temp2 will be always on initial even indexed values.
            temp3=temp1->next;//Stores the next value to temp3 variable.
            temp1->next=temp2->next;// Changing the next addresses of both temp1, temp2 and temp2->next.
            temp2->next->next=temp3;
            temp2->next=temp4;
            temp2=temp2->next;// Shifting values for next iteration.
            temp1=temp1->next;// Shifting values for next iteration.
        }
        return head;
    }
};