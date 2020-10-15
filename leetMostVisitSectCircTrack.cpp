/*
*
//*************************************1560. Most Visited Sector in a Circular Track.**************************************

https://leetcode.com/problems/most-visited-sector-in-a-circular-track/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked on test cases provided with the question.

4
[1,3,1,2]
2
[2,1,2,1,2,1,2,1,2]
7
[1,3,5,7]
3
[3,2,1,2,1,3,2,1,2,1,3,2,3,1]



// Time Complexity: O(n).  													// n- #sectors in the track.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- #sectors in the track.
// Space Complexity: O(n).	
// This algorithm is observation based. Since, this is a circular track maxm. visited sectors would always start from 
// begin sector, two cases arise based on the sector we stop at. If stopped sector is >= start sector, we iter. from start
// to stop sector and store it. If stop< start, we iter. from 1 to stop and iter. from start to #sectors in track and
// store them and return the collection of maxm. visited sectors.








class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& v) {
        vector<int>res;
        for(int i=v[0];v[0]<=v.back() && i<=v.back();i++) res.push_back(i);	// If stop>=start.
        
		// If stop<start.
        for(int i=1;v.back()<v[0] && i<=v.back();i++) res.push_back(i);		// Collecting sectors from [1, stop]
        for(int i=v[0];v.back()<v[0] && i<=n;i++) res.push_back(i);		// Collecting sectors from [start, #sec. in track]
        return res;															// Returning the maxm. visited sectors.
    }
};