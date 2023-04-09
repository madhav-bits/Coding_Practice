/*
*
//******************************************************2455. Average Value of Even Numbers That Are Divisible by Three.******************************************************

https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,6,10,12,15]
[1,2,4,7,10]
[3,6,9,3]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. over given array, calc. total of all even nums which are divisible by 3 and return their avg.







class Solution {
public:
    int averageValue(vector<int>& nums) {
        int total=0, cnt=0;																				// Tracks sum of nums which satisfies given cdn, #nums which satisfies given conditions.
        for(int&num:nums) {
            if(num%2==0 && num%3==0) {																	// Checking for even nums divisible by 3.
                total+=num;																				// Updating sum of nums and #nums.
                cnt++;
            }
        }
        if(cnt==0) return 0;																			// Base condition.
        return (int)total/cnt;																			// Returning the avg of all even nums divisible by 3.
    }
};

