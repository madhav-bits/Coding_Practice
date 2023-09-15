/*
*
//*********************************************1033. Moving Stones Until Consecutive.*********************************************

https://leetcode.com/problems/moving-stones-until-consecutive/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
2
5
4
3
2
3
5
1
1
2
5
1
4
7
1
3
6
1
5
7
1
5
7
1
2
3
1
6
4
4
5
3
76
55
36
98
35
39



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. In case of max moves in every step we take the left, right border stones and move one step inside unless we have a 
// stone there, so the total #steps is (gap b/w two border stones-2).
// For min moves if there is <=1 empty space b/w any two stones we place the other stone in the middle in case of 1 empty space or beside the middle stone in 
// case of no-empty space, thus all of them are consecutive. In case of greater space b/w left, mid and mid, right pair of stones, in first instant we take 
// any of the border stone and place it beside other border now, middle stone becomes a border stone and we take this and place it beside middle stone which 
// is already beside other border stone, thus all stones are adjacent now in 2 steps.







class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if(a>b) return numMovesStones(b,a,c);								// Making sure a<b<c for convenience.
        if(b>c) return numMovesStones(a,c,b);
        if(a+1==b && b+1==c) return {0,0};									// If stones are already adjacent, we return {0,0}.
        int gap1=b-a-1, gap2=c-b-1;											// Calc. gaps b/w [left, mid] and [mid, right] stones.
        int minm=(gap1<=1 || gap2<=1)?1:2;									// If any of the gap is<=1, min steps would be 1 else it would be 2.
        int maxm=gap1+gap2;													// Max. steps is gap/empty spaces b/w two border stones.
        return vector<int>({minm, maxm});									// Returning minm, maxm moves for all stones to be adjacent.
    }
};

