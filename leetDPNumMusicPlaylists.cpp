/*
*
//******************************************************920. Number of Music Playlists.***********************************************

Your music player contains N different songs and she wants to listen to L (not necessarily different) songs during your trip.  You create a 
playlist so that:

Every song is played at least once
A song can only be played again only if K other songs have been played
Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.

 

Example 1:

Input: N = 3, L = 3, K = 1
Output: 6
Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
Example 2:

Input: N = 2, L = 3, K = 0
Output: 6
Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]
Example 3:

Input: N = 2, L = 3, K = 1
Output: 2
Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]
 

Note:

0 <= K < N <= L <= 100



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



8
11
5


4
6
1






// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. Here, since we have to use all given songs. We construct based on number of songs used, number
// of songs in playlist obtained. Here, dp[i][j] depends on dp[i][j-1] and dp[i-1][j-1]. In case of dp[i][j-1], we are adding one more song
// to playlist, from the already chosen songs, since 'k' prev. songs can't be used, we have 'j-k' possibilities, we mutiply this with dp[i][j-1]
// and add it to dp[i][j]. In case of dp[i-1][j-1], we add one new song to playlist, we have 'total-i-1' songs avaialbe, as we are forming #combi.
// in which 'i' songs can be arranged, we mutiply dp[i-1][j-1] with 'i' and add it to dp[i][j], at the end we return dp[total][playlist].


// dp[i][j] indicates total #combi. in which 'i'songs are used to obtain playlists of 'j' songs.





class Solution {
public:
    
    long long int factorial(int num){										// Calc. factorial.
        if(num<=1) return 1;//(long long int)
        return (factorial(num-1)*num)%1000000007;
    }
    
    int numMusicPlaylists(int total, int playlist, int gap) {
        if(playlist<total || gap>=total) return 0;							// Base cases.
        int modu=1000000007;
        long long int res=0;												// Final result var.
        vector<vector<long long int>>dp(total+1,vector<long long int>(playlist+1,0));// DP array.
        for(int i=gap+1;i<=total;i++){										// Iter. over all songs provided.
            for(int j=i;j<=playlist;j++){									// Iter. over all playlist range to be formed.
                if(i==gap+1 || i==j) dp[i][j]=factorial(i);					// Base cases(As i Uniq. songs are used, factorial is calc.).
                else{														// Update curr. value based on prev.(i-1) combi. of songs.
                    dp[i][j]=((dp[i-1][j-1]*i)+(dp[i][j-1]*(i-gap)))%modu;
                }
            }
        }
        return dp[total][playlist];											// Return the #combi. to get playlist #songs using total #songs.
    }
};