/*
*
//************************************2779. Maximum Beauty of an Array After Applying Operation.*************************************

https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,6,1,2]
2
[1,1,1,1]
10
[5,4,6,3,2,8,7,12,15,14,17,23,24,23,1,2,5,4,3,6,7,8,6,5,4,4,56,3,4,23,45,34,25,36,34,35,37,38,32,12,29,2,92,28,50,92,478,209,48,202]
20


// Solution 1 has better Space Complexity where as Solution 2 has better Time Complexity.
// Time Complexity: O(n+m).													// n-length of the array, m-maxm. value in the array.
// Space Complexity: O(m).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting+Sliding Window based. Here, as we can inc./dec. values, we can convert all nums in an window of range 2*k into same value/mid 
// value of the window. So, we use sliding window and we pop out all nums from the front until the first value is within 2*k diff of curr. value, so that 
// all nums in the window can be converted to a same number, we use window length and try to maximize the #nums that can be converted to same number, as 
// all values in req. subseq are of same value. 







class Solution {
public:
    int maximumBeauty(vector<int>& v, int k) {
        int res=0, start=0;
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++) {
            while(v[i]-v[start]>2*k) start++;								// Pop smaller nums which are >2*k diff from curr. number.
            if(i-start+1>res) res=i-start+1;								// Maximizing the window length.
        }
        return res;															// Returning length of longest subseq. that can be converted to same values.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// n-length of the array, m-maxm. value in the array.
// Space Complexity: O(m).	
// This algorithm is Map based. Since the range of values in the array, we use map to store #occur. of each num in the array. We calc. prefixSum of this array,
// for every index/number, we remove all those nums which are at >2*k from curr. number by: occur[i]-occur[i-(2*k)-1] and try to maximize the diff and return it.
// Since when i<2*k, we keep on assigning occur[i] to res, as this would be increasing since occur[i] is prefixSum of all values till that index.








class Solution {
public:
    int maximumBeauty(vector<int>& v, int k) {
        int res=0;
        int maxm=*max_element(v.begin(), v.end());
        if(2*k>=maxm) return v.size();
        vector<int>occur(maxm+1, 0);
        for(int&num:v) occur[num]++;										// Calc. #occur. of each number.
        for(int i=1;i<=maxm;i++) {
            occur[i]+=occur[i-1];											// Calc. prefixSum of #occur. of all values<=i.
            if(i>2*k) res=max(res, occur[i]-occur[i-(2*k)-1]); 				// Calc. #nums in the 2*k window using prefixSums.
            else res=occur[i];												// Assigning #nums to res, as this window length<2*k.
        }
        return res;															// Returning length of longest subseq. that can be converted to same values.
    }
};

