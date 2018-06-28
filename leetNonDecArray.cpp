/*
*
//************************************************************665. Non-decreasing Array.*****************************************************

Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,3,10,9]

[2,3,1,9]

[2,3,4,2]


[3,4,2,3]


[2,3,3,2,4]

[2,3,2,4]

[3,4,2,3]


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the array, when a pair with v[i]>v[i+1] is found, we can modify any of them, and check whether the entire array is
// sorted or not? 








class Solution {
public:
    
    bool isSorted(vector<int>&v){											// Check whether passed array is sorted or not?
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>v[i+1]) return false;
        }
        return true;
    }
    
    bool checkPossibility(vector<int>& v) {
        if(v.size()<=1) return true;										// If one/zero elem. present, return true.
        vector<int>dup1(v),dup2(v);											// Stores modified arrays.
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>v[i+1]){												// If mismatch found.
                int temp=v[i];
                v[i]=v[i+1];												// Setting v[i] to value of v[i+1]
                if(isSorted(v)) return true;								// If sorted, return true, else wait for other combination.
                v[i]=temp; v[i+1]=v[i];										// Set v[i+1] to value of v[i]
                return isSorted(v);											// Return whether it's sorted ot not?
            }
        }
        return (isSorted(dup1)|| isSorted(dup2)); 							// If modified vectors are sorted, return true.
        return false;														// Else, return false.
    }
};