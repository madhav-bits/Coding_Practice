/*
*
//********************************************************************Vowels.*************************************************************

https://www.interviewbit.com/problems/vowels/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



1

2


3


4

10


10001



99999

100000




// Time Complexity: O(n).  
// Space Complexity: O(k).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(k).	
// This algorithm is Dynamic Programming based. Here, we iterate from 2 to target num, at each stage, we store the #strings ending with 
// a,e,i,o,u respectively in DP array. When we are at row 'i', this means we are calculating #strings with length 'i', while calculating
// strings ending with char 'a', it has to have a 'i-1' length string ending with either 'i'/'o', we get #strings with length 'i-1' ending 
// with prev. row of DP array and add them to get 'i' length strings ending with 'a'. As, here curr. row values depend on prev. row values,
// we maintain only 2 rows, at the end of iteration, we add #strings ending a/e/i/o/u and return them.



// Here, dp[i][0]  is #strings of length 'i' ending with char 'a'.
// Here, dp[i][1]  is #strings of length 'i' ending with char 'e'.
// Here, dp[i][2]  is #strings of length 'i' ending with char 'i'.
// Here, dp[i][3]  is #strings of length 'i' ending with char 'o'.
// Here, dp[i][4]  is #strings of length 'i' ending with char 'u'.






int Solution::solve(int num) {
    if(num==1) return 5;													// Base case.
    int mod=1000000007;														// Defining mod value.
    vector<vector<long int>>dp(2,vector<long int>(5,0));					// Init. DP array.
    dp[1][0]=1; dp[1][1]=1; dp[1][2]=1; dp[1][3]=1; dp[1][4]=1;				// Init. #strings with 1 length.
    for(int i=2;i<=num;i++){												// Iter. over all string lengths.
        for(int j=0;j<=4;j++){												// Iter. over all ending chars.
            dp[i%2][j]=0;													// Resetting the value in DP index.
            if(j==0) dp[i%2][j]=(dp[(i-1)%2][2]+dp[(i-1)%2][3])%mod;		// Calc. curr. length #strings based on prev. row values.
            else if(j==1) dp[i%2][j]=((dp[(i-1)%2][0]+dp[(i-1)%2][2])%mod+dp[(i-1)%2][4])%mod;
            else if(j==2) dp[i%2][j]=(dp[(i-1)%2][0]+dp[(i-1)%2][1])%mod;
            else if(j==3) dp[i%2][j]=(dp[(i-1)%2][2]+dp[(i-1)%2][4])%mod;
            else if(j==4) dp[i%2][j]=(dp[(i-1)%2][2]+dp[(i-1)%2][3])%mod;
        }
    }
    long res=0;																// Stores final result.
    for(int j=0;j<=4;j++){													// Iter. over all clmns in last row.
        // cout<<"val: "<<dp[num%2][j]<<endl;
        res=(res+dp[num%2][j])%mod;											// Adding all values.
    }	
    return res;																// Returning the #strings of length 'num' ending with vowels.
}
