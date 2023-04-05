/*
*
//******************************************************2563. Count the Number of Fair Pairs.******************************************************

https://leetcode.com/problems/count-the-number-of-fair-pairs/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,1,4,4,5,7]
3
6
[1,2,5,7,9]
11
11
[1,2,4,7]
14
15
[4,5,3,2,6,5,4,8,7,6,5,9]
5
10



// Time Complexity: O(nlogn).
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Two Pointer approach. We use two pointers to track indices whose values are < for lower, <= for upper values. As the array is sorted, if we move from lesser to greater values, the second number to be paired
// would always be to the left earlier low, high positions and we can 2 pointers sum approach to find the best possible [start, close] indices range which satisfy the given requirement.







class Solution {
public:
    long long countFairPairs(vector<int>& arr, int lower, int upper) {
        long long int res=0;
        sort(arr.begin(), arr.end());										// Sorting the given array enabling us to use 2 pointer sum approach.
        int low=arr.size()-1, high=arr.size()-1;
        for(int i=0;i<arr.size();i++) {										// Iter. over all possible first num in the pairs to be formed.
            while(low>=0 && arr[i]+arr[low]>=lower) low--;					// Finding least index which satisfies the given condition(>=lower) with 'i' index as one num of the pair.
            while(high>=0 && arr[i]+arr[high]>upper) high--;				// Finding greatest index which satifies the given condition(<=upper).
            low++;															// To satisfy the (>=lower)condition.
            // cout<<"index: "<<i<<" and low: "<<low<<" and high: "<<high<<endl;
            if(high>i)res+=0ll+(high-max(i+1,low)+1);						// As two indices have to be distinct, we are forming [i,j] index pairs where i<j. If condition to verify that there has to valid index pairs.
            if(low>=arr.size()) low=arr.size()-1;							// Edge case, where [0, arr.size()-1] can't form a valid pair and i goes out of bound.
        }
        return res;															// Returning total #pairs satisfying given condition.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Two Pointer approach based. This is almost same as the above one. Here, instead of using 2 ptrs for both lower, upper values in a same loop, we find #pairs whose sum is <=target, we do this for <=upper,
// which also include pairs whose sum <lower which dont meet the requirement, so we call the same function to calc. these unwanted #pairs whose sum is <lower and subtract them the earlier #pairs and return the resulting #pairs
// satisfying the requirement.









class Solution {
public:
    
    long long int findLesserCountPairs(vector<int>&arr, int target) {									// Calc. #dist. index pairs whose sum is <=target 
        long long int res=0;
        for(int i=0,j=arr.size()-1;i<j;i++) {															// Iter. over all possible values of first index in the pair.
            while(i<j && arr[i]+arr[j]>target) {														// Reaching greatest index where the sum of the values <=target
                j--;
            }
            res+=0ll+(j-i);																				// Adding #distinctive index pairs to res.
        }
        return res;																						// Returning total #index pairs satisfying given condition(<=target).
    }
    
    long long countFairPairs(vector<int>& arr, int lower, int upper) {
        sort(arr.begin(), arr.end());
        return findLesserCountPairs(arr, upper)-findLesserCountPairs(arr, lower-1);						// #pairs with sum<=upper-#pairs with sum<lower
    }
};

