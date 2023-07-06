/*
*
//*******************************************1968. Array With Elements Not Equal to Average of Neighbors.******************************************

https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,5]
[6,2,0,9,7]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Couning sort+observation based. Here, we first sort the array using counting sort. We avoid the mentioned situation, if we swap every 
// 2,3 indices, in all triplets in sorted array.







class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        // sort(v.begin(), v.end());										// Sorting the array.
        // for(int i=1;i+1<v.size();i+=2) {
        //     swap(v[i], v[i+1]);											// Swapping 2,3 indices in every triplet.
        // }
        // return v;
        
        
        int maxm=*max_element(v.begin(), v.end());
        vector<bool>occur(maxm+1,false);
        for(int&num:v) occur[num]=true;										// Updating the array with the occur. of nums in the given array.
        int j=0;
        for(int i=0;i<=maxm;i++) {
            if(occur[i]==true) v[j++]=i;									// Populating the res array with sorted values.
        }
        for(int i=1;i+1<v.size();i+=2) {									// i+=2 is done to prune and avoid unnecc. comparisons.
            swap(v[i], v[i+1]);												// Swapping 2,3 indices in every triplet.
        }
        return v;															// Returing the res array.
    }
};


