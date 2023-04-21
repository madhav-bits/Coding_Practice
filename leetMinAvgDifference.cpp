/*
*
//******************************************************2256. Minimum Average Difference.******************************************************

https://leetcode.com/problems/minimum-average-difference/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,5,3,9,5,3]
[0]
[5,4,3,6,7,5,4,1,8,6,12,14,453,5,76,53,7,6,4,8,98,645,4,7,4,3,2,7,89,65,445,78,78,875,43,3,78,763,5,87,6]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is prefixSum based. As we have to return first index with least diff. b/w prefix, suffix avgs. We calc. the total of the array first, we iter. over array, calc. prefixAvg,
// suffixAvg at every index, try to udpate minAvg Difference if needed and update the corresponding if minAvg updated.




class Solution {
public:
    int minimumAverageDifference(vector<int>& v) {
        long long int right=accumulate(v.begin(), v.end(), 0ll);										// Calc. total of the array which helps in calc. suffixSum at every index during iteration.
        long long left=0;
        int minAvg=INT_MAX, res=-1;																		// Tracks minAvg diff and the corresponding index.
        for(int i=0;i<v.size();i++) {
            left+=v[i];
            right-=v[i];
            double avgLeft=left/(i+1);																	// Calc. leftAvg, rightAvg at every step and calc. their abs diff.
            double avgRight=(i==v.size()-1)?0:right/(v.size()-1-i);
            if(abs(avgLeft-avgRight)<minAvg) {															// If curr. avgDiff is less than minAvg till now update it and the index.
                minAvg=abs(avgLeft-avgRight);
                res=i;
            } 
        }
        return res;																						// Returing the first index with least abs Diff of avgs.
    }
};
