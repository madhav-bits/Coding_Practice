/*
*
//******************************************************1906. Minimum Absolute Difference Queries.******************************************************

https://leetcode.com/problems/minimum-absolute-difference-queries/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,4,8]
[[0,1],[1,2],[2,3],[0,3]]
[4,5,2,2,7,10]
[[2,3],[0,2],[0,5],[3,5]]



// Time Complexity: O(l*m*log(n/m)).													// n-#nums, m-max. num in array, l-#queries.
// Space Complexity: O(n+m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(l*m*log(n/m)).													// n-#nums, m-max. num in array, l-#queries.
// Space Complexity: O(n+m).	
// This algorithm is Map based. We see that the range of nums is low, so we store indices in which a num has occurred in a set. We iter. over queries, for 
// each query[l,r] we iter. over nums, we check if we are able to find index: 'l' in the set, if we find an index in [l,r], this means this num has occurred
// in the range of indices [l,r], so we calc. dist b/w curr. num and prev. occurred num in this range, as we are trying to get abs.diff order doesn't matter.
// we track the minimum dist b/w consec. nums which occurred in intervals [l,r] and append it to res.






class Solution {
public:
    vector<int> minDifference(vector<int>& v, vector<vector<int>>& queries) {
        vector<int>res;
        int maxm=*max_element(v.begin(), v.end());
        vector<set<int>>m(maxm+1);
        for(int i=0;i<v.size();i++) {
            m[v[i]].insert(i);												// Storing indices in which curr. nums has occurred.
        }
        for(vector<int>&u:queries) {										
            int prev=-1, minDiff=INT_MAX;
            for(int i=0;i<=maxm;i++) {										// Iter. over range of nums.
                auto it=m[i].lower_bound(u[0]);
                if(it!=m[i].end() && *it<=u[1]) {							// If curr. num had occurred in [u[0], u[1]] range.
                    if(prev!=-1 && i-prev<minDiff) minDiff=i-prev;			// We calc. dist from last occurred num and track minm. dist.
                    prev=i;
                }
				if(minDiff==1) break;										// Corner case.
            }
            res.push_back((minDiff==INT_MAX)?-1:minDiff);					// Adding the minDiff to res.
        }
        return res;															// Returning array with min. abs. num diffs for query intervals.
    }
};

