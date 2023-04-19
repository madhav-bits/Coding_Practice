/*
*
//******************************************************2481. Minimum Cuts to Divide a Circle.******************************************************

https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4
1
2
3
5
7
6
8
10
100
99
94



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. For even splits we can use the diagonal cut which results in adding two more slices. So, n/2 cuts result in n slices, for odd n value, we have to use raidus 
// cut, we use n cuts to create n slices.







class Solution {
public:
    int numberOfCuts(int n) {
        if(n<=2) return n-1;																			// Base condition.
        if(n%2==0) return n/2;																			// For even #slices, we return n/2, as we use n/2 diagonal cuts.
        return n;																						// For odd #slices, we return n, as we use n radius cuts.
    }
};

