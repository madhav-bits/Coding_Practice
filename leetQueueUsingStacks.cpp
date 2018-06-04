/*
*
//******************************************************232. Implement Queue using Stacks.***********************************************

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long 
as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["MyQueue","push","push","peek","pop","push","peek","empty"]
[[],[1],[2],[],[],[3],[],[]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. We make sure that the top elem. of the stack is the first elem. pushed into queue, thus the sequence of ints
// will be same as the sequence in queue, as a result all other operations(pop, peek, top, empty) will be exactly same as queue.







class MyQueue {

private:
    stack<int> s1, s2;															// Using two stacks.
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {															// Pushing elem. into stack.
        while(!s1.empty()){														// Inorder to make sure that newly added elem. has to be last
            s2.push(s1.top());													// accessible one, we pop all elem. store them in other stack,
            s1.pop();															// push the curr. value and copy back all elem. into orig. stack.
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp=s1.top();														// Storing the top elem.
        s1.pop();																// Removing the top elem.
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();														// Returning the top value.
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();														// Returning whether queue is empty or not?
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */






