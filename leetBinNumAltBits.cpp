/*
*
//******************************************************693. Binary Number with Alternating Bits.***********************************************

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101
Example 2:
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.
Example 3:
Input: 11
Output: False
Explanation:
The binary representation of 11 is: 1011.
Example 4:
Input: 10
Output: True
Explanation:
The binary representation of 10 is: 1010.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1431655765

15

16

17

1

0

6

21




// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is bit manipulation based. We extract each bit from the num, and check whether curr. and prev. bit are same, if they are same,
// then return false. If we don't observe any cases same consecutive bits, then return true. We need to handle the cases when temp. var moves 
// past INT_MAX.








class Solution {
public:
    bool hasAlternatingBits(int num) {
        if(num==0) return true;												// IF 0, return 0 directly.
        int temp=1;															// Used to extract bits from given num.
        int prev=temp&num;													// Extr. first bit of given num.
        temp=2;																// Inc. the temp value.
        while(temp<num){													// Until temp<given num.
            int res=num&temp;												// Extracting curr. bit from given num.
            // cout<<"curr. res: "<<res<<endl;
            if(res==0){														// If curr. bit is 0.
                if(prev==0) return false;									// If prev. bit is 0, return false.
				else prev=0;												// Else, assign prev. to be 0 for next iter.
            }
            else{
                if(prev==1) return false;
                else prev=1;
            }
            if(temp>INT_MAX/2) break;										// If next iter. has temp. val>INT_MAX then stop iter.
            temp=temp<<1;													// Inc. the temp value by 2.
        }
        return true;														// As, no conse. ones appeared, return true.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is BIt Manipulation based. Since, we are looking for alternating ones, we form all ones by doing XOR b/w num and (num>>1). We
// form perfect square by adding 1 to it. If we get a perfect square, we return true else return false.








class Solution {
public:
    bool hasAlternatingBits(int num) {
        int res=(num^(num>>1))+1;											// Forming all ones first, then add 1 to form perfect square.
        return !(res&(res-1));												// Perfect square checking cdn.
    }
};