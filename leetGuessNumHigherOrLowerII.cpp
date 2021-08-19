/*
*
//******************************************************375. Guess Number Higher or Lower II.***********************************************

https://leetcode.com/problems/guess-number-higher-or-lower-ii/


We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

 

Example 1:


Input: n = 10
Output: 16
Explanation: The winning strategy is as follows:
- The range is [1,10]. Guess 7.
    - If this is my number, your total is $0. Otherwise, you pay $7.
    - If my number is higher, the range is [8,10]. Guess 9.
        - If this is my number, your total is $7. Otherwise, you pay $9.
        - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
        - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
    - If my number is lower, the range is [1,6]. Guess 3.
        - If this is my number, your total is $7. Otherwise, you pay $3.
        - If my number is higher, the range is [4,6]. Guess 5.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
            - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
        - If my number is lower, the range is [1,2]. Guess 1.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
            - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.
Example 2:

Input: n = 1
Output: 0
Explanation: There is only one possible number, so you can guess 1 and not have to pay anything.
Example 3:

Input: n = 2
Output: 1
Explanation: There are two possible numbers, 1 and 2.
- Guess 1.
    - If this is my number, your total is $0. Otherwise, you pay $1.
    - If my number is higher, it must be 2. Guess 2. Your total is $1.
The worst case is that you pay $1.
 

Constraints:

1 <= n <= 200



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.



5
6
20
10
200
4



// Time Complexity: O(n^3).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. Here, since there are multiple ways to achieve the minimum sum and their is no specific way to find
// it, we use DP to keep track of all possible ways and return the minm. sum among them.


// dp[start][close] gives the minm. cost to guess any number in the range [start, close].








class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1, vector<int>(n+1,INT_MAX));				// Tracks min. cost for all possible range of nums.
        for(int i=0;i<=n;i++){												// Base Case.
            dp[i][i]=0;
        }
        
        for(int len=2;len<=n;len++){										// Length of subarray under consideration.
            for(int start=1;start+len<=n+1;start++){						// Calc. min cost for all subarrays with this length.
                int close=start+len-1;
                for(int mid=start;mid<=close;mid++){						// Iter. over all possible mid vals.
                    int left=mid-1, right=mid+1;
                    int total=mid;
                    int lt=(left<start)?0:dp[start][left];
                    int rt=(right>close)?0:dp[right][close];
                    total+=max(lt, rt);
                    // if(len==6) cout<<"mid: "<<mid<<" lt: "<<lt<<" and rt: "<<rt<<" and res: "<<dp[start][close]<<endl;
                    dp[start][close]=min(dp[start][close], total);			// Keep track of the minm. total.
                }
                // if(len==6) 
                    // cout<<"start: "<<start<<" and close: "<<close<<" cost: "<<dp[start][close]<<endl;
            } 
        }   
        return dp[1][n];													// Returning minm. cost for the range 1,n.
    }
};

