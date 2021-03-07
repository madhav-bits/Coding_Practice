/*
*
//**************************************************1031. Maximum Sum of Two Non-Overlapping Subarrays.*******************************************

https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/


Given an array A of non-negative integers, return the maximum sum of elements in two non-overlapping (contiguous) subarrays, which have lengths 
L and M.  (For clarification, the L-length subarray could occur before or after the M-length subarray.)

Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:

0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
0 <= j < j + M - 1 < i < i + L - 1 < A.length.
 

Example 1:

Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.
Example 2:

Input: A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.
Example 3:

Input: A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8] with length 3.
 

Note:

L >= 1
M >= 1
L + M <= A.length <= 1000
0 <= A[i] <= 1000


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[0,6,5,2,2,5,1,9,4]
1
2
[2,1,5,6,0,9,5,0,3,8]
4
3
[4,6,3,7,8,3,8,3,4,2,8,9,4,2,8,3,2,7,5,4,2,2,6,5,9]
4
3



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Cumulative Sum based. Here, since we are trying to find sum of L, M length subarrays. We form max arrays, which at index 'i' stores
// maximum max subarray total ending at indices <=i. In the second iteration, we form subarray total of length L,M for every index and add it to max 
// subarray total upto index (i-L) and (i-M) and maximize the result.











class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& v, int L, int M) {
        int res=0;
        vector<int>maxL(v.size(),0), maxM(v.size(),0);
        int sumL=0,sumM=0;
        for(int i=0;i<v.size();i++){
            sumL+=v[i];
            sumM+=v[i];
            if(i>=L) sumL-=v[i-L];
            if(i>=M) sumM-=v[i-M];
            if(i==L-1) maxL[i]=sumL;
            if(i==M-1) maxM[i]=sumM;
            if(i>L-1) maxL[i]=max(maxL[i-1], sumL);							// calc. L length max subarray total ending at indices <=i.
            if(i>M-1) maxM[i]=max(maxM[i-1], sumM);
        }
        // cout<<"yo"<<endl;
        sumL=0;sumM=0;
        for(int i=0;i<v.size();i++){
            sumL+=v[i];
            sumM+=v[i];
            if(i>=L) sumL-=v[i-L];
            if(i>=M) sumM-=v[i-M];
            if(i>=L+M-1) res=max(res, sumL+maxM[i-L]);						// Updating res with total of [i-L+1,i] subarr. and max of M len. subarr ending <=(i-L).
            if(i>=L+M-1) res=max(res, sumM+maxL[i-M]);
        }
        return res;															// Returning the max possible total of subarrays.
    }
};