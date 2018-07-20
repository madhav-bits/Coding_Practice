/*
*
//*****************************************************702. Search in a Sorted Array of Unknown Size.**********************************************

Given an integer array sorted in ascending order, write a function to search target in nums.  If target exists, then return its index, otherwise 
return -1. However, the array size is unknown to you. You may only access the array using an ArrayReader interface, where ArrayReader.get(k) 
returns the element of the array at index k (0-indexed).

You may assume all integers in the array are less than 10000, and if you access the array out of bounds, ArrayReader.get will return 2147483647.

 

Example 1:

Input: array = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: array = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Note:

You may assume that all elements in the array are unique.
The value of each element in the array will be in the range [-9999, 9999].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[-1,0,3,5,9,12]
9


[5]
-5


[-1]
-5



[]
1



// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Binary Search based. We start from index-0, and keep on increasing the scanning indices twice each time, until a node
// with greater/equal val. that of target is obtained. Once, greater val. is encoun., we search from curr. index/2 to curr. index for the 
// target value using Binary search, as target value>curr. index/2's value and <=curr. index's value.








// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int start=1,end=0;													// Tracks start, end indices of observation.					
        int val1=reader.get(0);
        if(val1==INT_MAX || val1>target) return -1;							// If array size=0,target<arr[0], then return false.
        if(target==reader.get(0)) return 0;									// If target is at index=0, then return 0.
        while(reader.get(start-1)!=INT_MAX && reader.get(start-1)<target) start*=2;// Until a greter val./equal val. is reached.
        end=start-1;														// Setting the start, end indices for binary search.
        start/=2;
        start--;															// Setting the start index.
        // cout<<"start: "<<start<<" and end: "<<end<<endl;
        while(start<end){													// While start<end index under observation.
            int mid=(start+end)/2;											// Calc. middle index.
            int val=reader.get(mid);										// Get mid index's value.
            if(val==target) return mid;										// If target reached, return mid index.
            if(val>target) end=mid;											// If target<mid value, then search in left half of indices.
            else start=mid+1;												// Else, check in right half of indices.
        }
        return (reader.get(start)==target)?start:-1;						// If the narrowed down last observing index has target value or not?
    }
};