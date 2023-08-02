/*
*
//******************************************************2195. Append K Integers With Minimal Sum.******************************************************

https://leetcode.com/problems/append-k-integers-with-minimal-sum/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,4,25,10,25]
2
[5,6]
6
[5,6,4,3,5,4,7,6,8,10,14,12,15,20,26,25,29,14]
10
[5,6,4,3,5,4,7,6]
10
[3,10,16,20,25,32,25,7,4,2,4,6,5,7,865,33,77,5,3,23,55,34,65,33,56676,4,3,6,65,4,3]
2000



// Time Complexity: O(nlogn+n)=O(nlogn).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+n)=O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting+Greedy based. Here, for use to get min. sum of numbers after changes, we have to greedily pick the least valued missing numbers and append them.
// We first sort the given nums, while iter. over them we can identify the missing nums b/w adj. indices and find how many missing nums out of them could be useful for us(<=k),
// we use arithmatic formula to get their sum as missing values are adj. values and k is a very huge value, individually adding them would lead to TLE. We return sum of added
// numbers at the end of iter.







class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());										// Sort the given array.
        long long int res=0;
        int start=1;
        for(int i=0;i<nums.size() && k; i++) {
            if(start>=nums[i]) {											// If there is no gap b/w adj. values.
                start=nums[i]+1;
                continue;
            }
            int len=min(k, nums[i]-start);									// Calc. how many values can we add b/w curr. and prev. num.
            long long int val=(1ll*len*(0ll+start+start+len-1))/2;			// Using sum=(n*(a+l))/2 formula to get sum of appended nums.
            res+=val;														// Adding the sum of appended nums to res.
            // cout<<"i: "<<i<<" and len: "<<len<<" and addn: "<<val<<" and res: "<<res<<endl;
            k-=len;															// Dec. the allowed append nums value.
            start=nums[i]+1;												// Pointing to next missing value after curr. value.
        }
        if(k) {																// If there are still allowed append nums left.
            long long int val=(1ll*k*(0ll+start+start+k-1))/2;				// We calc. sum of appended nums and add it to res.
            res+=val;
        }
        return res;															// Returning the sum of all appended nums.
    }
};

