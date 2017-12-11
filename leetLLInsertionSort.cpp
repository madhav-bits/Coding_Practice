/*

//*******************************************************147. Insertion Sort List.**************************************************

Sort a linked list using insertion sort.


//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/


//Solution 1:
 
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp1=NULL, *temp2=head;				//temp1 contains the new Sorted List.
        while(temp2!=NULL){								//Pushes all the elements in temp2.
            ListNode* temp3=new ListNode(temp2->val);	// New value to be pushed inot temp2.
            ListNode *temp4=temp1, *prev=NULL;
			while(1){
				//cout<<"Inside while with temp3 val is: "<<temp3->val<<endl;
				if(temp4==NULL || temp4->val>temp3->val){
					//cout<<"Inside if with temp3 val: "<<temp3->val<<endl;
					if(prev==NULL){						// When the curr. value is the least value encountered till then.
						temp3->next=temp4;
						temp1=temp3;
					}
					else{								//Placing the curr. vlaue in it's psn in Sorted List.
						prev->next=temp3;
						temp3->next=temp4;
					}
					break;
				}
				prev=temp4;								// Setting the prev value for the next iteration.
				temp4=temp4->next;						//Finding the psn of the curr. value in the Sorted List.
			}
            temp2=temp2->next;							// Iterating, so as to push all the elements into the Sorted List.
        }
        return temp1;									// Returning the temp1 which cotains the Sorted List.
        
    }
};