/*
*
//**************************************************918. Maximum Sum Circular Subarray.*******************************************

Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and 
C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there 
does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[5,-3,6]


[3,-2,1,1,-3,2]


[1]


[-1,-2]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, there are two possibilities to get max. sum subarray, one in the array without looping around edge,
// other loops around edge. The first possibility can be obtained by getting max. sum subarray(which we do generally). The looping around edge 
// case can be obtained by Subtracing total sum of array-min. subarray(Calc. same ways as Max. sum subarray). We return max. of these two 
// values.
// Edge case is that whole array is neg.(Minm. subarray value == sum value), here we return max subarray value.







class Solution {
public:
    int maxSubarraySumCircular(vector<int>& v) {
        if(v.size()==1) return v[0];										// Base case.
        int maxm=INT_MIN, minm=INT_MAX, sum=0;								// Tracks overall Max/Min. subarray sums.
        int tempMax=0, tempMin=0;											// Tracks max./min. sum of subarrays ending at index 'i'.
        for(int i=0;i<v.size();i++){
            sum+=v[i];														// Calc. sum of whole array.
            tempMax=max(v[i], v[i]+tempMax);								// Extracting Maxm. value subarray from array.
            maxm=max(maxm, tempMax);										// Tracking Max. subarray sum.
            
            tempMin=min(v[i], tempMin+v[i]);								// Extracting Minm. value subarray from array.
            minm=min(minm, tempMin);										// Tracking Min. subarray sum.
        }
        // cout<<"maxm: "<<maxm<<" and sum-minm: "<<sum-minm<<endl;
        int temp=sum-minm;													// Case where minSubSubarray is whole array.
        if(temp==0) temp=INT_MIN;											// The, make it INT_MIN.
        return (maxm>(temp))?maxm:temp;										// Return the max. of two possibilities.
																			// Below line does the same as above three lines.
		//return (maxm>0)?(max(maxm, sum-minm)):maxm;						// Maxm being neg. also indicates that whole array has neg. values.
    }
};

