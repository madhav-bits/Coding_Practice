/*
*
//******************************************************2103. Rings and Rods.******************************************************

https://leetcode.com/problems/rings-and-rods/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"B0B6G0R6R0R6G9"
"B0R0G0R9R0B0G0"
"G4"
"R1G1G1R2G3B4B1"
"R1G1G1R2G3B4B1B2G2"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Binary Representation+Iteration based. Here, we iter. over given string and store the occurance of chars in an int array where 'R','G', 'B' are stored in 1,2,3 bits of the numbers stored in the corres. index.
// After iter. over string, we iter. over int array and if a num==7, that means that index has three Rings present there(3 bits are set), so we inc. the res value and return at end of int array iteration.






class Solution {
public:
    int countPoints(string s) {
        int res=0;
        vector<int>rep(10,0);																			// Stores the occur. of Rings in each of the indices.
        for(int i=0;i<s.length();i+=2) {																// Iter. over given string.
            char ch=s[i];																				// Get curr. char and corresponding rod psn/index.
            int index=(s[i+1]-'0');
            if(ch=='R') rep[index]|=1;																	// If curr. char is 'R', first bit is set.
            else if(ch=='G') rep[index]|=2;
            else if(ch=='B') rep[index]|=4;
        }
        for(int i=0;i<10;i++) {																			// Iter. over int array.
            if(rep[i]==7) res++;																		// If a index/corresponding rod has all three types of rings, we inc. the res value.
        }
        return res;																						// Returning the #rods with all three types/colors of rings.	
    }	
};

