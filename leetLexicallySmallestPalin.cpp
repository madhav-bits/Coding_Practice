/*
*
//******************************************2697. Lexicographically Smallest Palindrome.********************************************

https://leetcode.com/problems/lexicographically-smallest-palindrome/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"egcfe"
"abcd"
"seven"
"kajlasejijbioajrlaiklasdjfieornbaergaowfoiksadn"
"sdklajspqiwejfjsjnjfb"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. For a palindrome symmetrically opposite indices has to be of same char irres. of other chars, so when deciding #oper, we 
// decide moves on symmetrically opp. index's chars. We take two ptrs from both drns and iter. over symmetrically opp. indices, for us to use min. #oper., we 
// dont' make any oper if two chars are equal, if not equal we only change one char among i,j indices, if the s[i] is small of the both, we make s[j]=s[i], else
// if s[j] is smaller, we make s[i]=s[j]. We can make both chars to be 'a' to make it lexically small but that might need two oper, thus it won't lead to min. 
// #oper. so we avoid it. After the iter. we return the modified str.







class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i=0, j=s.length()-1;
        while(i<j) {														// Iter. over symmetrically opp. indices and comparing them.
            if(s[i]>s[j]) s[i]=s[j];										// Assigning min of both chars to greater char and make it palindromic.
            else s[j]=s[i];
            i++;															// Move to next pair of symmetrically opp. indices.
            j--;
        }
        return s;															// Returning the palindromic str after all the oper.
    }
};

