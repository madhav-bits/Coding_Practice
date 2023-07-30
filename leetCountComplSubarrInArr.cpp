/*
*
//******************************************************2799. Count Complete Subarrays in an Array.******************************************************

https://leetcode.com/problems/count-complete-subarrays-in-an-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,1,2,2]
[5,5,5,5]
[6,5,4,2,4,3,6,7,8,9,7,6,5,4,1,2,3,4,5,6,3,4,2,5,4,6,8,7,5,4,3,4,2,1,4,2,3]
[2,2,3,4,2,4]
[2,2,3,2,4,4]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window+map based. Here, since the substring has to contain all the uniq. nums in the array. In the first iter. we track the first index(firstOccur) 
// of the last occur uniq. num because if our window starts at '0', it should end at atleast 'firstOccur' so that it includes all uniq. nums in the array, so for '0', we add
// (v.size()-firstOccur) indicating that all indices from [firstOccur, v.size()-1] could be the end of the window satisfying the requirements. As we move the start of the window
// by '1', we track if we had lost any uniq. num which we earlier have, if yes, we move the end of the window/firstOccur until we include that num in the window or reach end of 
// array. If missing num found, we add indices right to it and including to it to res. If we reach end of array, that means we can't find the missing num and we can't form 
// a window with all uniq. nums, so we stop the process here as same would be the case even if we move the start of the window to right anymore.







class Solution {
public:
    int countCompleteSubarrays(vector<int>& v) {
        int occur[2001];
        int firstOccur=-1, res=0;
        memset(occur, 0, sizeof(occur));
        for(int i=0;i<v.size();i++) {
            if(occur[v[i]]==0) firstOccur=i;								// Tracking first occur. of last occuring uniq. num.
            occur[v[i]]++;
        }
        memset(occur, 0, sizeof(occur));
        for(int i=0;i<=firstOccur;i++) {									// Tracking #occur. of nums in the window: [0, firstOccur].
            occur[v[i]]++;
        }
        int i=0, req=0;
        while(firstOccur<v.size()) {
            while(req>0 && firstOccur+1<v.size()) {							// If any uniq. num is missing, window expands to right until we include it once again.
                if(++occur[v[++firstOccur]]==1) req--;
            }
            if(req>0) break;												// Reaching end of array means we can't find the missing uniq. num.
            res+=(v.size()-firstOccur);										// Adding all possible windows to res.
            if(--occur[v[i]]==0) req++;										// Moving window's start to right and noting if any uniq. num is missing.
            i++;															// Moving the window's start pointer to right.
        }
        return res;															// Returing total #windows/subarrays that satisfy the condition.
    }
};

