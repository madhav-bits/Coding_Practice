/*
*
//******************************************************915. Partition Array into Disjoint Intervals.******************************************************

https://leetcode.com/problems/partition-array-into-disjoint-intervals/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,0,3,8,6]
[1,1,1,0,6,12]
[1,2,3,4,5,6]
[4,3,2,1,5]
[3,4,3,2,3,4,4,5,4,5,6,5,5,4]



// Solution 2 is a clever approach and has better Space Complexity and same Time Complexity as first solution.
// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is SuffixSum based. We use another array to track suffixMin[i] which stores min val in [i, v.size()-1] indices range, for this we iter.
// array from the back and update suffixSum minm array with min values. Now, we iter. from the front and track max val till now and when at 'i', if
// maxTillNow<=suffixMin[i+1] we can break at 'i', so we return i+1, if not we move to next index and continue the process and return the least index which
// meets the requirement.







class Solution {
public:
    int partitionDisjoint(vector<int>& v) {
        int len=v.size(), prefixMax=-1;
        int suffixMin[len];
        memset(suffixMin, 0, sizeof(suffixMin));
        suffixMin[len-1]=v.back();
        for(int i=len-2;i>=0;i--) {											// Iter. from the back.
            suffixMin[i]=min(v[i], suffixMin[i+1]);							// Track min val in the suffix array from 'i' and store it.
        }
        for(int i=0;i+1<v.size();i++) {
            if(v[i]>prefixMax) prefixMax=v[i];								// Track max val in the prefix array.
            if(prefixMax<=suffixMin[i+1]) return i+1;						// If we meet the requirement, we reutrn i+1.
        }
        return -1;															// Default return value.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we start by assuming index '0' to be answer and eventually we change it to 'i' as we iter. over array and we 
// also track max. value among indices till 'i' in maxm and as we iterate we track max. val in tempMax, if we encounter an index 'j' where v[i]<maxm, our 
// curr. res value doesn't work and we update it to 'j' and we update maxm=tempMax. We may think that any of the indices in b/w i and j could als have been 
// answer here but it can't be because if there was a cut in b/w the maxm of left subarray would be >=maxm as cut is > 'i' and this cut would fail as 
// v[j]<newMax, which is >maxm we used earlier. We return the res at the end of iter.







class Solution {
public:
    int partitionDisjoint(vector<int>& v) {
        int maxm=v[0], res=1, tempMaxm=v[0];								// We set res index, maxm and tempMax to v[0].
        for(int i=1;i<v.size();i++) {
            if(v[i]>tempMaxm) tempMaxm=v[i];								// Tracking max val till curr. index.
            if(v[i]<maxm) {													// If curr. val<maxm till cut at res. index, that cut would fail.
                maxm=tempMaxm;												// We make 'i' as the new cut and we update res and maxm.
                res=i+1;
            }
        }
        return res;															// We return res at the end of iter.
    }
};

