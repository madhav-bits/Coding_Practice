/*
*
//***************************************2006. Count Number of Pairs With Absolute Difference K.****************************************

https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,2,1]
1
[3,2,1,5,4]
2
[1,3]
3
[1,100,99,3,4,96,97,99,98,60]
3



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Map based. Since the range of nums is small, we use an array to store the #occur. of each num. During iter. for every num, we check for 
// curr. num-k, curr. num+k from prev. iterated values and their occur. to res and them and curr. index would form pairs which would product desired abs. diff.
// We return #pairs at the end of iter.






class Solution {
public:
    int countKDifference(vector<int>& v, int k) {
        int res=0;
        vector<int>occur(101,0);											// Stores #occur. of each num in the array.
        for(int i=0;i<v.size();i++) {
            if(v[i]>k) res+=occur[v[i]-k];									// Check for v[i]-k in prev. iter. indices, which are stored in map.
            if(v[i]+k<=100) res+=occur[v[i]+k];								// If desired vals found in prev. indices, we add their #occur. to res.
            occur[v[i]]++;
        }
        return res;															// Returning total #pairs which produces desired abs. diff.
    }
};

