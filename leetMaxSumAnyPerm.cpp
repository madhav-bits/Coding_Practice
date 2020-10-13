/*
*
//****************************************1589. Maximum Sum Obtained of Any Permutation.*************************************

https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/





*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


I had worked on test cases provided with the question.

[1,2,3,4,5]
[[1,3],[0,1]]
[1,2,3,4,5,6]
[[0,1]]
[1,2,3,4,5,10]
[[0,2],[1,3],[1,1]]



// Time Complexity: O(nlogn).  												// n- length of the array.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n- length of the array.
// Space Complexity: O(n).	
// This algorithm is Sorting based. Here, we want maxm. total of subarrays requested. That translates to maximum
// weighted sum of all indices, as we can say that a range query can be called as giving a weight of 1 to all that range
// indices and adding them, if we add result of all queries, then it is weighted sum of indices, where weights are 
// assigned based on #queries an index would appear in. We used prefix sum technique, where we inc. the weight by 1 at 
// start and dec. by 1 at (close+1) index and we assign the weight to that index in the iter. process. To get maxm. weight
// sum, we multiply maxm. weight with maxm. value in array and greater weights are assigned based on how greater their 
// value is, this is done by sorting both arrays and multiplying the values in the iter and adding them.







class Solution {
public:
    int maxSumRangeQuery(vector<int>& v, vector<vector<int>>& reqs) {
        long int mod=1000000007;
        sort(v.begin(), v.end());											// Sorting the array values.				
        vector<int>psns(v.size(),0);
        for(auto u:reqs){												// Assigning weights based on query start, close.
            psns[u[0]]++;
            if(u[1]+1<psns.size()) psns[u[1]+1]--;
        }
        for(int i=1;i<psns.size();i++) psns[i]+=psns[i-1];					// Assign weights with prefix sum technique.
        sort(psns.begin(), psns.end());										// Sorting the weights assigned to indices.
        long long int res=0;
        for(int i=0;i<v.size();i++){										// Multiplying weights with values of array.
            long long int curr=1ll*psns[i]*v[i];
            res=(res+curr)%mod;
        }
        return res;															// Returning the weighted sum of values.
    }
};
