/*
*
//**********************************************************266. Palindrome Permutation.***************************************************

Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


""
"a"
"aa"
"aba"
"abba"
"abcdba"
"adfa"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the array, as we need to form a palindrome from permutation. We count #occurances of each char, as even numbered
// chars stay to both sides of mid char/chars, we can have only one/zero odd numbered chars(As the last char can be middle). 
// In the algo. i extract #odd numbered chars. If a char is encountered for odd numbered time, then odd count, inc. count also inc., if 
// it's encountered even numbered times(odd count,it's count in array also dec.). At the end, if we zero/ one odd numbered chars, then we 
// return true else return false.








class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int>count(26,0);												// Tracks count of chars.
        int odd=0;															// Tracks chars that occured odd number of times.
        for(int i=0;i<s.length();i++){										// Iterates through the array.
            if(count[s[i]-'a']==0){											// If char is encountered odd numbered time.
                odd++;														// Odd count inc.
                count[s[i]-'a']++;											// It's count in array set to 1.
            }
            else{															// If char encountered even numbered time.
                odd--;														// Odd count dec.
                count[s[i]-'a']=0;											// It's count set to 0.
            }
        }
        return (odd<=1)?true:false;											// If >1 odd numbered chars exists, return false else return true.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algo. is taking a bit of length 256, whenver a char is encountered, that index is swapped, at the end if we have >1 bits as 1, return
// false else return true.

// This algo. is from discussion forum of Leetcode.



class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> b;
        for(auto c : s){
            b.flip(c);														// Whenever char. encountered, flip that numbered bit.
        }
        return b.count() < 2;												// If >1 bits set as 1, return false else return true.
        
    }
};