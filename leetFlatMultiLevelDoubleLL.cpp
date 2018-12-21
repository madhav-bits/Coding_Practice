/*
*
//******************************************************430. Flatten a Multilevel Doubly Linked List.***********************************************

You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point 
to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data 
structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

 

Example:

Input:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

Output:
1-2-3-7-8-11-12-9-10-4-5-6-NULL
 



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


// Complex format to write down any test cases.



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we merge Double Linked List with child. We form a new Double LL in merged state. We create a dup
// node with value (-1). We start iterating we make curr. node the next node of res node, if this node has child, we recursively merge those
// children as next nodes of curr. node and return the last node in the children from the recursive call, we continue our curr. iteration, make 
// next node as next node of returned last node from recursive call. Thus, we merge child elements in the process and merge all the nodes to a 
// single-level Double LL.


// Here, I had created an entirely new result Double LL, instead we can restructure provided Double LL into result.





/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    
    Node* flattenList(Node* node, Node* res){
        if(!node) return NULL;												// Base case.
        Node* temp=res;														// Temp. stores res node.
        while(node){														// Iter. all nodes in curr. level.
            temp->next=new Node(node->val, NULL, NULL, NULL);				// Making next node as next node of result node.
            // cout<<"temp: "<<temp->val<<" and next; "<<node->val<<endl;
            temp->next->prev=temp;											
            temp=temp->next;												// Result node moving ahead.
            if(node->child) temp=flattenList(node->child, temp);			// If child present, merging child nodes and ret last node post merging.
            node=node->next;												// Iter. this level.
        }
        return temp;        												// Returning last node from this level after merging.
    }
    
    Node* flatten(Node* head) {
        if(!head) return head;												// Base case of empty List.
        Node* dup=new Node(-1, NULL, NULL, NULL);							// Creating a dup node and making it as head of result.
        flattenList(head, dup);												// Call to merge child nodes into single-level LL.
        dup->next->prev=NULL;												// Removing link b/w dup node and it's next node.
        return dup->next;													// Returning the root of the result(next node of dup node).
    }
};