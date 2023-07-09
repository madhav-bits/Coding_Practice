/*
*
//******************************************************2130. Maximum Twin Sum of a Linked List.******************************************************

https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,4,2,1]
[4,2,2,3]
[1,100000]
[1,2,3,4,2,2]
[1,2,3,4,5,6,7,8]
[1,2]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack+ Two Pointers based. We use two pointers(slow, fast) to find the middle node of the LL, in the process, we also store the first half
// nodes in stack. Now, while iter. over second half of LL, we pop nodes out of stack, as these two nodes are symmetrical from the middle we add their value
// and try to maximize the sum and return it at the end of iter.







class Solution {
public:
    int pairSum(ListNode* head) {
        int res=0;
        stack<int>st;
        ListNode* slow=head, *fast=head;
        while(fast) {														// We use slow, fast pointers to identify the middle node of the LL.
            st.push(slow->val);												// Adding first half nodes into stack.
            slow=slow->next;
            fast=fast->next->next;
        }
        while(slow) {
            if(st.top()+slow->val>res) res=st.top()+slow->val;				// Adding symmetrical nodes values and try to maximize their total.
            slow=slow->next;
            st.pop();														// We pop first half's nodes from stack as we iter. over second half of LL.
        }	
        return res;															// Returning the max. twin sum.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is same as the above one except that we didn't use stack to get the symmetrical nodes for second half nodes, while using slow, fast ptrs
// to find the middle node, we also reverse the first half of LL. After finding the middle node, first half's ptr iter. in reverse drn, second half's ptr
// iter. in forward drn, at every step we calc. and maximize their total and return it at the end of iter.








class Solution {
public:
    int pairSum(ListNode* head) {
        int res=0;
        ListNode* slow=head, *fast=head, *prev=NULL, *fol=NULL;
        while(fast) {
            fast=fast->next->next;
            
            fol=slow->next;													// Reversing the first half of LL.
            slow->next=prev;
            prev=slow;
            slow=fol;
        }
        fast=slow;
        slow=prev;
        // cout<<"slow: "<<slow->val<<" and fast: "<<fast->val<<endl;
        while(slow) {
            if(fast->val+slow->val>res) res=fast->val+slow->val;			// Adding symmetrical nodes values and try to maximize their total.
            slow=slow->next;												// First half's ptr iter. in reverse drn.
            fast=fast->next;												// Second half's ptr iter. in forward drn towards the end of LL.
        }
        return res;															// Returning the max. twin sum.
    }
};

