/*
*
//*******************************************974. Subarray Sums Divisible by K.*******************************************

https://leetcode.com/problems/subarray-sums-divisible-by-k/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked on test cases provided with the question.


// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(k).													// k- given num.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(k).													// k- given num.
// This algorithm is Prefix and map based. Here, we store the prefix sum with moduls in a map. At every index with total
// 'x', we look for #occur. of 'x-k' which gives all subarr. whose sum is multiples/divisible by k. We return the total
// at the end of iter.







class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        int res=0;
        int total=0;
        vector<int>occur(k,0);
        occur[0]=1;
        for(auto num:v){
            total+=num;
            total%=k;
            if(total<0) total+=k;
            // cout<<"total: "<<total<<endl;
            res+=occur[total];
            occur[total]++;
        }
        return res;
    }
};