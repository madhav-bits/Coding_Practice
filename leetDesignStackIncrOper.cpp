/*
*
//*********************************************1381. Design a Stack With Increment Operation.******************************************

https://leetcode.com/problems/design-a-stack-with-increment-operation/description/


Design a stack which supports the following operations.

Implement the CustomStack class:

CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack or do nothing if the stack reached the maxSize.
void push(int x) Adds x to the top of the stack if the stack hasn't reached the maxSize.
int pop() Pops and returns the top of stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, just increment all the elements in the stack.
 

Example 1:

Input
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
Output
[null,null,null,2,null,null,null,null,null,103,202,201,-1]
Explanation
CustomStack customStack = new CustomStack(3); // Stack is Empty []
customStack.push(1);                          // stack becomes [1]
customStack.push(2);                          // stack becomes [1, 2]
customStack.pop();                            // return 2 --> Return top of the stack 2, stack becomes [1]
customStack.push(2);                          // stack becomes [1, 2]
customStack.push(3);                          // stack becomes [1, 2, 3]
customStack.push(4);                          // stack still [1, 2, 3], Don't add another elements as size is 4
customStack.increment(5, 100);                // stack becomes [101, 102, 103]
customStack.increment(2, 100);                // stack becomes [201, 202, 103]
customStack.pop();                            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
customStack.pop();                            // return 202 --> Return top of the stack 102, stack becomes [201]
customStack.pop();                            // return 201 --> Return top of the stack 101, stack becomes []
customStack.pop();                            // return -1 --> Stack is empty return -1.
 

Constraints:

1 <= maxSize <= 1000
1 <= x <= 1000
1 <= k <= 1000
0 <= val <= 100
At most 1000 calls will be made to each method of increment, push and pop each separately.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]


["CustomStack","pop","increment","push","increment","increment","increment","pop","increment"]
[[30],[],[3,40],[30],[4,63],[2,79],[5,57],[],[5,32]]



// Time Complexity: O(1).													// Bec. of lazy prop. incr. req. takes constant time.
// Space Complexity: O(n).													// Maxm. stack size.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m).													//#values in stack to be incremented.  
// Space Complexity: O(n).													// Maxm. stack size.
// This algorithm is array based solution. Here, we use a array to keep track of values in the stack. A var called index keeps track of 
// topmost index where newly inserted value gets stored.







class CustomStack {
public:
    int index, cap;
    vector<int>v;															// Array to simulate stack functionality.
    CustomStack(int maxSize) {
        v=vector<int>(maxSize,0);
        index=0;															// Tracks topmost index of array to store next ins. valued.
        cap=maxSize;
    }
    
    void push(int x) {
        if(index==cap) return ;
        v[index++]=x;														// Updating the topmost index with newly inserted value.
        return ;
    }
    
    int pop() {
        if(index==0) return -1;
        int res=v[--index];													// Return the value at topmostIndex-1 index.
        return res;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k, index);i++) v[i]+=val;							// Iter. over the array and increment the values.
        return ;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 //************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// Bec. of lazy prop. incr. req. takes constant time.
// Space Complexity: O(n).													// Maxm. stack size.
// This algorithm is array, Lazy Propagation based solution. Here, we use a array to keep track of values in the stack. We use another
// array to keep track of increment requests we get. We store the value of increment req. upto k values in index 'k-1'. The #values
// to be incremented is min(index, k). We update the actual stack with the increment value if at the time of deletion, the lazy array
// has non-zero value, we add this value to it and we will pass the non-zero value to it's below index, as a result incremented value
// is reached to every index it is supposed to affect. In this way, we avoid iterating over the array to update the values.
 
 
 
 
 
 
 
 
 
 
 class CustomStack {
public:
    int index, cap;
    vector<int>v,lz;
    CustomStack(int maxSize) {
        v=vector<int>(maxSize,0);
        lz=vector<int>(maxSize,0);											// Lazy array to store the increment values.
        index=0;
        cap=maxSize;
    }
    
    void push(int x) {
        if(index==cap) return ;
        v[index++]=x;
        return ;
    }
    
    int pop() {
        if(index==0) return -1;
        v[index-1]+=lz[index-1];											// Adding the lazy array value to topmostIndex-1's value.
        if(index-2>=0) lz[index-2]+=lz[index-1];							// Propagating lazy array's top index value to the bottom.
        lz[index-1]=0;														// Setting the curr. index value to zero.
        int res=v[--index];
        return res;
    }
    
    void increment(int k, int val) {
        // for(int i=0;i<min(k, index);i++) v[i]+=val;
        if(index==0) return ;
        lz[min(k, index)-1]+=val;										// Storing the incr. value in the topmost index to be affected.
        return ;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]


 
 */
 
 
 
 