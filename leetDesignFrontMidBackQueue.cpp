/*
*
//***********************************************1670. Design Front Middle Back Queue.***********************************************

https://leetcode.com/problems/design-front-middle-back-queue/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had  tweaked and worked on.


Worked with test cases provided with the question.
["FrontMiddleBackQueue","pushFront","pushBack","pushMiddle","pushMiddle","popFront","popMiddle","popMiddle","popBack","popFront"]
[[],[1],[2],[3],[4],[],[],[],[],[]]



// Time Complexity: O(1).													// For each operation.  
// Space Complexity: O(n).													// For the entire update/query process.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// For each operation.  
// Space Complexity: O(n).													// For the entire update/query process.
// This algorithm is DeQueue based. Here, we maintain two Dequeues, one stores the first half and the other stores the second half. 
// While adding or deleting we make sure that the last element of first dequeue is the middle node of the entire elements. Using Dequeue
// functions we would be able to add or remove elements from start, mid, end positions of elements added.


// The same functionality can also be achieved by using LinkedList structure. Where we maintain three ptrs start, mid, close to track
// the three positions and make additions/deletions and move them accordingly.





class FrontMiddleBackQueue {
public:
    deque<int>first, second;
    
    void firstToSecond(){													// Balances to make sure last elem. in first half is mid.
        second.push_front(first.back());
        first.pop_back();
    }
    
    
    void secondToFirst(){													// Balances to make sure last elem. in first half is mid.
        first.push_back(second.front());
        second.pop_front();
    }
    
    
    FrontMiddleBackQueue() {
        first=deque<int>();
        second=deque<int>();
    }
    
    void pushFront(int val) {
        first.push_front(val);
        if(first.size()>1+second.size()) firstToSecond();
        return ;
    }
    
    void pushMiddle(int val) {
        if(first.size()>second.size()) firstToSecond();
        first.push_back(val);
        return ;
    }
    
    void pushBack(int val) {
        second.push_back(val);
        if(second.size()>first.size()) secondToFirst();
        return ;
    }
    
    int popFront() {
        if(first.size()==0) return -1;
        int res=first.front();
        first.pop_front();
        if(first.size()<second.size()) secondToFirst();
        return res;
    }
    
    int popMiddle() {
        if(first.size()==0) return -1;
        int res=first.back();
        first.pop_back();
        if(first.size()<second.size()) secondToFirst();
        return res;
    }
    
    int popBack() {
        if(first.size()==0 && second.size()==0) return -1;
        if(second.size()==0){												// When there is only one element in the queue.
            int res=first.back();
            first.pop_back();
            return res;
        }
        int res=second.back();												// If >1 element is there in queue.
        second.pop_back();
        if(first.size()>1+second.size()) firstToSecond();
        return res;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */