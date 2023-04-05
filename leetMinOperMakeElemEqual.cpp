/*
*
//******************************************************2602. Minimum Operations to Make All Array Elements Equal.******************************************************

https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,1,6,8]
[1,5]
[2,9,6,3]
[10]
[4,5,8,12,13,14,23,27,56,54,58,87,65,32,21,98,65,45,23,74]
[5,1,4,56,100,32,37,64,20]




// Time Complexity: O(nlogn+mlogn).																		//n-#nums provided, m-#queries.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+mlogn).																		//n-#nums provided, m-#queries.
// Space Complexity: O(n).	
// This algorithm is Sorting+PrefixSum based. Here, we are trying to calc. minm #steps to move all nums to given query num. We sort the array nums, we calc. prefixSum of the sorted array and store it in another array. While
// iter. over query array, for every query, we find the largest index where arr[i]<=curr. query. The #moves it takes for k lesser values take to become query is k*query-sum of all lesser values, similarly #steps it takes k
// greater values to become query value is prefixSum of all greater values-k*query, we use this equations to get the #moves it takes for greater, lesser values to become query. 







class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());																	// Sort the given nums.
        long long int total=accumulate(nums.begin(), nums.end(), 0ll);
        vector<long long int>prefixSum(nums.size(),0);													// Calc. prefixSum of the nums array.
        prefixSum[0]=nums[0];
        for(int i=1;i<nums.size();i++) {																// Updating the prefixSum array.
            prefixSum[i]=nums[i];
            prefixSum[i]+=prefixSum[i-1];
        }
        vector<long long int>res(queries.size(), 0);
        for(int i=0;i<queries.size();i++) {																// Iter. over queries.
            int ind=upper_bound(nums.begin(), nums.end(), queries[i])-nums.begin()-1;					// Finding largest index with arr[i]<=curr_query
            long long int left=(ind>=0)?prefixSum[ind]:0;												// PrefixSum of lesser and equal values.
            long long int right=total-left;																// PrefixSum of greater values.
            ind++;
            res[i]=0ll+((1ll*ind*queries[i])-left)+(right-1ll*(nums.size()-ind)*queries[i]);			// Adding #moves it takes for lesser, greater values and adding to res.
        }
        return res;																						// Returning the array with minm #moves for each query values.
    }
};

