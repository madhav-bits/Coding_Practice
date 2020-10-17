/*
*
//****************************************************739. Daily Temperatures.*******************************************************

https://leetcode.com/problems/daily-temperatures/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[73,74,75,71,69,72,76,73]
[73,74,75,71,69,72,72,73]



// Time Complexity: O(n).  													// n- length of the array.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(n).	
// This algorithm is Stack based. Here, we store all those indices in stack for whom a relatively warmer day haven't been encountered 
// after that date. For every date, we remove all those dates for whom the current date is warmer and calc. the diff b/w dates and 
// update the corresponding colder date index. All the dates which are still in stack will have zero in their index, so we init. res
// with zeroes.








class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        vector<int>res(v.size(),0);
        stack<int>st;													// Stores dates to whom warmer dates still aren't encountered.
        for(int i=0;i<v.size();i++){
            while(!st.empty() && v[st.top()]<v[i]){							// Remove dates for whom curr. date is warmer.
                res[st.top()]=i-st.top();									// Updating result indices with diff b/w dates.
                st.pop();
            }
            st.push(i);														// Pushing curr. index into stack to find warmer date.
        }
        return res;															// Returning result array with closest warmer dates info.
    }
};