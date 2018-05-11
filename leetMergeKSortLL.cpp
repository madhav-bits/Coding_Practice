/*
*
//********************************************************23. Merge k Sorted Lists.*************************************************

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[]]
[[1->2],[1->3],[]]




// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm maintians a Min Heap with a pair of (value and the ptr to the curr. node) as contents, with value as determining factor in sorting.
// We have extract the min. at any instant and push the next ptr in that LL into the Min Heap, we do this process until all LLs are empty.




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
    
    struct compare{																	// Maintaining the Min Heap based on the Value of the nodes.
      bool operator()(const pair<int, ListNode*>l, const pair<int, ListNode*> r){
        return l.first>r.first;
      }
    };
    
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, compare> pq;					// Defining a Min Heap.
        for(int i=0;i<lists.size();i++){																// Constructing Min Heap.
            if(lists[i]!=NULL)																			// Push only non-empty nodes & values.
                pq.push(make_pair(lists[i]->val,lists[i]));
        }
        
        ListNode* res= new ListNode(0);       
        ListNode* temp=res;																				// Final result returned.
        
        while(!pq.empty()){
            pair<int, ListNode*> pr= pq.top();															// Extracting the min. value.
            res->next= new ListNode(pr.first);															// Adding values to final result.
            //cout<<"Currently pushed value is: "<<pr.first<<endl;
            if(pr.second->next!=NULL){																	// If next exist, then push into Min Heap.
                ListNode* node= pr.second->next;
                pq.push(make_pair(node->val, node));
            }
            pq.pop();																					// Remove the curr. min value.
            res=res->next;																				// Iterating the result LL.
        }
        
        
        return temp->next;																				// Returning the result LL.
    }
};
