/*
*
//**********************************************************1331. Rank Transform of an Array.***************************************************

https://leetcode.com/problems/rank-transform-of-an-array/


Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
 

Example 1:

Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
Example 2:

Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.
Example 3:

Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
 

Constraints:

0 <= arr.length <= 105
-109 <= arr[i] <= 109



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[40,10,20,30]
[100,100,100]
[4,2,2,3,1]
[]
[1]



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Sorting based. Here, we have to rank values based on their positions in the sorted version of the array and the ranks array is 
// returned. Since we have to udpate ranks array with ranks in the num's original index, when we sort the array we also attach the index with it's value.
// So, after sorting we iter. over values, we start with rank 1 and udpate that num's original index in result array. If the curr. val== prev. val then
// it's rank would be same,if not we inc the rank by 1 and update the result array.











class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return vector<int>();
        vector<int>res(arr.size(),-1);
        vector<pair<int,int>>u;												// Array to store and sort values with orig. indices paired with them.
        for(int i=0;i<arr.size();i++) u.push_back({arr[i],i});
        sort(u.begin(), u.end());											// Sorting the values with indices paired with them.
        res[u[0].second]=1;													// updating rank of minm. value in the result array in it's index.
        for(int i=1;i<u.size();i++){
            if(u[i-1].first==u[i].first) res[u[i].second]=res[u[i-1].second];// If prev. and curr. are same, they have same rank.
            else res[u[i].second]=res[u[i-1].second]+1;						// If prev. are curr. are diff. val, curr. rank inc. by one.
        }
        return res;															// Returning the ranks array.
    }
};

