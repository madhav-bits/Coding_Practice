/*
*
//****************************************************************Sort List.*********************************************************


https://www.interviewbit.com/problems/sort-list/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


0

1 1

2 2 1


2 1 2


4 1 2 3 4


4 4 3 2 1


5 1 2 3 4 5


5 5 4 3 2 1


7 5 4 3 2 1 7 3
 




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Merge Sort based. As, we have linked lists, we can merge Sorted lists without using extra space. Here, we follow/impement
// Standard Merge Sort.We sort each half individually, one sorte we merge them into one LL. At the end, we get complete sorted LL.








/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int calcLen(ListNode* node){												// calc. len of LL.
    int len=0;
    while(node){
        len++;
        node=node->next;
    }
    return len;
} 

ListNode* mergeLL(ListNode* lt, ListNode* rt, int start, int close){		// Merge two Sorted LLs.
    // cout<<"Prev1: "<<start<<" and close: "<<close<<endl;
    ListNode* prev1=new ListNode(-1), *prev2=new ListNode(-1);				// We create dup nodes and make root of two LLs, their next elem.
    prev1->next=lt;prev2->next=rt;										
    // cout<<"left val: "<<lt->val<<" and right val: "<<rt->val<<endl;
    ListNode* res=prev1;													// Temp. storing final result(First Dup. node).
    while(lt && rt){														// While both nodes are valid.
        // cout<<"lt val: "<<lt->val<<" and rt val: "<<rt->val<<endl;
        if(lt->val > rt->val){												// If second list's curr. value<first list's curr. value.
            // cout<<"Inside if"<<endl;
            ListNode* temp=prev1->next;										// Temp. storing curr. node in first LL.
            ListNode* temp2=rt;												// Temp. storing curr. node in second LL.
            prev2->next=prev2->next?prev2->next->next:NULL;					// Skip/Delete curr. node in second LL.
            
            prev1->next=temp2;												// Bring curr. elem. of second LL to front of curr. elem. in first LL.
            temp2->next=temp;												// Making curr. of first LL, next of second LL's first elem.
            rt=prev2->next;													// Updating curr. node in second LL.
            prev1=prev1->next;												// Moving prev. node in first LL a step ahead(As, new elem. is inserted).
        }
        else{																// Else, moving ptrs in first LL a step ahead.
            prev1=prev1->next;
            lt=lt->next;
        }
    }
    
    if(rt) prev1->next=rt;

    return res->next;
    
}

ListNode* sortLL(ListNode* node, int start, int close){
    // cout<<"start: "<<start<<" and close: "<<close<<endl;
    if(start>close) return NULL;											// No LL present.
    if(start==close) return node;											// Single Node.
    int mid=(start+close)/2;												// Calc. middle node psn.
    // cout<<"mid: "<<mid<<endl;
    
    int dist=start;															// Init. ptr to start of LL.
    ListNode* node2=node;													// Temp. storing start of LL.
    while(dist<mid){														// Iterating till mid of LL.
        node2=node2->next;
        dist++;
    }
    ListNode* fol=node2->next;												// Store next of mid node(start of second LL).
    node2->next=NULL;														// Make next of mid node as NULL.
    
    // cout<<"left: start: "<<start<<" fin: "<<mid<<" close: "<<close<<endl;
    ListNode* lt=sortLL(node, start, mid);									// Call fn. to sort left half of LL.
    
    
    // cout<<"right: start: "<<start<<" fin: "<<mid+1<<" and close: "<<close<<endl;
    ListNode* rt=sortLL(fol, mid+1, close);									// Call fn. to sort right half of LL.
    ListNode* res=mergeLL(lt, rt, start, close);							// Merge the two sorted LLs.
    return res;																// Return the start of combined/Merged LL.
}

ListNode* Solution::sortList(ListNode* root) {
    int len=calcLen(root);													// Calc. len of LL.
    return sortLL(root,0,len-1);											// Call fn. to sort the given LL.
}
