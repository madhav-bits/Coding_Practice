/*
*
//******************************************************2063. Vowels of All Substrings.******************************************************

https://leetcode.com/problems/vowels-of-all-substrings/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aba"
"abc"
"ltcd"
"abac"
"abacd"
"aeiuo"
"bdghlmn"
"ljhlakrejlkjatnobjnoarjpew"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, each vowel can be part of multiple substrings and it is counted once in each of those substrs. So, if we calc. #substrs each 
// vowel can be part of, that indicates that vowels contribution towards #vowels in substrs. For an index 'i', it can be part of (i+1)*(v.size()-i) substrings, we use this 
// formula to get #substrs each vowel is part of and return the final sum of #substrs.







class Solution {
public:
    long long countVowels(string s) {
        long long int res=0;
        for(int i=0;i<s.length();i++) {										// Iter. over string.
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {// If curr. char is vowel.
                int left=i+1, right=s.length()-i;							// #starts, #ends of substrs involving curr. index.
                res+=(1ll*left*right);										// Adding #substrs involving curr. index to res.
            }
        }
        return res;															// Returning sum of #vowels in all possible substrs of the string.
    }
};

