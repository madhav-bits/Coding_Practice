/*
*
//******************************************************2080. Range Frequency Queries.******************************************************

https://leetcode.com/problems/range-frequency-queries/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


 
["RangeFreqQuery","query","query"]
[[[12,33,4,56,22,2,34,33,22,12,34,56]],[1,2,4],[0,11,33]]
["RangeFreqQuery","query","query","query","query","query","query","query"]
[[[4,2,9,7,5,5,1,9,8,6]],[4,5,9],[2,3,4],[7,8,4],[2,6,10],[2,5,6],[2,6,10],[0,7,8]]



// Time Complexity: O(logn).												// Asymp. Time Complexity: O(logl), l-avg. #occur. of a num in the array.											
// Space Complexity: O(n+m).												//n-#nums in the array, m-range of nums.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).												// Asymp. Time Complexity: O(logl), l-avg. #occur. of a num in the array.											
// Space Complexity: O(n+m).												//n-#nums in the array, m-range of nums.
// This algorithm is Binary Search based. 







class RangeFreqQuery {
public:
    vector<vector<int>>occur;
    RangeFreqQuery(vector<int>& arr) {
        int maxm=*max_element(arr.begin(), arr.end());
        occur=vector<vector<int>>(maxm+1);
        for(int i=0;i<arr.size();i++) occur[arr[i]].push_back(i);			// Segregating indices based on the nums occurred in them.
    }
    
    int query(int left, int right, int value) {
        if(value>=occur.size() || 
           occur[value].size()==0 || 
           occur[value].back()<left || 
           occur[value].front()>right) return 0;							// Base conditions.
        int ind2=upper_bound(occur[value].begin(), occur[value].end(), right)-occur[value].begin();// First value>=left index.
        int ind1=lower_bound(occur[value].begin(), occur[value].end(), left)-occur[value].begin();// First value>right index.
        return ind2-ind1;													// Returning total #occur. of num in [left, right] index range.
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
 
 