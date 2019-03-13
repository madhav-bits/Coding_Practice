/*
*
//*****************************************************768. Max Chunks To Make Sorted II.**********************************************

This question is the same as "Max Chunks to Make Sorted" except the integers of the given array are not necessarily distinct, the input 
array could be up to length 2000, and the elements could be up to 10**8.

Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks" (partitions), and individually 
sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 2000].
arr[i] will be an integer in range [0, 10**8].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.




[3,1,2,6,8,7,9]


[3,1,2,4,3,4,2,5]


[1]


[1,2,3,4,5]



[1,2,3,4,5,1]


[5,4,3,2,1]



[5,4,3,2,1,2,1,7]



[3,1,2,6,5,5,9,6]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Observation based solution. Here, for every window, we shouldn't have any smaller value to right of it, for that
// we iter. from back and store minm. value from 'i' to last index 'i' of 'least' array. Now, we iter. over given array, those instances
// where maxm. encountered till that index, is less than minm. from rest of indices starting next index are where the curr. chunk ends,
// we add next block's count to final count. We iter. till 'v.size()-2' only, when we are 'v.size()-2', we decide whether to form new
// chunk for last index or include it in curr. chunk.









class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int pieces=1;														// Tracks #chunks, takes into account first chunk.
        vector<int>least(v.size(),0);										// Stores least value from 'i' to last index.
        least.back()=v.back();
        for(int i=v.size()-2;i>=0;i--)										// Calculating least values for suffix array.
            least[i]=min(least[i+1], v[i]);
        int maxm=INT_MIN;
        for(int i=0;i<v.size()-1;i++){										// ITer. over given array.
            maxm=max(maxm, v[i]);											// Update maxm. encountered till now.
            if(maxm<=least[i+1]) pieces++;									// Compare max. till now and minm. from next index.
        }
        return pieces;														// Returning the total #chunks.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Observation/Stack based solution. Here, since a chunk depends on minm., maxm value. Once we encounter minm. value
// we can safely neglect rem. chars except maxm. value, so we store maxm. value and remove all else chars >minm. value and push the
// maxm. value back into stack, as it represents maxm. value of curr. chunk. If we encounter, a greater value than top of stack, then 
// it might be part of next chunk, so we just take it in. At the end of iter., each elem. in stack represents the maxm. elem. of chunks
// So, we return #chunks by returning #maxm. values.









class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        stack<int>st;														// Tracks all chunks values.
        for(int i=0;i<v.size();i++){										// Iter. over given array.
            if(st.empty() || st.top()<=v[i]) st.push(v[i]);					// If greater value, it might be of next chunk's value.
            else{															// If smaller, we remove values that are not chunks's max.
                int currMax=st.top(); st.pop();
                while(!st.empty() && st.top()>v[i]) st.pop();
                st.push(currMax);											// Pushing the chunk's max. back into stack.
            }
        }
        return st.size();													// Returning maxm. #chunks.
    }
};


