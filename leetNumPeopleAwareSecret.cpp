/*
*
//****************************************2327. Number of People Aware of a Secret.****************************************

https://leetcode.com/problems/number-of-people-aware-of-a-secret/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


6
2
4
4
1
3
234
20
30
1000
234
456



// Time Complexity: O(n).  													//n-forget value.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													//n-forget value.
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, dp[i] is #people who knows secret till day 'i' including the people who might have forgot after 'forgot'
// days. So, to get exact number of people who remembers on that day, we remove all the people who knows till dp[i-forgot], which is dp[i]-dp[i-forget].
// When working on an index 'i', we have to find out who remembers and can pass the secret, so we do dp[i-delay](who can pass the secret)-dp[i-forgot](who 
// don't remember) and add their diff. to dp[i], we also add dp[i-1] to it as dp[i] is a prefixSum of all people who knows the secret till day 'i'.







class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,0);
        dp[1]=1;
        int mod=1000000007;
        for(int i=2;i<=n;i++) {
            int k=max(0, i-delay);
            int j=max(0, i-forget);
            dp[i]=(0ll+dp[k]-dp[j]+mod)%mod;								// Calc. people who remembers and can pass the secret to curr. day.
            // cout<<"i: "<<i<<" and cnt: "<<dp[i]<<endl;
            dp[i]=(0ll+dp[i]+dp[i-1])%mod;									// Adding dp[i-1], as dp[i] is prefixSum of #people who knows the secret till 'i'.
            // cout<<"i: "<<i<<" and prefixSum: "<<dp[i]<<endl;
        }
        return (0ll+dp.back()-dp[n-forget]+mod)%mod;						// Returning total #people who remembers the secret by day 'n'.
    }
};

