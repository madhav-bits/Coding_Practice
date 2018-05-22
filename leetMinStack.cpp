/*
*
//**************************************************************155. Min Stack.*******************************************************

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]


["MinStack","push","push","push","getMin","pop","top","getMin", "push", "push","pop","getMin"]
[[],[-2],[0],[-3],[],[],[],[],[-5],[-9], [],[]]



// Time Complexity: O(1).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm is stack based. We maintain two stacks s1- which contains all pushed elem. s2- which contains only min. values at diff. pts of
// time. When pushed we push into both stacks, when removed, we remove form s1 directly, if the removing top of s1 has same value as that of s2,
// then only we remove the top of s2 also, This way, we perform all activities in O(1) time.








class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1, s2;																	// Two stacks to contain values.
    
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);																		// Push into stack.
        if(s2.empty() || x<=s2.top()) s2.push(x);										// If to be pushed is new min. then only push into stack.
    }
    
    void pop() {
        if(s1.top() == s2.top()) s2.pop();												// If to be removed val. is minValue, then pop from s2.
        s1.pop();																		// pop from s1.
        
    }
    
    int top() {
        return s1.top();																// Top of s1.
    }
    
    int getMin() {
        return s2.top();																// Get Min value.
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
 
 
 
 
 
 
 
 //************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).							// This doesn't meet question's requirements.
// Space Complexity: O(n).	
// This algorithm is silly/Naive implementation of the Min Stack using Min Heaps.




 
 

class MinStack {
public:
    /** initialize your data structure here. */
    struct comparator{                                                      		// Implements Min Heap on first value of pair.
        bool operator()(const auto& lhs, const auto& rhs){
            return lhs.first>rhs.first;
        }
    };
    
    
    stack<pair<int, int>> st;														// Each value has a unique index value.
    map<int, int>m;																	// Keeps track os popped index values.
    int index=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator>pq;			// Min Heap.
    
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(make_pair(x,index));
        pq.push(make_pair(x,index));
        index++;
    }
    
    void pop() {
        m[st.top().second]=1;														// Updating popped values in map.
        //cout<<"adding to map value: "<<st.top().first<< " and index: "<<st.top().second<<endl;
        st.pop();																	// Pop from s1.
    }
    
    int top() {
        return st.top().first;														// Returning Top Value.
    }
    
    int getMin() {
        //cout<<"Begin initial: "<<pq.top().second<<endl;
        while(!m.empty() && m.count(pq.top().second)==1){							// Removing the minValues which were already removed.
            //cout<<"Removing top which have been deleted: "<<pq.top().second<<endl;
            pq.pop();
        }
        return pq.top().first;														// Returning MinValue.
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */