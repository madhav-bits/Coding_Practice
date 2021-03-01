/*
*
//******************************************************1167. Minimum Cost to Connect Sticks.*************************************************

https://leetcode.com/problems/minimum-cost-to-connect-sticks/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[2,4,3]
[1,8,3,5]
[4,9,3,6,12,15,16,3]


// Time Complexity: O(nlogn).												// 2n-removing and n-adding elements for joining sticks.  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// 2n-removing and n-adding elements for joining sticks. 
// Space Complexity: O(n).	
// This algorithm is Priority Queue based. Here, since we want to minimize the cost, at every step we chose two sticks with minm lengths and join, so
// that we haven't spent any extra money for joining two sticks(Dec. sticks by one). After joining we add this stick into PQ, so that we can get next
// two minm. sticks, we repeat this process until we have one stick left.








class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int res=0;
        // sort(v.begin(),v.end());
        priority_queue<int,vector<int>,greater<int>>pq;						// Declaring Min PQ.
        for(int num:sticks) pq.push(num);
        while(pq.size()>=2){												// Until atleast two sticks are available.
            int val1=pq.top();												// Extracting two least length sticks.
            pq.pop();
            int val2=pq.top();
            pq.pop();
            res+=val1+val2;													// Adding the joint stick into PQ.
            pq.push(val1+val2);
        }
        return res;															// Returning the total cost for joining sticks.
    }
};