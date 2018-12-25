/*
*
//**************************************************600. Non-negative Integers without Consecutive Ones.*******************************************

Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do NOT contain 
consecutive ones.

Example 1:
Input: 5
Output: 5
Explanation: 
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
Note: 1 <= n <= 109




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


951341331


995003971


995548688



4



16


31




// Time Complexity: O(logn).  
// Space Complexity: O(logn).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DFS based. We start from base case of 1, and keep on adding 0s and 1s to it satisfying the given cdns, if newly formed num.
// is <target num. We inc. the result val. by 1, and form new pairs and give recursive calls.

// I had also did it using BFS, it's giving Memory Limit Exceeding errors.









class Solution {
public:
    int res=1;																// Final result.
    int num;																// Given target num.
    void findCombi(long int curr){											// Finds #digits satisfying given cdns.
        if(curr>num) return ;												// Terminating cdn.
        res++;																// If curr. digit <target, inc. the count by 1.
        if(curr%2==0){														// IF LSB is 0, append new bits(0/1) to given bits.
            findCombi(curr*2);												// Give recursive call to find further possibilities to add bits.
            findCombi(curr*2+1);
        }else{																// IF LSB is 1, append new bits(0) to given bits.
            findCombi(curr*2);
        } 
    }
    
    int findIntegers(int n) {
        num=n;        					
        findCombi(1l);														// Give recursive call to find #digits satisfying given cdns.
        return res;															// Returning the final result.
        
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(logn).	
// This algorithm is Dynamic Programming based. We extract the bits from the given num and form a binary rep. Next, we calculate #digits
// satisfying this condition for num. of bits ranging from 1 to bits of target num. For bits of length 'i' ending with '0', they can have 
// 'i-1' the bits either 0/1, so we add #digits with 'i-1' bits ending with 0/1. For bits of length 'i' ending with '1', they can have 'i-1'th
// bit has 1. So, we add #digits with 'i-1' bits and MSB has 0.

// After we need to remove digits with #bits has target num with value>target num. For this purpose, we iter. from MSB to LSB, if we find
// '11' in binary rep. then all the digits formed with these bits in this psns are <target num, so we break iteration. If we have '10', as this
// is the max. value that can be performed with '0' in smaller significant bit, it can't contribute to values >target num(Same is case with
// 01). If we encounter '00', then we can also have formed '01' and counted it, so we remove contribution of '1's in ith bit res-=dp[i-1][1].
// Now, we return the result.


// dp[i][0] is #digits with i bits and 0 as MSB.
// dp[i][1] is #digits with i bits and 1 as LSB.



class Solution {
public:
    int findIntegers(int num) {
        int res=0;
        vector<int>bits;
        while(num>0){														// Extracting binary rep. of given num. 
            bits.push_back(num&1);
            num=num>>1;
        }
        int len=bits.size();
        vector<vector<int>>dp(len+1,vector<int>(2,0));
        dp[0][0]=1;
        dp[0][1]=1;
        
        for(int i=1;i<len;i++){												// Calc. #digits with i bits and 0/1 in MSB.
            dp[i][0]=dp[i-1][0]+dp[i-1][1];
            dp[i][1]=dp[i-1][0];
        }
        res=dp[len-1][0]+dp[len-1][1];										// Total #digits with bits as target num satisfying bits cdns.
        // cout<<"INit. res; "<<res<<endl;
        for(int i=len-1;i>0;i--){											// Iter. from MSB to LSB.
            if(bits[i]==1 && bits[i-1]==1) break;							// IF '11' encountered, break loop.
            if(bits[i]==0 && bits[i-1]==0) res-=dp[i-1][1];					// If '00' encountered, remove contribution of digits with 1s in ith bit.
        }
        
        return res;															// Returning the final result.
        
    }
};