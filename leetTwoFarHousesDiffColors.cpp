/*
*
//******************************************************2078. Two Furthest Houses With Different Colors.******************************************************

https://leetcode.com/problems/two-furthest-houses-with-different-colors/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,1,1,6,1,1,1]
[1,8,3,8,3]
[0,1]
[1,2,3,4,3,4,5]
[1,2,3,4,5,1]
[6,6,6,6,6,6,6,6,6,19,19,6,6]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Greedy based. If last houses on both sides are of diff. they would be answer, else means both have same color, so we try to find the first non-last color index from left, right







class Solution {
public:
    int maxDistance(vector<int>& v) {
        if(v[0]!=v.back()) return v.size()-1;
        int i=0, j=v.size()-1;
        while(i<v.size() && v[0]==v[i]) i++;															// Calc. first diff. color form left.
        while(j>=0 && v[j]==v.back()) j--;																// Calc. first diff. color from right.
        return max(j, (int)v.size()-1-i);																// Returning the max. dist of the both.
    }
};

