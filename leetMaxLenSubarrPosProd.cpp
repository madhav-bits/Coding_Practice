/*
*
//**********************************1567. Maximum Length of Subarray With Positive Product.********************************

https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[1,-2,-3,4]
[0,1,-2,-3,-4]
[-1,-2,-3,0,1]
[-1,2]
[9,8,-3,5,8,-4,-3,9,-4,0,8,-4,-4,9,2,-1]
[1,2,3,5,-6,4,0,10]
[-1]
[1]
[0]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, since we want a subarray with non-zero values where the prod. is posi. It's 
// possible if #neg. values are even or array where we skip nums to the left of and including first neg, array where we
// skip nums to right of and including last neg. We find the maximum len. of all these possible results and start a 
// new subarray when we encounter a zero, as prod. would be zero and return the maxm. length at the end.









class Solution {
public:
    int getMaxLen(vector<int>& v) {
        int res=0;
        int lastNeg=-1, firstNeg=-1, prevZero=-1, negs=0;
        for(int i=0;i<=v.size();i++){
            if(i<v.size() && v[i]<0){
                 negs++;
                if(firstNeg==-1) firstNeg=i;
                lastNeg=i;
            }
            if(i==v.size() || v[i]==0){										// Zero breaks the array under consideration.
                if(negs%2==0) res=max(res, i-prevZero-1);					// As even negs. entire array is counted for.
                else{														// As odd negs. are encountered.
                    res=max(res, lastNeg-prevZero-1);
                    res=max(res, i-firstNeg-1);
                }
                firstNeg=-1;
                lastNeg=-1;
                prevZero=i;
                negs=0;
            }
            // cout<<"i: "<<i<<" and res: "<<res<<endl;
        }
        
        return res;															// Returning the mamx. length of subarray.
    }
};
