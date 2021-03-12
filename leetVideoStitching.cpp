/*
*
//**************************************************************1024. Video Stitching.**************************************************************

https://leetcode.com/problems/video-stitching/


You are given a series of video clips from a sporting event that lasted T seconds.  These video clips can be overlapping with each other and have 
varied lengths.

Each video clip clips[i] is an interval: it starts at time clips[i][0] and ends at time clips[i][1].  We can cut these clips into segments freely: 
for example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].

Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event ([0, T]).  If the task is 
impossible, return -1.

 

Example 1:

Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
Output: 3
Explanation: 
We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
Then, we can reconstruct the sporting event as follows:
We cut [1,9] into segments [1,2] + [2,8] + [8,9].
Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].
Example 2:

Input: clips = [[0,1],[1,2]], T = 5
Output: -1
Explanation: 
We can't cover [0,5] with only [0,1] and [1,2].
Example 3:

Input: clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], T = 9
Output: 3
Explanation: 
We can take clips [0,4], [4,7], and [6,9].
Example 4:

Input: clips = [[0,4],[2,8]], T = 5
Output: 2
Explanation: 
Notice you can have extra video after the event ends.
 

Constraints:

1 <= clips.length <= 100
0 <= clips[i][0] <= clips[i][1] <= 100
0 <= T <= 100



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]]
10
[[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]]
9
[[0,4],[2,8]]
5
[[0,1],[1,2]]
5



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting and Greedy approach based. This can be restructured into finding minm. #overlapping intervals which lead to second 'T'. 
// This is similar to Frog Jump problem. Here, in the indices that can be covered by a step we calculate max. dist. that can be travelled in next step,
// at the end of curr. step we take second step and calc. maxm. next step in this way we take minm. steps/ clips to cover upto second 'T'.











class Solution {
public:
    int videoStitching(vector<vector<int>>& v, int T) {
        sort(v.begin(), v.end());											// Sort the clips based on start times.
        if(T==0) return 0;													//  Base cases.
        if(v[0][0]!=0) return -1;
        if(v[0][1]>=T) return 1;
        int steps=0;
        int currMax=0,nextMax=0;											// Tracks maxm. timestamp curr. and next clip can cover.
        for(int i=0;i<v.size();i++){
            // cout<<"i: "<<"start: "<<v[i][0]<<" and close: "<<v[i][1]<<endl;
            if(v[i][0]>currMax){											// Present clip at 'i' is after the curr. interval. 
                // cout<<"nextMax; "<<nextMax<<endl;
                if(nextMax<v[i][0]) return -1;								// If next maxm. timestamp is<curr. clip, we can't join curr. clip.
                currMax=nextMax;
                steps++;													// Inc. steps count.
            }
            nextMax=max(nextMax, v[i][1]);									// Tracking maxm. timestamp that next clip can cover.
            if(nextMax>=T) return steps+1;									// If next clip coverage>=T th second, return steps/clips required.
        }
        return -1;															// If Tth second can't be reached, return -1.
    }
};
