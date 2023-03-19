/*
*
//******************************************************2593. Find Score of an Array After Marking All Elements.******************************************************

https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,1,3,4,5,2]
[2,3,5,1,3,2]
[4,3,2,6,5,4,3,7,6,5,4,6,5,4,8,7,5,12,13,15,1,2,13,23,24,21,29,65,43,23,36,45,27,28,31,35,30]



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Sorting based. As we want to process from smallest to greatest values while also tracking indices. So, we push {arr[i],i} pair to a new array and sort it. We iter. over this array
// at every step we check if curr. value index in orig. array's has been already marked/chosen, if not chosen we add this value to the res. mark this index by changing the value to -1 in the orig. 
// array, we also change it's adjacent indices to be -1. We process and mark all possible indices in this way and return the res at the end of the iteration.







class Solution {
public:
    long long findScore(vector<int>& v) {
        long long int res=0;
        vector<pair<int,int>>u;
        for(int i=0;i<v.size();i++) u.push_back({v[i], i});												// Push {arr[i],i} pairs to new array.
        sort(u.begin(), u.end());																		// Sort the pairs array.
        for(int i=0;i<u.size();i++) {
            if(v[u[i].second]==-1) continue;															// If this index(in orig. array) is already taken, we skip it.
            res+=u[i].first;																			// Adding curr. chosen value to res.
            v[u[i].second]=-1;																			// Mark curr. index(in orig. array) as taken.
            if(u[i].second-1>=0) v[u[i].second-1]=-1;													// Mark adjacent indices also to be taken.
            if(u[i].second+1<v.size()) v[u[i].second+1]=-1;
        }
        
        
        return res;																						// Return the total of all chosen integers.
    }
};

