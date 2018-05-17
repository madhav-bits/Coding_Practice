/*
*
//**************************************************************148. Sort List.*******************************************************

Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,4,2,6,3,2,2,6,5,8,0]
[9,0,2,6,9,-1,-2,-8,7,2,10]
[1]
[]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is MERGE SORT based. We split the LL into two halves, they recursively get split into stage of single/zero nodes. We 
// merge them recursively from bottom to top, until we get the given LL in sorted form.






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
    
    int calcLength(ListNode* head){										// Calc. the length of the passed LL.
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    
    ListNode* mergeSort(ListNode* head, ListNode* tail){				// Merges the passed two LLs into the first one.
        //cout<<"Inside merge with head and tail: "<<head->val<<" and tail: "<<tail->val<<endl;
        ListNode* temp= new ListNode(0);								// To keep track of changed head of first LL.
        temp->next=head;
        ListNode* prev=temp;
        ListNode* curr=head;
        while(curr && tail ){											// While both Lists are not iterated completely.
            if(curr->val>tail->val){									// If first LL has> second LL's curr. iter value, then push it into the
                //cout<<"Merging: "<<tail->val<<" before curr: "<<curr->val<<endl;
                ListNode* temp2=tail->next;								// first LL as first iter.'s prev. node.
                prev->next=tail;
                tail->next=curr;
                prev=tail; // prev=prev->next;  also valid.
                //curr=curr->next;
                tail=temp2;												// Second LL's iterator is updated accordingly to the next value in it.
            }
            else{														// If first iter. < second iter., then simply forward the first iter.
                prev=curr;
                curr=curr->next;
            }
        }
        
        if(tail)														// If there are elem. still in second LL to be added, simply add them
            prev->next=tail;											// to the end of first LL.
        
        return temp->next;												// Return the head of fisrt LL.
        
        
        
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;						// Terminating conditions.
        int len=calcLength(head);											// Calc. length of LL.
        ListNode* temp=head;
        int i=len/2-1;
        while(i>0){															// Finding the separator of the LL.
            temp=temp->next;
            i--;
        }
        ListNode* ptr= temp->next;
        temp->next=NULL;
        ListNode* left=sortList(head);    									// Recursively calling the left half of LL.
        ListNode* right=sortList(ptr);										// Recursively calling the right half of LL.
        return mergeSort(left, right);										// Merging the left and right halves.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Quick Sort based. We chose last ptr as separator, split the curr. LL to two sides of chosen ptr, then recursively work
// on two sides of ptr that way, until single node is reached.






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
    
    ListNode* sortLL(ListNode* start, ListNode* end){                           // Includes start and excludes end.
        if(start->next==end) return start;
        if(start==NULL) return NULL;
        ListNode* origin=new ListNode(INT_MAX);
        ListNode* comp;
        origin->next=start;
        ListNode* prev=origin;
        ListNode* curr=start;
        ListNode* later=start->next;
        
        
        ListNode* temp=start;
        ListNode* temp2;                                            				// Finding the chosen node.
        while(temp!=end){
            temp2=temp;
            temp=temp->next;
        }
        comp=temp2;
        
        
        cout<<"comp. value is: "<<comp->val<<"with start and end value is: "<<start->val<<endl;
        while(curr!=comp){															// Separating val. to either side of chosen node(comp)
            if(curr->val>comp->val){
                prev->next=curr->next;
                curr->next=comp->next;
                comp->next=curr;
                later=later->next;
                curr=prev->next;
            }
            else{
                prev=curr;
                curr=later;
                later=later->next;
            }
        }
        
        cout<<"Calling left and righ fns with comp value: "<<comp->val<<endl;
        origin->next= sortLL(origin->next, comp);									// Recursively calling the left and right parts of comp.
        comp->next=sortLL(comp->next, end);
        return origin->next;
        
        
    }
    
    
    ListNode* sortList(ListNode* head) {
        ListNode* temp=head;
        ListNode* temp2;
        ListNode* origin= new ListNode(INT_MAX);
        origin->next=head;
        while(temp!=NULL){
            temp2=temp;
            temp=temp->next;
        }
        
        ListNode* res=sortLL(head,NULL);												// Calling the fn. with head, NULL as start and end(excl).
        return res;
    }
};

