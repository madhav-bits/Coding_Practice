/*
*
//******************************************************1921. Eliminate Maximum Number of Monsters.******************************************************

https://leetcode.com/problems/eliminate-maximum-number-of-monsters/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,4]
[1,1,1]
[1,1,2,3]
[1,1,1,1]
[3,2,4]
[5,3,2]
[5,7,6,10,23,12,14,15,12,14,24,25,34,20,14,16,30,28]
[2,4,3,5,4,7,2,1,2,3,4,5,4,6,5,7,6,4]



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Sorting based. We first calc. time taken by each monster to reaching player and sort them. We keep on eliminating monsters in inc. 
// order of time taken to reach player, iterator actually indicates we are ready to eliminate another monster after reloading, the moment time[i]<=i we stop 
// the iter. as this indicates monster reached player before he can eliminate the player. We return the #monsters eliminated until now.







class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>time(dist.size(),0);
        for(int i=0;i<dist.size();i++) {
            time[i]=(0.0+dist[i])/(0.0+speed[i]);							// Calc. time taken by each monster to reach player.
        }
        sort(time.begin(), time.end());										// Sort based on time taken.
        int res=0;
        for(int i=0;i<time.size();i++) {
            // cout<<"time: "<<time[i]<<endl;
            if(time[i]<=i) break;											// If the monster reached player, we stop playing.
            res++;															// We eliminate curr. monster and get ready after 1 second, i.e., next iter.
        }
        
        
        return res;															// Returning the max. #monsters eliminated.
    }
};

