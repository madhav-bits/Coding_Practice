/*
*
//*******************************************2411. Smallest Subarrays With Maximum Bitwise OR.*******************************************

https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,0,2,1,3]
[1,2]
[5,7,6,8,19,10,29,28,3,6,5,7,20,5,4,7,8,20]
[2,2,2,2,2]
[0]
[1]
[2,3,5,0,4,6]
[0,2,0,0,0,4,5]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Bit Manipulation based. Min. subarray length with max. suffix OR is determined by the max of the closest indices where each of the 
// possibly occuring 32 bits has been set. closestIndex[i] stores the index of the number whose ith bit has been set when iter. from the back and reach curr. 
// index of observation.







class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& v) {
        vector<int>res(v.size(), 1);
        vector<int>closestIndex(31, -1);									// Setting base index for the 31 bits.
        for(int i=v.size()-1;i>=0;i--) {
            int maxIndex=i;
            int temp=v[i], ind=0;
            while(ind<31) {
                if((temp%2)==1) closestIndex[ind]=i;						// If bit occurred here, we set closestIndex[bitPsn] to curr. index.
                if(closestIndex[ind]>maxIndex) maxIndex=closestIndex[ind];	// We get the maxIndex among the closestIndices where each of 31 bits have been set.
                ind++;
                temp>>=1;
            }
            // cout<<"i: "<<i<<" and maxIndex: "<<maxIndex<<endl;
            res[i]=maxIndex-i+1;											// Calc. dist b/w curr. index and the maxIndex among closestIndices of all bits.
        }
        return res;															// Returning arr with min subarr lengths with max OR starting each index. 
    }
};

