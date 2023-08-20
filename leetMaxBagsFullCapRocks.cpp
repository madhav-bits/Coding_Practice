/*
*
//****************************************2279. Maximum Bags With Full Capacity of Rocks.*********************************************

https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,3,4,5]
[1,2,4,4]
2
[10,2,2]
[2,2,0]
100



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Priority Queue+Greedy based. We greedily fill the bags which need lesser #rocks to completely fill them such that we can fill as many bags
// as possible with extra rocks available. We first calc. rem. space in all the bags and push these space vals into min PQ and extract the least gap bags first
// and use rocks to fill them and dec. the extra rocks value and we continue this until either of the extra rocks or bags are done or we don't have enough rocks
// to fill bags anymore. We return how many bags did we fill in the process.


// We can use an array to store the rem. space in bags and sort the array in the way we used PQ here, it gave smaller runtime.






class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int extraRocks) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<rocks.size();i++) pq.push(capacity[i]-rocks[i]);		// Calc. rem space in each bag and push into min PQ.
        int res=0;
        while(extraRocks>=pq.top() && !pq.empty()) {						// Until rocks can fill the bag or all the bags are done.
            res++;															// Inc. the full bags count.
            extraRocks-=pq.top();											// Dec. the extra rocks value.
            pq.pop();
        }
        return res;															// Returning the total #full bags.
    }
};

