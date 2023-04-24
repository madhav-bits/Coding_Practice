/*
*
//******************************************************2487. Remove Nodes From Linked List.******************************************************

https://leetcode.com/problems/remove-nodes-from-linked-list/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,2,13,3,8]
[1,1,1,1]
[1,2,3,3,4,3,2,1]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is stack based. Here, we use a stack to store nodes for whom greater value to the right side not yet found, while iterating we pop nodes from the stack whose values < curr. node
// and we add curr. node to the stack, as all the nodes in the stack have >=values than curr. node. At the end, while popping nodes out, we link them in the reverse LL to reflect their orig. drn
// of connections and return the new LL.







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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;																				// Stores nodes which didn't encounter greater nodes yet on right side.
        ListNode* node=head;
        
        while(node) {																					// Iterating over LL.
            while(!st.empty() && st.top()->val<node->val) st.pop();										// Removing nodes which are<curr. node value.
            st.push(node);																				// Adding curr. node to stack.
            node=node->next;
        }
        
        ListNode* prev=NULL;
        while(!st.empty()) {																			// Popping nodes which dont have > value nodes on their right side.
            st.top()->next=prev;																		// Linking these nodes to reflect their orig. drn of connections.
            prev=st.top();
            st.pop();
        }
        return prev;																					// Returning the root of the modified LL.
    }
};
