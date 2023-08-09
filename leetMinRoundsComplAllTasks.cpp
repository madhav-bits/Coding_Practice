/*
*
//*******************************************2244. Minimum Rounds to Complete All Tasks.*********************************************

https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,2,3,3,2,4,4,4,4,4]
[2,3,3]
[2,2,2,3,3,3,3,3,2,2,2]
[2,2,2,3,3,3,3]
[2,2,2,2,2,3,3,3,3,4,4,4,4,4,4]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Map based. We use the observation that we can complete any difficulty level of task which occurs >=3 times, if they occur multiple of 3 times, that's 
// straight forward, else if we get 1 remainder, we do only 2 tasks in prev. round and carry rem. 1 task to curr. round making it 2 and we process 2 tasks now and if we are 
// left with 2 tasks, we we simply process in last round. If we have ==1 occur of a task in the beginning, we can't process this task. We use this observations while iter. 
// over #occur. of each difficuly level of task in the map and adding #rounds needed to finish each diff. level of task to res. We return #rounds at the end of iter.








class Solution {
public:
    int minimumRounds(vector<int>& v) {
        unordered_map<int,int>m;											// Tracks #occur. of each task.
        int res=0;
        for(int&num:v) m[num]++;											// Iter. over array and stores #occur. of each difficulty level of task
        for(auto it=m.begin();it!=m.end();it++) {
            if(it->second==1) return -1;									// If a diff. level occurs only once, we can't complete it, we return -1.
            res+=it->second/3;												// Calc. #rounds needed to finish curr. difficulty level of tasks.
            if(it->second%3!=0) res++;
        }
        return res;															// Returning total #rounds needed to finish all tasks.
    }
};

