/*
*
//*************************************************************628. Maximum Product of Three Numbers.****************************************************

Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[1,2,3,0,-1]
[2,3,-5,-1,-9]
[-9,-8,-7,-6,-5]
[-9,1,2,3]


// Time Complexity: O(n).
// Space Complexity: O(n).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).			
// Max. product can be product of three largest values or it can be product of last-2 largest -ve/+ve and a largest value. We extract
// both thest values and return max. of the two values.



class Solution {
public:
    int maximumProduct(vector<int>& v) {
        sort(v.begin(), v.end());
        int len=v.size();
        int maxm=v[len-1]*v[len-2]*v[len-3];							// Product of largest three values.
        //cout<<"maxm1 till now is: "<<maxm<<endl;
        return max(maxm,v[0]*v[1]*v[len-1]);							// Prodcut of two least values and largest value. Return the max. of them.
    }
};


