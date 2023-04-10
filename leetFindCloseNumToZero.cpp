/*
*
//******************************************************2239. Find Closest Number to Zero.******************************************************

https://leetcode.com/problems/find-closest-number-to-zero/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[-4,-2,1,4,8]
[2,-1,1]
[3,4,-3, 5]
[-3,4,3,-6]
[3,1,2,-1,-4]
[0]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is comparison based. We iter. over nums in the array, calc. their distance from zero, track the closest num and it's diff/dist from zero and return the num.







class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res=100001, diff=100001;
        for(int&num:nums) {
            if(num>=0 && num<=diff) {																	// If curr. dist<=diff, we update the res as this value would be greater for eq. diff.
                res=num;
                diff=num;
            }else if(num<0 && -num<diff) {																// If curr. dist<diff, we update the num, diff.
                res=num;
                diff=-num;
            }
        }
        return res;																						// Returning the closest num.
    }
};

