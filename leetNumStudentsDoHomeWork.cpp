/*
*
//**********************************1450. Number of Students Doing Homework at a Given Time.*************************************

Given two integer arrays startTime and endTime and given an integer queryTime.

The ith student started doing their homework at the time startTime[i] and finished it at time endTime[i].

Return the number of students doing their homework at time queryTime. More formally, return the number of students where 
queryTime lays in the interval [startTime[i], endTime[i]] inclusive.

 

Example 1:

Input: startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
Output: 1
Explanation: We have 3 students where:
The first student started doing homework at time 1 and finished at time 3 and wasn't doing anything at time 4.
The second student started doing homework at time 2 and finished at time 2 and also wasn't doing anything at time 4.
The third student started doing homework at time 3 and finished at time 7 and was the only student doing homework at time 4.
Example 2:

Input: startTime = [4], endTime = [4], queryTime = 4
Output: 1
Explanation: The only student was doing their homework at the queryTime.
Example 3:

Input: startTime = [4], endTime = [4], queryTime = 5
Output: 0
Example 4:

Input: startTime = [1,1,1,1], endTime = [1,3,2,4], queryTime = 7
Output: 0
Example 5:

Input: startTime = [9,8,7,6,5,4,3,2,1], endTime = [10,10,10,10,10,10,10,10,10], queryTime = 5
Output: 5
 

Constraints:

startTime.length == endTime.length
1 <= startTime.length <= 100
1 <= startTime[i] <= endTime[i] <= 1000
1 <= queryTime <= 1000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[1,2,3]
[3,2,7]
4


[9,8,7,6,5,4,3,2,1]
[10,10,10,10,10,10,10,10,10]
5



// Time Complexity: O(n).  													// n- Size of the array.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- Size of the array.
// Space Complexity: O(1).	
// This algorithm is comparision based. We iter. over array of intervals, for every interval, we check whether queryTime is within 
// interval by comparing, if true, we inc. the value of res by 1. At the end of iter., we return res, the #students doing homework.




class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res=0;															// Tracks #students doing home work.
        for(int i=0;i<startTime.size();i++){								// Iter. over array.
            if(startTime[i]<=queryTime && queryTime<=endTime[i]) res++;		// If queryTime is in between start and endTime, inc. res.
        }
        return res;															// Return the total count of students doing homework.
    }
};