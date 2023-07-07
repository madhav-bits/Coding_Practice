/*
*
//******************************************************2145. Count the Hidden Sequences.******************************************************

https://leetcode.com/problems/count-the-hidden-sequences/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,-3,4]
1
6
[4,-7,2]
3
6
[4,-3,6,7,-3,-4,6,-3,-6,5,-4,5,2,-6,6,4,3,-7,7,6,4,-4,3,4]
100
200



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. We calc. the cumulative sum to understand the range of nums in hidden array. If the range of nums is > given range,
// that is upper-lower, we return 0, else we calc. maxm. number if lower is chosen as the minm. value of cumul. sum and calc. it's dist. upper+1 and return it.








class Solution {
public:
    int numberOfArrays(vector<int>& v, int lower, int upper) {
        long long int total=0, minm=0, maxm=0;
        for(int&num:v) {
            total+=num;
            if(total>maxm) maxm=total;										// Calc. minm., maxm. of cumul. sum
            if(total<minm) minm=total;
        }
        int range=maxm-minm;												// Calc. range of nums.
        int high=lower+range;												// Calc. highest value if lower is chosen as the minm. cumul. sum
        return (high>upper)?0:(upper-high+1);								// Returning all possible sequences count.
    }
};

