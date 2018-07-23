/*
*
//********************************************426. Convert Binary Search Tree to Sorted Doubly Linked List.*************************************

Convert a BST to a sorted circular doubly-linked list in-place. Think of the left and right pointers as synonymous to the previous and next 
pointers in a doubly-linked list.

Let's take the following BST as an example, it may help you understand the problem better:

 


 
We want to transform this BST into a circular doubly linked list. Each node in a doubly linked list has a predecessor and successor. For a 
circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

The figure below shows the circular doubly linked list for the BST above. The "head" symbol means the node it points to is the smallest 
element of the linked list.

 


 
Specifically, we want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its 
predecessor, and the right pointer should point to its successor. We should return the pointer to the first element of the linked list.

The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor 
relationship.

 





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


{"$id":"1","val":4,"left":{"$id":"2","val":2,"left":{"$id":"4","val":1,"left":null,"right":null},"right":{"$id":"5","val":3,"left":null,"right":null}},"right":{"$id":"3","val":5,"left":null,"right":null}}

null


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Inorder Traversal based. We need to connect the nodes based on their Inorder Traversal.Once, a node is reached, we link
// it with the previously visited node. If we don't have any prev. visited node,then curr. is the head of the Double LL. Update the prev. 
// var to curr. node. At every node, we make prev. node the left child of curr. node and the curr. node as prev. node's right child.








/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* head=NULL,*prev=NULL;												// Stores head, prev. visited nodes.
    void constList(Node* node){
        if(!node) return ;													// If NULL enocuntered, return .
        constList(node->left);												// First travel left child.
        if(prev==NULL){														// If no prev. node exists, then curr. is head.
            head=node;
            prev=node;														// Set the prev. to curr. node.
        }
        else{																// If prev. node exists.
            node->left=prev;												// Make prev. node the left child connection to curr. node.
            prev->right=node;												// Make curr. node the right connection of the prev. node.
            prev=node;														// Set the prev. var to curr. node.
        }	
        constList(node->right);												// visit the right child.
        
    }
    
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;												// If empty tree given, return NULL.
        constList(root);													// Call fn. to extract Double LL.
        head->left=prev;													// Make last visited node, the left connection of head node.
        prev->right=head;													// Make head node, the right connection of last visited node.
        
        return head;														// Return the head.
    }
};