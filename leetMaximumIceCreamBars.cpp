/*
*
//******************************************************1833. Maximum Ice Cream Bars.******************************************************

https://leetcode.com/problems/maximum-ice-cream-bars/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,2,4,1]
7
[10,6,8,7,7,8]
5
[1,6,3,1,2,5]
20
[7,3,3,6,6,6,10,5,9,2]
56



// Time Complexity: O(n+m).  																			// n-#range/maxm of ice-cream prices, m-#ice-creams.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).																				// n-#range/maxm of ice-cream prices, m-#ice-creams.
// Space Complexity: O(n).	
// This algorithm is Counting Sort+Greedy based. Here, we iter. over coins and get the #occur. of each valued coin. Then iter. over the occur. array from least to highest value to get max. #ice creams.
// For every value, we calc. #ice-creams we can afford with the money left, we buy as many ice-creams as possible. If ice-creams we can afford<=#coins of this value, we stop the iter. as we won't 
// be able to buy any ice-cream of next greatest value. We add the #ice-creams bought of each value and return the total at the end of iter.







class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxm=*max_element(costs.begin(), costs.end());
        vector<int>occur(maxm+1, 0);
        for(int&cost:costs) occur[cost]++;																// Calc. #occur. of each valued ice-cream.
        int res=0;
        for(int i=1;i<=maxm && coins>=i;i++) {
            int num=coins/i;																			// Calc. #ice-creams we can afford with money left.
            res+=min(num, occur[i]);																	// Adding #ice-creams possible to buy to the result.
            // cout<<"i: "<<i<<" and res: "<<res<<endl;
            if(num<=occur[i]) break;																	// If what we can afford<=available ice-creams, we break the loop.
            coins-=i*occur[i];																			// Removing the coins spent to buy ice-creams in this step.
        }
        return res;																						// Returning the #ice-creams bought.
    }
};

