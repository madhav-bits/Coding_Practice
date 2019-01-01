/*
*
//**********************************************************622. Design Circular Queue.**************************************************

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on 
FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes 
full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store 
new values.

Your implementation should support following operations:

MyCircularQueue(k): Constructor, set the size of the queue to be k.
Front: Get the front item from the queue. If the queue is empty, return -1.
Rear: Get the last item from the queue. If the queue is empty, return -1.
enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
isEmpty(): Checks whether the circular queue is empty or not.
isFull(): Checks whether the circular queue is full or not.
 

Example:

MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false, the queue is full
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4
 
Note:

All values will be in the range of [0, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in Queue library.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]
[[3],[1],[2],[3],[4],[],[],[],[4],[]]




["MyCircularQueue","Rear","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]
[[3],[],[1],[2],[3],[4],[],[],[],[4],[]]





["MyCircularQueue","enQueue","Rear","Front","deQueue","Front","deQueue","Front","enQueue","enQueue","enQueue","enQueue"]
[[3],[2],[],[],[],[],[],[],[4],[2],[2],[3]]







// Time Complexity: O(1).													// All operations cost constant time.  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// All operations cost constant time.  
// Space Complexity: O(n).	
// This algorithm is vector based. Here, we used four vars, one is maxm. values allowed, start and closing values indices in vector, var tracking
// num. of values in vector. Whenever we add a new element, last element may change, so we inc. the index of last element by 1 and mod len, since
// we are assigning values circularly. When removing, our start index inc. by 1 and mod by len, since it's ciruclar indices. These start, close
// indices are useful to return front, rear values directly. occup var. tracking #elements in vector useful to know whether vector is completely 
// filled or not?








class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    vector<int>v;															// Stores valeus.
    int len;																// Stores maxm. #vars allowed.
    int start, close;														// Tracks start, close indices of vector elements.
    int occup;																// Tracks #elements in vector.
    MyCircularQueue(int k) {
        start=0;															// Init. all vars.
        close=-1;
        v=vector<int>(k);													// Init. vector of size k.
        len=k;
        occup=0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(occup>=len) return false;										// If vector compl. filled, return false.
        if(occup<len){														// Not filled.	
            occup++;														// INc. the filled size.
            close=(close+1)%len;											// Calc. index for next value to be placed.
            v[close]=value;													// Placing value in last most index.
            return true;								
        } 
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(occup==0) return false;											// If vector is empty, return false.
        occup--;															// Dec. the filled elements size.
        start=(start+1)%len;												// Moving on to new first value index.
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(occup==0) return -1;												// If vector is empty, return -1.
        return v[start];													// Return first value in vector.
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(occup==0) return -1;												// If vector is empty, return -1.
        return v[close];													// Return last value in vector.
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (occup==0);													// Return whether vector is empty or not?
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (occup==len);												// Return whether vector is full or not?
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */