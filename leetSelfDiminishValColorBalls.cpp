/*
*
//******************************************************1648. Sell Diminishing-Valued Colored Balls.***********************************************


https://leetcode.com/problems/sell-diminishing-valued-colored-balls/



You have an inventory of different colored balls, and there is a customer that wants orders balls of any color.

The customer weirdly values the colored balls. Each colored ball's value is the number of balls of that color you currently have in your inventory. For 
example, if you own 6 yellow balls, the customer would pay 6 for the first yellow ball. After the transaction, there are only 5 yellow balls left, so the 
next yellow ball is then valued at 5 (i.e., the value of the balls decreases as you sell more to the customer).

You are given an integer array, inventory, where inventory[i] represents the number of balls of the ith color that you initially own. You are also given 
an integer orders, which represents the total number of balls that the customer wants. You can sell the balls in any order.

Return the maximum total value that you can attain after selling orders colored balls. As the answer may be too large, return it modulo 109 + 7.

 

Example 1:


Input: inventory = [2,5], orders = 4
Output: 14
Explanation: Sell the 1st color 1 time (2) and the 2nd color 3 times (5 + 4 + 3).
The maximum total value is 2 + 5 + 4 + 3 = 14.
Example 2:

Input: inventory = [3,5], orders = 6
Output: 19
Explanation: Sell the 1st color 2 times (3 + 2) and the 2nd color 4 times (5 + 4 + 3 + 2).
The maximum total value is 3 + 2 + 5 + 4 + 3 + 2 = 19.
Example 3:

Input: inventory = [2,8,4,10,6], orders = 20
Output: 110
Example 4:

Input: inventory = [1000000000], orders = 1000000000
Output: 21
Explanation: Sell the 1st color 1000000000 times for a total value of 500000000500000000. 500000000500000000 modulo 109 + 7 = 21.
 

Constraints:

1 <= inventory.length <= 105
1 <= inventory[i] <= 109
1 <= orders <= min(sum(inventory[i]), 109)


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.



[2,5]
4
[3,5]
6
[2,8,4,10,6]
20
[1000000000]
1000000000


[2,5]
4
[3,5]
6
[2,4,6,6,9,10]
23
[2,8,4,10,6]
20
[1000000000]
1000000000
[1000,1000]
2




// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn)
// Space Complexity: O(1).	
// This algorithm is Sorting based. Here, in order to maximize the total, we sell the balls with max. value first, we calc. the total value in an 
// optimized way. At every step, we calc. the #groups with highest balls cnt.(value), we calc. #cnt spaces we have b/w two consecurive counts, so that
// we can sell our ball in those spaces. If the gap accomodates more spaces than the groups we have, we first fill all the full rounds and then do
// partial rounds with left out balls.








class Solution {
public:
    
    long long int getTotal(int high, int low){								// Calc. total earned by selling balls in gap's occurances.
        return (1ll*high*(high+1))/2-(1ll*low*(low+1))/2;    
    }
    
    int maxProfit(vector<int>& v, int orders) {
        long int res=0, mod=1000000007;
        v.push_back(0);														// Makes it easier processing least count colored balls.
        sort(v.begin(),v.end());											// Sorting based on count and process from maxm. count.
        int cnt=1;
        for(int i=v.size()-2;orders && i>=0;i--,cnt++){
            if(v[i+1]-v[i]>0 && orders>=cnt*(v[i+1]-v[i])){					// orders>groups*gap
                res=(res+(cnt*getTotal(v[i+1],v[i])))%mod;
                orders-=cnt*(v[i+1]-v[i]);									// Dec. orders count based on balls sold in this round.
            }else if(v[i+1]-v[i]>0){										// groups*gap>orders
                int gap=orders/cnt;
                res=(res+(cnt*getTotal(v[i+1],v[i+1]-gap)))%mod;			// Calc. total because of selling full group's balls.
                orders-=cnt*gap;											// Dec. orders count.
                
                long int val=v[i+1]-gap;									// Calc. total because of selling partial group's balls.
                res=(res+orders*val)%mod;
                orders=0;
            }
            // cout<<"res: "<<res<<endl;
        }
        return res;															// Returning the maximum total value.
    }
};

