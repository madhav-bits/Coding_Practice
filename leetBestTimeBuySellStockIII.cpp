/*
*
//**************************************************123. Best Time to Buy and Sell Stock III.*******************************************

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,3,5,0,0,3,1,4]


[1,2,3]

[2,1,5]





// Time Complexity: O(k*n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programmin based. As, we are allowed two transactions, I had stored the profit obtained from one transaction in the
// DP array. In the inner loop, we iter. over subarray, get the profit for second transaction (maximize it), add it to profit obtained at fol
// -lowing subarrrays, and update the overall result.






class Solution {
public:
    int maxProfit(vector<int>& v) {
        vector<int>dp(v.size(),0);											// Store the profit obtained from first transaction.
        int res=0;															// Stores the final result.
        for(int i=v.size()-1;i>=0;i--){										// Iter. over prices(various days where second stock is purchased).
            int maxm=v[i];													// Maxm price to sell second stock.
            for(int j=i+1;j<v.size();j++){									// Iter. over following day when second stock is purchased.
                res=max(res,(maxm-v[i])+dp[j]);								// Calc. profit+first stock profit and update final result.
                maxm=max(maxm,v[j]);										// Update the max. price to sell.
            }
			dp[i]=maxm-v[i];												// Update the max profit for this purchase date.
			res=max(res,dp[i]);												// Update the final result.
        }
        //for(auto num:dp)
        //    cout<<num<<" ";
        return res;
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(k*n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programmin based. Since, Profit for the kth transaction depends on {k-1)th transaction, we maintain DP arrays,
// to track max. profit obtainable for various days given. We return the max. profit obtainable for the given entire days. buy[1] is max. profit
// one can get of purchaisal following first stock selling. sell[1] is the max. profit obtainable for 2 transactions.

// These links has even clearer explantion for the below algo.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1).
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution



class Solution {
public:
    int maxProfit(vector<int>& v) {
        vector<int>buy(2,INT_MIN);											// Tracks max. profit obtainable after purchaisals.
        vector<int>sell(2,0);												// Tracks max. profit obtainable after selling.
        for(auto price:v){													// Iter. over given possible days.
            sell[1]=max(sell[1],buy[1]+price);								// Trying to update the profit after second transaction.
            buy[1]=max(buy[1],sell[0]-price);								// Trying to udpate the profit after second purchaisal.
            sell[0]=max(sell[0], buy[0]+price);								// Trying to update the profit after first transaction.
            buy[0]=max(buy[0], -price);										// Trying to update the profit after first purchaisal.
        }
        return sell[1];														// Return the max. profit after 2 transactions in given days.
    }
};












//********************************************************Solution 3:*******************************************************
//**************************************************THIS IS LEET ACCEPTED CODE.********************************************
// Time Complexity: O(2*n).
// Space Complexity: O(n).	
// This algorithm is Memoization based solution. Here, since we need atmost two transactions, we keep track of single 
// transactions done from both the ends, at leftMax[i] we store the maxm transaction possible till index-i, similary 
// rightMax[i] indicates maxm value transaction that could have happened starting index-i. We assign the maxm. of the 
// two values to the res var. In the third iteration, we iter. over entire array and sum up leftMax[i]+rightMax[i+1] and
// try to maximize the result value.






class Solution {
public:
    int maxProfit(vector<int>& v) {
        
        if(v.size()<=1) return 0;
        vector<int>leftMax(v.size(),0), rightMax(v.size(),0);
        int minm=v[0], maxm=0;
        for(int i=1;i<v.size();i++){
            maxm=max(maxm, v[i]-minm);
            leftMax[i]=maxm;
            minm=min(minm,v[i]);
        }
        int res=maxm;
        int sell=v.back();maxm=0;
        for(int i=v.size()-2;i>=0;i--){
            maxm=max(maxm, sell-v[i]);
            rightMax[i]=maxm;
            sell=max(sell,v[i]);
        }
        res=max(res, maxm);
        for(int i=0;i<v.size()-1;i++){
            res=max(res, leftMax[i]+rightMax[i+1]);		// Adding the maxm. transaction upto "i" and maxm. trans from "i+1".
        }
        return res;
    }
};
