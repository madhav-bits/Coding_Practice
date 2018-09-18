/*
*
//**********************************************************907. Sum of Subarray Minimums.***********************************************

Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[3,112121,21212,41212,3121,4445111,2222,4,1212122,1212124]


[3,1,2,4]


[71,55,82,55]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, we move from subarrays of length 2 to length -len. At each step, we add an index-'i' to the 
// subarray ending at index-'i-1' and recalc. the minm and add it to the final result.

// As, the time complexity is O(n^2), it has thrown Time Limit Exceeded errors.





class Solution {
public:
    int sumSubarrayMins(vector<int>& v) {
        vector<vector<int>>dp(2,vector<int>(v.size(),0));
        int res=0, len=v.size();
        int mod=1000000007;
        for(int i=0;i<v.size();i++){										// Substr of len-1.
            dp[1][i]=v[i];
            res=(res+v[i])%mod;
        }
        // cout<<"res of len1: "<<res<<endl;
        for(int len=2;len<=v.size();len++){									// Iter. from len 2 to len.
            // cout<<"curr. length: "<<len<<endl;
            for(int start=0;start<=v.size()-len;start++){					// Iter. over all possible starts.
                // cout<<"start: "<<start<<" and end: "<<start+len-1<<endl;
                dp[len%2][start]=min(dp[(len-1)%2][start],v[start+len-1]);	// Update curr. index based on prev. len's values, curr. index.
                res=(res+dp[len%2][start])%mod;								// Add the minm to the final result.
            }
        }
        return res;															// Returning the final result.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. Here, we maintain two stacks, one maintains #elem. adjacent to curr. index and are larger than curr. value.
// We store the stack's results(#larger elements to left, right) in left, right vectors. Then, in the final iteration, we multiply the count in 
// left and right vector with curr. index' value and sum them.


// By gettting left, right vectors values, we know #substr starting from left of curr. index and have curr. index has minm. value(right[i]).
// We sum all those combi's values and add it to final result var.




class Solution {
public:
    int sumSubarrayMins(vector<int>& v) {
        stack<int>lt, rt;													// Useful in getting #larger elements to curr. index' value.
        vector<int>left(v.size(),0);										// Stores #larger elements to curr. index. in index -'i'.
        vector<int>right(v.size(),0);
        int modulus=1000000007;
        int res=0;
        for(int i=0;i<v.size();i++){										// Tracks #larger elements to left of curr. index 
            while(!lt.empty() && v[lt.top()]>=v[i]) lt.pop();
            
            if(lt.empty()) left[i]=i+1;										// If all are larger elements.
            else left[i]=i-lt.top();            							// Prev. indices smaller than curr. index's value.
            lt.push(i);														// Pushing curr. index into stack.
        }
        
        for(int i=v.size()-1;i>=0;i--){										// Tracks #larger elements to right of curr. index.
            while(!rt.empty() && v[rt.top()]>v[i]) rt.pop();
            if(rt.empty()) right[i]=v.size()-i;
            else right[i]=rt.top()-i;
            rt.push(i);
        }
        
        for(int i=0;i<v.size();i++){
            // cout<<"left: "<<left[i]<<" and right: "<<right[i]<<endl;
            res=(res+v[i]*left[i]*right[i])%modulus;						// Multiply left, right vectors values at each index to get result.
        }
        return res;															// Returning the result.
    }
};