/*
*
//*******************************************2200. Find All K-Distant Indices in an Array.*******************************************

https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,4,9,1,3,9,5]
9
1
[2,2,2,2,2]
2
2


// Solution 2 has better Time and Space Complexity.
// Time Complexity: O(n).
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Stack based. Here, we track the latest index where v[i]=key and check if curr. index-matchIndex<=k, if yes we add this to res else we 
// add this index to stack, as if the latest matchIndex to the left is >k dist from curr. index then any of the left matchIndices will also be >k dist. from it.
// Stack contains all indices which are waiting for matchind indices to the right. For every matching, we check the stack values and if they are <= k dist. we 
// add this index to res, since the nums in res are not sorted, we sort them and return res.


// I could also had done this problem by iterating from both sides to track the closest index with value=key on both sides, here the Time is linear and 
// Space complexity is constant.






class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& v, int key, int k) {
        vector<int>res;
        stack<int>st;
        int latestIndex=-1;
        for(int i=0;i<v.size();i++) {
            if(v[i]==key) latestIndex=i;									// Track latest matching index.
            if(latestIndex!=-1 && i-latestIndex<=k) res.push_back(i);		// If the dist to left latest Index<=k, we add curr. index to res.
            else st.push(i);												// If the dist. if longer we add index to res.
            while(latestIndex==i && !st.empty() && i-st.top()<=k) {			// If curr. index has matching num we try to find K-distant indices on left.
                // cout<<"latestIndex: "<<i<<" and stack top: "<<st.top()<<endl;
                res.push_back(st.top());									// Adding indices to res.
                st.pop();
            }
        }
        sort(res.begin(), res.end());										// Returning the res values.
        return res;															// Returning the K-Distant sorted indices.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, at every matching index, we try to iterate from max(i-k, prev. K-Distant index+1) to min(i+k, v.size()-1) and add 
// indices to res. We return res at the end of iter.






class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& v, int key, int k) {
        vector<int>res;
        for(int i=0;i<v.size();i++) {
            if(v[i]!=key) continue;											// If curr. val isn't key.
            int left=(res.empty())?0:res.back()+1;							// Calc. prev. K-Distant index.
            for(int j=max(i-k, left);j<=min(i+k, (int)v.size()-1);j++) res.push_back(j);// Add K-Distant indices to res.
        }
        return res;															// Returning sorted K-Distant indices.
    }
};

