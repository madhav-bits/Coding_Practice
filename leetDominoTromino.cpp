/*
*
//********************************************************790. Domino and Tromino Tiling.*************************************************

We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.

XX  <- domino

XX  <- "L" tromino
X
Given N, how many ways are there to tile a 2 x N board? Return your answer modulo 10^9 + 7.

(In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells 
on the board such that exactly one of the tilings has both squares occupied by a tile.)

Example:
Input: 3
Output: 5
Explanation: 
The five different ways are listed below, different letters indicates different tiles:
XYZ XXZ XYY XXY XYY
XYZ YYZ XZZ XYY XXY
Note:

N  will be in range [1, 1000].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



0
1
33
900
999
1000


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is DP based. Here we use five vars to save #ways to fill tiles upto length N-2, N-1, N and #ways to fill tiles upto length N-2 
// and upper one in length N-1 and a var to store #ways to fill Lower one in length N-1 and fill all earlier lengths. We extract #ways to get 
// work get curr. psn by working on all prev. psns from which the curr. psn can be obtained by using single tile. This way, we fill the five vars
// mentioned above at each length and thus obtain the final result(#ways to fill tiles upto length N).



class Solution {
public:
    int numTilings(int N) {
		
		int curr=0;																		// #ways to fill tiles upto length N.
        int prev=1;																		// #ways to fill tiles upto length N-1.
																						// This value is 1 as no tiles scenario satisfies cdn.
		int morePrev=0;																	// #ways to fill tiles upto length N-2.
		int prevUp=0;																	// #ways to fill tiles upto Upper one in len N-1.
		int prevDown=0;																	// #ways to fill tiles upto Lower one in len N-1.
		
        
        long temp=0;
        for(int i=1;i<=N;i++){                                                                          //1000000007
            curr=(int)((temp+morePrev+prev+prevUp+prevDown)%1000000007);				// Curr. length can be filled by adding a single tile to
																						// all these prev. fillings.
            prevDown=(morePrev+prevDown)%1000000007 ;									// prevDown and RHS psns differ by single tile.
            prevUp=(morePrev+ prevUp)%1000000007;										// prevUp and RHS psns differ by single tile.
            morePrev=prev;																// Updating morePrev count.
            prev=curr;																	// Updating the prev count.
        }
        
        return curr;
    }
};