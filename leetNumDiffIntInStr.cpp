/*
*
//*********************************************1805. Number of Different Integers in a String.*****************************************

https://leetcode.com/problems/number-of-different-integers-in-a-string/




You are given a string word that consists of digits and lowercase English letters.

You will replace every non-digit character with a space. For example, "a123bc34d8ef34" will become " 123  34 8  34". Notice that you are left with 
some integers that are separated by at least one space: "123", "34", "8", and "34".

Return the number of different integers after performing the replacement operations on word.

Two integers are considered different if their decimal representations without any leading zeros are different.

 

Example 1:

Input: word = "a123bc34d8ef34"
Output: 3
Explanation: The three different integers are "123", "34", and "8". Notice that "34" is only counted once.
Example 2:

Input: word = "leet1234code234"
Output: 2
Example 3:

Input: word = "a1b01c001"
Output: 1
Explanation: The three integers "1", "01", and "001" all represent the same integer because
the leading zeros are ignored when comparing their decimal values.
 

Constraints:

1 <= word.length <= 1000
word consists of digits and lowercase English letters.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"a123bc34d8ef34g0"
"a1b01c001"
"leet1234code234"
"0afa00fs10100sf0fs1"
"a1h1h1h1h"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Hash Set based. We collect nums in the string while iterating. When we encounter a alpha char, we check prev. char to know if it's
// digit, if it is the string which we had collected till now is a number and we try to store in the hash set. We use string form of nums as nums are
// causing int overflow. We return hash set size as this gives the #unique nums found in the string.











class Solution {
public:
    int numDifferentIntegers(string s) {
        unordered_set<string>st;											// Stores all unique nums in the string.
        int num=0;
        string temp="";														// Stores nums in the string while iterating.
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])==false){
                if(i>0 && isdigit(s[i-1])) st.insert(temp);					// If prev. char is digit, temp is num and we insert it into set.
                temp="";
            }else{
                if(temp=="" && s[i]=='0') continue;							// To avoid leading zeroes.
                temp+=s[i];
            }
        }
        if(isdigit(s.back())) st.insert(temp);								// To confirm that temp holds a num.
        return st.size();													// Returning the #unique nums found in the string.
    }
};


