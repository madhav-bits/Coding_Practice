/*

//**********************************************************746. Min Cost Climbing Stairs.*******************************************************

On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, 
and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].



//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************


class Solution {
public:
    int minCostClimbingStairs(vector<int>& v) {
        int len=v.size();
        vector<int> price(len+2);
        for(int i=3;i<=len+1;i++){
            price[i]=min(price[i-1]+v[i-2], price[i-2]+v[i-3]); //Price for the ith step.
        }														// As the same step can be reached from two methods, choosing min. val. of them.
        //for(auto num:price)
        //    cout<<"The prices for the step is: "<<num<<endl;
        
        //cout<<"The result is: "<<price[len+1]<<endl;
        return price[len+1];        //We need to reach len+1 th step, as we have to cross all the steps.
    }
};