/*
*
//****************************************************160. Intersection of Two Linked Lists.*********************************************

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[], [1]

[1->2->3],[2->3]


// Time Complexity: O(m+n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n).
// Space Complexity: O(1).	
// This algorithm iterates through both the LLs, we maintain two Ptrs starting from heads of both LLs.When a ptr reach it's tail for the first time,
// we redirect the ptr to other LL. If there is a intersection then both ptrs will meet at the pt. of intersection, if not both of them gets same
// value as they reach the end of LLs they are currently iterating.

// They meet at pt. of intersect as both the ptrs travel same elements in both the LLs to reach the pt. of intersection for the second time. If 
// intersection doesn't exist, they would be iterating through length of both LLs to reach end of their curr. iterating LLs.





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
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        if(l1==NULL || l2==NULL) return NULL;								// Returning NULL, if either of LL is NULL.(No intersection).
			
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        while(temp1!=temp2){
            
            if(temp1!=NULL) temp1=temp1->next;								// Iterating in the curr. LL.
            else temp1=l2;													// If end of LLs is reached, then redirect to other LL.
            if(temp2!=NULL) temp2=temp2->next;								// Iterating in the curr. LL.
            else temp2=l1;													// If end of LLs is reached, then redirect to other LL.
            
            
            
        }
        return temp1;
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates thorugh one of LL and stores all of nodes in Map, in the iteration of the second LL, the instant we encounter a 
// node in map, we return that node(that's the pt. of intersection). If we didn't find any such node, then return NULL.






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
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        map<ListNode*, int>m;
        ListNode* temp1= l1;
        ListNode* temp2=l2;
        while(temp1!=NULL){
            m[temp1]=1;
            temp1=temp1->next;
        }
        
        while(temp2!=NULL){
            if(m.count(temp2)) return temp2;
            temp2=temp2->next;
        }
        return NULL;
    }
};