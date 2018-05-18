/*
*
//**********************************************************461. Hamming Distance.***************************************************

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


11
4

8
7

6
9




// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is iteration based. We do a XOR on both numbers. Which takes one on all those bits where one int has "0" and the other as "1"-
// differ. We do right bit shift each time and check whether the last bit "1" or not. If last bit is "1", we inc. the count. After all iterations
// we return count, which is the total number of bits, where the two ints have different bits.



class Solution {
public:
    int hammingDistance(int x, int y) {
        x=x^y;															// Calc. XOR, indicating diff bits in two ints by "1" in the result.
        int count=0;													// Total num. of diff bits in two ints.
        while(x!=0){													// Until the XOR result becomes "0".
            if(x&1) count++;											// If last bit of XOR result is "1", inc. count.
            x=x>>1;														// Doing a right shift on XOR result each time.
        }
        //cout<<"The dist. is: "<<count<<endl;
        return count;													// Returning total number of diff. bits in two ints.
    }
};