/*
*
//********************************************1471. The k Strongest Values in an Array.********************************************

https://leetcode.com/problems/the-k-strongest-values-in-an-array/description/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

[1,2,3,4,5]
2
[1,1,3,5,5]
2
[6,7,11,7,6,8]
5
[6,-3,7,2,11]
3
[-7,22,17,3]
2



// Time Complexity: O(nlogn).												// n-length of the array.
// Space Complexity: O(1).		

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n-length of the array.
// Space Complexity: O(1).													
// This algorithm is sorting based. Here, we are comparing values in the array based on their |arr[i] - m|. Since, every number is 
// getting median subtracted from it, the strength depends on two distance numbers are from median. To find median, we sort the array,
// we take the middle index's value as median. We place two pointers on two ends of the array, we take the most distant point from 
// median and move the corres. pointer until k elems are gathered.








class Solution {
public:
    vector<int> getStrongest(vector<int>& v, int k) {
        sort(v.begin(), v.end());											// Sorting the given array.
        int median=v[((int)v.size()-1)/2];									// Store the median val.
        // cout<<"median: "<<median<<endl;
        vector<int>res;														// Stores K greaters values.
        int i=0, j=v.size()-1;												// Init. ptrs to two ends of the array.
        while((int)res.size()<k){											// Until K elems are gathered.
            int lt=abs(median-v[i]), rt=abs(median-v[j]);					// Calc. left and rigt ptr's values.
            if(rt>=lt){														// If right ptr has greater value.
                res.push_back(0+v[j--]);									// (If val. equal, v[j]>v[i] as j is always to the right of i.)
            }else res.push_back(0+v[i++]);									// If left ptr has greater value.
        }
        return res;															// Return the K strongest values in the array.
    }
};

