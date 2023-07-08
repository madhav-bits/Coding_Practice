/*
*
//******************************************************2149. Rearrange Array Elements by Sign.******************************************************

https://leetcode.com/problems/rearrange-array-elements-by-sign/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,1,-2,-5,2,-4]
[-1,1]
[3,-1,-3,-6,6,5,4,-4,8,-7,-1,5]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We create res array of same size of provided array. We use two pointers to find the next occur. pos. and neg. value resp.
// we use another pointer to iter. over res array and assign these found values to res array in even followed odd value and revisit the loop. We return res
// at the end of iter.







class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        vector<int>res(v.size(),0);
        int i=0, j=0, k=0;
        while(i<v.size() && j<v.size()) {
            while(i<v.size() && v[i]<0) i++;								// Finding the next neg. value.
            while(j<v.size() && v[j]>0) j++;								// Finding the next pos. value.
            res[k++]=v[i++];												// Assigning the values found in a order into res array.
            res[k++]=v[j++];
        }
        return res;															// Returning the array with values in place as specified by conditions.
    }
};

