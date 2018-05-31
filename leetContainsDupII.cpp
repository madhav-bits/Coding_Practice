/*
*
//******************************************************219. Contains Duplicate II.***********************************************

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that 
nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: [1,2,3,1], k = 3
Output: true
Example 2:

Input: [1,0,1,1], k = 1
Output: true
Example 3:

Input: [1,2,1], k = 0
Output: false




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2147483647,-2147483647]
2147483647

[2147483647,-2147483647]
2

[1,2,3,1]
3

[20,1,23,24,1,6]
4

[1,2]
0

[]
1



// Time Complexity: O(n).  
// Space Complexity: O(k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(k).	
// This algorithm is HashMap based question. We maintain a window size of "k+1". At each step, we check there exists a similar elem. in window.
// If present, return true, else return false. 

// Once, window size is reached, we remove the first elem and check "k" elem, if curr. value v[i] 
// is present in window.








class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        if(v.size()==0 || k<1) return false;										// IF empty vector/window size is 1, return false.
        unordered_map<long long, int> window;                                      	// Window to store elements.
        for(int i=0;i<v.size();i++){
            if(i>k) window.erase(v[i-k-1]);											// Removes the first inserted elem. when window size is reached.
            if(window.count(v[i])==1) return true;									// If the curr. value is already in map, return true.
            window[v[i]]=1;															// Insert the curr. value.
        }
        return false;																// If no such pairs are found, return false.
    }
};