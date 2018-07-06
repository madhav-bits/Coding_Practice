/*
*
//**************************************************************369. Plus One Linked List.*******************************************************

Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0]

[1,2,9]

[8,9,9]


[9,9,9]

[1,2,7]


[9]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Recursion based. We iterate till the end, add 1 to the last value, and return the carry to the previous node. We add the
// carry to the curr. node and recalc. the carry to be returned to it's prev. node. We update the curr. node to curr. (val+rem)%10.So, that
// we won't have two digits in a single node. 








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
    
    int calcAddn(ListNode* node){
        if(node->next==NULL){												// On reaching the last node.
            node->val+=1;													// Adding. one to it.
            int res=node->val/10;											// Calc. the carry to be returned.
            node->val%=10;													// Updating the curr. value.
            return res;														// Returning the carry.
        }
		
        int res=calcAddn(node->next);										// Getting the carry from the next node.
        if(res==0) return 0;												// If carry=0, return 0(As, there won't be any change in this node).
        node->val+=res;														// Adding carry to curr. node.
        res=node->val/10;													// Calc. carry to be returned.
        node->val%=10;														// Update the curr. node.(Making sure each node has only single digit).
        return res;															// Returning the carry.
    }
    
    ListNode* plusOne(ListNode* head) {
        ListNode* dup= new ListNode(-1);									// Init. a dummy node.
        dup->next=head;														// Make head as dummy's next node.
        int res=calcAddn(head);												// Call fn. to get carry from head.
        if(res>0){															// If carry>0 obtained.
            dup->val=res;													// Dup. node is obtained.
            return dup;														// Return the Dup Node.
        }
        else return dup->next;												// Else, return original head of LL.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. We iterate the LL and push the contents into the Stack. We init. the carry var to 1, we add the carry to the 
// top node of the stack, update it's value, calc. carry to be forwarded to node below it and pop top node. We iterate till stack is empty.
// At the end of iteration, if we get carry>0, then we create a new node with carry as value and given head as next node to newly created node.
// If carry=0, we return the given head directly.





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
    
    ListNode* plusOne(ListNode* head) {
        ListNode* dup= new ListNode(-1);									// Creating the Dummy node.
        dup->next=head;														// Making head as it's next.
        stack<ListNode*>st;													// Pushing all nodes into Stack.
        while(head){										
            st.push(head);
            head=head->next;
        }
        int carry=1;														// Init. carry to 1.
        while(!st.empty()){													// Till stack is empty.
            ListNode* curr=st.top();										// Extract top node.
            st.pop();
            curr->val+=carry;												// Add carry to top node.
            carry=curr->val/10;												// Calc. carry to be forwarded.
            curr->val%=10;													// Update the curr. node(Making sure each node has only single digit).
        }
        
        if(carry>0){														// If carry obtained, then we udpate the dummy node.
            dup->val=carry;	
            return dup;														// Return the dummy node, which has given head node as it's next node.
        }
        else return dup->next;												// Else, return the given head node.
    }
};