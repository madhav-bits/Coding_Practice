/*
*
//******************************************************188. Best Time to Buy and Sell Stock IV.***********************************************

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



3
[1,2,5,3,2,6,5,0,3]

7
[4,2,7,4,9,3,1]




// Time Complexity: O(m*n).  
// Space Complexity: O(min(m,n)).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).
// Space Complexity: O(m).	
// This algorithm is Dynamic Programming based. Here, dp[i] indicates maximum possible profit obtainable for given iter. #numbers considered and
// iter. #transactions considered. We maintain two arrays, one to store profit when ith purchase/ selling is done. As, jth selling depends on
// jth purchaisal of stocks in the allowed range of vals. We calc. the max. profit upon selling curr. value and store it. We also update the 
// profit for jth purchase by based on profit on (j-1)th selling. 

// The optimization step here is to make sure, we escape TLE, if we have #transactions>=days/2, then we can transaction on every increasing value
// seq. in the array.








class Solution {
public:
    
    int quickSolve(int k, vector<int>&v){									// Case, #transactions allowed are>=prices len/2.
        int sum=0;
        for(int i=1;i<v.size();i++){
            if(v[i]>v[i-1]) sum+=v[i]-v[i-1];
        }
        return sum;
    }
    
    int maxProfit(int k, vector<int>& v) {
        if(k>=v.size()/2) return quickSolve(k,v);							// Call quickSolve fn.
        vector<int>sell(k+1,0), buy(k+1,INT_MIN);							// Init. sell and buy array. 
        for(int price:v){													// Iter. over prices.
            for(int j=k;j>0;j--){											// ITer. over transactions.
                sell[j]=max(sell[j], buy[j]+price);							// Maxm. profit when jth selling is made.
                buy[j]=max(buy[j], sell[j-1]-price);						// Max. profit when jth purchase is made.
            }
        }
        return sell[k];														// Returning max. profit after k transactions.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).
// Space Complexity: O(n).	
// This algo. is Dynamic Programming based. Here, we maintain states over #transactions made. We store maxm. profit of i transactions when consi.
// length of array is given array. In the next step, we are working on ith transactions, so now we use profits obtained when i-1th tran. is done.
// of various lengths are stored in various DPS indices.We try to udpate the max. profit possible.



// These links have even clearer explantion for this algo.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/54113/A-Concise-DP-Solution-in-Java




class Solution {
public:
    
    int quickSolve(int , vector<int>&v){									// Special cases of >=len/2 transactions allowed.
        int sum=0;
        for(int i=1;i<v.size();i++){
            if(v[i]>v[i-1]) sum+=v[i]-v[i-1];
        }
        return sum;
    }
    
    int maxProfit(int k, vector<int>& v) {
        if(k>=v.size()/2) return quickSolve(k,v);							// Calling quickSolve.
        vector<int>dp(v.size(),0);                							// Vals. of curr. transaction.
        // vector<int>dp2(v.size(), 0);              						// Vals. from previous transaction.
        for(int i=1;i<=k;i++){												// Iter. over 1 transanctions at a time.
            int maxm=dp[0]-v[0];											// Maxm. profit when ith purchase is made.
            for(int j=1;j<v.size();j++){									// Iter. over all possible allowed days.
                int temp=dp[j];												// Temp. storing prev. iter. max. profit.
                dp[j]=max(dp[j-1], v[j]+maxm);								// Update curr. tran's max. profit. when purchase is done at prev. index.
                maxm=max(maxm,temp-v[j]);									// Updating the max. profit after ith purchase is made.
            }
        }
        return dp.back();													// Returning the max. profit for the given prices, transactions.
    }
};