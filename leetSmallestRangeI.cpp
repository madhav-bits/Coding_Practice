/*
*
//******************************************************908. Smallest Range I.******************************************************

https://leetcode.com/problems/smallest-range-i/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1]
0
[1,3,6]
3
[14,35,83,63,88,36,24,2,28,35,8,48,4,32,78,49,84,66,42,45,89,95,99,87,35,53,33,3,45,5]
49
[14,35,83,63,88,36,24,2,28,35,8,48,4,32,78,49,84,66,42,45,89,95,99,87,35,53,33,3,45,5]
29



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. We find the minm, maxm in orig. array as they are imp. in determining extreme values on both ends. We inc. minm to 
// minm+k and dec. maxm to maxm-k to closen the gap, but they might also cross each other if their gap <2*k, as we can pick any value in the range of
// [-k,k] for change we pick value accordingly so that both values would coincide. All values to left of minm value wouldn't dec. value as that would inc. 
// the gap b/w max to minm value, so inc. value which would be minm+k but if v[i]+k>maxm-k, we ensure it reaches at max. maxm-k.
// Same logic can be applied to indices with val >maxm-k, if we inc. their value the final max value would inc. so we dec. their value but also ensure 
// it's not <minm, so that final minm and maxm would be determinedy by orig. minm and maxm values, which is the best they can do to minm the gap.







class Solution {
public:
    int smallestRangeI(vector<int>& v, int k) {
        int minm=*min_element(v.begin(), v.end()), maxm=*max_element(v.begin(), v.end());
        if(maxm-minm>=2*k) return maxm-minm-2*k;							// If the gap b/w best possible minm, maxm vaues>2*k, we return the rem. gap.
        return 0;															// If gap<=2*k, we change vals so that they coincide and final gap is 0.
    }
};

