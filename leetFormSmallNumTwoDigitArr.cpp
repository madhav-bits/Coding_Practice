/*
*
//******************************************************2605. Form Smallest Number From Two Digit Arrays.******************************************************

https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,1,3]
[5,7]
[3,5,2,6]
[3,1,7]
[4,6,3,1]
[2,6,4,3]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, for us to create a small num from digits form both arrays, we extract smallest nums from both arrays, but there is an exception that if we have a common digit in both arrays, the 
// least common value would be the answer then. So, we first find the smallest common digit if any, we sort the array, we use two pointers to find the smallest digit, if found we return it directly, else we use the smallest 
// digit among the smallest from both arrays in ten's place and the other in 1's place, we create a num and return it.







class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());																// Sort the given array of digits.
        sort(nums2.begin(), nums2.end());
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()) {														//  Using two pointers to find the smallest common digit.
            if(nums1[i]==nums2[j]) return nums1[i];
            if(nums1[i]<=nums2[j]) i++;
            else j++;
        }
        int min1=nums1[0];																				// Get smallest digit from both arrays.
        int min2=nums2[0];
        if(min1<=min2) return min1*10+min2;																// If min1 is least, that takes the 10s place and the other takes 1s place to create the smallest num using them.
        return min2*10+min1;																			// If min2 is the least digit among the both array's smallest digits.
    }
};

