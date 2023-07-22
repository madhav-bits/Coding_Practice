/*
*
//******************************************************2240. Number of Ways to Buy Pens and Pencils.******************************************************

https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


20
10
5
5
10
10
11
5
5
1000000
2500
2490



// Time Complexity: O(n/m).													// n-total amount, m-max. cost of the items.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n/m).													// n-total amount, m-max. cost of the items.
// Space Complexity: O(1).	
// This algorithm is observation based. As we have only two type of items to buy, we pick an item and keep on picking it until their is no money left, for
// every selection of item1, we calc. rem. amount and calc. how many of the item2 can be bought, as we may not use entire amount, we add all these possib.
// to res and we move to next selection of items1 bought. In this way we cover every possible combination of item1, item2 can be bought.


// As we have only 2 items we were able to use this relativley faster way to get #combinations of item1, item2. It gets time consuming and complex if #types
// of items are>2, we might have to use mutiple levels of nested loops, in which case Dynamic Programming would make it faster and easier to understand.





class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if(total<cost1 && total<cost2) return 1;							// Base case.
        if(cost1<cost2) swap(cost1, cost2);									
        long long int res=0;
        
        for(int i=0;i<=total;i+=cost1) {									// Iter. over diff.ways to select item1.
            res+=1ll+(0ll+total-i)/cost2;									// Calc. #ways in which we can buy item2 for curr. item1 selection(i/cost1).
        }
        return res;															// Returning the total #ways in which item1, item2 combination can be bought.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, since the order of items bought matters and we only count unique combinations, we ensure to avoid 
// duplicates by processing item1 followed by item2. When at index 'i', we use dp[i-cost1] to determine #ways to buy item1 with 'i' amount. Later, we iter.
// over item2 and use dp[i-cost2] to determine #ways we can buy {item1, item2} combination using 'i' money. Since, we can use any amount of money, we add
// #ways of using all these possible options to use money and return res.


// We avoided iter. over item1 by inc. dp[i] by 1, when i%cost1==0 while iter. over item2, because earlier when we are looping over item1 and calc. #ways, 
// we are actually filling it's multiples of cost1 index with 1 as their only one way to select i=k*cost1 index.




class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if(total<cost1 && total<cost2) return 1;
		if(cost1<cost2) swap(cost1, cost2);
        vector<int>dp(total+1, 0);
        dp[0]=1;
        //for(int i=cost1;i<=total;i++) {
        //    dp[i]+=dp[i-cost1];
        //}
        for(int i=cost2;i<=total;i++) {
			if(i%cost1==0) dp[i]++;											// To reflect the only way to select item1 using 'i' money. 
            dp[i]+=dp[i-cost2];												// Calc. #ways to buy {item1, item2} combination using 'i' money.
        }
        long long int res=accumulate(dp.begin(), dp.end(), 0ll);			// Adding all ways to buy items combinations using full or partial money.
        return res;															// Returning all ways to buy items combinations using full or partial money.
    }
};

