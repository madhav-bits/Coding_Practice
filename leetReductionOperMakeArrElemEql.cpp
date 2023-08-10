/*
*
//*********************************1887. Reduction Operations to Make the Array Elements Equal.*************************************

https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,1,3]
[1,1,2,2,3]
[1,1,1]
[4,6,4,3,5,56,34,3,6,66,34,3,3,6,6,534,3,7]




// Time Complexity: O(n+m).													// n-length of the array, m-range of vals in the array.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// n-length of the array, m-range of vals in the array.
// Space Complexity: O(m).	
// This algorithm is Counting Sort based. Here, in the proecss of dec. greatest vals, when we are abt to dec. all greater vals to arr[i], that means all
// greater vals at this moment are equal to the closest greater val and their cnt is #greater vals>arr[i], which would be the #oper. made here. Later, we 
// dec. all these modified arr[i] to next smaller value. Since the range of nums in small, we use counting sort and use an array to store #occur. of each 
// num in the array, we move from greater to smaller indices, when at index with non-zero occur. we get #greater vals than it by suffixSum and add it to res,
// we add #occur. of curr. num to suffixSum and move towards smaller vals, we skip indices with zero val and there aren't any nums with such val. We return 
// #oper. at the end of iter.







class Solution {
public:
    int reductionOperations(vector<int>& v) {
        int res=0, cnt=0;
        int occur[50001];													// Tracks #occur. of each num in the array.
        memset(occur, 0, sizeof(occur));
        for(int&num:v) occur[num]++;										// Update #occur of each num in the array.
        for(int i=50000;i>=0;i--) {											// Iter. from greater to smaller vals.
            if(occur[i]==0) continue;										// Skipping indices with zero indices as there are no such nums in the given array.
            res+=cnt;														// Adding #oper. to make all greater vals to 'i'.
            cnt+=occur[i];													// Adding #occur. of 'i' to suffixSum.
			if(cnt==v.size()) break;										// If we had converted all nums to the least value, we stop process.
        }
        return res;															// Returning #oper. to convert all nums to the least value in the array.
    }
};


