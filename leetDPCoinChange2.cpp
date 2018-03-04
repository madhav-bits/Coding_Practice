/*
*
//************************************************************518. Coin Change 2.*****************************************************

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that 
make up that amount. You may assume that you have infinite number of each kind of coin.

Note: You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

1,[]
0,[1.2]
5,[2,3]
14[2,1,6]
16[2,4,6,8]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. As, there is a possibility on forming a sum, with same coins in diff combination(Here Order doesn't
// matter).We, first use all coins of a type, form possible no. of possib., then the next type of coins, add no. of possib., this way get the 
// total no. of possib. using all the coins.


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0) return 1;
        if(coins.size()==0) return 0;
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(int j=0;j<coins.size();j++){							// Using coins of a type at a time.
            for(int i=1;i<=amount;i++){								// Forming all possib. sums with types of coins used, till now.	
                //cout<<" For value of i: "<<i<<" coins index is: "<<j<<endl;
                if(i-coins[j]>=0)									// No. of times a sum is formed is equal to no. of times sum-coins[i] is formed.
                    dp[i]+=dp[i-coins[j]];
            }
        }
        //for(auto num:dp)											// Debugging purpose, getting all possib. for all sums starting from 1.
        //    cout<<"The possib. are: "<<num<<endl;
        return dp[amount];
    }
};