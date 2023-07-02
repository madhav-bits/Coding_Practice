/*
*
//******************************************************2708. Maximum Strength of a Group.******************************************************

https://leetcode.com/problems/maximum-strength-of-a-group/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,-1,-5,2,5,-9]
[-4,-5,-4]
[-2]
[0,0,0,0,0]
[0,3,5,0,-2,-5,8]
[4,3,5,7,4,-3,-2,-6,-4,9,0,6,-2]
[0,-1]
[0,2]
[0,0,-2,-3,-4]
[0,0,1,2,-1]
[1,2,3,4]
[0,0,0,-1]
[0,0,-1,-2]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We calc. prod of non-zero nums, we multiply those values. If all values are zeroes, we return 0. If only one single
// non-zero is present which is neg, we return 0. If prod.is positive, we return it, else we remove the greatest. neg value from res and return the res.







class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size()==1) return nums[0];									// Base case.
        long long res=1;
        int greatNeg=INT_MIN;
        int zeroes=0, pos=0, neg=0;
        for(int&num:nums) {
            if(num!=0) {
                if(num>0) pos++;											// Counts #pos. nums.
                else {
                    neg++;
                    if(num>greatNeg) greatNeg=num;							// Tracks greatest negative number.
                }
                res*=num;													// Calc. prod of non-zero nums.
            }else zeroes++;
        }
        if(zeroes==nums.size()) return 0;									// If all are zeroes, return 0.
        if(neg%2==1) res/=greatNeg;											// Remove greatest neg. if #negs are odd.
        if(pos) return res;													// If prod. is neg, return it.
        if(neg==1) return 0;												// If only one neg. is present with zero pos, rest values would be zero, we return 0.
        return res;															// We return the calc. prod of nums.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. This deals with intricate conditions smoothly when compared to the above sln. If #zeroes=arr. size, we return 0.
// If #zeroes=arr.size()-1, we return max(0, prod) else we have two non-zero values atleast, so we remove. greatest neg. from prod, if it's neg else we return 
// prod.





class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size()==1) return nums[0];									// Base case.
        int zeroes=0, greatestNeg=INT_MIN;
        long long int res=1;
        for(int&num:nums) {
            if(num!=0) res*=num;
            else zeroes++;
            if(num<0 && num>greatestNeg) greatestNeg=num;					// Tracks greatest negative number.
        }
        if(zeroes==nums.size()) return 0;									// If all nums are zeroes, we reutrn 0.
        if(zeroes==nums.size()-1) return max(0ll, res);						// If one non-zero num is present, we return >=0
        if(res<0) res/=greatestNeg;											// If prod. is neg, we remove greatestNeg from it.
        return res;															// We return the greatest possible prod. of nums.
    }
};



