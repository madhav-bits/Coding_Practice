/*
*
//********************************1477. Find Two Non-overlapping Sub-arrays Each With Target Sum.*********************************

https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/


Given an array of integers arr and an integer target.

You have to find two non-overlapping sub-arrays of arr each with sum equal target. There can be multiple answers so you have to find an 
answer where the sum of the lengths of the two sub-arrays is minimum.

Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.

 

Example 1:

Input: arr = [3,2,2,4,3], target = 3
Output: 2
Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.
Example 2:

Input: arr = [7,3,4,7], target = 7
Output: 2
Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), but we will choose the first and third 
\sub-arrays as the sum of their lengths is 2.
Example 3:

Input: arr = [4,3,2,6,2,3,4], target = 6
Output: -1
Explanation: We have only one sub-array of sum = 6.
Example 4:

Input: arr = [5,5,4,4,5], target = 3
Output: -1
Explanation: We cannot find a sub-array of sum = 3.
Example 5:

Input: arr = [3,1,1,1,5,1,2,1], target = 3
Output: 3
Explanation: Note that sub-arrays [1,2] and [2,1] cannot be an answer because they overlap.
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 1000
1 <= target <= 10^8




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[3,2,2,4,3]
3
[7,3,4,7]
7
[4,2,2,6,2,3,4]
8
[5,5,4,4,5]
3
[3,1,1,1,5,1,2,1]
4
[1,1,1,1,1,1,1,4,3,3,7,2]
6



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is map based. Here, we use the maps to store prefix sums and their indices from left and right. We first from largest
// to smallest index and right[i] indicates smallest substr whose sum is target starting from [i, v.size()-1], we do the same for left
// drn. whenever we encounter a subarray with total=target, we add that with right[i+1] and try to update the final result.








class Solution {
public:
    int minSumOfLengths(vector<int>& v, int target) {
		vector<int>left(v.size(), v.size()+1), right(v.size(), v.size()+1);
        int total=0, minLen=v.size()+1, res=v.size()+1;
        unordered_map<int,int>rightPrefix, leftPrefix;
        rightPrefix[0]=v.size();
        for(int i=v.size()-1;i>=0;i--){										// Calc. prefix sums from right side.
            total+=v[i];
            if(rightPrefix.count(total-target)==1) minLen=min(minLen, rightPrefix[total-target]-i);
            rightPrefix[total]=i;
            right[i]=minLen;												// Storing minLen subarr with target total from [i, v.size()-1]
            // cout<<"right i: "<<i<<" and minLen: "<<minLen<<endl;
        }
        
        total=0;
        leftPrefix[0]=-1;
        minLen=v.size()+1;
        for(int i=0;i<v.size();i++){										// Calc. prefix sums for left side.
            total+=v[i];
            if(leftPrefix.count(total-target)==1){							// If subarr. with total=target found. 
                minLen=min(minLen, i-leftPrefix[total-target]);
                if(i+1<v.size()) res=min(res, minLen+right[i+1]);			// Add curr. subarr len with minLen from i+1 and udpate res.
            } 
            leftPrefix[total]=i;											// Update map with prefixSum.
            
        }
        if(res!=v.size()+1) return res;										// If subarrs found, return res.
        return -1;															// If no subarrs found, return -1.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Sliding Window based. Here, we slide the window and find all subarr. whose sum is target. Whenever we found a subarr.
// we add it's length with smallest window len in index range [0, start-1] and try to update the res.







class Solution {
public:
    int minSumOfLengths(vector<int>& v, int target) {
        int res=v.size()+1, total=0, start=0, minLen=v.size()+1;
        vector<int>maxTill(v.size(),v.size()+1);
        for(int i=0;i<v.size();i++){
            total+=v[i];
            while(total>target)
                total-=v[start++];
            if(total==target){												// If subarr with target total found. 
                if(start>0 && maxTill[start-1]!=v.size()+1) res=min(res, maxTill[start-1]+i-start+1);// We add with earlier subarr.
                minLen=min(minLen, i-start+1);								// Updating the minLen subarr till now.
            }
            maxTill[i]=minLen;												// Updating the arr to store minLen till 'i'.
        }
        return (res==(int)v.size()+1)?-1:res;								// Returning the res val.
    }
};
