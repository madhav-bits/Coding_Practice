/*
*
//******************************************************2465. Number of Distinct Averages.******************************************************

https://leetcode.com/problems/number-of-distinct-averages/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,1,4,0,3,5]
[1,100]
[1,2,2,4]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Map+Set based. Since the range of nums is small, rather than sorting the array to get sorted values, we store #occur. of each val in an 
// array then iterate over the array from both sides to get sorted values. We calc. avg. of nums whose #occur. is non-zero and store it in set, then dec. the 
// occur. of these nums and move to next num if their #occur. is zero. We return total #unique avgs at the end of process by returning size of the set.







class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int res=0;
        unordered_set<double>st;
        int occur[101];
        memset(occur, 0, sizeof(occur));
        for(int&num:nums) occur[num]++;										// Track #occur. of each num in the array.
        int i=0,j=100;
        while(i<=j) {
            while(i<=j && occur[i]<=0) i++;									// Skip nums whose #occur. is zero.
            while(i<=j && occur[j]<=0) j--;
            if(i>j) break;
            int minm=min(occur[i], occur[j]);								// Remove the min. #occur among the two to avoid similar calc. again in next iter.
            // cout<<"i: "<<i<<" and j: "<<j<<" and minm: "<<minm<<endl;
            occur[i]-=minm;													// Dec. #occur by minm occur of the two nums.
            occur[j]-=minm;
            double avg=(0.0+i+j)/2;
            st.insert(avg);													// Calc. avg and storing it in set.
        }
        return st.size();													// Returning total #unique avgs calculated.
    }
};

