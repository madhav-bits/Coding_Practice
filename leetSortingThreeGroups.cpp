/*
*
//******************************************************2826. Sorting Three Groups.******************************************************

https://leetcode.com/problems/sorting-three-groups/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,1,3,2,1]
[1,3,2,1,3,3]
[2,2,2,2,3,3]
[3,2,1,2,2,2,1,1,2,2,3,2,2,1,1,2,2,3,1,1,2]
[1,1,1,1,2,2,2,2,3,3,3,3]
[3,3,3,3,2,2,2,2,1,1,1,1]
[2,2,2,2,1,1,1,1,2,2,2,2,2,3,3,3,3,2,2,2,2,1,1]
[2,2,2,2,2,2,2,2,3,3,3,3,3,1,1,1,1]
[2,2,2,2,2,1,1,1,1,1,3,3,3,3,3]
[1,1,1,1,2,2,2,2]
[2,2,2,2,3,3,3,3]
[1,1,1,1,2,2,2,2]
[1,1,1,1,1]
[2,2,2,2,2]
[3,3,3,3,3,3]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based. For us to get a sorted array, we need that all vals in grp1<all vals in grp2<all vals in grp3. Essentially all
// 1s followed by 2s followed by 3s in orig. array after changes. We keep 3 vars, oneCost, twoCost representing minCost to keep curr. index's val to 1 or 2
// based on var name. 
// While iter. over array, if curr. val  is 2, we try to keep oneCost, twoCost to the minm, in this case we inc. oneCost as we have to change curr. val, for 
// twoCost as the curr. val is already 2 we dont need extraCost but prev. val can be 1 or 2, so make twoCost=min(prevOneCost, prevTwoCost).
// If curr. val is 1, oneCost would remain the same as prev. val is 1, we needn't change any value. For twoCost we need to change curr. val and prev. val can be 
// any of 1 or 2, so twoCost=min(prevOneCost, prevTwoCost)+1. As all the ones/twos until now are in non-dec order, we make all right indices to have val:3, we 
// keep track of #non-3s to the right, so total cost to maintain the curr. state is min(oneCost, twoCost)+nonThreeCount, we iter. over all indices and track the 
// minCost to maintain all possible valid states and return the minCost among them.






class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res=INT_MAX, nonThreeCount=0, oneCost=0, twoCost=0;
        for(int&num:nums) {
            if(num!=3) nonThreeCount++;
        }
        if(nonThreeCount==0) return 0;
        res=nonThreeCount;
        for(int&num:nums) {
            if(num==1) {													// If curr. val is 1.
                twoCost=min(oneCost, twoCost)+1;							// twoCost needs change so we use min of (prev. oneCost, prev. twoCost) +1.
                nonThreeCount--;											// Updating the non-3 vals count.
            } else if(num==2) {												// If curr. val is 2.
                twoCost=min(twoCost, oneCost);								// twoCost can be min of (prev. oneCost, prev. twoCost).
                oneCost++;													// Inc. the oneCost by 1.
                nonThreeCount--;											// Updating the non-3 vals count.
            } else {
                twoCost=min(oneCost, twoCost)+1;							// twoCost needs change so we use min of (prev. oneCost, prev. twoCost) +1.
                oneCost++;													// Inc. the oneCost by 1.
            }
            if(min(oneCost, twoCost)+nonThreeCount<res) res=min(oneCost, twoCost)+nonThreeCount;// Tracking the minCost among all the valid arrangements.
        }
        
        return res;															// Tracking the minCost to attain a valid state.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based. This solution is simplified version of above one, as the number of states are less/3, we used the above one, in
// case of too many states, using an dp array would be optimal. While iter. over array, at an index where val is 'i', minCost to keep 'i' in this index in final 
// state would be minCost to have any num in the range [0,i] in prev. index+oper. needed on curr. index if any. Rather than using a 2d array and iter. over
// [1,i] for every state possible in curr. index. we keep the min. value keep any of [1,i] in prev. index in dp[i] as it prevents iter. for every state also 
// we can update dp[j] where j<i before updating dp[i] for curr. index. We inc. dp[i] by 1, if curr. val!=i. After processing all the indices, we return dp[3],
// as it means minCost to have any of [1,3] in last index, in a valid state of the array.


// When iter. on index: 'ind'.
// dp[i]- minCost to have any of [1,i] in curr. index while array until curr. index is in a valid state.








public:
    int minimumOperations(vector<int>& nums) {
        int res=INT_MAX, nonThreeCount=0, oneCost=0, twoCost=0;
        int dp[4];
        memset(dp, 0, sizeof(dp));
        for(int& num:nums) {
            for(int i=1;i<=3;i++) {
                if(num!=i) dp[i]++;											// Now, dp[i] is minCost to have 'i' in curr. index.
                if(i>1 && dp[i]>dp[i-1]) dp[i]=dp[i-1];						// After updating, dp[i] is minCost to have any of [1,i] in curr. index in a valid state of array.
            }
        }
        return dp[3];														// Returning minCost to have any of [1,3] in the last index in a valid state of array.
    }
};

