/*
*
//******************************************************2553. Separate the Digits in an Array.***********************************************

https://leetcode.com/problems/separate-the-digits-in-an-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[13,25,83,77]
[7,1,3,9]
[3,13,20,3400]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. We get the digits of each number in reverse order, we do it for all nums in the array. We reverse the whole res array to get digits original order and return it.









class Solution {
public:
    vector<int> separateDigits(vector<int>& v) {
        vector<int>res;
        for(int i=v.size()-1;i>=0;i--) {
            while(v[i]) {
                res.push_back(v[i]%10);
                v[i]/=10;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
