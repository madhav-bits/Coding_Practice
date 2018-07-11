/*
*
//******************************************************634. Find the Derangement of An Array.***********************************************

In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.

There's originally an array consisting of n integers from 1 to n in ascending order, you need to find the number of derangement it can generate.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
Note:
n is in the range of [1, 106].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


100000


1000000


10

12

4

1

2


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Number of derangements for a number of elem. depend on previous two numbers of elements. For 
// derangements for num-N, we need to append/replace any char in already derange array of nums-(N-1), thus preserving it's deranged state. We can
// also get deranged state by swapping the only int in original place(else all deranged nums of len(N-2)) with curr. num. Thus, our curr. answer
// depends on prev. two values. 









class Solution {
public:
    int findDerangement(int n) {
        if(n==1) return 0;													// Base cases.
        if(n==2) return 1;													// Base cases.
        vector<long>dp(n+1,0);												//Tracks deragned nums. count at each length.
        dp[2]=1;															// Setting the initital value.
        for(int i=3;i<=n;i++){
            // cout<<"Curr. i: "<<i<<endl;
            // long sum1=dp[i-1]*(i-1), sum2=dp[i-2]*(i-1);
            dp[i]=(dp[i-1]*(i-1)+dp[i-2]*(i-1))%1000000007;					// Curr. value depends on prev. two values.
            // cout<<"Curr. value: "<<dp[i]<<endl;
        }
        return dp[n];														// Returning the #deranged combinations for curr. length.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based. Number of derangements for a number of elem. depend on previous two numbers of elements. For 
// derangements for num-N, we need to append/replace any char in already derange array of nums-(N-1), thus preserving it's deranged state. We can
// also get deranged state by swapping the only int in original place(else all deranged nums of len(N-2)) with curr. num. Thus, our curr. answer
// depends on prev. two values. 


// This algo. is same as above one. Here, we have used three vars to keep track of prev. 2 len's #derange combinations, and use them in calc.
// #derangements for curr. length.




class Solution {
public:
    int findDerangement(int n) {
        if(n==1) return 0;
        if(n==2) return 1;
        long prev1=1,prev2=0;												// Tracks #derangements for prev. 2 lengths.
        for(int i=3;i<=n;i++){
            // cout<<"Curr. i: "<<i<<endl;
            long temp=(prev1*(i-1)+prev2*(i-1))%1000000007;					// Calc. #derangements for curr. length.
            prev2=prev1;													// Updating the tracking vars.
            prev1=temp;
            // cout<<"Curr. value: "<<dp[i]<<endl;
        }
        return prev1;														// Returning the #derangements for curr. length.
    }
};