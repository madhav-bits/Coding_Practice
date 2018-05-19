/*
*
//******************************************************295. Find Median from Data Stream.***********************************************

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the 
mean of the two middle value.

For example,
[2,3,4] , the median is 3 

[2,3], the median is (2 + 3) / 2 = 2.5 

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["MedianFinder","addNum","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","addNum","findMedian"]
[[],[4],[5],[],[0],[],[7],[],[9],[1],[]]



["MedianFinder","addNum","findMedian"]
[[],[1],[]]

["MedianFinder","findMedian"]
[[],[]]



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Data Structure Utilization based. Here we maintain two Heaps(Max and Min Heaps) Max Heap maintains the lower half of values
// and Min Heap maitains upper half of values, if arranged in ascending order. If Min Heap and Max Heap differ in size by >1 elem. we shift the
// top elem. from the larger heap to other heap, thus we maintain the diff. in size in both heaps to 0/1. While calc. median if a heap's size is
// greater than other one, then just return it's top value(As it will be middle value in asc. order). If both heaps have same size, then calc.
// avg of two heap's top values.



class MedianFinder {
public:
    
    priority_queue<int> maxHeap;                                            	// Contains lower half of numbers.
    priority_queue<int, vector<int>, greater<int>> minHeap;                  	// Contains upper half of numbers.
    
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //cout<<"Pushing into heaps num: "<<num<<endl;
        if(maxHeap.size()==0){													// Pushing the first value into MaxHeap.
            maxHeap.push(num);
            return ;
        } 
        if(num<=maxHeap.top()) maxHeap.push(num);								// If val.<=MaxHeap's top value, push into MaxHeap.
        else minHeap.push(num);													// Else, push into minHeap.
        
        int temp;
        if(maxHeap.size()>minHeap.size()+1){									// If differ in size by >1, then shift top value into smaller one.
            temp=maxHeap.top();
            //cout<<"Transfer. temp into minHeap."<<temp<<endl;
            maxHeap.pop();
            minHeap.push(temp);
        }
        else if(minHeap.size()>maxHeap.size()+1){
            temp=minHeap.top();
            //cout<<"Transfer. temp into maxHeap."<<temp<<endl;
            minHeap.pop();
            maxHeap.push(temp);
        }
        
    }
    
    double findMedian() {
        double l1,l2;															
        if(!maxHeap.empty())													// Extract top values if size>0.
            l1=double(maxHeap.top());
        if(!minHeap.empty())													// Extract top values if size>0.
            l2=double(minHeap.top());
        if(maxHeap.size()==minHeap.size()) return (l1+l2)/2;					// If equal size, return avg. of two top values.
        else if(maxHeap.size()>minHeap.size()) return l1;						// If size is greater, then return that top value of larger heap.
        else return l2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */