/*
*
//******************************************************2012. Sum of Beauty in the Array.******************************************************

https://leetcode.com/problems/sum-of-beauty-in-the-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3]
[2,4,6,4]
[3,2,1]
[4,5,3,4,5,6,7,6,5,4,3,2,1,2,34,5,6,7,8,8,7,7,6,5]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Map+Observation based. Here, the primary condition is that all the preceeding indices should have less than v[i] and all succeeding indices
// having greater values. We can check this condition easily by maintaining a greater preceeding value tracker and building a suffixMin array, suffixMin[i] 
// stores the min. value from [i, v.size()-1] indices, if this max. val<v[i] it means all prev. values are smaller than v[i], if suffixMin[i+1]>v[i], it means
// all right indices have greater values than v[i] and we inc. res by 2. If this doesn't satisfy we prev. adj. indices for second condition, if satisfied 
// we inc. res by 1. We return res at the end of iter.






class Solution {
public:
    int sumOfBeauties(vector<int>& v) {
        vector<int>suffixMin(v);
        for(int i=v.size()-2;i>=0;i--) {
            if(suffixMin[i+1]<suffixMin[i]) suffixMin[i]=suffixMin[i+1];	// Storing min. value in [i, v.size()-1] indices range.
        }
        int res=0, maxm=v[0];
        for(int i=1;i<v.size()-1;i++) {
            if(maxm<v[i] && v[i]<suffixMin[i+1]) res+=2;					// All left indices values<v[i]<all right indices values.
            else if(v[i-1]<v[i] && v[i]<v[i+1]) res++;						
            if(v[i]>maxm) maxm=v[i];										// Maintaining max. value in [o, i] indices range.
        }
        return res;															// Returning the sum of beauty of all indices in the array.
    }
};

