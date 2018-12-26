/*
*
//********************************************************************Flip Array.***********************************************************

https://www.interviewbit.com/problems/flip-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



3 10 20 4


7 4 9 3 6 2 2 5



// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, we form DP array of length total/2, over which we iterate for each num. in the array.
// In iteration, for a vector's value of k, if dp[i-k] is valid then, dp[i]=dp[i-k]+1, of all these possibilities for each num, we assign the
// min. value. At the end of iteration, we iterattion from the back, the first instant, where we find the value in dp array to be not equal to 
// INT_MAX, we return that value. Here, the question asks for smallest non-negative num. possible to be obtained if selected nums are subtracted
// from remaining nums, for that we try to get max. sum closest to total/2. Which we encounter if we iterate the dp array from the back.


// dp[i] indicates smallest num. of values to be selected to get the sum of i.








void removeSum(vector<int>v, vector<int>&dp, int val){						// Updates dp array, if curr. num is used.
    vector<int>copy(dp);													// Takes a copy of dp array.
    for(int i=1;i<dp.size();i++){											// Iter. over all possible sums.
        if((i-val)>=0 && dp[i-val]!=INT_MAX) copy[i]=min(copy[i], dp[i-val]+1);// If prev. sum possible, we add 1 to get #values to get curr. sum.
    }        
    dp=copy;																// Assigning the update DP array to old DP array.
}

int Solution::solve(const vector<int> &v) {
    int res=INT_MAX;
    int total=0;	
    for(auto num:v) total+=num;												// Calc. total of all nums.
    vector<int>dp((total/2)+1, INT_MAX);									// DP array of total/2, to track min. #values for each sum possible.
    dp[0]=0;
    for(int i=0;i<v.size();i++){											// Call fn. over each num to udpate DP array.
        removeSum(v, dp, v[i]);
    }
    
    // for(int i=0;i<dp.size();i++){
    //     cout<<"index i: "<<i<<" and num: "<<dp[i]<<endl;
    // }
    for(int i=dp.size()-1;i>0;i--){											// We iter. from back, we return the first possible sum obtainable.
        if(dp[i]!=INT_MAX) return dp[i];									// First possible sum, as if that's subtr, we get small remaining val.
    }
}
