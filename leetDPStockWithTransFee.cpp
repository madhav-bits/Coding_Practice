/*
*
//**********************************************714. Best Time to Buy and Sell Stock with Transaction Fee.****************************************

Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a 
non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may 
not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.

//These are the examples I had tweaked and worked on.
[1,3,2,8,4,9,2,25,23,15,22,4,7,2,8,1,6]
2



// Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// The algorithm is to save the max. one can earn at any stage if you had selling by then or purchasing by then(last transaction). Returning the
// max one earns if selling is the last transaction one has made.

class Solution {
public:
    int maxProfit(vector<int>& v, int fee) {
        int len=v.size();
        vector<int> buy(len,0);
        vector<int> sell(len,0);
        buy[0]=-v[0]-fee;
        for(int i=1;i<len;i++){
            buy[i]=max(buy[i-1], sell[i-1]-v[i]-fee);	//buy index "i" stock or go on with previous earned money by selling(buy state).
            sell[i]=max(sell[i-1], buy[i-1]+v[i]);		//sell index "i" stock or go on with saved money by selling(sell state).
            //cout<<"i: "<<i<<" buy is: "<<buy[i]<<" and sell is: "<<sell[i]<<endl;
        }
        
        //cout<<"The result is: "<<sell[len-1]<<endl;
        return sell[len-1];								//Returning max. earnings by index "len-1" because of sellings.
    }
};





//********************************************************THIS IS NOT A LEET ACCEPTED CODE.***************************************************
//************************************************************Solution 2:************************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).
// This algorithm checks all previous stock values and chooses teh optimum time to purchase a stock and sell. I don't know why it's not working-
// Half of the test cases are failing. Need to still work on it and improve the code, though being a costly one Time Complexity Wise.


class Solution {
public:
    int maxProfit(vector<int>& v, int fee) {
        int len=v.size();
        vector<int> u(len,0);   //-1 indicates to purchase, 1 indicates to sell.
        int sell=0;             //0 indicates to purchase.
        vector<int>dp(len,0);
        for(int i=0;i<len;i++){
            if(i+1<len && v[i]<v[i+1] && sell==0){//Stocks positions To purchase.
                u[i]=-1;
                sell=1;
            }
            if(i+1<len && v[i]>v[i+1] && sell==1){// Stocks positions To sell.
                u[i]=1;
                sell=0;
            }
        }
        
        if(sell==1 && v[len-1])
            u[len-1]=1;
        
        
        for(int i=0;i<len;i++){
            for(int j=0;j<i;j++){
                if(u[i]==1 && u[j]==-1 && v[j]<=v[i]){
                    //int temp=(dp[j]+v[i]-v[j]-fee);
                    //cout<<"initially dp[i]: "<<dp[i]<<" temp is: "<<temp<<endl;
                    dp[i]=max((dp[j]+v[i]-v[j]-fee), dp[i]);		// Choosing the opti. psn to purchase and sell a stock.
                    //cout<<"dp[j]: "<<dp[j]<<" v[i] val is: "<<v[i]<<" v[j] val is: "<<v[j]<<" dp[i] val is: "<<dp[i]<<endl;
                }
                else if(u[i]!=1 && i>=1)
                    dp[i]=dp[i-1];
            }
            
        }
        
        /*
        for(int i=0;i<len;i++){
            cout<<"index i: "<<i<<" and value is: "<<u[i]<<endl;
            cout<<"index i: "<<i<<" and value is: "<<dp[i]<<endl<<endl;
        }
        */
        //cout<<"The result is: "<<dp[len-1]<<endl;
        return dp[len-1];
    }
};