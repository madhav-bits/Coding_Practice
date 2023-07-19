/*
*
//******************************************1913. Maximum Product Difference Between Two Pairs.***************************************

https://leetcode.com/problems/maximum-product-difference-between-two-pairs/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,6,2,7,4]
[4,2,5,9,7,4,8]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting based. To get max. diff we need to substract product of least 2 values from the product of max 2 values, to get these values we 
// sort the array, get their products and return difference between them.







class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-1]*nums[nums.size()-2]-nums[0]*nums[1];
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// This is iteration based. We use 4 vars to track least 2 min, greatest 2 max values and substract their product to get result.






class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int min1=INT_MAX, min2=INT_MAX, max1=0, max2=0;
        for(int&num:nums) {
            if(num<min1) {
                min2=min1;
                min1=num;
            }else if(num<min2) min2=num;
            
            if(num>max1) {
                max2=max1;
                max1=num;
            } else if(num>max2) max2=num;
        }
        return max1*max2-min1*min2;
    }
};



