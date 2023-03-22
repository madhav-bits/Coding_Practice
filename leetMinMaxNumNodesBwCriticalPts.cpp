/*
*
//******************************************************2058. Find the Minimum and Maximum Number of Nodes Between Critical Points.******************************************************

https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,1]
[5,3,1,2,5,1,2]
[1,3,2,2,3,2,2,2,7]
[1,1,1,1,1]
[3,4]
[1,3,2,3,4,2,1,3,5]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. At every step we check if it's a critical node, We store the index of prev. critical in prev. var. and if curr. node is critical node, we calc. gap b/w curr. and 
// prev. cirical node and try to update the least dist b/w critical nodes, we also try to update the max. dist b/w critical nodes every time we encounter a critical node by using index of first. cri. 
// node, when we update it for the last critical node, it's value would be maximized.







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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>res({INT_MAX, INT_MIN});
        
        ListNode* node=head;
        int prevCritical=-1, prev=-1, index=0, firstCritical=-1;										// Stores index of first enc. crit. node, latest encoutered crit. node.
        
        while(node) {
            if(node->next && prev!=-1) {
                if(prev<node->val && node->val>node->next->val 
                  || prev>node->val && node->val<node->next->val) {										// If it is a critical node.
                    if(prevCritical!=-1 && index-prevCritical<res[0]) res[0]=index-prevCritical;		// If gap b/w curr. and prev. crit. node is lower, we update the min. dist.
                    
                    if(firstCritical!=-1) res[1]=index-firstCritical;									// We also update the max. dist, when an crit. node is encountered(except first crit. node).
                    else firstCritical=index;															// For the first enc. crit. node, we update the variable.
                    prevCritical=index;
                }
            }
            prev=node->val;
            node=node->next;																			// Updating the iterator and the corresponding index.
            index++;
        }
        
        
        return (res[0]==INT_MAX)?vector<int>({-1, -1}):res;												// Returning the min, max dist b/w critical nodes.
    }
};

