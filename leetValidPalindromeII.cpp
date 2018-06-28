/*
*
//**********************************************************680. Valid Palindrome II.***************************************************

Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aba"

"abcbbca"

"abccbca"

"abgba"

"fabba"

"aba"





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, we take ptrs from both end, we check if they are equal or not? If they are not equal, we take two paths, 
// one is skipping the lower index, other is skipping the higher index, and check whether else indices are palindromic or not? As, we need to 
// skip only 1 char. We need not worry about skipping chars anymore. So, it's O(n) as a whole.







class Solution {
public:
    bool checkPalindrome(string s, int start, int end){						// Check whether the substr passed is palindrome or not?
        while(start<end){
            if(s[start]!=s[end]) return false;								// If chars are not equal, return false.
            start++;														// Moving the iterators.
            end--;
        }
        return true;														// If palindromic, return true.
    }
    
    bool validPalindrome(string s) {
        int i=0, j=s.length()-1;											// Setting the ptrs values.
        while(i<j){
            if(s[i]!=s[j]){													// IF chars mismathc.
                return checkPalindrome(s,i+1,j)|| checkPalindrome(s,i,j-1);	// One is skipping left index, other is skipping right child.
            }
            i++;j--;														// Moving the iterators.
            
        }
        return true;														// If palindromic, return true.
    }
};
