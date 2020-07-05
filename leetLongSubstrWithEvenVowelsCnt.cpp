/*
*
//***********************************1371. Find the Longest Substring Containing Vowels in Even Counts.***********************************


https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/


Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', 
and 'u' must appear an even number of times.

 

Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
 

Constraints:

1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"eleetminicoworoep"

"leetcodeisgreat"


"bcbcbc"



// Time Complexity: O(n).													// n- leng. of the string.
// Space Complexity: O(k).													// Constant value.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- leng. of the string.
// Space Complexity: O(k).													// Constant value.
// This algorithm is iteration based. We use int rep to store #occur. of each vowel and whether it is odd/even. We store this in dp array, 
// if the int rep. is already occured, we calc. dist. from first occur. to curr. index and maximize the longest substr value. If curr. rep
// has never occurred, we update the dp array with curr. index. In the int rep, the bit is set, only if the vowel had occurred odd #times, 
// we use XOR operation for this purpose.








class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char,int>m;											// Converts vowels to their bit pns in int rep.
        m['a']=0;m['e']=1;m['i']=2;m['o']=3;m['u']=4;
        vector<int>dp(32, -2);												// Stores the index where vowels with this rep. occured.
        dp[0]=-1;															// Base case.
        int encountered=0, res=0;											// Keeps track of the vowels encountered till now.
        for(int i=0;i<s.length();i++){
            if(m.count(s[i])==1) encountered=(encountered^(1<<m[s[i]]));	// If char is vowel, we set bits only if it occurs odd # times.
            if(dp[encountered]==-2) dp[encountered]=i;						// If curr. rep has never occured, we update the occurrance.
            else res=max(res, i-dp[encountered]);							// If it has already occured, we calc. substring len and maximize it.
        }
        return res;															// Return the maxm. len substr with even vowel cnt.
    }
};

