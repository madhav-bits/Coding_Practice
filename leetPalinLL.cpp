/*
*
//******************************************************234. Palindrome Linked List.***********************************************

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[]
[1]
[1,1]
[1,2]
[1,2,2,1]
[1,2,3,2,1]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is recursion based. We go recursively each time we return the curr.node's next node in return and the caller checks the returned
// and curr. node are equal or not? If equal we return returned node's next val. if not we return curr. node. So, at the end we except NULL as
// output(Is palindrome), if not not a palindrome.



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
    
    ListNode* findPalin(ListNode* node, int mid, int odd){
        //cout<<"Curr. inside palin with mid: "<<mid<<" and node val: "<<node->val<<endl;
        if(mid==0 && odd==1) return node->next;											// If odd len. then return next node.
        if(mid==0 && odd==0){ return node;}												// If even len. then return curr. node without checking.
        
        ListNode* res=findPalin(node->next, mid-1, odd);
        //cout<<" Returned val is: "<<res->val<<endl;									// Saving the returned node.
        if(node->val!=res->val)															// Comparing the value.	If equal return returned node's next
            return node;
        else return res->next;															// If val not equal, then return curr. node.
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;									// If 0/1 len. return true.
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){																// Calc.length of LL.
            len++;
            temp=temp->next;
        }
        int mid=len/2;																	// Calc. half of length.
        int odd=(len%2==0)?0:1;															// Marking len. is odd or not?
        ListNode*res=findPalin(head,mid, odd);
        if(res==NULL) return true;														// If NULL obtained, then return true.
        else return false;																// Else return false.
    }
};