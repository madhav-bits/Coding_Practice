/*
*
//******************************************************225. Implement Stack using Queues.***********************************************

Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long 
as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["MyStack","push","push","push","top","pop","pop","empty"]
[[],[1],[2],[3],[],[],[],[]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is queue based. We implement Stack using queue, where queue's front represent the top of the stack. The main logic is to mainta.
// the int in the sequence as in stack. If we have to insert a new elem., we delete all elem. from the front and insert them from the back, making
// sure, that the newly inserted elem. is the front elem. of the queue.







class MyStack {
private:
    queue<int> q;															// Declaring queue data structure.
	
	
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int len=q.size();
        q.push(x);																// Inserting new elem.
        for(int i=0;i<len;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {																	// Rearranging values to make new elem. front of queue.
        int temp=q.front();
        q.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {																	// Returning the top/front of queue.
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {																// Return whether queue is empty or not?
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
 
 
 
 
 
 
 
 
 //************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Deque based. We implement Stack using Deque, here the implementation is really simple. As, the new elem. is simply pushed onto
// end and accessed directly from the end. Infact popped directly from the end. 
 
 
 
 
 
 class MyStack {
public:
    /** Initialize your data structure here. */
    deque<int> q;																// Declaring Deque Data Structure.
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push_back(x);															// Inserting new elem. directly at the end.
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp=q.back();
        q.pop_back();															// Accessing and deleting last elem.
        return temp;
    }
    
    /** Get the top element. */
    int top() {																	// Accessing last elem.
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {																// Returning whether stack is empty or not?
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */