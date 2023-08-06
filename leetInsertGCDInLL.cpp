/*
*
//******************************************************2807. Insert Greatest Common Divisors in Linked List.******************************************************

https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[18,6,10,3]
[7]
[1,3,4,5,6,8]
[2,5,7,11,17]
[2,4,6,5,6,7,7,65,4,56,7,67,5,4]



// Time Complexity: O(nlogm).  												// n-#nodes in the LL, m-highest val. in LL.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogm).												// n-#nodes in the LL, m-highest val. in LL.
// Space Complexity: O(1).	
// This algorithm is iteration and Maths based. We iter. over the LL, in every iter. we calc. gcd b/w curr. and next node and insert it b/w them and move to orig. next node.
// We repeat this process until the end of LL and return the head of the LL.







/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;
        ListNode* res=head;
        while(head->next) {													// Iter. over the entire LL.
            int gcd=__gcd(head->val, head->next->val);						// Calc. gcd of curr. and next val.
            ListNode* temp=new ListNode(gcd);								// Create new node.
            temp->next=head->next;											// Inserting new node b/w orig. curr. and orig. next node.
            head->next=temp;
            head=head->next->next;											// Move to orig. next node.
        }
        return res;															// Returning the head of the modified LL.
    }
};

