/*
*
//******************************************************703. Kth Largest Element in a Stream.***********************************************

Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth 
distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from 
the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.

Example:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
Note: 
You may assume that nums' length ≥ k-1 and k ≥ 1.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["KthLargest","add","add","add","add","add"]
[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]


["KthLargest","add","add","add","add","add","add"]
[[3,[4,5,8,2]],[3],[1],[10],[2],[4],[3]]



// Time Complexity: O(nlogk).  
// Space Complexity: O(k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogk).
// Space Complexity: O(k).	
// This algorithm is Priority Queue based(Min Heap). Here, we try to maintain a heap size =k, at any instant(not required though). If the heap
// reached target size and curr. val is greater than top of minHeap, then we pop the top elem. and add the curr. elem. to heap.Then, return the
// updated top value of minHeap.





class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;						// MinHeap initialization.
    int maxLen;																// Stores psn of maxValue to be returned.
    KthLargest(int k, vector<int> v) {
        maxLen=k;
        for(int i=0;i<v.size();i++){										// Pushing vector's elem. into heap.
            if(pq.size()<k) pq.push(v[i]);									// If size<target psn, just push into heap.
            else if(pq.size()==k && v[i]>pq.top()){							// If size is target size and curr. val>top of heap.
                pq.pop();													// Pop the curr. top.
                pq.push(v[i]);												// Push the curr. val.	
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<maxLen) pq.push(val);									// If size<target psn, just push into heap.
        else if(pq.size()==maxLen && pq.top()<val){							// If size is target size and curr. val>top of heap.
            pq.pop();														// Pop the curr. top.
            pq.push(val);													// Push the curr. val.	
        }
        return pq.top();													// Return the kth largest value of stream.
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */