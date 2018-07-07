/*
*
//**********************************************************760. Find Anagram Mappings.***************************************************

Given two lists Aand B, and B is an anagram of A. B is an anagram of A means B is made by randomizing the order of the elements in A.

We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.

These lists A and B may contain duplicates. If there are multiple answers, output any of them.

For example, given

A = [12, 28, 46, 32, 50]
B = [50, 12, 32, 46, 28]
We should return
[1, 4, 3, 2, 0]
as P[0] = 1 because the 0th element of A appears at B[1], and P[1] = 4 because the 1st element of A appears at B[4], and so on.
Note:

A, B have equal lengths in range [1, 100].
A[i], B[i] are integers in range [0, 10^5].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[12,28,46,12,50]
[50,12,12,46,28]

[12,28,46,32,50]
[50,12,32,46,28]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is HashMap based. We iterate the first array and store the indices of all values in map. We iterate the second array, for
// each elem. we get the index from map, and push curr. index to final result.








class Solution {
public:
    vector<int> anagramMappings(vector<int>& u, vector<int>& v) {
        unordered_map<int,vector<int>>m;									// Tracks rln b/w num and index.
        for(int i=0;i<u.size();i++) m[u[i]].push_back(i);					// Storing num's indices of first array.
        vector<int>res(u.size());											// Stores num's replaced indices in second array.
        for(int j=0;j<v.size();j++){	
            res[m[v[j]].back()]=j;											// Storing second array's num's index in final result array.
            m[v[j]].pop_back();												// Popping the last index of curr. num in first array.
        }
        return res;															// Returning the final result array.
    }
};