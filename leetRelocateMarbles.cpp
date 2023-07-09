/*
*
//******************************************************2766. Relocate Marbles.******************************************************

https://leetcode.com/problems/relocate-marbles/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,6,7,8]
[1,7,2]
[2,9,5]
[1,1,3,3]
[1,3]
[2,2]
[2,3,6,8,5]
[2,6,5]
[5,7,2]
[1,2,6,7,8]
[7,2,6,8,1]
[2,1,8,1,6]
[5,7,8,15]
[5,7,8,9]
[9,15,2,7]
[3,4]
[4,3,1,2,2,3,2,4,1]
[3,1,2,2,3,2,4,1,1]
[2]
[2,1,2]
[1,2,3]



// Time Complexity: O(n+m+nlogn).											// n-#nums in the array, m-#length of moves array.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m+nlogn).											// n-#nums in the array, m-#length of moves array.
// Space Complexity: O(n).	
// This algorithm is Map based. As the range of nums is large and we only need to report their occurrance, we use sets. We iter. over the moves arrays, we 
// add new entry into map for the moveTo curr.val, and delete the moveFrom entry from the map. If the moveTo, moveFrom curr. values are the same we skip 
// this index. We add the entries in the map into res array, since we used unordered_set, we sort the res array and return it.







class Solution {
public:
    vector<int> relocateMarbles(vector<int>& v, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int>st;
        for(int&num:v) st.insert(num);										// Tracks the occurrance of the nums in the array.
        for(int i=0;i<moveFrom.size();i++) {
            if(moveFrom[i]==moveTo[i]) continue;							// If move from and to vals are the same, skip this index.
            st.insert(moveTo[i]);											// Add an entry for moveTo value.
            st.erase(moveFrom[i]);											// Delete the moveFrom value.
        }
        vector<int>res(st.begin(), st.end());								// Copying vals. in set into res array.
        sort(res.begin(), res.end());										// Sort the res array.
        return res;															// Returning the sorted final state values.
    }
};

