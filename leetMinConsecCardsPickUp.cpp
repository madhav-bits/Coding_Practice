/*
*
//******************************************************2260. Minimum Consecutive Cards to Pick Up.******************************************************

https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,4,2,3,4,7]
[1,0,5,3]
[1,3,4,6,2]
[3,4,5,6,3,7,8,3]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is map based. Here, to get min. consec. cards to pick to matching cards we have to match two adjacent occurances of same number separated by few other nums. We use map to 
// store the index of prev. occur. of each num and when we encounter same number once again, we calc. the gap and udpate the res if needed. We also update the last occur. of curr. num in map to curr.
// index. We return the res at the end of iter.


// We can also an array to store the last occur of each number, as the range of nums in the array is small.




class Solution {
public:
    int minimumCardPickup(vector<int>& v) {
        int res=INT_MAX;
        unordered_map<int,int>m;																		// Stores last occur. of each num in the array.
        for(int i=0;i<v.size();i++) {
            if(m.count(v[i])==1) {																		// If curr. occurred atleast once.
                if(i-m[v[i]]+1<res) res=i-m[v[i]]+1;													// We calc. gap from last occur. to curr. index and update res if curr. gap is smaller.
            }
            m[v[i]]=i;																					// Update last occur. of curr. num in map to curr. index.
        }
        return (res==INT_MAX)?-1:res;																	// Returning the min. gap b/w same values.
    }
};

