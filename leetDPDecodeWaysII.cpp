/*
*
//**************************************************************639. Decode Ways II.*******************************************************

A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
Example 2:
Input: "1*"
Output: 9 + 9 = 18
Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"1***"

"1*2"


"1**2"

"1**"


"1**2**3"


"1**2**345"


"1**2**342432423425235****4234**5"


"432423425235****4234**5"	


"1**2**342****23*48*3*4"



"1**2**342*****234**92****22"

"*"

"*1"

"*1*3*0"

"*10*1"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. #Decoding ways depend on curr. and prev. char at any instant. When, we are counting contribution
// of curr. char(at index i) to total ways, that multiplies the contribution of string of length(i-1) with the curr. chars #variations. Whenver
// we are counting contribution of curr. and prev. char combinedly(like 10-26 nums), we multiply contribution of string( i-2) with the #varitions 
// these two chars combinedly can produce.









class Solution {
public:
    
    int numDecodings(string s) {
        int MOD=1000000007;													// Modulus value.
        vector<long long int>dp(s.length()+1,0);							// DP array of length equals that of given string.
        dp[0]=1;															// Base case.
        for(int i=0;i<s.length();i++){
            long long int sum=0;
            long long int pre=1;
            if(i>1) pre=dp[i-1]%MOD;										// # ways possible from string till index "i-1".
            if(s[i]=='*'){													// If curr. char is "*".
                sum=(sum+(dp[i]*9))%MOD;									//As "*" can be written in 9 ways.
                if(i>0 && s[i-1]=='*') sum=(sum+(pre*15)%MOD)%MOD;			// We can form (10-19& 20-25) with these "*"s.
                else if(i>0 && s[i-1]==49) sum=(sum+(pre*9)%MOD)%MOD;		// We can form (10-19) with this "1" and "*".
                else if(i>0 && s[i-1]==50) sum=(sum+(pre*6)%MOD)%MOD;		// We can form (20-25) with this "2" and "*".
            } 
            else if(s[i]>=49 && s[i]<=57){									// If curr. chars is from (1-9).
                sum=(sum+dp[i])%MOD;										// It adds one more char to previous string's ways.
                if(i>0 && s[i-1]=='*' && s[i]<=54) sum=(sum+(pre*2)%MOD)%MOD;// We can form one of (10-15) and (20-25).
                else if(i>0 && s[i-1]=='*' && s[i]>54) sum=(sum+pre)%MOD;	// We can form one of (16-19) with "*" and curr. char>=6.
                else if(i>0 && s[i-1]==49) sum=(sum+pre)%MOD;				// It adds one of (10-19) with "1" and curr. char.
                else if(i>0 && s[i-1]==50 && s[i]<=54) sum=(sum+pre)%MOD;	// We can form one of (20-25) with "2" and curr. char.
            }
            else{
                if(i>0 && (s[i-1]=='*')) sum=(sum+(pre*2)%MOD)%MOD;			// We can form both 10/20 with "*" and "0".
                else if(i>0 && (s[i-1]==49 || s[i-1]==50)) sum=(sum+pre)%MOD;// We can form either of 10/20 with "1/2" and "0".
            }
            dp[i+1]=sum%MOD;    
        }
        // for(auto num:dp)
        //     cout<<num<<" ";
        // cout<<endl;
        return dp[s.length()];     											// Return # ways possible for given string.
    }
};