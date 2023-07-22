/*
*
//******************************************************2104. Sum of Subarray Ranges.******************************************************

https://leetcode.com/problems/sum-of-subarray-ranges/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3]
[1,3,3]
[4,-2,-3,4,1]
[4,6,5,7,6,5,4,3,2,4,5,-6,7,8,7,-6,5,4,3,-2,4,5,-6,7,8,9,7,6,-5,9]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. As we are trying to min, max of all possible subarrays and calc. their diff., we try to find indices of influence for min, 
// max value for each index. For st stack, we maintain the min. val indices in it for which right side border still haven't been found, when we find a 
// <= value(j) to stack top and we pop the stack top, that means stack top(i) can't be min. of substrings which includes 'j', so try to form substrings 
// with each of the left indices of influence(i-st.top()) with it's right side indices(j-i)-> (i-st.top())*(j-i) substrings where arr[i] would be minm, so 
// we substract min. val's contribution from res. We do the same for max. values and add it's contribution to res and return res at the end of iter.







class Solution {
public:
    long long subArrayRanges(vector<int>& v) {
        int n=v.size();
        long long int res=0;
        stack<int>st, st1;
        for(int i=0;i<=n;i++) {
            while(!st.empty() && (i==n || v[st.top()]>=v[i])) { // Calc. min. values and their substrings of influence and substracting from res.
                int ind=st.top();
                st.pop();
                int prev=(st.empty())?-1:st.top();							// Calc. leftside border of indices of influence.
                int lt=ind-prev, rt=i-ind;									// Calc. left, right index ranges of influence of index 'ind'.
                res=res+(1ll*(-v[ind])*lt*rt);								// Substr. min. val's substrings contribution from res.
            }
            
            while(!st1.empty() && (i==n || v[st1.top()]<=v[i])) { // Calc. max. values and their substrings of influence and adding from res.
                int ind=st1.top();
                st1.pop();
                int prev=(st1.empty())?-1:st1.top();
                int lt=ind-prev, rt=i-ind;
                res=res+(1ll*v[ind]*lt*rt);									// Add max. val's substrings contribution to res.
            }
            st.push(i);														// Adding curr. index to both stacks.
            st1.push(i);
        }
        return res;															// Returning the sum of subarray ranges.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// This solution is stack based but we store left, right boundaries of indices of influence for every index. One important observation is that we
// don't use '=' sign in nums[st.top()]>nums[i] condition to prevent overlaps in case of equal values with no smaller values in b/w them affect the min.val
// indices of influence ranges of them and might lead to overlap, by not using '=' sign,we avoid it.







class Solution {
public:
    
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        stack<int>st;
        vector<int> minPrev(n,-1),minNext(n,n),maxPrev(n,-1),maxNext(n,n);
        
        // Calculates indices of influence to left side.
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&nums[st.top()]>=nums[i]){st.pop();}
            if(!st.empty()){minPrev[i]=st.top();}
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        
        // Calculates indices of influence to right side.
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]>nums[i]){st.pop();}   // We dont' use equal sign here in nums[st.top()]>nums[i] condition to prevent overlap 
                                                                    // of intervals in case of same values, not using equal sign avoids overlap.
            if(!st.empty()){minNext[i]=st.top();}
            st.push(i);
        }
        
        // Calculates indices of influence to left side.
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&nums[st.top()]<=nums[i]){st.pop();}
            if(!st.empty()){maxPrev[i]=st.top();}
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        
        // Calculates indices of influence to right side.
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]<nums[i]){st.pop();}
            if(!st.empty()){maxNext[i]=st.top();}
            st.push(i);
        }
        
        for(int i=0;i<n;i++)
        {
            long long leftMin=i-minPrev[i],rightMin=minNext[i]-i;
            long long leftMax=i-maxPrev[i],rightMax=maxNext[i]-i;
            sum+=(leftMax*rightMax-leftMin*rightMin)*nums[i];
            
        }
        return sum;
    }
};


