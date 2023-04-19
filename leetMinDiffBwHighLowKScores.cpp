/*
*
//******************************************************1984. Minimum Difference Between Highest and Lowest of K Scores.******************************************************

https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[90]
1
[9,4,1,7]
2
[6,5,7,12,14,2,8,5,7,4,3,17,23,12,18,20,26,21,26]
5



// Time Complexity: O(nlogn+n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+n).
// Space Complexity: O(1).	
// This algorithm is sorting based. Here, we are trying to find the least diff b/w any k words. We can get the least diff b/w these two extremes if the array is sorted. So, we sort the array and 
// calc. diff b/w these two extremes for every window of length 'k' and try to update res with min. diff. We return res at the end of iter.






class Solution {
public:
    int minimumDifference(vector<int>& v, int k) {
        sort(v.begin(), v.end());																		// Sorting the array to get min. diff b/w max, min vals in window.
        int res=1000000;
        for(int i=k-1;i<v.size();i++) {																	// Iter. over the array.
            if(v[i]-v[i-k+1]<res) res=v[i]-v[i-k+1];													// Calc. the diff and update the res if needed.
        }
        return res;																						// Return the min. diff b/w max, min values of nums of k size.
    }
};


