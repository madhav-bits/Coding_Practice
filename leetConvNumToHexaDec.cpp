/*
*
//******************************************************405. Convert a Number to Hexadecimal.***********************************************


Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the 
first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



0

-1

-2


2147483647


-2147483648



// Time Complexity: O(logn/log16).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn/log16).
// Space Complexity: O(1).	
// This algorithm is Plain Conversion of base 10 to base 16. We keep on extracting each contributing char in hex. format from lowest to highest
// significant bit. At the end, we reverse the accumulated chars till then and return them.








class Solution {
public:
    
    string convert(unsigned int num){
        string res="";
        while(num){															// Num. still needs to be converted into Hex. format.
            int rem=num%16;													// Extracting LSB contributing to curr. num.
            num/=16;														// Remvoing LSB's contribution from curr. num.
            res+=(rem>9)?rem+87:rem+48;										// Appending the char to final result string.
        }
        reverse(res.begin(), res.end());									// Reversing the result string.
        if(res=="") res="0";												// If empty obtained, then it becuase of integer-'0'.
        return res;															// Return the result.
    }
    
    string toHex(int num) {
        return convert(num);												// Call fn. to convert to Hexa. format.
    }
};