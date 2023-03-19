/*
*
//******************************************************2595. Number of Even and Odd Bits.******************************************************

https://leetcode.com/problems/number-of-even-and-odd-bits/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


17
2
4
5
7
9
12
15
16
1000
938
784



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is iteration based. We extract bit from LSB to MSB and inc. the cnt of bits at even, odd indices and return at end of iter.







class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even=0, odd=0;
        bool evenBit=true;
        while(n) {
            int digit=n%2;
            n/=2;
            // cout<<"evenBit: "<<evenBit<<" and digit: "<<digit<<endl;
            evenBit?even+=digit:odd+=digit;																// Inc. the set bits count for even, odd indices.
            evenBit=!evenBit;
        }
        return {even, odd};
    }
};

