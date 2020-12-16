/*
*
//*******************************************1685. Sum of Absolute Differences in a Sorted Array.****************************************

https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[2,3,5]
[1,4,6,8,10]
[2,2,4,6,67,234,890,2939,2939,5849,9242]


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we iter. over array to calculate the diff. b/w rest of indices to curr. index, we calc. 
// diff. to left indices in first iter. We cover diff. to right indices in second iter. We add both these values and add it to final
// array.








class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& v) {
        vector<int>res(v.size(),0);
        int diff=0;
        for(int i=1;i<v.size();i++){
            res[i]+=res[i-1]+((v[i]-v[i-1])*i);								// Adding prev. index's left diff. to v[i]-v[i-1]*i 
        }																	// to get curr. index left diff.
        for(int i=v.size()-2;i>=0;i--){
            diff=diff+((v[i+1]-v[i])*(v.size()-1-i));						// Adding prev. index's right diff. to v[i+1]-v[i]*len-1-i
            res[i]+=diff;													// to get curr. index right diff.
        }        
        return res;															// Returning the final result array.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This solution is iteration based. The intuition is that we first calc. the diff. b/w all indices to zero index. Now, we iter. from
// left to right and add (2*i-len)*(v[i]-v[i-1]) to convert v[i]-v[x] for i>=x v[i]-v[curr. index], and v[x]-v[i] to
// v[curr. index]-v[i] for i<y and push this value to result array for each index.


// This solution is obtained from discussion forum.







class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i < nums.size();++i){
            ans += nums[i] - nums[0];
        }
        vector<int> go;
        for(int i = 0;i < nums.size();++i){
            if(i != 0){
                ans += (2*i - nums.size()) * (nums[i] - nums[i-1]);
            }
            go.push_back(ans);
        }
        return go;
    }
};