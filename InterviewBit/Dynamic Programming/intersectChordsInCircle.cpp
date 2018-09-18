/*
*
//******************************************************Intersecting Chords in a Circle.***********************************************

https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2


1000

1

23

4

64




// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programing based. We start from the base case of 1 chord. Here, we build the #chords from 1. We inc. the #chords
// in seq. and store #ways given #chords can be formed. In the next iter. we use the new chord, which divides the available points into two 
// parts, each part has #points to form chord from, which we had already calculated, we make use of it. At the end of iter, we get the #possib.
// using giving #chords can be formed.








int Solution::chordCnt(int num) {
    vector<long long int>dp(num+1,0);										// Dp to store #possib. using each #chords.
    int modulus=1000000007;
    dp[0]=1;																// Base cases.
    dp[1]=1;
    if(num<=1) return dp[num];
    for(int i=2;i<=num;i++){												// Building the DP array.
        // cout<<"i: "<<i<<endl;
        for(int j=1;j<2*i;j+=2){											// Dividing the chord space into two parts.
            int sum=((dp[(j-1)/2]*dp[(2*i-j-1)/2])%modulus);				// Calc. #ways using two parts.
            // cout<<"j: "<<j<<" and sum: "<<sum<<endl;
            dp[i]=(dp[i]+sum)%modulus;										// Sum of all ways because of new chord.
        }
        // cout<<endl;
    }
    return dp[num];															// Return #possib. using given #chords.
}
