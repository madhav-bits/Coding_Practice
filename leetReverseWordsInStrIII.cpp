/*
*
//******************************************************557. Reverse Words in a String III.***********************************************

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]


["t","h","e"," ","s","k","y"," ","i"," ","b","l","u","e"]


["t","h","e"," ","s","k","y"," ","b","l","u","e"]


["t","h","e"]


[]





// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the array, we reverse each word by after finding it's first and last indices. Thus, we get the required answer.








class Solution {
public:
    string reverseWords(string s) {
        for(int i=0;i<s.length();i++){										// Iterating the entire string.
            int j=i;
            while(j<s.length() && s[j]!=' ') j++;							// Finding the last index of the curr. word.
            int k=j;
            j--;
            while(i<j){														// Reversing the curr. word.
                swap(s[i], s[j]);
                i++;j--;
            }
            i=k;															// Setting the index to " " separating curr. and next word.
        }
        return s;															// Returning the str with reversed words.
    }
};