/*
*
//**********************************************************879. Profitable Schemes.***************************************************


There are G people in a gang, and a list of various crimes they could commit.

The i-th crime generates a profit[i] and requires group[i] gang members to participate.

If a gang member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least P profit, and the total number of gang members participating 
in that subset of crimes is at most G.

How many schemes can be chosen?  Since the answer may be very large, return it modulo 10^9 + 7.

 

Example 1:

Input: G = 5, P = 3, group = [2,2], profit = [2,3]
Output: 2
Explanation: 
To make a profit of at least 3, the gang could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.
Example 2:

Input: G = 10, P = 5, group = [2,3,5], profit = [6,7,8]
Output: 7
Explanation: 
To make a profit of at least 5, the gang could commit any crimes, as long as they commit one.
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).
 

Note:

1 <= G <= 100
0 <= P <= 100
1 <= group[i] <= 100
0 <= profit[i] <= 100
1 <= group.length = profit.length <= 100




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



10
5
[2,3,5,0]
[6,7,8,0]





// Time Complexity: O(N*G*P).  
// Space Complexity: O(G*P).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(N*G*P).
// Space Complexity: O(G*P).	
// This algorithm is Dynamic Programming based similar to KnapSackproblem. Here, we build from the base cases of zero target value with zero
// criminals needed to be 1. Then, we build on it with only one gang available, all possible combinations of G,P, and improve it to various #gangs.
// dp[j][k] at ith iteration means #ways to get atleast k-sum with with j criminals usable and only i gangs available. Here, we go through 
// all combinations for every gang added, that gang leaves it's influence/profit it can bring the DP array, by combining with earlier possible
// combinations of gangs generated #ways (DP values).




// This link has even clerer explanation to the similar/below algorithm.
// https://leetcode.com/problems/profitable-schemes/discuss/154617/C++JavaPython-DP?page=2




class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        vector<vector<long long int>>dp(G+1,vector<long long int>(P+1,0));	// 2D DP array over various Criminals, Profits allowed.
        dp[0][0]=1;															// Base case.
        long long int res=0;												// Final result.
        int modu=1000000007;		
        for(int i=0;i<group.size();i++){									// Iter. over all groups.
            // cout<<"i: "<<i<<endl;
            for(int j=G-group[i];j>=0;j--){						// We iter. in reverse drn cause same group may keep on adding to itself(>1 used).
                for(int k=P;k>=0;k--){										// Iter. over all profits.
                    if(dp[j][k]==0) continue;								// If this isn't reachable from the start.
                    if(j+group[i]<=G )										// Updating the index which curr. gang contributes to from curr. index.
                        dp[j+group[i]][min(P,k+profit[i])]=(dp[j+group[i]][min(P,k+profit[i])]+dp[j][k])%modu;
                    if(k+profit[i]>=P && j+group[i]<=G){					// If Final conditions satisfied, add to final result.
                        // cout<<"members: "<<j<<" and money: "<<k<<"overall: "<<k+profit[i]<<endl;
                        res=(res+dp[j][k])%modu;
                    } 
                }
            }
        }
        
        
        
        // for(auto nums:dp){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
		
		
		// for(int i=0;i<=G;i++) res=(res+dp[i][P])%modu;   				// This is alternative to adding to final result in every step.
        
        return res;															// Returning the final result.
    }
};