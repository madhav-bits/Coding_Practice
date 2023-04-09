/*
*
//******************************************************2615. Sum of Distances.******************************************************

https://leetcode.com/problems/sum-of-distances/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,1,1,2]
[0,5,3]
[3,5,4,2,1,6,7,5,12,13,15,12,19,10,10,7,5,23,25,23,26,24,34,57,54,32,75,43,8,9,7,5,57,64,90]



// Time Complexity: O(n).																				// n- length of nums array.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).																				// n- length of nums array.
// Space Complexity: O(n).	
// This algorithm is Prefix Sum based. Here, as we are calculate dist. b/w indices with same numbers. We store those indices in a map, then we iter. over the indices, calc. prefixSum of indices along the way, when at index 'j'
// in those indices with same number, we calc. the prefix Total and Suffix Total and update the value in the actual index in the res array, we return res at the end of iter.







class Solution {
public:
    vector<long long> distance(vector<int>& arr) {
        vector<long long>res(arr.size(),0);
        unordered_map<int,vector<int>>m;																// Map to store indices with same value.
        for(int i=0;i<arr.size();i++) m[arr[i]].push_back(i);											// Appending all indices with same value.
        for(auto it=m.begin();it!=m.end();it++) {
            long long int total=accumulate(it->second.begin(), it->second.end(), 0ll);					// Calc. total of all indices.
            long long int prefix=0;
            for(int i=0;i<it->second.size();i++) {														// Iter. over indices with same value.
                long long int left=1ll*i*it->second[i]-prefix;											// Calc. dist. to all lesser indices(To the left side of array).
                long long int right=(0ll+total-prefix)-1ll*(it->second.size()-i)*it->second[i];			// Calc. dist. to all greater indices(To the right side of array).
                res[it->second[i]]=left+right;															// Updating the res array's corres. index with the calc. dist. value.
                prefix+=it->second[i];																	// Updating the prefixSum of the indices.
            }
        }
        return res;																						// Returning the array with distance values.
    }
};

