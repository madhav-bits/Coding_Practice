/*
*
//**********************************************************Tushar's Birthday Party.***************************************************

https://www.interviewbit.com/problems/tushars-birthday-party/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


6 4 6 3 8 3 2
7 1 3 4 2 3 8 6
7 5 3 4 6 2 9 3



// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).
// This algorithm is Dynamic Programming based. Here, we sort the friends capcities in Inc. order, we iterate from lowest to highest capcities
// while storing the min. cost to satisfy them. Thus, reusing them while calc. min. cost for friends with higher capacities. For each friend,
// we iterate over all items, we add min. cost to get [i-curr. item quan] plus curr. item quan and try to minimize this sum. At the end of 
// iteration, we return the sum of min. cost to satisfy each friend.



// dp[i] indicates min. cost to satisfy 'i' quantity.





int findCost(int target, vector<int>vol, vector<int>cost, vector<int>&dp, int prev){
    for(int i=prev;i<=target;i++){											// We iter. over prev. friend's satisfying vol. to curr. friends vol.
        for(int j=0;j<vol.size();j++){										// We iter. over all items available.
            int quan=vol[j];												// Curr. item's quantity.
            if(i-quan>=0) dp[i]=min(dp[i], dp[i-quan]+cost[j]);				// If curr. item is consumable(less quan. than curr. satisfying quan.)
        }
    }
    return dp[target];														// Min. cost to satisfy target/curr. friend.
}

int Solution::solve(const vector<int> &friends, const vector<int> &vol, const vector<int> &cost){
    int res=0;
    vector<int>v;															// Temp. storing the friend's list.
    v=friends;
    sort(v.begin(), v.end());												// Sort them in Inc. order of quantities.
    vector<int>dp(v.back()+1,INT_MAX);										// DP array.
    dp[0]=0;																// Base case.
    int prev=1;																// Tracks friends with closest lesser capacity than curr. friend.
    for(int i=0;i<friends.size();i++){										// Iter. over all friends.
        int ans=findCost(v[i], vol, cost, dp, prev);						// Extract min. cost to satisfy curr. friend.
        res+=ans;															// Sum all min. costs.
        prev=v[i]+1;														// Tracking the prev. friend's capacity.
        // cout<<"the cost: "<<ans<<endl;
    }
    return res;																// Returning the min. cost to satisfy all friends.
}
