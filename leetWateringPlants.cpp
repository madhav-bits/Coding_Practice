/*
*
//******************************************************2079. Watering Plants.******************************************************

https://leetcode.com/problems/watering-plants/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,2,3,3]
5
[1,1,1,4,2,3]
4
[7,7,7,7,7,7,7]
8




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, when we are at index 'i' in the iteration, we are physically at index 'i-1', if the curr. water > water needed at index 'i', we remove the water from curr.
// water and move to curr. index, if curr. water < water needed at index 'i', we travel to well( index: -1) and return to index 'i-1', so we add 2*i for the distance covered and add +1 for moving
// to curr. index after watering the plant. We return the total distance/steps made at the end of iter.







class Solution {
public:
    int wateringPlants(vector<int>& arr, int cap) {
        int res=0, curr=0;
        for(int i=0;i<arr.size();i++) {
            if(curr<arr[i]) {																			// If curr. water<water needed.
                res+=2*i;																				// To and from index 'i-1' to '-1' to refill the can.
                curr=cap;																				// Updating the can to max. possible.
            }
            curr-=arr[i];																				// Water the plant at index 'i'.
            res++;																						// Move to curr. index.
        }
        return res;																						// Return the total #steps taken.
    }
};

