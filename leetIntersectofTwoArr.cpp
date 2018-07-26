/*
*
//******************************************************349. Intersection of Two Arrays.***********************************************

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,2,1,4]
[3,1,2,1]





// Time Complexity: O(nlogn).  												// logn time erasing each num from map.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// logn time erasing each num from map.
// Space Complexity: O(n).												
// This algorithm is HashMap based. We first iterate first vec and store the ints occured in a map. While iterating second vec, if we encount.
// a int which we have encountered in first vec, then we push that int into final result vector and delete that int from map, as we need uinque
// ints in final result vector.








class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;														// Final result vector.
        unordered_map<int,int>m;											// Stores occured ints.
        for(auto num:nums1)													// Iter. first vec and storing occured ints.
            m[num]=1;
        for(auto num:nums2){												// Iter. second vec.
            if(m.count(num)==1){											// when found int that occured in first vector.
                res.push_back(num);											// Push that int into final result vector.
                m.erase(num);												// Delete that int from map, for uniqueness of ints in result.
            } 	
        }
        return res;															// Returning the final result vector.
    }
};