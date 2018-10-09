/*
*
//******************************************************Best Time to Buy and Sell Stocks I.***********************************************

https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



5 2 1 3 2 3

2 1 2



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. For an allowed single transaction, we check at every index, if we sell at curr. index,and purchase at lowest 
// possible values in prev. indices and try to update the res variable.








int Solution::maxProfit(const vector<int> &v) {
    int res=0;																// Final result/Max prof value.
    int minm=INT_MAX;														// Minm. of the values encountered till now.
    for(int i=0;i<v.size();i++){											// Iter. over all values of prices.
        if(v[i]>minm) res=max(res, v[i]-minm);								// Get Max profit if sold now and try to update overall max profit.
        minm=min(minm, v[i]);												// Try to update the minm. value encountered till now.
    }
    return res;																// Return the overall max. profit attainable.
}
