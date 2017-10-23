/*
287. Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

//************************************************THIS IS LEET ACCEPTED SOLUTION.****************************************************
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==0)
            return -1;
        sort(nums.begin(), nums.end());// Sort the array. Complexity is O(nlogn) using quick sort. USes O(1) space by the way.
        for(int i=0;i+1<nums.size();i++){
            if(nums[i]==nums[i+1])// First repitition is the desired answer.
                return nums[i];
        }
    }
};