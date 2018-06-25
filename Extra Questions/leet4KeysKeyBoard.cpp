/*
*
//**********************************************************651. 4 Keys Keyboard.***************************************************

Imagine you have a special keyboard with the following keys:

Key 1: (A): Print one 'A' on screen.

Key 2: (Ctrl-A): Select the whole screen.

Key 3: (Ctrl-C): Copy selection to buffer.

Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

Now, you can only press the keyboard for N times (with the above four keys), find out the maximum numbers of 'A' you can print on screen.

Example 1:
Input: N = 3
Output: 3
Explanation: 
We can at most get 3 A's on screen by pressing following key sequence:
A, A, A
Example 2:
Input: N = 7
Output: 9
Explanation: 
We can at most get 9 A's on screen by pressing following key sequence:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
Note:
1 <= N <= 50
Answers will be in the range of 32-bit signed integer.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
3
4
9
10
11



// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Greedy Algorithm. We take previous calculations, we copy and paste them repetitively. So, we iterate till i-3 previous
// indices, and calculate curr.count if, prevoius A's of j index, copy pasted(j-i-1), we extract the max. of all those possibilities.








class Solution {
public:
    int maxA(int n) {
        vector<int>dp(n+1,0);           									// Index i-max A's after i moves.
        for(int i=1;i<=n;i++){
            dp[i]=i;														// Init. with min. possible value.
            for(int j=1;j<=i-3;j++){										// Scanning prev. values till i-3 moves.(3 moves for C-A, C-C, C-V)
                dp[i]=max(dp[i],dp[j]*(i-j-1) );							// Extract max possible from prev. values by copy pasting.
            }
        }
        // for(auto num:dp)
        //     cout<<num<<" ";
        return dp[n];														// Returning max A's for N moves.
    }
};