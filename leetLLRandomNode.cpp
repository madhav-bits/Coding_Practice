/*
*
//******************************************************382. Linked List Random Node.***********************************************

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["Solution","getRandom"]
[[[1,2,3]],[]]


["Solution","getRandom","getRandom","getRandom"]
[[[1]],[],[],[]]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. In the first loop, we find the length of the LL. When getRandom is called, we extract any number from 1 to
// len and iterate those many steps and return the value. As the number is chosen with equal probability using rand fn., all values are of equal
// prob.








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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* root;															// Stores the root of LL.
    int count=0;															// Stores the length of the LL.
    Solution(ListNode* temp) {
        root=temp;
        while(temp!=NULL){													// Calc. the length of the LL.
            count++;
            temp=temp->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int curr=rand()%count+1;											// Find the index of the random value.
        int res;
        ListNode* head= root;
        while(curr>0){														// Return the value at that index.
            curr--;
            res=head->val;													// Stores the curr. node's val.
            head=head->next;
        }
        return res;															// Returning the random value chosen.
    }
    
        
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
 
 
 
 
 
 
 
 
 //************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. This is some special method of chosing with equal prob. At each step, we chose with one with equal prob., 
// after adding new elem., we once again find the random index, if it's equal to newly added elem., then random value is updated, if not it 
// stays as it is. The random value obtained after pushing all values is the answer. 
 
 
 
 
 
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* root;
    Solution(ListNode* temp) {
        root=temp;															// Storing the root of the LL.
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res;
        int len=0;
        ListNode* head= root;	
        while(head!=NULL){													// Iterates till the end of the LL.
            len++;															// Tracks the length of LL traversed.
            int ind=rand()%len;												// Find the index of the chosen random value.
            if(ind==len-1) res=head->val;									// If the index is of curr. value, then random value is updated.
            head=head->next;												// Iterator is moved forward.
        }
        return res;															// Returning the random value chosen.
    }
    
        
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
 
 
 
 