/*

//****************************************************************403. Frog Jump.*********************************************************

A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, 
but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last 
stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward 
direction.

Note:

The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

[0,1,2,3,4,8,9,11]

Return false. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[0,1,3,4,5,7,9,10,12]



[0,1,3,5,6,7,8,9,12,15,17,20]




// Time Complexity: O(n).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. Here, for every stone we track the prev. stones from which it is possible to make a jump onto
// this stone. When we are at a stone, we iter. over stones and calc. dist. for stones from which we are successfully making onto curr. stone
// and check for next stones with dist, dist+1, dist-1, if we find any stones in that psn, we mark stones with successful jumps from curr. stone
// This way we iterate over all stones. At the end of iteration, we check on last stone while iter. over prev. stones, if we are able to 
// make successful jumps onto it prev. stones return true else return false.



// dp[i][j] indicates whether we are able to make successful jump from index 'i' to 'j', when we can reach index 'i' from '0' index successfully.



// OBSERVATION: Whenever the next step is curr. step+1, curr. step, curr. step+1, as steps move on, the range of steps would be increasing and
// forms a conse. sequence of values.





class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len=stones.size();
        if(stones[1]!=1) return false;										// If there is no stone at 1 psn, return false.
        unordered_map<int,int>dist;											// Maps psn of stones to their indices in array.
        for(int i=0;i<stones.size();i++){									// Map psns to indices.
            dist[stones[i]]=i;
        }
        vector<vector<bool>>dp(len,vector<bool>(len+1,false));				// Tracks successful jumps b/w indices.
        dp[0][0]=true;														// Base case.
        dp[1][0]=true;														// Base case.
        for(int i=1;i<stones.size();i++){									// Iter. over all indices.
            for(int j=0;j<i;j++){											// Iter. over prev. indices of curr. index.
                if(dp[i][j]==true){											// If there is successful jump from 'i' to 'j'.
                    int gap=stones[i]-stones[j];							// Calc. gap b/w them.
                    if(dist.count(stones[i]+gap)==1){						// Check for stone in the curr. psn+gap.
                        dp[dist[stones[i]+gap]][i]=true;					// If stone present mark corres. dp index to be true.
                    }
                    if(dist.count(stones[i]+gap-1)==1){						// Check for stone in the curr. psn+gap-1.
                        dp[dist[stones[i]+gap-1]][i]=true;
                    }
                    if(dist.count(stones[i]+gap+1)==1){						// Check for stone in the curr. psn+gap+1.
                        dp[dist[stones[i]+gap+1]][i]=true;
                    }
                }
            }
        }
        // for(int i=0;i<stones.size();i++){
        //     // cout<<stones[i]<<"  ";
        //     for(int j=0;j<stones.size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int j=0;j<stones.size();j++){									// Checking on last stone from prev. stones.
            if(dp[len-1][j]==true) return true;								// If we are able to reach it from prev. index, return true.
        }
        return false;														// If last stone not reachable, return false.
        
    }
};