/*
*
//******************************************************2303. Calculate Amount Paid in Taxes.******************************************************

https://leetcode.com/problems/calculate-amount-paid-in-taxes/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[3,50],[7,10],[12,25]]
10
[[1,0],[4,25],[5,50]]
2
[[2,50]]
0




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. over different slabs of taxes and calc. amount of income falls into that bracket and calc. it's taxes and add
// to total tax, we keep dec. income by the amount used under curr. slab at evey step and we stop when we finish all our income and return the total tax 
// calculated.







class Solution {
public:
    double calculateTax(vector<vector<int>>& taxes, int income) {
        double res=0;
        int prev=0;
        for(int i=0;income>0 && i<taxes.size();i++) {
            double used=min(income, taxes[i][0]-prev);						// Amount used under current slab of tax.
            res+=used*0.01*taxes[i][1];										// Calc. tax in curr. slab and add to total tax.
            income-=used;													// Dec. inc by amount used in curr. slab.
            prev=taxes[i][0];								
        }
        return res;															// Returning the total tax payed.
    }
};


