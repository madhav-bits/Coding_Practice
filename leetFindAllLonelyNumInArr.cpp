/*
*
//******************************************************2150. Find All Lonely Numbers in the Array.******************************************************

https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[10,6,5,8]
[1,3,5,3]
[1,2,3,5,7,7,8,9,13,14,15,16,19,21,15,23,28]
[0]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting based. Here, since we want numbers with single occurance and their adj. numbers are absent. We sort the array and iteration over the array and compare adj. numbers, if 
// they satisfy the conditions, we add the curr. num to res. We return res at the end of iteration.







class Solution {
public:
    vector<int> findLonely(vector<int>& arr) {
        if(arr.size()==1) return arr;																	// Base condition.
        vector<int>res;
        sort(arr.begin(), arr.end());																	// Sorting the array.
        if((arr[0]+1)<arr[1]) res.push_back(arr[0]);													// Checking condition for the lowest value.
        if((arr.back()-1)>arr[arr.size()-2]) res.push_back(arr.back());									// Checking condition for the highest value.
        for(int i=1;i<arr.size()-1;i++) {																// Iter. over the last boundary values.
            if(arr[i-1]<(arr[i]-1) && (arr[i]+1)<arr[i+1]) res.push_back(arr[i]);						// If curr. val has 1 occurance and adj. values are absent, add to res.
        }
        return res;																						// Returning values that satisfies the conditions.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).																				//n-length of the array, m-max. value of the nums in the array.
// Space Complexity: O(m).	
// This algorithm is Counting Sort based. Since, the range of nums is small, we can use this as it's time complexity would be similar to that of Comparison based Sorting. We get the max. val in 
// the array and create an occur. array of size maxm+2 to keep track of #occur. of each number. We iter. over given array and update the occur array with each num's occur.. We iter. over this array
// at every index, we check if it's occur. value is 1 and adj. values are zero, if it is we add curr. index to res. We return res at the end of iter.





class Solution {
public:
    vector<int> findLonely(vector<int>& arr) {
        if(arr.size()==1) return arr;																	// Base condition.
        vector<int>res;
        
        // Counting Sorting based. 
        int maxm=*max_element(arr.begin(), arr.end());													// Extracting max. value of the array.
        vector<int>occur(maxm+2,0);																		// Array to track occur. of nums in the given array.
        
        for(int&num:arr) occur[num]++;																	// Updating occur. of nums in the array.
        
        if(occur[0]==1 && occur[1]==0) res.push_back(0);												// Checking condition for '0' value.
        for(int i=1;i<=maxm;i++) {																		// Iter. over other nums.
            if(occur[i]==1 && occur[i-1]==0 && occur[i+1]==0) res.push_back(i);							// If condition is satisfied, add it to res.
        }
        return res;																						// Returning values that satisfies the conditions.
    }
};

