/*
*
//******************************************************1856. Maximum Subarray Min-Product.******************************************************

https://leetcode.com/problems/maximum-subarray-min-product/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,2]
[2,3,3,1,2]
[3,1,5,6,4,2]
[6,8,5,4,6,4,7,4,3,7,5,4,3,8,6,5,12,15,3,2,12,16,34,30,28,24,40,31,34,32,31,19,17,18,12,14,15,20,19,15,12,21]
[902929,108947,693743, 542343,897654,465739,857685,987654,354678]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. It's approach is similar to Largest Rectangle Area Histogram/Rectangle problem. Here, we use the minm. value of the subarr.
// which means all values in subarr>=minm. value, we can find the subarr. with greater vals. than minm. using stack. At every index, we pop all indices which
// are greater than curr. value, because since the curr. value<stack top value, the subarr this minm/stack top can be part of ends here, as while inserting 
// curr. stack top we had removed all prev. indices with greater values than it, we get. the minm. val from stack top, we pop it, we get start of subarr. from 
// prev. val. in stack, if stack is empty we can take all vals form zero index. We use prefixSum to get sum of vals from start index of subarr to curr. index-1
// and mult. with minm. and try to maximize the product and store in res. On reaching the end of the array, we pop all the vals. from stack as they also can 
// form subarr. We return res at the end of iter.







class Solution {
public:
    int maxSumMinProduct(vector<int>& v) {
        long long int res=0, mod=1000000007;
        vector<long long int>prefixSum(v.begin(), v.end());
        for(int i=1;i<v.size();i++) {										// Calc. prefixSum for the given array.
            prefixSum[i]=(0ll+prefixSum[i]+prefixSum[i-1]);
        }
        stack<int>st;														// Stores the min.value indices for whom subarr can still extend to the right side.
        for(int i=0;i<=v.size();i++) {
            while(!st.empty() && (i==v.size() || v[st.top()]>=v[i])) {		// Removing all smaller vals whose subarr. can't extend past curr. index., as it's
																			// smaller than the stack top value.
                int minm=v[st.top()];										// Get the small value in the subarr.
                st.pop();
                long long int val=prefixSum[i-1];							// Get. prefixSum till prev. index.
                if(!st.empty()) val=(val-prefixSum[st.top()]);				// Remove prefixSum of indices which are to the left of start of subarr.
                // cout<<"index: "<<i<<" minm: "<<minm<<" and prefixSum: "<<val<<endl;
                if(val*minm>res) res=1ll*val*minm;							// Calc. the min. product and track the max of min. product.
            }
            st.push(i);														// Push the curr. index into stack.
        }
        return res%mod;														// Returning the mod value of max of min. product.
    }
};

