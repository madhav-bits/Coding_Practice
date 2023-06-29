/*
*
//******************************************************1817. Finding the Users Active Minutes.******************************************************

https://leetcode.com/problems/finding-the-users-active-minutes/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,5],[1,2],[0,2],[0,5],[1,3]]
5
[[1,1],[2,2],[2,3]]
4
[[4,3],[1,3],[2,2],[6,1],[6,3],[2,5],[3,8],[5,8],[6,2]]
6



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Map+Set based. Here, since the range of ids is huge, we use map to keep track of all ids mentioned in the logs. We use set to store all times that an 
// user had performed an action in leetcode as the usage would be sporadic, using set would save space when compared to array. While iterating we store the ids as key and 
// the used time in the set corresponding to the key. At the end of iter., we iter. over map update the res array with #ids with same #usage times and return it.






class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int>res(k,0);
        unordered_map<int, unordered_set<int>>m;							// Stores [ids, usage time set] pairs.
        for(vector<int>&v:logs) {
            m[v[0]].insert(v[1]);											// Inserting the usage time for the corresponding id.
        }
        for(auto it=m.begin();it!=m.end();it++) {							// Iter. over all ids and their corresponding usage time sets.
            res[it->second.size()-1]++;										// Updating the res with #ids with same #usage times count.
        }
        
        return res;															// Returning the res with #ids with same #index numbered usage times.
    }
};
