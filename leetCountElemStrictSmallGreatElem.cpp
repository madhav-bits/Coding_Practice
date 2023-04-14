/*
*
//******************************************************2148. Count Elements With Strictly Smaller and Greater Elements.******************************************************

https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[11,7,2,15]
[-3,3,3,90]
[3,3,3,3,3,3]
[1,1,2,3,4,4,4,4,5,5,6,6,7,7,7,7,7,7]
[1,2,3,4,3,2,4,3,2,5,6,5,4,7,7,7,7,7]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we are trying to get nums which are neither minm nor maxm so that they can strictly number(minm) and strictly greater number(maxm) in the array where 
// these border values can't have both strict smaller, greater values to them. So, we extract minm, maxm nums of the array, we iter. over the array and get the count of all the non-boundary nums.







class Solution {
public:
    int countElements(vector<int>& arr) {
        if(arr.size()<=2) return 0;																		// Base condition.
        int minm=*min_element(arr.begin(), arr.end());													// Getting the minm, maxm nums of the array.
        int maxm=*max_element(arr.begin(), arr.end());
        if(minm==maxm) return 0;																		// Base condition.
        int res=arr.size();																				// Setting default ans to include all nums, later remove boundary nums from the res.
        for(int&num:arr) {																				// Iter. over array.
            if(minm==num) res--;																		// We remove the count of boundary nums.
            else if(maxm==num) res--;
        }
        return res;																						// Returning the count of non-boundary nums.
    }
};

