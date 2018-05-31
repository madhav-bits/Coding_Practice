/*
*
//******************************************************220. Contains Duplicate III.***********************************************

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between 
nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: [1,2,3,1], k = 4, t = 0
Output: true
Example 2:

Input: [1,0,1,1], k = 1, t = 0
Output: true
Example 3:

Input: [4,2], k = 2, t = 1 
Output: false




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,1]
4
0


[20,1,23,24,1,6]
4
6

[0]
4
6


[0,2,3]
0
6



// Time Complexity: O(nlogk).  
// Space Complexity: O(k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogk).
// Space Complexity: O(k).	
// This algorithm is Queue based. We maintain a queue of size: "k+1". If the window size reaches that,we eliminate the last one. Prior adding an
// elem.(nums[i]) to window we search for nums[i]-t in the queue using binary search(lower_bound), we get first index of value,which is >nums[i]-t.
// We check if that value is <=t distance form nums[i]. If it is with in required dist. we return true. If we didn't find any true resulting scen-
// -ario in all the iterations, we return false.





class Solution {
public:
    
    bool containsNearbyAlmostDuplicate(vector<int>& v, int k, int t) {
        if(v.size()<2 || k<1) return false;												// If vector size<2 or window size=1, return false.
        set<long long > window;															// Window of max.size "k+1".
        for(int i=0;i<v.size();i++){
            //cout<<"Inside the for loop with index: "<<i<<" and set size: "<<window.size()<<endl;
            if(i>k) window.erase(v[i-k-1]);												// If window max. size reached, we remove first elem.
            auto it= window.lower_bound(v[i]-t);										// Searching for first val. >= nums[i]-t
            //if(it!=window.end()) cout<<"Extracted val. is: "<<*it<<endl;
            if(it!=window.end() && *it-v[i]<=t) return true;							// Check that value is <=t distant from nums[i]
            window.insert(v[i]);														// Inserting the new elem.
        }
        return false;																	// If such pair not found, return false.
    }
};