/*
*
//**************************************************************901. Online Stock Span.******************************************************

Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the 
price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].

 

Example 1:

Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
Output: [null,1,1,1,2,1,4,6]
Explanation: 
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.
 

Note:

Calls to StockSpanner.next(int price) will have 1 <= price <= 10^5.
There will be at most 10000 calls to StockSpanner.next per test case.
There will be at most 150000 calls to StockSpanner.next across all test cases.
The total time limit for this problem has been reduced by 75% for C++, and 50% for all other languages.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["StockSpanner","next","next","next","next","next","next","next"]
[[],[100],[80],[60],[70],[60],[75],[85]]


["StockSpanner","next","next","next"]
[[],[80],[70],[90]]


["StockSpanner","next","next","next","next","next","next","next","next","next"]
[[],[75],[70],[85],[80],[60],[65],[80],[70],[70]]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based problem. Here, we iterate over given seq. of stock prices. We store the stocks in a Stack, we remove all previous
// indices to curr. index whose values are<=curr. value. As, the diff. in index of stack's top and curr. index gives #values satisfying given 
// cdn for the curr. index. If the curr. value is greater than prev. value we remove prev.value from Stack, all those top values which are <= curr.
// value, the Stack top's index now indicates first char from the curr. index which obeys given cdns. The diff. in index is the result.








class StockSpanner {
public:
    stack<pair<int,int>>st;													// Stores the Stock value and the index of it.
    int index=0;															// Tracks index of curr. value.
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && st.top().second<=price) st.pop();				// While prev. values are<=curr. value.
        int res=0;															// Result for this index.
        res=(st.empty())?index+1:index-st.top().first;						// If stack is empty, res=index+1, else curr. index-St top's index.
        st.push({index,price});												// Push curr. index, value into Stack.
        index++;															// Inc. the index.
        return res;															// Returning the final result.
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */