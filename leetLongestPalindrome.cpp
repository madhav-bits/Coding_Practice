/*
*
//**********************************************************409. Longest Palindrome.***************************************************

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abccccddghicccddddddd"

""
"aa"

"a"
"aac"


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is HashMap based. Here, since we know range of keys values. I chose to work with vector, in the first iteration we count the 
// #occurances of all chars in string. In the second iteration, I extract paired chars(even number Ex: #occur. =5, of which 4 can be used in palin-
// -drome). We also check whether we have odd numbered chars or not, if we have we mark/assign a var. with value=1, while caculating final
// result, we check for the mark, if it's 1, I add 1 to even numbered elem. of palindrome.







class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> dp(58,0);															// Stores #occurances of all chars.
        int count=0, ones=0;
        for(int i=0;i<s.length();i++) dp[s[i]-'A']++;									// Counting #occurances of all chars.
        for(int i=0;i<dp.size();i++){
            count+=dp[i]/2;																// Extracting even number of char occurances to form palin.
            if(dp[i]%2!=0) ones=1;														// Checking for odd number occured chars.
            
        }
        //cout<<"The no.of pairs: "<<count<<endl;
        return ones==1? 2*count+1:2*count;												// Returning the palindrome length.
            
    }
};