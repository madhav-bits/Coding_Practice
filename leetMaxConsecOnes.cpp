/*
*
//******************************************************485. Max Consecutive Ones.***********************************************

Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,0,1,0,1,0]
[0]
[1]
[1,0,1]





// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the array, at each step we check for 0/1, if 1 encountered, we inc. the count and we try to update the max. len. If 
// 0 encountered, we set the length =0.




class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int res=0, count=0;											// Final result, count of conse. ones at curr. index.
        for(int i=0;i<v.size();i++){
            if(v[i]==1) res=max(res,++count);						// Checking at each occurane of 1, whether max. can be changed or not?
            else count=0;											// If 0 encountered, change the count=0.
        }
        return res;													// Returning the max. len of consec. ones.
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the array, at each step we check for 0/1, if 1 encountered, we inc. the count.
// If 0 encountered, we try to update the max. len, we reset the length =0.



class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int res=0, count=0;											// Final result, count of conse. ones at curr. index.
        for(int i=0;i<v.size();i++){
            if(v[i]==1) count++;									// If 1 encountered, we inc. the count.
            else{
                res=max(res,count);									// We try to update the max. len of consec. ones.
                count=0;											// Reset the count=0.
            } 
        }
        res=max(res,count);											// We try to update the max. len of consec. ones.(conse. 1's ending at len-1)
        return res;													// Returning the max. len of consec. ones.
    }
};