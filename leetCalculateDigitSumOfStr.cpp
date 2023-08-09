/*
*
//******************************************************2243. Calculate Digit Sum of a String.******************************************************

https://leetcode.com/problems/calculate-digit-sum-of-a-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"11111222223"
3
"00000000"
3



// Time Complexity: O(n).												// This is loose upper bound, in every step length dec. by log10 times, as calc. is compliate we take O(n).
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).												// This is loose upper bound, in every step length dec. by log10 times, as calc. is compliate we take O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, at every step we calc. sum of vals from str and add the stringified sum to temp str when we reach multiples of 'k' indices and form 
//new str in this process, if this new str at the end of loop is more lengthier than 'k', we repeat this process and we stop it, when it's length<=k.







class Solution {
public:
    string digitSum(string s, int k) {
        string temp="";
        int total=0;
        while(s.length()>k) {												// Repeat the process as long as length of str>k.
            temp="";
            total=0;
            for(int i=0;i<s.length();i++) {
                if(i>0 && i%k==0) {											// At end of every window.
                    temp+=to_string(total);									// Append stringified total to temp str.
                    total=(s[i]-'0');										// Reset the total to curr. char as new window started.
                } else total+=(s[i]-'0');									// Calc. sum of values.
            }
            temp+=to_string(total);											// Append last sum to temp str.
            s=temp;															// Assign temp str to orig. str.
        }
        return s;															// Returning the final str after going through the process.
    }
};

