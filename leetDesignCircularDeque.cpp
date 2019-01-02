/*
*
//**********************************************************641. Design Circular Deque.***************************************************

Design your implementation of the circular double-ended queue (deque).

Your implementation should support following operations:

MyCircularDeque(k): Constructor, set the size of the deque to be k.
insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
getRear(): Gets the last item from Deque. If the deque is empty, return -1.
isEmpty(): Checks whether Deque is empty or not. 
isFull(): Checks whether Deque is full or not.
 

Example:

MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to be 3
circularDeque.insertLast(1);			// return true
circularDeque.insertLast(2);			// return true
circularDeque.insertFront(3);			// return true
circularDeque.insertFront(4);			// return false, the queue is full
circularDeque.getRear();  			// return 2
circularDeque.isFull();				// return true
circularDeque.deleteLast();			// return true
circularDeque.insertFront(4);			// return true
circularDeque.getFront();			// return 4
 

Note:

All values will be in the range of [0, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in Deque library.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]
[[3],[1],[2],[3],[4],[],[],[],[4],[]]




["MyCircularDeque","insertFront","insertLast","getFront","insertLast","getFront","insertFront","getRear","getFront","getFront","deleteLast","getRear"]
[[5],[7],[0],[],[3],[],[9],[],[],[],[],[]]






// Time Complexity: O(1).  													// All operations cost constant time.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// All operations cost constant time.
// Space Complexity: O(n).	
// This algorithm is Vector based. Here, we use 5 vars. A vector to store elements, to track start, close indices of vector, maxm. elements 
// allowed, #elements in vector at any instant. Here, while inserting elements at the front, we dec. the start index value and insert given value
// at that index. While inserting at the end, we inc. the close index and insert given value. While inserting or deleting after the operation, if
// the size of vector is 1, we set start and close indices to be equal. 
// While deleting, if we delete from last, we dec. the last index value and adjust it acc. to mod len value. If deleting from start, we inc. the
// start value and adjust it acc. to mod len indices range. we use start, close indices to return front and rear values respectively. We use 
// occup value to say whether vector is empty/completely filled.









class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    vector<int>v;															// Stores values.
    int len;																// Max. elements allowed.
    int occup;																// #elements in vector.
    int start, close;														// Start, close indices of values in Queue.
    MyCircularDeque(int k) {
        occup=0;															// Init. all vars.
        v=vector<int>(k);
        len=k;
        start=1;
        close=-1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(occup>=len) return false;										// If vector filled, return false.
        occup++;															// Inc. the #values count.
        start--;															// Calc. start index to put new value.
        if(start<0) start=len-1;											// Adjusting index acc. to mod indices.
        v[start]=value;														// Setting value in that index.
        if(occup==1) close=start;											// If size==1, set start=close indices(Unmatches while init. execution).
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(occup>=len) return false;										// If vector filled, return false.
        occup++;
        close=(close+1)%len;												// Calc. close index to put new value.
        v[close]=value;														// Setting value in that index.
        if(occup==1) start=close;											// If size==1, set start=close indices(Unmatches while init. execution).
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(occup==0) return false;											// If empty, return false.
        occup--;															// Dec. the #elements count.
        start=(start+1)%len;												// INc. the start index value.
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(occup==0) return false;											// If empty, return false.
        occup--;															// Dec. the #elements count.
        close--;															// Dec. the close index value.
        if(close<0) close=len-1;											// Adj. index value acc. to mod indices range.
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(occup==0) return -1;												// If #elements is 0, return -1.
        return v[start];													// Return the first value.
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(occup==0) return -1;												// If #elements is 0, return -1.
        return v[close];													//// Return the last value.
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (occup==0);       											// Return whether #elements in vector is 0 or not?
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (occup==len);    											// Return whether #elements in vector is len or not?
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */