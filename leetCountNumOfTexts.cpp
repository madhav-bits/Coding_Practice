/*
*
//******************************************************2266. Count Number of Texts.******************************************************

https://leetcode.com/problems/count-number-of-texts/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.






// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. At every stage in DFS, we try to form a key using curr. index, if it's [2,9] except 7,9 then we have three texts
// that curr. num can be part of, so we try to iterate to next three indices or until a diff. char whichever comes first. We form a char with these nums and 
// give DFS call to form texts from rem. right side indices and we store #ways to form texts from 'i' to last index in dp[i]. For 7,9 we try to iter. until 
// next 4 indices or a diff. char whichever comes first. We avoid duplicate calc by using vals in dp array if already calculated. As, we give 4 DFS calls from 
// each index at max. and we use DP array to avoid recalc., the time compexity becomes linearO(n*4)=O(n). In this way we calc. #ways to form texts starting 
// index '0' and ending at last index.







class Solution {
public:
    int mod=1000000007;
    
    void calculateTexts(string& s, int index, vector<int>&v, vector<int>&dp) {
        if(dp[index]!=-1) return ;											// Avoids recalc. #ways to form texts starting 'index' if already calculated.
        int cnt=0;
        for(int i=0;i<v[s[index]-'0'] && index+i<s.length() && s[index+i]==s[index];i++) {// We try to form a char using nums similar to that of at index
            calculateTexts(s, index+i+1, v, dp);							// DFS to get #ways to form texts from rem. indices.
            cnt=(0ll+cnt+dp[index+i+1])%mod;								// Adding #ways until starting 'index'.
        }
        dp[index]=cnt;														// Updating dp array with #ways to form texts.
        return ;
    }
    
    int countTexts(string s) {
        vector<int>v({0,0,3,3,3,3,3,4,3,4});								// #chars each num can form at max.
        vector<int>dp(s.length()+1,-1);
        dp.back()=1;
        calculateTexts(s, 0, v, dp);										// DFS to calc. #ways to form texts from '0'.
        return dp[0];														// Returning #ways to form texts from '0'.
    }
};

