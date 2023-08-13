/*
*
//******************************************************1774. Closest Dessert Cost.******************************************************

https://leetcode.com/problems/closest-dessert-cost/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,7]
[3,4]
10
[2,3]
[4,5,100]
18
[3,10]
[2,5]
9
[10]
[6]
15
[]
[10, 20, 50]
[1,2]
47




// Time Complexity: O(m+n*l).												// m-#base, n-#toppings.
// Space Complexity: O(l).													//l=max(target+maxToppingCost, maxBaseCost).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n*l).												// m-#base, n-#toppings.
// Space Complexity: O(l).													//l=max(target+maxToppingCost, maxBaseCost).
// This algorithm is Dynamic Programming based. Here, we can generally use DP find the closest sum to a target, but the complication arises where we were
// notified that sums can even be >target. So, we need to estimate what could be largest possible greater sum which we can use. So, here there are two 
// main observations we need to come up with this estimate:
// One observation is that sum could be result adding of any of the base costs+some combination of toppings where it is >target, we only use this 
// sum=prevSum+topping[i] if it's close to target than prevSum, so we see what would be the max Topping that we can add while the prevSum being farther 
// than sum, for it prevSum<target-maxTop/2 and sum<=target+maxTop/2, if we use maxTop it facilitates all values of toppings.
// Other Observation is that: Here sum of base+any combi. of toppings is so high as a result it's very far from target and using only base would 
// bring sum closer to target.







class Solution {
public:
    int closestCost(vector<int>& base, vector<int>& topping, int target) {
        int res=0;
        int maxTop=*max_element(topping.begin(), topping.end());			// Extracting the max cost of the toppings.
        int maxBase=*max_element(base.begin(), base.end());					// Extracting the max cost of the bases.
        int len=max(target+maxTop/2+1, maxBase+1);
        bool dp[len];
        memset(dp, false, sizeof(dp));
        for(int&cost:base) dp[cost]=true;									// Setting all the base costs to true.
        for(int&cost:topping) {												// Iter. over all toppings.
            for(int i=len-1;i>=cost;i--) {									// Setting any combination of base+toppings to true.
                if(i-2*cost>=0 && dp[i-2*cost]) dp[i]=true;					// Using 1 instance of curr. topping.
                if(dp[i-cost]) dp[i]=true;									// Using 2 instances of curr. topping.
            }
        }
        // for(int i=0;i<len;i++) cout<<"i: "<<i<<" and dp: "<<dp[i]<<endl;
        int diff=0;
        while(target-diff>0 || target+diff<len) {							// We start from target and move in both drns, we return dist. to nearest true.
            if(target-diff>0 && dp[target-diff]) return target-diff;		// This move to left towards zero.
            if(target+diff<len && dp[target+diff]) return target+diff;		// This moves to right towards greater sum value.
            diff++;
        }
        return res;															// Default return value.
    }
};

