/*
*
//**********************************************************476. Number Complement.***************************************************

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


0

1

16 

15

2147483646

2147483647



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Bit Manipulation based. We iterate through 31 bits in the given number. Whenever we have 0 in that bit, we add that bit's
// value to the result. We iterate only 31 bits only, as 32 bit is used for sign. This way, we get the inverse of the given number.








class Solution {
public:
    int findComplement(int num) {
        int temp=1;															// Used to extract the curr. bit value of given number.
        int res=0;int bit=0;												// Stores inverse value, bit we are currenly in.
        while(bit<31 && temp<=num){											// Until 31 bits are visited and temp val. is <=given num. 
            // cout<<"bit: "<<bit<<" and temp: "<<temp<<endl;
            int ans=num&temp;												// Extract the curr. bit
            if(ans==0) res+=temp;											// If curr. bit is 0, add that bit's value to result.
            temp=temp<<1;													// Inc. the temp value by 2.
            bit++;															// INc. the bit count.
        }
        return res;															// Returning the Complement value.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Bit Manipulation based. As, complement and given nums bits would form all 1s till MSB of given num. Their combined value is
// 2^(MSB+1)-1. So, we extract the MSB, get the result by subtracting given num. from the eqn.




class Solution {
public:
    int findComplement(int num) {
        int temp=1;															// Stores temp. value.
        while(num>temp-1){													// Until temp. value<given value.
            temp*=2;														// Inc. the temp value by 2.
        }
        return temp-1-num;													// Returning the complement value.
    }
};