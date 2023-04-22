/*
*
//******************************************************2432. The Employee That Worked on the Longest Task.******************************************************

https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


10
[[0,3],[2,5],[0,9],[1,15]]
10
[[0,3],[2,5],[0,29],[1,35]]
26
[[1,1],[3,7],[2,12],[7,17]]
3
[[0,10],[1,20]]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. over the array and calc. task duration for the task at each index, if curr. task duration is>maxTime/ if task duration=maxTime but the emp id<res id,
// we update the max Time and also the res id. We return the res id at the end of iteration.







class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& v) {
        int res=v[0][0], maxTime=v[0][1];																// Set the res id, maxTime to the task at index-0.
        for(int i=1;i<v.size();i++) {
            int diff=v[i][1]-v[i-1][1];																	// Calc. time for the curr. task.
            if(diff>maxTime || (diff==maxTime && res>v[i][0])) {										// If curr. task time>maxTime or if task time is equal but emp Id is smaller, we update.
                maxTime=diff;																			// Update maxTime and the corresponding emp Id.
                res=v[i][0];
            }
        }
        return res;																						// Returning the emp id with the longest task duration.
    }
};
