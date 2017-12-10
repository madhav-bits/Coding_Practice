/*

//***************************************************215. Kth Largest Element in an Array.**********************************************

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.


//Time Complexity: O((n-k)logn).
// Space Complexity: O(n)(tita(n-k)).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/


//Solution 1:
// The Idea is to maintain a Priority Queue of size n-k. As in the question it's been kth largest which translates to (n+1-k)th elem.-
// in ascending order of elements. 
 
class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        int len=v.size();
        k=len+1-k;
        priority_queue<int> q;
        for(int i=0;i<k;i++)				//Intiazling the Priority Queue of size (n+1-k).
            q.push(v[i]);
        for(int i=k;i<len;i++){
            if(v[i]<=q.top()){				// If an int. value <= current PQ's top is found, pushed into PQ, as these values less than-
                q.pop();					//- the req. value-> output.
                q.push(v[i]);
            }
        }
        //cout<<"the result is: "<<q.top()<<endl;
        return q.top();
    }
};