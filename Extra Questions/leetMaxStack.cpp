/*
*
//************************************************************716. Max Stack.*****************************************************

Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["MaxStack","push","push","push","top","popMax","top","peekMax","pop","top"]
[[],[5],[1],[5],[],[],[],[],[],[]]



["MaxStack","push","push","popMax","peekMax"]
[[],[5],[1],[],[]]


["MaxStack","push","push","push","push","pop","pop","peekMax"]
[[],[3],[1],[5],[4],[],[],[]]


["MaxStack","push","push","push","push","pop","peekMax","pop","peekMax"]
[[],[3],[1],[5],[4],[],[],[],[]]






// Time Complexity: O(logn).  												// Forming Heap.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(n).	
// This algorithm is based on Stack and Priority Queue based. Here, we maintain to stack to maintain LIFO property of stack. Heap to track
// maxm. value at any instant. When pusing new elem. into stack, we also push it into heap, to get max. value.We also track the seq. of vals pushed
// in by maintaining a vector to track latest val's index. When popping from stack,  we remove the curr. val's index from the map's list. If the 
// curr. val is top of heap, we remove it then, we also remove the all the previously removed elem. from the heap,map after this(If the 
// curr. top's index is not equal to last index in map, then this value had been removed).


// Time Complexity: 
// Push: O(1)
// top:O(1)
// Peek Max:O(1)
// Pop: O(logn)(Ammortized).	
// Pop Max: O(logn)(Ammortized).



class MaxStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>>st;													// Stores the nums.
    unordered_map<int,vector<int>>occur;									// Stores indices of each num in corres. val's list.
    int index=0;															// Uniq. identifies each num.
    priority_queue<pair<int,int>>pq;										// To keep track of max. num.
    MaxStack() {
        
    }
    
    void push(int x) {
        st.push({x,index});													// Pushing into stack, heap with value and index.
        pq.push({x,index});
        occur[x].push_back(index);											// Storing the index in curr. num's list.
        index++;															// INc. the index value.
        return ;
    }
    
    int pop() {
        int curr=st.top().first;											// Temp. storing curr. top value.
        // cout<<"Del node: "<<curr<<" with index: "<<occur[curr].back()<<endl;
        occur[curr].pop_back();												// Removing index value from list in map.
        
        st.pop();															// Removing from the stack.
        if(curr==pq.top().first) pq.pop();									// If the maxm. val==top elem. we remove that also.
        while(!st.empty() &&  occur[st.top().first].back()!=st.top().second){// If the num is already deleted.
            //cout<<"Deleting val: "<<st.top().first<<" with index: "<<st.top().second<<endl;
            st.pop();	
        }
        
        //*******************************This is useful in getting the correct top values at each call of top, peekMax.***********************
        // cout<<"pq top: "<<pq.top().first<<" and index: "<<pq.top().second<<endl;
        while(!pq.empty() &&  occur[pq.top().first].back()!=pq.top().second){// If the num is already removed from stack,heap.
            // cout<<"Deleting val: "<<pq.top().first<<" with index: "<<pq.top().second<<endl;
            pq.pop();
        }
        return curr;  
    }
    
    int top() {
        return st.top().first;													// Returning the top value.
    }
    
    int peekMax() {
        // cout<<"top value: "<<pq.top().first<<endl;
        return pq.top().first;													// Returning the maxm. value.
    }
    
    int popMax() {
      int curr=pq.top().first;													// Temp. storing the to be deleted value.
      int ind=pq.top().second;
      pq.pop();
      occur[curr].pop_back();													// Removing curr. index from back of list.
      if(st.top().first==curr) st.pop();										// If this value is top of stack, then remove it.
      while(!pq.empty() &&  occur[pq.top().first].back()!=pq.top().second){		// If maxm is already deleted, then remove it.
        // cout<<"Deleting val: "<<pq.top().first<<" with index: "<<pq.top().second<<endl;
        pq.pop();
      }
    while(!st.empty() &&  occur[st.top().first].back()!=st.top().second){		// If val. is already deleted, then remove it.
        // cout<<"Deleting val: "<<st.top().first<<" with index: "<<st.top().second<<endl;
        st.pop();
    }
      // cout<<"Delting node with index: "<<ind<<endl;
      return curr;     															// Deleting the maxm. value.
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */