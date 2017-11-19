/*

//************************************************237. Delete Node in a Linked List**********************************************

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should 
become 1 -> 2 -> 4 after calling your function.

//Solution 3: is accepted.
//Time Complexity: O(1).
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
};