/*
*
//****************************************************154. Find Minimum in Rotated Sorted Array II.*********************************************

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,2,2,0,1]
[2,2,2,0,1,2,2,2]
[2,2,2,0,1,2,2]
[0,0,2,2]
[0,1,2,2]
[0,1,2,3,4]
[0,1,2,3,0]

[10,10,10,1,10]
[10,10,10,10,1]
[10,10,1,10,10]
[1,10,10,10,10]
[10,1,10,10,10]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Binary Search based. We check mid and last elem., if mid<end, then res can be number prior to mid or mid itself. So, we 
// search in first half(incl. mid) or if mid>end, as we have smaller value in end, mid can't be answer, so, we move to second half(excl. mid).
// If mid== end values, it's undecidable, we just remove a dup by dec. index of end.So, in the worst case, this would take, O(n).






class Solution {
public:
    int findMin(vector<int>& v) {
        int begin=0, end=v.size()-1, mid;
        while(begin<end){
            mid=begin+(end-begin)/2;
            if(v[end]>v[mid]) end=mid;										// If last>mid, then start won't be second half.(Include mid also).
            else if(v[mid]>v[end]) begin=mid+1;								// If last<mid, mid can't be ans. , we move to second half.
            else end--;														// If both are same, remove dup.
        }
        // cout<<"The result is: "<<v[begin]<<endl;
        return v[begin];													// Returning the result.
    }
};