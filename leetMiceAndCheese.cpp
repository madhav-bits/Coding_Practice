/*
*
//******************************************************2611. Mice and Cheese.******************************************************

https://leetcode.com/problems/mice-and-cheese/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,1,3,4]
[4,4,1,1]
2
[1,1]
[1,1]
2
[4,5,3,2,6,5,4,3,2,10,10,18,19,23,27,4,2,7,20]
[5,7,4,3,8,6,10,19,20,6,4,14,13,3,8,19,11,8,5]
10



// Time Complexity: O(n+klogn).
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+klogn).
// Space Complexity: O(n).	
// This algorithm is Priority Queue based. Here, since we have to K values from first array rest from second arrray, we try to take those values from first array which would increase the total to an greater extent and take the
// rest values from second array. So, we push the arr1[i]-arr2[i] into PQ and extract top K values and add them to res(which adds the diff to form the complete number form array1) and return the res.







class Solution {
public:
    int miceAndCheese(vector<int>& u, vector<int>& v, int k) {
        int res=accumulate(v.begin(), v.end(), 0);														// Calc. sum of second array elements.
        priority_queue<int>pq;
        for(int i=0;i<u.size();i++) {																	// Pushing arr1[i]-arr2[i] into PQ.
            pq.push(u[i]-v[i]);
        }
        while(k) {																						// Extracting top K diff and adding them to res(which forms complete arr1 values for nums which has top K diff).
            res+=pq.top();
            pq.pop();
            k--;
        }
        return res;																						// Returning the total of picked nums.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+nlogk).
// Space Complexity: O(k).	
// This has the same approach as the top solution except that here instead of taking top K diff after pushing all diffs into PQ. We try to maintain a PQ of size k, removing the top values if size exceeds K. Here, since we are
// able to get K least values after entire iteration, we store arr2[i]-arr1[i] and subtract these values from the res which inturn results in adding K values from arr1, rest form arr2. We return res at end of iter.










class Solution {
public:
    int miceAndCheese(vector<int>& u, vector<int>& v, int k) {
        int res=accumulate(v.begin(), v.end(), 0);
        priority_queue<int>pq;
        for(int i=0;i<u.size();i++) {
            pq.push(v[i]-u[i]);
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()) {
            res-=pq.top();
            pq.pop();
            k--;
        }
        return res;
    }
};

