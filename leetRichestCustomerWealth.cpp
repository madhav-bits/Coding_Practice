/*
*
//******************************************************1672. Richest Customer Wealth.**************************************************

https://leetcode.com/problems/richest-customer-wealth/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked with examples provided with question.



// Time Complexity: O(m*n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, each row contains bank balances of each customer, we get total balance of each customer 
// and return the max. balance among all customers. We iter. all rows, get total of each row and maximize the balanace of a customer 
// and return it.








class Solution {
public:
    int maximumWealth(vector<vector<int>>& v) {
        int res=0, total=0;
        for(int i=0;i<v.size();i++){
            total=0;														// Gets total balance of each customer.
            for(int j=0;j<v[0].size();j++){
                total+=v[i][j];
            }
            res=max(res, total);											// Gets maxm. balance among all customers.
        }
        return res;															// Return maxm. individual balance.
    }
};