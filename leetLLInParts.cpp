/*

//************************************************725. Split Linked List in Parts**********************************************

Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to 
some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or 
equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input: 
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].
Example 2:
Input: 
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
Note:

The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].


//Time Complexity: O(n).
// Space Complexity: O(n). (In precise it is n/k).

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* temp1=root, *temp2=root;
        vector<ListNode*> v;
        int count=0, quo, rem;
        //cout<<" No. of parts: "<<k<<endl;
        while(temp1!=NULL){
            count++;
            temp1=temp1->next;
        }
        //cout<<"Count is: "<<count<<endl;
        quo=count/k;
        rem=count%k;
        
        int a=0;
        for(int i=0;i<k;i++){
            ListNode* temp3=new ListNode(0);// Creating a new LL ptr.
            ListNode* temp4=temp3;//Copying it's header in another LL ptr.
            for(int i=0;i<quo;i++){
                temp3->next=new ListNode(temp2->val);// Pushing given LL values into another temp. new LL.
                temp2=temp2->next;// Moving through the LL's elements.
                temp3=temp3->next;// Moving through the new LL's elements.
            }
            if(a<rem){
                temp3->next=new ListNode(temp2->val);//Passing an extra val. into new LL rem. no. of times-
                temp2=temp2->next;//-, as the diff. has to be less than one.
                
            }
            v.push_back(temp4->next);// Passing from second val. of LL as the first value is zero.
            a++;
        }
        return v;
    }
};