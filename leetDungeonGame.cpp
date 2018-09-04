/*
*
//************************************************************174. Dungeon Game.*****************************************************

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out 
in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the 
princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies 
immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either 
empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> 
DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)
 

Note:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[-2,-3,3],[-5,-10,1],[10,30,-5]]



[[-2,-3,1,4],[4,-10,2,-3],[-2,10,-5,-7]]


[[-2,-3,1,4]]



[[-2,3,1,4],[4,10,2,-3],[-2,10,5,-7]]



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. For the Knight to be alive his allowed min health is 1. We start moving from Princess towards
// [0,0] in Top, Left directions. We first set the min. allowed health in the Princess's index(If room has threat of x, then min. health Knight
// has to have prior entering is -x+1, if it has magical Orbs, then Min health required is 1). Then, we iterate from backwards, if right index
// exists for a curr. index, min. health prior entering curr. index=Min. health in right index-curr. index's threat/Orbs value. The same logic 
// applies if a bottom index also, we extract min possible value from both these possibilities. If after calculation, the min. health for curr. 
// index becomes <=0, we set to 1(Least allowed health to be alive). Thus, we iter. and reach [0,0] index. We return the value in dp[0,0] index.








class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& v) {
        vector<vector<int>>dp(v.size(), vector<int>(v[0].size(),INT_MAX));
        if(v[v.size()-1][v[0].size()-1]<0) dp[v.size()-1][v[0].size()-1]=-v[v.size()-1][v[0].size()-1]+1;// Setting the val. in last index.
        else dp[v.size()-1][v[0].size()-1]=1;								// If index has Orbs, min. required is 1.
        for(int i=v.size()-1;i>=0;i--){										// Iter. over entire array to get min. required health.
            for(int j=v[0].size()-1;j>=0;j--){								// From Bottom Right to Top Left.
                if(i==v.size()-1 && j==v[0].size()-1) continue;				// Skip the last index.
                if(i+1<v.size()) dp[i][j]=min(dp[i][j],dp[i+1][j]-v[i][j]);	// If right index exists, curr. val depends on right index's value.
                if(j+1<v[0].size()) dp[i][j]=min(dp[i][j],dp[i][j+1]-v[i][j]);// If Bottom index exists.
                if(dp[i][j]<=0) dp[i][j]=1;									// If resulting val. is <=0, set to least allowed health(1).
            }
        }
        // for(auto nums:dp){												// Printing out the DP array's values to debug.
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }	
        return dp[0][0];													// Return Min. required health to start(index [0,0]).
    }
};