/*
*
//***************************************************1679. Max Number of K-Sum Pairs.***************************************************

https://leetcode.com/problems/max-number-of-k-sum-pairs/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[1,2,3,4]
5
[3,1,3,4,3]
6
[2,2,2,2,2,2,2,2,2,2,2,3]
4



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Unordered Map based. Here, we iter. over given array, at each num. we look for k-curr. num to check matching pair
// which totals k and haven't been used exists in the past indices, if yes we inc. the cnt of res by 1 and dec. the cnt of k-curr.num.
// If cnt of k-curr. num is 1, we delete that num. from map. Else, we inc. cnt of curr. num.








class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int res=0;
        for(auto num:nums){
            if(m.count(k-num)==1){
                res++;
                if(m[k-num]==1) m.erase(k-num);
                else m[k-num]--;
            }else m[num]++;
        }
        return res;
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is is Sorting based. We use two pointers on both ends and use them to find the target sum logic. When we get the
// target total, we inc. the res by 1, inc. i by 1, dec. j by 1. 







class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res=0;
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]==k){
                res++;
                i++;j--;
            }else if(nums[i]+nums[j]<k) i++;
            else j--;
        }
        return res;
    }
};