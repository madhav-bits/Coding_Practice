/*
*
//****************************************2767. Partition String Into Minimum Beautiful Substrings.*******************************************

https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"1011"
"111"
"0"
"0101"
"100101001100101"



// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Progamming based. Here, we do a Top Down DP. At every step we try to form a number starting at curr. index(i), if the formed number
// till index 'j' is Power of 5, we recursively call function to call minm. beautiful substrings starting 'j+1' and we repeat the same step, to prevent recalc.
// we store the minm. beauty substrs count in dp[j+1] and return it to recursive function with start index 'i', here, we try to minimize 1+dp[j] and assign it 
// to dp[i] and return to it's parent recrusive call. If a recursive call for a starting index 'i' which is already visited, we simply return val. dp[i].
// We assign dp[i]=s.length()+1 in case we are not able to form any beautiful substrings from that index, we use s.length()+1 as the max. possible ans is 
// s.length() in case of all 1s in the string. At the end of entire process we return -1 if dp[0] is >=s.length()+1 else we return dp[0].







class Solution {
public:
    int findSubstrings(string&s, int index, vector<int>&dp, unordered_set<int>&st) {// Forming a number starting index: 'index'
        if(index==s.length() || dp[index]!=-1) return dp[index];			// If func. call with this index is already made, return the dp[index].
        if(s[index]=='0') {													// As num wont have leading zeroes, return s.length()+1.
            dp[index]=s.length()+1;
            return s.length()+1;
        }
        int res=s.length()+1, num=0;
        for(int i=index;i<s.length();i++) {
            num=num*2+(s[i]-'0');											// If curr. num is power of 5, recur. call function to find minm substrs form 'i+1'.
            if(num%2==1 && st.count(num)) res=min(res, 1+findSubstrings(s, i+1, dp, st));// Minimize the #substrs starting at 'index'.
        }
        dp[index]=res;														// Assign the minm #substrs to dp array.
        return res;															// Returning the minm #beautiful substrs starting from 'index'.
    }
    
    int minimumBeautifulSubstrings(string s) {
        if(s[0]=='0') return -1;
        vector<int>dp(s.length()+1, -1);
        dp.back()=0;
        unordered_set<int>st;
        int pwr=1, cap=(1<<15);
        while(pwr<cap) {													// As the num. range is small, we pre calc. powers of 5 and store them in set.
            st.insert(pwr);
            pwr*=5;
        }
        findSubstrings(s,0, dp, st);										// Calling func. to calc. minm #beautiful substrs starting from index: 0.
        return (dp[0]>s.length())?-1:dp[0];									// Returing minm #beautiful substrs starting from index: 0.
    }
};

