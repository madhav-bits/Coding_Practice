/*
*
//*************************************************1636. Sort Array by Increasing Frequency.*********************************************

https://leetcode.com/problems/sort-array-by-increasing-frequency/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[1,1,2,2,2,3]
[-1,1,-6,4,5,-6,1,4,1]
[2,3,1,3,2]



// Time Complexity: O(nlogn).  
// Space Complexity: O(nlogn).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(nlogn).	
// This algorithm is Sorting based. Here, since the range of nums is limited. We store the frequencies in an array. Now, we push the
// nums and freq. into another array, we sort the new array based on inc. order of freq. and dec. order of nums, if freq. is equal.
// We iter. over new array and push the result into final arr and return it.








class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>occur(201,0);											// Stores the freq. of each num.
        for(auto num:nums)
            occur[num+100]++;
        vector<pair<int,int>>v;												// Stores freq., nums to sort them based on freq.
        for(int i=0;i<=200;i++){											// Storing freq., nums in new array.
            if(occur[i]==0) continue;
            v.push_back({occur[i], -i+100});								// To Sort in Inc. Freq. and Dec. Nums order.
        }
        sort(v.begin(), v.end());											// Sort the new array.
        vector<int>res;
        for(auto pr:v){
            // for(int i=-1;i>=pr.first;i--)
            for(int i=1;i<=pr.first;i++)									// Storing the num. freq. times.
                res.push_back(-pr.second);
        }
        return res;															// Returning the final array.
    }
};