/*
*
//**********************************************1669. Merge In Between Linked Lists.***********************************************

https://leetcode.com/problems/merge-in-between-linked-lists/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked on test cases provided with the question.
[0,1,2,3,4,5]
3
4
[1000000,1000001,1000002]
[0,1,2,3,4,5,6]
2
5
[1000000,1000001,1000002,1000003,1000004]



// Time Complexity: O(n+m).													// Sum of lengths of two strings.  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// Sum of lengths of two strings.
// Space Complexity: O(1).	
// This algorithm is iteration based. We iterate the first LL, we store the nodes at position a-1 and b+1 and link them to start and
// last node of second LL and return the start of first LL.








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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* node1=NULL, *node2=NULL, *temp=list1;
        for(int i=0;i<=b;i++){												// Iter. and find nodes at a-1 and b+1 psn.
            if(i==a-1) node1=temp;
            temp=temp->next;
        }
        node2=temp;															
        // while(temp){
        //     if(temp->next && temp->next->val==a)
        //         node1=temp;
        //     if(temp->val==b)
        //         node2=temp->next;
        //     temp=temp->next;
        // }
        ListNode* last=list2;
        while(last->next){													// Get last node of second LL.
            last=last->next;
        }
        last->next=node2;													// Link last node of sec LL and first LL node at b+1 psn.
        if(!node1)															// If a psn not found, we return second LL start.
            return list2;
        node1->next=list2;													// Link first LL a-1 psn node to second LL start. 
        return list1;														// Return start of first LL.
    }
};