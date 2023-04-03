/*
*
//******************************************************2125. Number of Laser Beams in a Bank.******************************************************

https://leetcode.com/problems/number-of-laser-beams-in-a-bank/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["011001","000000","010100","001000"]
["011001","100000","010100","001000"]
["000","111","000"]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, as we can't have devices in the row b/w two rows containing devices which makes up lasers, it means we can have lasers b/w any two consecutive rows which have non-zero devices in them.
// So, we calc. #devices in each row, if it is zero, we move to next row, if not we get the prev non-zero devices row's devices count, we multiply both of these to get all possible combination of lasters b/w these two rows and
// add this product to res, we update the prev. non-zero #devices count to curr. devices count, we move to next row then. We return res at end of iter.







class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res=0, prev=0;																				// Stores #lasers, #devices in prev. non-zero devices row.
        
        for(string&s:bank) {																			// Iter. over all rows.
            int curr=0;
            for(char&ch:s) {																			// Calc. #devices in curr. row.
                if(ch=='1') curr++;
            }
            if(curr) {																					// If curr. row has non-zero devices.
                res+=prev*curr;																			// We multiply to get #lasers possible with curr. row's devices and prev. non-zero devices row.
                prev=curr;																				// Updating the prev. non-zero devices count.
            }
        }
        
        return res;																						// Returning the total #lasers.
    }
};

