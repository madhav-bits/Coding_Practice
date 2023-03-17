/*
*
//******************************************************2566. Maximum Difference by Remapping a Digit.******************************************************

https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


11891
90
1111
9999
28282
9483785
56848589



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration+Greedy based. Here, we find the first char from left which is not 9 and convert it to 9 to get the max. possible value after remapping.
// We find first char from left that's not 0 and convert those chars to 0 to get least value after remapping. We subtract these two tansformed numbers and return the result.







class Solution {
public:
    int minMaxDifference(int num) {
        int res=0;
        string s=to_string(num);
        int maxIndex=0, minIndex=0;
        while(maxIndex<s.length() && s[maxIndex]=='9') maxIndex++;										// Finding first char. that's not '9'
        if(maxIndex==s.length()) return num;															// If all chars are '9' return the same.
        
        while(minIndex<s.length() && s[minIndex]=='0') minIndex++;										// Finding first char. that's not '0'
        if(minIndex==s.length()) return stoi(string(s.length(),'9'));									// If all chars are '0' we return all '9's.
        
        string maxStr=s, minStr=s;
        
        for(int i=0;i<s.length();i++) {
            if(maxStr[i]==s[maxIndex]) maxStr[i]='9';													// Modifying first non '9' to '9' to get max. possible value.
            if(minStr[i]==s[minIndex]) minStr[i]='0';													// Modifying first non '0' to '0' to get min. possible value.
        }
        return stoi(maxStr)-stoi(minStr);																// Returning their diff. b/w max, min possible values.
    }
};



