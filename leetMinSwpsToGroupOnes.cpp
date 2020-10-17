/*
*
//******************************************1151. Minimum Swaps to Group All 1's Together.**********************************************

https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[1,0,1,0,1]
[0,0,0,1,0]
[1,0,1,0,1,0,0,1,1,0,1]
[1,0,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1]
[1]
[0]
[1,0,0,0,1]
[0,1,1,0,1,1,0,1,1,1]



// Time Complexity: O(n).													// n-length of the array.
// Space Complexity: O(n).													// Could be O(1), if input array is modified.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n-length of the array.
// Space Complexity: O(n).													// Could be O(1), if input array is modified.
// This algorithm is PrefixSum and Window based. Here, we want to group all ones. So, we want them all to be one window(#ones size). We store the 
// #ones prefixSum array. In each window of calc. size, to minimize swaps we only swap the zeroes with ones from outside window. So,
// we iter. over all windows, find the one with minm. zeroes(swaps required) and return the minm. zeroes count.








class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones=0;
        vector<int>prefixSum(data.size(),0);
        for(int i=0;i<data.size();i++){										// Updating the prefix sum array.
            if(data[i]!=0) ones++;
            prefixSum[i]=ones;
        }
        if(ones==0 || ones==data.size()) return 0;							// If all/ zero ones are present, return 0.
        int res=ones;														// Init. the minm. zeroes/swaps required.
        for(int i=ones-1;i<data.size();i++){								// Iter. over all possible windows.
            int curr=prefixSum[i];
            if(i-ones>=0) curr-=prefixSum[i-ones];							// Calc. ones in windows.
            int zeroes=ones-curr;											// Infering zeroes in window.
            res=min(res, zeroes);											// Track minm. zeroes in a window.
        }
        return res;															// Return minm. zeroes/swaps required in a window.
    }
};