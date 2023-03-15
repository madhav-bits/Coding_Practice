/*
*
//************************************************2496. Maximum Value of a String in an Array.***********************************************

https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


["alic3","bob","3","4","00000"]
["1","01","001","0001"]
["abc34d","0006","i234"]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. over all strings in array. We iter. over each string, if curr. char is digit, we add it to numeric rep. of the string, if we find a alphabet, we set
// the num. rep to length of the string and stop iter. over the curr. string. We track the max. value among the strings in res variable and return it at the end of iter. over array.








class Solution {
public:
    int maximumValue(vector<string>& v) {
        int res=0;
        for(string&s:v) {																				// Iter. over array of strings.
            int val=0;
            for(char&ch:s) {
                if(isdigit(ch)) val=val*10+(ch-'0');													// If curr. char is digit, convert it to numeric representation.
                else {																					// If alphabet is found, we set the num. rep to length of the string and break the iter.
                    val=s.length();
                    break;
                }
            }
            if(val>res) res=val;																		// Tracking the max. string value in the array.
        }
        return res;																						// Returning the max. string value in the array.
    }
};


