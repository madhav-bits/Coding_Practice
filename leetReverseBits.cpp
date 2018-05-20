/*
*
//**********************************************************190. Reverse Bits.****************************************************

GiReverse bits of a given 32 bits unsigned integer.

Example:

Input: 43261596
Output: 964176192
Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
             return 964176192 represented in binary as 00111001011110000010100101000000.
Follow up:
If this function is called many times, how would you optimize it?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
10
0
1025



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is bit manipulation based. At each step we calculate the last bit value and push into the res integer. Since, we use only 31 bits
// in standard integer representation. We extract only 31 bits from given integer and push them into last 31 bits of result integer.




class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        int i=0;																// Indicates curr. bit under scanning.
        while(n>0){																// We extract until given int decomp. to 0, rem. bits are 0s
            int temp=n&1;
            if(temp)
                res=res|(1<<(31-i));											// First bit is pushed into 31st bit of result, similarly i to 31-i
            i++;																// Tracking the psn of bit being scanned.
            n>>=1;																// Reducing the value of given integer.
        }
        return res;																// Returning the obtained result.
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is bit manipulation based. At each step we calculate the last bit value and push into the res integer. Since, we use only 31 bits
// in standard integer representation. We extract only 31 bits from given integer and push them into last 31 bits of result integer.






class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<32;i++){												// We iterate 31 times.
            res=res<<1;														// since, we push only 31 bits, pushing the first bit to right.
            int temp=n&1;													// Extracting the last bit of given integer.
            if(temp)														// If it is one, then push 1 into result integer.
                res=res|1;
            n>>=1;															// Reducing the val. of given integer.
            
        }
        return res;															// Returning the result integer.
    }
};