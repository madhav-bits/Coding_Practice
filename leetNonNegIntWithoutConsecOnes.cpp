/*
*
//*************************************600. Non-negative Integers without Consecutive Ones.***************************************

https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/


Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do 
NOT contain consecutive ones.

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


1000000000

97439262

93702812

97439262



// Time Complexity: O(32).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is BFS based. Here, since we want the nums to be not have two set bits to be adj. We build nums from 1.
// We add 1 to queue, after extracting every num. if it has zero at end, we left shift by 1 and 1,0 at the end and push it into queue
// if new num is <=num. If curr. num is 1, we do left shift and add 0 at the end and push it into queue. Thus, we encounter all nums
// <=num without consec. bits being set.


// This solution has given TLE, it expects faster & optimized solution.







class Solution {
public:
    int findIntegers(int num) {
        int res=1;
        queue<int>q;
        q.push(1);
        while(!q.empty()){
            res++;															// Counting curr. num to final result.
            int x=q.front();
            q.pop();
            // if(x%2==1 && x*2<=num) q.push(x*2);
            if(x*2<=num) q.push(x*2);										// Adding num*2 to queue.
            if(x%2==0 && (x*2+1)<=num) q.push(x*2+1);						// Adding num*2+1 to queue.
        }
        return res;															// Returning the final count.
        
        
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(32).
// Space Complexity: O(1).	
// This algorithm is Observation and BIT Manipulation based. We use a observation that Fib(n) gives the #nums without consec. set bits
// from [0,(2^n)). We use this observation, we iter. from Least value bit to Highest Value bit, whenever we encounter 1, we add
// fib(i) to the final result. We start from zero psn, since Fib gives values where the highest num is not inclusive, so we inc. num
// by one and apply the logic. An observation is that whenever a bit is set and it's adj. higher val. Bit is 1, we ignore the nums
// observed till then as they would have this two consec. set bits included in their cnt, so, we start afresh. We also update the 
// Fib values, we dec. the num by 2 at every step. At the end of iter. we return the cnt.


// The discussion forum in Leetcode has quite few discussions which discusses various approaches to the solution and clearly explain
// them.
// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/discuss/






class Solution {
public:
    int findIntegers(int num) {
    
        int res=0;															// Tracks the cnt of nums satisfying given condition.
        int x=1, y=2;														// Fib. values.
        num++;																// We inc. the num by 1, as Fib. doesn't 2^n value in cnt.
        while(num){
            if((num&1)!=0 && (num&2)!=0) res=0;								// If curr. and next bit is set, erase cnt till now.
            res+=x*(num&1);													// If curr. bit is 1, add fib. val to final cnt.
            // cout<<"bit: "<<(num&1)<<" and x: "<<x<<endl;
            num>>=1;														// Dec. the num by 2 at every step.
            y+=x;															// Updating the Fib. values.
            x=y-x;
        }
        return res;															// Returning the total cnt.
    }
};








//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(32).
// Space Complexity: O(32).	
// This algorithm is DP+BIT Manipulation based. It uses different observation as the Solution 2. Here, we store the #nums with len.
// k, starting with 0/1 and satisfying given non-consec. ones condition. Here, if given num as k bits, we add total #nums starting
// with zero, ones to final cnt., which also includes nums greater than given num. So,we iterate over given num. calculate # greater
// valued nums and substract them. We go from MSB to LSB, whenever we encounter a bit which is '0' and it's adj. higher bit is '0',
// we can greater valued nums which follow reuirements and got counted to final result, so we substract nums where curr. bit is 
// set to '1'. Whenever we encounter a bit set to '1' and it's adj. higher bit is '1', then all the nums formed by changing the later
// LSB to 1 and forming greater nums satisfying conditions is not possib. as we have two consec. set bits. So, we stop iter. We
// return the cnt at the end of iter.



// This link has clear explanation of the algorithm.
// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/discuss/103749/Java-Solution-DP







class Solution {
public:
    int findIntegers(int num) {
        int res=0;
        vector<int>bits;
        while(num>0){														// Stores the binary rep. from LSB to MSB
            bits.push_back(num&1);
            num=num>>1;
        }
        int len=bits.size();
        vector<vector<int>>dp(len+1,vector<int>(2,0));						// Stores the #nums with index len. satisfying given cdns.
        dp[0][0]=1;															// Init. the values.
        dp[0][1]=1;
        
        for(int i=1;i<len;i++){												// Calc. the #nums with curr. len based on prev. len cnt.
            dp[i][0]=dp[i-1][0]+dp[i-1][1];
            dp[i][1]=dp[i-1][0];
        }
        res=dp[len-1][0]+dp[len-1][1];										// If given num len. is len, we add #nums with len to res.
        // cout<<"INit. res; "<<res<<endl;
        for(int i=len-1;i>0;i--){											// We iter. given num. and remove the greater valued nums from res.
            if(bits[i]==1 && bits[i-1]==1) break;							// We encounter consec. ones in given num.
            if(bits[i]==0 && bits[i-1]==0) res-=dp[i-1][1];					// We encounter consec. zeroes, so that we can set it to 1 and get greater nums.
        }
        
        return res;															// Return the total cnt of nums<=num satisfying given cdns.
        
    }
};

