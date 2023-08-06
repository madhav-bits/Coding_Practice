/*
*
//******************************************************2806. Account Balance After Rounded Purchase.******************************************************

https://leetcode.com/problems/account-balance-after-rounded-purchase/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


9
15
99
89
80
100
1
0
9
10
11
21
25
24
26



// Time Complexity: O(1).  													
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													
// Space Complexity: O(1).	
// This algorithm is observation based. If we add 5 to given purchase value it would bring a num closer to it's closest factor of 10<= itself after change.
// We divide the changed number by 10 and multiple the result with 10 to get the closest multiple of 10, we return (100- factor of 10).







class Solution {
public:
    int accountBalanceAfterPurchase(int purchase) {
        int used=(purchase+5)/10;											// Bring the num closer to the factor of 10<=itself and divide by 10.
        used*=10;															// Get the closest factor of 10.			
        return 100-used;													// Returning the remaining amount after purchase 
    }
};

