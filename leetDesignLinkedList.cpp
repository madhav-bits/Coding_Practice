/*
*
//************************************************************707. Design Linked List.*****************************************************

Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly 
linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. 
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all 
nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node 
of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the 
node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
Example:

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
Note:

All values will be in the range of [1, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in LinkedList library.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[2],[1]]



["MyLinkedList","addAtHead","addAtTail","addAtTail","deleteAtIndex"]
[[],[1],[3],[2],[2]]



// Time Complexity: O(n).													// For adding/getting value from indices.  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// For adding/getting value from indices.  
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we implement our own Double LL. Where, for convenience, we maintain two extra nodes named Head, Tail b/w
// whom our LL lies. So, if LL size is 0, then we have only Head, Tail. Here, adding at tail and head are handled specially as asked for. If
// value at index "i" is needed, we iterate till "i-1" index, then join new node b/w curr. node and next node. Same is the case with deleting 
// nodes, we stop at index "i-1" and join curr. and curr->next->next node.








class MyLinkedList {
public:
    /** Initialize your data structure here. */
    
    struct Data{															// New Data Structure we created for Double LL.
        int val;
        Data* next;
        Data* prev;
        Data(int x){
            val=x;
            next=NULL;
            prev=NULL;
        }
    };
    
    int length=0;
    Data* head, *tail;
    
    MyLinkedList() {
        head=new Data(-1);													// Declaring two extra nodes to help maintaining LL.
        tail=new Data(-1);
        head->next=tail;													// Join both of those nodes.
        tail->prev=head;	
        length=0;															// Init. lenght of LL to 0.
    }
    
    void joinNode(Data* first, Data*second, Data* curr){					// Here, first, second are nodes b/w whom curr is inserted.
        curr->next=second;													// Joining newNode to old nodes.
        curr->prev=first;
        second->prev=curr;													// Changing prev, next of first, second nodes.
        first->next=curr;
        return ;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0 || index>=length) return -1;								// Invalid indices to ask for.
        int curr=0;
        Data* temp=head->next;
        while(curr<index){													// Iterating till index "i".
            temp=temp->next;
            curr++;
        }
        return temp->val;													// Returning the value at that index.
    }
    
    void printLL(Data* head){												// Prints the contents of the LL. Used for debugging purpose.
        while(head){
            cout<<"The val: "<<head->val<<endl;
            head=head->next;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Data* newNode=new Data(val);										// Creating new Node.
        joinNode(head,head->next, newNode);									// Calls fn. to insert node b/w head and it's following node.
        length++;															// Inc. the size of the LL.
        // cout<<"The length is: "<<length<<endl;
        // printLL(head);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Data *newNode=new Data(val);				
        joinNode(tail->prev, tail, newNode);								// Calls fn. to insert node b/w tail and it's previous node.
        // printLL(head);
        length++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        // cout<<"Adding at index i: "<<index<<" and length: "<<length<<endl;
        if(index<0 || index>length) return ;								// Invalid indices.
        else if(index==0) return addAtHead(val);							// Edge cases.
        else if(index==length) return addAtTail(val);
        else{
            index--;														// Dec. the target index, as we sought to read index "i-1".
            Data*temp=head->next;
            int curr=0;
            while(curr<index){												// Reaching index "i-1".
                temp=temp->next;
                curr++;
            }
            Data* newNode=new Data(val);									// Creating new node.
            // cout<<"temp val: "<<temp->val<<endl;
            joinNode(temp, temp->next, newNode);							// Insert node b/w index 'i-1' and old index 'i'.
        }
        // printLL(head);
        length++;															// Inc. the size of the LL.
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        // cout<<"Deleting value at index: "<<index<<endl;
        if(index<0 || index>=length) return ;
		else{																// Removing from indices.
            index--;														// Intend to stop at index 'i-1'.
            int curr=-1;
            Data* temp=head;
            while(curr<index){												// Iterating til index 'i-1'.
                curr++;
                temp=temp->next;
            }
            temp->next=temp->next->next;									// Deleting next node and merging curr. and curr->next->next nodes.
            temp->next->prev=temp;
        }
        // printLL(head);
        length--;															// Dec. the size of the LL.
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */