/*
*
//*********************************************1010. Pairs of Songs With Total Durations Divisible by 60.***************************************

You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices 
ai, j such that i < j with (time[i] + time[j]) % 60 == 0.

 

Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
Example 2:

Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
 

Constraints:

1 <= time.length <= 6 * 104
1 <= time[i] <= 500



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[30,20,150,100,40]
[3,90,45,34,533,2543,255,60,606,300,360,420]
[30,30,303,303,03,3030,30,30,30,30,30,60]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm involves matching pairs, we can take #occurances of each of the %60 values, we match it with other song whose addition makes it divisible
// by 60. We iter over array and get cnt of %60 values, in the second iter. we iter. from 31 to 59 and look for lower %60 val song and multiply their occur.
// to get #pairs with given requirement. We treat 30 and 0 separately as they themselves can form pairs and meet the requirement. 








class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& v) {
        vector<int>occur(60,0);
        for(int num:v) occur[num%60]++;										// Get #occur. of %60 values.
        int res=0;
        for(int i=31;i<60;i++){												// Forming pairs.
            res+=occur[i]*occur[60-i];
        }
        int val=occur[30];
        res+=(val*(val-1))/2;												// 30 mins songs pairing with themselves.
        val=occur[0];
        res+=(val*(val-1))/2;												// 60 mins songs pairing with themselves.
        return res;
    }
};