/*
*
//*************************************************************25. Reverse Nodes in k-Group.***************************************************

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then 
left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,5,6,7,8,9,10,11]
4

[1,2,3,4,5,6,7,8,9,10,11,12]
4

[1,2,3,4,5,6,7,8,9]
4

[1,2]
4

[1]
4


[]
3

[1,2]
1


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, we first find out, how many groups of k we have, as group with size<k, need not be reversed. We reverse the
// nodes in a group, we make the prev group's post inversion last elem. next=curr. group's last elem. pre-inversion. we also make
// curr. group's first elem's(pre) next elem.= next group's first elem(pre).(This would be useful, if we have last subgroup with len<k), as they
// won't get reversed.








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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* res=new ListNode(-1);
        ListNode* prev=res, *curr=head, *temp2=head;
        int len=0;
        while(temp2){												// Calc. length of LL.
            len++;
            temp2=temp2->next;
        }
        // cout<<"len: "<<len<<endl;
        int turns=len/k, count=0;    								// Calc. #groups in LL.
        
        res->next=curr;												// Making dummy's next= LL's head(pre) (Default scenario).
        while(curr && count<turns){									// we iterate till all complete groups are reversed.
            ListNode* first=curr, *prev2=prev;						// Temp. store curr. group's first and prev's groups last elem.
            for(int i=0;i<k-1;i++){
                ListNode* fol=curr->next;							// Reverse curr. group's elem. except last one(Overcautiously done this).
                curr->next=prev2;
                prev2=curr;
                curr=fol;
            }
            
            first->next=curr->next;									// Next group's first elem. would be curr. groups' last elem's next.
            prev->next=curr;										// Prev group's last elem's next will be curr. groups's first elem.	
            prev=first;												// Storing the last elem. of curr. group.
            ListNode* temp3=curr->next;								// Reversing the last Link in curr. group.
            curr->next=prev2;
            curr=temp3;
            count++;												// Inc. the group's iterate count.
        }
        return res->next;											// Returning the reversed LL's head.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, we first find out, how many groups of k we have, as sub-groups with size<k, need not be reversed. We 
// reverse the nodes in a group, we make the prev group's post inversion last elem.'s next=curr. group's last elem. pre-inversion. we also make
// curr. group's first elem's(pre) next elem.= next group's first elem(pre).(This would be useful, if we have last subgroup with len<k), as they
// won't get reversed.


// This algo. is almost same as the previous one, except that here, I had reversed all elem. in a group in the for loop.(Unlike earlier one, in
// which I had only inverted k-1 elem. in a group in for loop, and last one outside for loop(cautiously)).


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* res=new ListNode(-1);
        ListNode* prev=res, *curr=head, *temp2=head;
        int len=0;
        while(temp2){
            len++;
            temp2=temp2->next;
        }
        // cout<<"len: "<<len<<endl;
        int turns=len/k, count=0;    
        
        res->next=curr;												// Making dummy's next= LL's head(pre) (Default scenario).
        while(curr && count<turns){
            ListNode* first=curr, *prev2=prev;
            for(int i=0;i<k;i++){
                ListNode* fol=curr->next;
                curr->next=prev2;
                prev2=curr;
                curr=fol;
            }
            
            prev->next=prev2;										// Prev. group's last elem's next will be curr. group's last elem(pre-inv).			
            first->next=curr;										// Curr. group's first elem's(pre) next will be next group's first elem.(pre-inv).
            prev=first;												// Storing curr. group's last elem. to work on next group. 
            count++;												// Inc. the #groups iterated count.
        }
        return res->next;
    }
};