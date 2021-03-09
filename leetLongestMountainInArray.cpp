/*
*
//**********************************************************845. Longest Mountain in Array.***************************************************

https://leetcode.com/problems/longest-mountain-in-array/



You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 104
 

Follow up:

Can you solve it using only one pass?
Can you solve it in O(1) space?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[2,1,4,7,3,2,5]
[1,2,3,4,5]
[2,2,2]
[4,2,2,3,4,5,6,5,4,4,3,3,5,7]
[3,2]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we keep track of #inc. or #dec. numbers in the sequence, Whenever we encounter v[i]==v[i-1] or 
// dec>0 && v[i]>v[i-1], it means we are starting looking for new mountain and we reset up and down=0. If keep track of up and down based on curr. and 
// prev. nums. If up and down>0, we try to maximize the mountain length and return it at the end of the iteration.




// This link had good explanation for both the approaches.
// https://leetcode.com/problems/longest-mountain-in-array/discuss/135593/C%2B%2BJavaPython-1-pass-and-O(1)-space






class Solution {
public:
    int longestMountain(vector<int>& v) {
        int up=0, down=0, res=0;
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1] || (down>0 && v[i]>v[i-1])) up=0,down=0;		// Resettting up and down=0, as we look for new mountain.
            if(v[i]>v[i-1]) up++;											// Updating up count.
            if(v[i]<v[i-1]) down++;											// Updating down count.
            if(up && down) res=max(res, up+down+1);							// If up and down>0, mountain present and we maximize the mountain length.
        }
        return res;															// We return the max. mountain length.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. We iter. two times in the first iter. we calc. #inc. seq. ending at every index. In the second iter. we update #dec.
// seq. length at every index, if inc. and dec. length >1, it indicates that mountain exists and we keep track of max length of mountain encountered and
// return it at end of iteration.













class Solution {
public:
    int longestMountain(vector<int>& v) {
        vector<int>inc(v.size(),1), dec(v.size(),1);						//  Track inc. or dec. length ending at every index.
        int res=0;
        for(int i=1;i<v.size();i++){
            if(v[i]>v[i-1]) inc[i]=inc[i-1]+1;								// Updating inc. length at index 'i'.
        }
        for(int i=v.size()-2;i>=0;i--){
            if(v[i]>v[i+1]){
                dec[i]=dec[i+1]+1;											// Updating dec. length at index 'i'.
                if(inc[i]>1) res=max(res, inc[i]+dec[i]-1);					// If mountain exists, we udpate the max. mountain length.
            }
        }
        return res;															// Returning the max. mountain length.
    }
};

