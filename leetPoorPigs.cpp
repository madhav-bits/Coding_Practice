/*
*
//************************************************************458. Poor Pigs.*****************************************************

There are 1000 buckets, one and only one of them contains poison, the rest are filled with water. They all look the same. If a pig drinks that 
poison it will die within 15 minutes. What 
is the minimum amount of pigs you need to figure out which bucket contains the poison within one hour.

Answer this question, and write an algorithm for the follow-up general case.

Follow-up:

If there are n buckets and a pig drinking poison will die within m minutes, how many pigs (x) you need to figure out the "poison" bucket 
within p minutes? There is exact one bucket with poison.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
0
1000
12



// Time Complexity: O(logn).  												// Calc. log value.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1ogn).												// Calc. log value.									
// Space Complexity: O(1).	
// This algorithm is tricky one. This link gives the complete explanation of the logic I had used.


https://leetcode.com/problems/poor-pigs/discuss/94266/Another-explanation-and-solution





class Solution {
public:
    int poorPigs(int buckets, int toDie, int toTest) {	
        if(buckets==0) return 0;											// If buckets=0, return 0.
        int times=toTest/toDie;												// No of intervals available.
        int res=ceil(log(buckets)/log(times+1));							// Get #pigs required.
        // cout<<"reslut is: "<<res<<endl;
        return res;															// Return #pigs.
    }
};