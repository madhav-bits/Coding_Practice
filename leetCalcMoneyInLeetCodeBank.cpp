/*
*
//******************************************************1716. Calculate Money in Leetcode Bank.******************************************************

https://leetcode.com/problems/calculate-money-in-leetcode-bank/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4
10
20
21
22
27
28
29
990
991
1000
999



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is formula based. Since there is a pattern in which money gets added, I had formulated this process and used it to get total money.







class Solution {
public:
    int totalMoney(int n) {
        int res=0;
        vector<int>prefixSum({0,1,3,6,10,15,21});														// To easily get money added on rem. days.
        int weeks=n/7, days=n%7;																		// Calc. #total weeks and incomplete week's days.
        res=28*weeks+7*((weeks-1)*weeks)/2;																// Contribution from the complete weeks.
        res+=prefixSum[days]+(weeks*days);																// Contribution from the incomplete week.
        return res;																						// Returning total money deposited.
    }
};
