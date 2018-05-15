/*
*
//**********************************************************143. Reorder List.***************************************************

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1]
[]
[1,2]
[1,2,3,4]
[1,2,3,4,5]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iterative but recursion based. We travel upto mid of LL, at each step we Link the curr. node to the node obtained from 
// recursive call. We return the obtained node's next node to the caller. This way we link the way asked in the question. There are some 
// changes made specifically for even and odd length LLs.



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
    
    ListNode* modifyList(ListNode* node, int mid, int odd){
        if(mid==0 && odd==1){													// On reaching mid, if odd len. make the curr. node->next=NULL.
            ListNode* temp2=node->next;											// Return the curr. node.
            node->next=NULL;
            return temp2;
        }
        
        if(mid==0 && odd!=1) return node;										// On reaching mid, if even len. return curr. node.
        //cout<<"Curr. scanning node is: "<<node->val<<" mid val. is: "<<mid<<endl;
        ListNode* temp=node->next;												// Saving the curr. node's next node.
        ListNode* res=modifyList(node->next, mid-1,odd);						// Saving the node from reucrsive call.
        //cout<<"Returned from the fn. with node is: "<<node->val<<" and mid is: "<<mid<<" with value: "<<res->val<<endl;
        ListNode* resNext=NULL;
        if(res)																	// If call val is not NULL, then save it's next node temporarily.
            resNext=res->next;
        node->next=res;															// Updating the next to the curr. node.
        if(temp==res)															// In case of Even len. this scenario occurs, make next=NULL.
            res->next=NULL;
        else																	// Else update the next node to the call's result.
            res->next=temp;
        //cout<<"End of loop with mid: "<<mid<<endl;
        return resNext;															// Return the temporarily saved call's result's next node.
    }
    
    void reorderList(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){														// Calc. the length of the LL.
            len++;
            temp=temp->next;
        }
        int mid=len/2;															// Calc. mid length of LL.
        //cout<<"len is: "<<len<<" and mid is; "<<mid<<endl;
        if(len%2==0)
            modifyList(head,mid,0);												// If len. of LL is even.
        else 
            modifyList(head,mid,1);												// If len. of LL is odd.
        
        // ListNode* temp2=head;
        // while(temp2!=NULL){
        //     cout<<"The val is: "<<temp2->val<<endl;
        //     temp2=temp2->next;
        // }
        return ;
    }
};