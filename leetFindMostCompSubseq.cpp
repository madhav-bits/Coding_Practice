/*
*
//*********************************************1673. Find the Most Competitive Subsequence.**********************************************

https://leetcode.com/problems/find-the-most-competitive-subsequence/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[3,5,2,6]
2
[1,2,2,2,7,7,7,7,7]
4
[2,4,3,3,5,4,9,6]
4



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. Here, at every index we remove all vals from top of stack which are> curr. num to get the least 
// value/ top rank till that index. We only remove values from stack if the remaining indices in iteration would be able to form k
// values in stack. If the #elem. in stack is <k, we add curr. num into stack.








class Solution {
public:
    vector<int> mostCompetitive(vector<int>& v, int k) {
        if(k==v.size()) return v;
        stack<int>st;
        for(int i=0;i<v.size();i++){										// Iter. over entire array.
            while(!st.empty() && st.size()+v.size()-i>k && st.top()>v[i])	// Remove nums which are <curr. num
                st.pop();
            if(st.size()<k) st.push(v[i]);									// If curr. size<k, we add curr. num
        }
        vector<int>res(k,-1);												// Init. result array.
        int ind=res.size()-1;
        while(!st.empty()){													// Empty the stack and add them to result array.
            res[ind--]=st.top();
            st.pop();
        }
        return res;															// Return the most comp. subseq.
    }
};