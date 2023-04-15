/*
*
//******************************************************2139. Minimum Moves to Reach Target Score.******************************************************

https://leetcode.com/problems/minimum-moves-to-reach-target-score/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5
0
19
2
10
4
726
5
999999995
0



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Greedy Algorithm based. Here, as we are trying to min. moves and double the number would give us max. increase based on usage, we greedily use this step at later stages of 
// process so that upon doubling the number would increase by huge margin(ex: 128 on doubling becomes 256, we see 128 inrease in a single step). On other observation is that in this process, every 
// prefix binary rep would be formed in our process. So, here we greedily use this step earlier when we observe zeroes(which indicates double move) while moving from LSB to MSB, as LSB zeroes 
// would add/inrease more value during double the value steps in our process, for 1 bits we increase by 1, we do this process until we use all double move steps. Once double move steps are completed
// and we still , we simply the rest value by increment by 1 steps.







class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res=0;
        // cout<<bitset<32>(target)<<endl;
        
        while(target>1 && maxDoubles){																	// Until double move steps are available.
            if(target%2==0) {																			// If curr. bit is zero, we use double the value move.
                target>>=1;
                maxDoubles--;
            }else target--;																				// Else we use increment by 1 step.
            res++;																						// Counting total #moves.
        }
        return res+(target-1);																			// Returning the total #moves.
    }
};
