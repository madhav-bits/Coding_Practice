/*
*
//*********************************************1590. Make Sum Divisible by P.********************************************

https://leetcode.com/problems/make-sum-divisible-by-p/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked with the test cases provided with the question.


// Time Complexity: O(n).
// Space Complexity: O(n).													// length of the array.	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).													// length of the array.	
// This algorithm is Map based. Here, we calc. prefix sum and store the occurnce of a prefix sum with modulus in the map. 
// We calc. total of all nums. and calc. subarray sum to be removed(gap) and during second iter., if we are at an 
// index 'i' with total 'x', we look for 'x-gap' in the map, if it is present, we calc. the subarr. len and try to minimize
// the subarr. len. If at the end of the iter., the subarr len is nums.size(), we return -1 else we return subarr len.







class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int>m;
        long long int total=0;
        for(auto num:nums){
            total+=num;
            total%=p;
        }
        if(total==0) return 0;
        int gap=total, res=nums.size();
        total=0;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            total%=p;
            // cout<<"total: "<<total<<" and prev: "<<(total-gap+p)%p<<endl;
            if(m.count((total-gap+p)%p)==1) res=min(res, i-m[(total-gap+p)%p]);
            m[total]=i;
        }
        return (res==nums.size())?-1:res;
    }
};