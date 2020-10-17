/*
*
//***************************************************1328. Break a Palindrome.****************************************************

https://leetcode.com/problems/break-a-palindrome/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"abccba"
"a"
"aababaa"
"aaaaa"
"aaaaaa"




// Time Complexity: O(n). 													// n- length of the array. 
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we can break a palindrome by changing a char, which isn't possible if we have single 
// char, then we return empty array. We iter. until mid of the array and the char is 'a' looking for char to make it 'a', if we find
// it, we make it 'a' and return, if we aren't able to find and reached middle index, then we change the last char to 'b' and return.








class Solution {
public:
    string breakPalindrome(string s) {
        if(s.length()==1) return "";										// It will remain palindrome after change, so we return "".
        int ind=0;
        while(ind<s.length()/2 && s[ind]=='a') ind++;						// Searching for non 'a' char to make it 'a'.
        if(ind==s.length()/2) s.back()='b';									// If we reached mid, we change last char to 'b'.
        if(ind!=s.length()/2) s[ind]='a';									// If we found non 'a', we make it 'a'.
        return s;															// Return the modified string.
    }
};