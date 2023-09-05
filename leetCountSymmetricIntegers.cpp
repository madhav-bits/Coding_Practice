/*
*
//******************************************************2843. Count Symmetric Integers.******************************************************

https://leetcode.com/problems/count-symmetric-integers/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
100
1200
1230
1406
1450
1474
9833
2
10000



// Time Complexity: O(n).													// n-diff. b/w high and low.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n-diff. b/w high and low.
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. over the range of integers in consideration. For each num, we stringiy it and add the vals of first half chars
// and substract the rem. char's values and check if the total=0, if yes we inc. the res. If the curr. num is of odd length, we skip all it's following nums 
// of same length. We return res at the end of iter.







class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res=0;
        for(int i=low;i<=high;i++) {
            string temp=to_string(i);										// Stringify curr. num.
            if(temp.length()%2==1) {										// If curr. num is of odd length.
                i=pow(10,temp.length())-1;									// We skip all it's following nums of same length.
                continue;
            }
            int total=0;
            for(int i=0;i<temp.length();i++) {								// Iter. over curr. string.
                if(i<temp.length()/2) total+=(temp[i]-'0');					// Add all chars from first half to total.
                else total-=(temp[i]-'0');									// Substract all chars from second half from total.
            }
            if(total==0) res++;												// If total=0, we inc. res.
        }
        return res;														// Returning #nums of even length whose first half chars total=second half chars total.
    }
};

