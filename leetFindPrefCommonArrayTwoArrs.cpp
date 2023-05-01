/*
*
//******************************************************2657. Find the Prefix Common Array of Two Arrays.******************************************************

https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,2,4]
[3,1,2,4]
[2,3,1]
[3,1,2]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is map/array based. We use an array to mark those nums which have been in visited in each of the strings, when they are visited the second time, that means that num had occured in 
// both strings as each string has no duplicate nums in it, so we increase the cnt of #nums occured in both strs and append it to res in every iter.







class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& u, vector<int>& v) {
        vector<int>res;
        vector<bool>occur(u.size()+1, false);															// Stores occurance of a char in the strings.
        int cnt=0;
        for(int i=0;i<v.size();i++) {
            if(occur[u[i]]) cnt++;																		// If this num had already occured(in other str) before now, we inc. cnt by 1.
            occur[u[i]]=true;																			// Marking the curr. char as visited.
            if(occur[v[i]]) cnt++;																		// If this num had already occured(in other str) before now, we inc. cnt by 1.
            occur[v[i]]=true;																			// Marking the curr. char as visited.
            res.push_back(cnt);																			// Pushing the cnt to res.
        }	
        return res;																						// Returning the array with prefix common score.
    }
};

