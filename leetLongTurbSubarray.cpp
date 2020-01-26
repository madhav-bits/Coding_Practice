/*
*
//*******************************************978. Longest Turbulent Subarray.*******************************************

A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:

For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

Return the length of a maximum size turbulent subarray of A.

 

Example 1:

Input: [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])
Example 2:

Input: [4,8,12,16]
Output: 2
Example 3:

Input: [100]
Output: 1
 

Note:

1 <= A.length <= 40000
0 <= A[i] <= 10^9


*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[9,4,2,10,7,8,8,1,9]

[4,8,12,16]


[100]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based solution. Here, we keep track of curr. sequence of numbers, longest seq. till then. If
// curr. pair and prev. pair are of diff. sign, we inc. the seq. len and try to udpate the max. seq. If curr. pair are of
// same values. We set the seq. len =1. If curr. pair are not equal and prev. pair are of same sign, we init. the sign and
// make the seq. len=2 and try to update max. seq. At the end of iter. we return the max. seq. tracked till then.



class Solution {
public:
    int maxTurbulenceSize(vector<int>& v) {
        int prev=0, sign=0, res=1, seq=1;								// Default assuming first pair are equal and res=1.
        if(v.size()==1) return 1;
        prev=(v[0]<v[1])?-1:(v[0]==v[1])?0:1;							// Assign first pair sign.
        if(v[0]!=v[1]){													// If not equal, init. seq. len=2.
            seq=2;
            res=2;
        } 
        for(int i=1;i<v.size()-1;i++){
            sign=(v[i]<v[i+1])?-1:(v[i]==v[i+1])?0:1;					// Assign sign based on pair values.
            if(prev*sign==-1){											// If prev., curr. pairs are of diff. signs.
                seq++;													// Inc. the seq. len, update the max. seq.
                res=max(res, seq);
            }else{													// If curr. vals are equal/ prev, curr pairs are equal.
                seq=1;													// Default assuming they are equal.
                if(sign!=0) seq=2;										// If not equal, set seq. len=2.
                res=max(res, seq);										// Update the max. seq. len.
            }
            prev=sign;													// Update the prev. pair sign.
        }
        return res;														// Return the max. seq len.
    }
};
