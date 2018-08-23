/*
*
//****************************************************************292. Nim Game.*********************************************************

You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 
3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number 
of stones in the heap.

Example:

Input: 4
Output: false 
Explanation: If there are 4 stones in the heap, then you will never win the game;
             No matter 1, 2, or 3 stones you remove, the last stone will always be 
             removed by your friend.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4

19


13453353

9

17

16


// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming and Game Theory based. If we have <=3 stones left, we return true. If not, we remove 1 to 3 stones, for 
// each possibility we make a recursive call to find if a person with n-1to n-3 calls can win? If he wins in all 3 scenarios, curr. person looses
// for sure. While calculating the possibilities to win in one scenario, we store the results for lesser number of stones.
// With DP, we get Memory Limit Exceeded error.







class Solution {
public:
    
    bool findWinner(int n,vector<int>&dp){									// Fn. to determine, if a person n stones win.
        //if(n<=3){					
        //    dp[n]=true;
        //    return true;
        //}
		
        if(dp[n]!=-1) return dp[n];											// If val. calc. return the result.
        bool res=false;														// Init. the result var.
        res=findWinner(n-1,dp);												// Find if a person with n-1 stones can win?
        if(!res){															// If next person can't win in this case, curr. person wins.
            dp[n]=true;														// Storing in DP array that curr. person wins.
            return true;													// Return that curr.person wins.
        }
        res=false;
        res=findWinner(n-2,dp);
        if(!res){
            dp[n]=1;
            return true;
        }
        
        res=false;
        res=findWinner(n-3,dp);
        if(!res){
            dp[n]=1;
            return true;
        }
        
        dp[n]=0;															// Curr. person loses, if next person wins in all cases, store in DP.
        return false;														// Return that curr. person loses.
    }
    
    bool canWinNim(int n) {
        vector<int>dp(n+1,-1);												// Init. a dp of size n+1.
        dp[1]=1;dp[2]=1;dp[3]=1;											// Base cases.
        if(n<=3) return true;												// For faster execution, covered some base cases.
        findWinner(n,dp);													// Call fn. to determine if he can win with n stones.										
        //for(auto num:dp) cout<<num<<" "<<endl;
        return (dp[n]==1);  												// Return whether if one can win with n stones.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Math/Logic based. Below link has perfect explanation for this.
// https://leetcode.com/problems/nim-game/discuss/73760/One-line-O(1)-solution-and-explanation






class Solution {
public:
    
    
    
    bool canWinNim(int n) {
        return (n%4!=0);													// IF #stones are divisible by 4, he can't win.
    }
};