/*
*
//******************************************************2571. Minimum Operations to Reduce an Integer to 0.******************************************************

https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


39
54
15
17
29
100000
99999
1231
34534
2
16
8
9
3
2
4
5
10



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Greedy based. Here, we focus on LSBs at every step, if it is zero, we simply divide num by 2 to remove thid LSB. If it is 1, we check it's adjacent bit too, if it is set to 1, we add 1 to num, as this will
// set all the set adjacent bits to LSB to 0 and assign a '1' to their left, thus greedily we were able to remove all adj. set bits in a single step, and when this isn't possible we simply remove the LSB. Thus, we take
// minm #oper. to reduce num to zero.







class Solution {
public:
    int minOperations(int n) {
        int res=0;																						// Tracks the #oper. made.
        while(n>0) {																					// Till num is reduced to zero.
            // cout<<"num: "<<n<<" and rep: "<<bitset<32>(n)<<endl;
            if((n&3)==3) n++;																			// If atleast first two LSBs are set, we greedily add 1 to num.
            else if(n%2==1) n--;																		// If only first LSB is set(adj. bits not set), we simply remove the set LSB.
            else {																						// If LSB is not set, we simply remove the LSB for easy operability of the algo.(this doesn't count as step)
                n>>=1;
                res--;																					// To negate the inc. in res value in the below line outisde else bracket.
            }
            res++;																						// Inc. the #oper. count.
        }
        return res;																						// Returning the minm #oper. it takes to reduce the num to zero.
    }
};

