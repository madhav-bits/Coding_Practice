/*
*
//******************************************************2320. Count Number of Ways to Place Houses.******************************************************

https://leetcode.com/problems/count-number-of-ways-to-place-houses/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
2
3
4
5
1000
999
123
987



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based. Here, at every step it's #ways depends only on it's prev. state/adj. house, so we use two vars and update them
// accordingly at every step. We can have a building in curr. psn if there is no building in prev. psn(currTaken=prevNotTaken), we can not have building 
// currently irrespective of building's presence in prev. psn(currNoTaken=prevTaken+prevNotTaken), we use this recurrence relation and build dp values,dp[i]
// shows #ways to build buildings in a sequence of i psns. Since buildings on a side can't be built irrespective of building's positions on other side, we 
//  return dp[i]*dp[i] to get total #ways buildings can be built on both sides of the road.







class Solution {
public:
    int countHousePlacements(int n) {
        int mod=1000000007;
        int taken=1, notTaken=1;
        for(int i=2;i<=n;i++) {
            int temp=notTaken;
            notTaken=(0ll+taken+notTaken)%mod;								// We can not have building irrespective of building in prev. index.
            taken=temp;														// We can have building now only if there is no building in prev. index.
        }
        taken=(0ll+taken+notTaken)%mod;										// Total #ways to build buildings in n consec. psns on a side of the road.
        return (1ll*taken*taken)%mod;										// Total #ways to build buildings on both sides of the road.
    }
};

