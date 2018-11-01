/*
*
//******************************************************Best Time to Buy and Sell Stocks II.***********************************************

https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



17 2  5 2 3 2 5 3 5 3 2  1 5 2 -1 6 22 12


5 2 4 2 1 3



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based. Here, as we are allowed to make only one transaction at a time, we maintain two states one for 
// tracking the max. sum one could have after purchaising a stock, max. sum one could have after selling stock(Waiting to buy one). For every
// day, if we want to buy on that then we get the max. on that day, then we get the max. sum after selling till prev. day and subtract today's 
// share value. If we want to sell on that day, then we get max. sum after puchaising a stock till prev. day and sell that stock today. We 
// track the max. of all the selling instances.








int Solution::maxProfit(const vector<int> &v) {
    if(v.size()<=1) return 0;												// Base cases.
    int res=0;
    int maxSell=0, maxBuy=-v[0];											// Track max. sum after purchaising/ selling stock.
    for(int i=1;i<v.size();i++){											// At every index 'i'.
        // cout<<"index i: "<<i<<endl;
        int buy=maxSell-v[i];												// Max sum possible if we buy stock that day.
        int sell=maxBuy+v[i];												// Max sum possible if we sell stock that day.
        
        //res=max(res,buy);													// Not included, as we get maxm. if we sell this stock.
        res=max(res,sell);													// Track max. sum after selling stock.
        
        maxSell=max(maxSell, sell);											// Updating the max. possible sum after selling stock.
        maxBuy=max(maxBuy, buy);											// Updating the max. possible sum after buying stock.
        // cout<<"sell: "<<sell[i+1]<<" and buy: "<<buy[i+1]<<endl<<endl;
    }
    return res;																// Returning the maxm. possible sum.
}
