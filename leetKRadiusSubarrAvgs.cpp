/*
*
//******************************************************2090. K Radius Subarray Averages******************************************************

https://leetcode.com/problems/k-radius-subarray-averages/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[7,4,3,9,1,8,5,2,6]
3
[100000]
0
[5,4,6,5,7,6,8,7,6,5,4,3,2,1,3,4,5,6,7,8,9,10,23,21,24,21,24,35,40,3,6,5,4,7,6,5,1,6]
5



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window based. Here, we have a window of size 2*k+1, while iterating over array, we add values indices along the way and fill the res array as per the
// requirements and ensuring values from indices out of window aren't included in the total of window's values we track.







class Solution {
public:
    vector<int> getAverages(vector<int>& v, int k) {
        vector<int>res(v.size(), -1);
        long long int total=0;
        for(int i=0;i<v.size();i++) {
            total+=v[i];													// Adding curr. value to total tracker.
            if(i-2*k-1>=0) total-=v[i-2*k-1];								// Substracting the values that are out of window.
            if(i>=2*k) res[i-k]=total/(2*k+1);								// Filling the res array.
        }
        return res;															// Returning the array with avg. of values in the window as it slides over array.
    }
};

