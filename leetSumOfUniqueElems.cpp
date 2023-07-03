/*
*
//******************************************************1748. Sum of Unique Elements.******************************************************

https://leetcode.com/problems/sum-of-unique-elements/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,2]
[1,1,1,1,1]
[1,2,3,4,5]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Map based. We use an aray to track the #times each nums has occurred in the array, we update the freq. in an iter. Later, we iter. over
// this array and add those nums which occurred only once to res and return it at the end of iter.






class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int res=0;
        vector<int>occur(101, 0);											// Tracks #time each num has occurred.
        for(int&num:nums) {
            occur[num]++;													// Updating the count of each num.
        }
        for(int i=0;i<=100;i++) {
            if(occur[i]==1) res+=i;											// Adding those nums which occurred only once.
        }
        return res;															// Returning the total of unique nums.
    }
};
