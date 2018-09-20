/*
*
//************************************************************Excel Column Number.*****************************************************

https://www.interviewbit.com/problems/excel-column-number/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


A


Z


AA


ZZZZ


AZZZA

AAAAA

AAAAZ


ZAAAA



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. over given string, check each char and convert it to int. When we go to new char, we multiply the 
// sum we have accumulated till now by 26 and add curr. num. At the end of iter. we get the required number.








int Solution::titleToNumber(string s) {
    int res=0;																// Init. the final result.
    for(int i=0;i<s.length();i++){											// Iter. over given string.
        int temp=s[i]-64;													// Extract curr. char's corresponding num.
        res=(res*26)+temp;													// Adding curr. char with earlier char's representing num.
    }
    return res;																// Returning the final result(int representation).
}
