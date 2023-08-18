/*
*
//******************************************************2295. Replace Elements in an Array.******************************************************

https://leetcode.com/problems/replace-elements-in-an-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,4,6]
[[1,3],[4,7],[6,1]]
[1,2]
[[1,3],[2,1],[3,2]]
[1,2,4,5,3]
[[2,6],[4,2],[5,7],[7,8],[3,5],[5,10]]
[1,2,4,5,3]
[[2,1000000],[4,2],[5,999999],[1,242233],[3,38373],[38373,4]]




// Time Complexity: O(n+m+l).												//n-size of nums array, l-size of oper. array, m-range of nums.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m+l).												//n-size of nums array, l-size of oper. array, m-range of nums.
// Space Complexity: O(m).	
// This algorithm is iteration based. Here, as the range of nums that we operate on is medium size for Time constraints and at every instant all the nums in 
// the array would be unique, so we can use an array to track the indices of each of the nums in the array. We first iter. over array and map nums in the array
// and their indices to indices and value in numIndex array. While iter. over operations, we get the index num: u[0] is in from numIndex and update
// numIndex[u[1]] with the index of u[0] and update numIndex[u[0]]=-1 as this wont be present in array now. In this process we also update the num stored in 
// index: numIndex[u[0]] to u[1]. So, at every point we ensure our array stays updated, so we return the array we complete iter. over operations.







class Solution {
public:
    vector<int> arrayChange(vector<int>& v, vector<vector<int>>& operations) {
        int numIndex[1000001];
        memset(numIndex, -1, sizeof(numIndex));
        for(int i=0;i<v.size();i++) numIndex[v[i]]=i;						// Map nums to their indices in given array.
        for(vector<int>&u:operations) {
            numIndex[u[1]]=numIndex[u[0]];									// Update index of new num with the Index of old num. 
            v[numIndex[u[0]]]=u[1];											// Update array's corres. index with the new number.
            numIndex[u[0]]=-1;												// Update numIndex's old num index with -1, as this num is removed from array.
        }
        // for(int i=0;i<=1000000;i++) {
        //     if(numIndex[i]!=-1) v[numIndex[i]]=i;
        // }
        return v;															// Returning the updated array after all operations.
    }
};

