/*
*
//******************************************************2108. Find First Palindromic String in the Array.******************************************************

https://leetcode.com/problems/find-first-palindromic-string-in-the-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["abc","car","ada","racecar","cool"]
["notapalindrome","racecar"]
["def","ghi"]



// Time Complexity: O(n*m).																				//n-length of the array, m-avg. length of the string.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).																				//n-length of the array, m-avg. length of the string.
// Space Complexity: O(1).	
// This algorithm is iteration based. While iterating, we check every string whether it's a palindrome, if yes we return that string, else we return "" at the end of iter.







class Solution {
public:
    
    bool isPalindrome(string&s) {																		// Checks if a string is palindrome.
        int i=0,j=s.length()-1;
        while(i<=j && s[i]==s[j]) {
            i++;
            j--;
        } 
        return (i>j);
    }
    
    string firstPalindrome(vector<string>& words) {
        for(string&s:words) {																			// Iter. over array of strings.
            if(isPalindrome(s)) return s;																// If curr. string is palin., we return it.
        }
        return "";																						// If no palin. string found, we return an empty string.
    }
};

