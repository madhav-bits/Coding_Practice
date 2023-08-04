/*
*
//******************************************************1985. Find the Kth Largest Integer in the Array.******************************************************

https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["3","6","7","10"]
4
["2","21","12","1"]
3
["0","0"]
2
["1","5","8","9","11","12","22","24","30","100"]
3



// Time Complexity: O(n).  													// In the worst case, it could be O(n^2).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// In the worst case, it could be O(n^2).
// Space Complexity: O(1).	
// This algorithm is Sorting based. Here, as we ONLT need to get the target from 1 index in sorted array. We need not sort the entire array, so we use nth_element formula to 
// get the target index's value in sorted array, we specify the conditions to sort the stringified nums.







class Solution {
public:
    
    
    string kthLargestNumber(vector<string>& v, int k) {
        nth_element(v.begin(), v.begin()+v.size()-k, v.end(),[&](string&lt, string&rt) {// Using nth_element formula to get the target index's value in sorted array.
            if(lt.length()!=rt.length()) return lt.length()<rt.length();	// If both strs are of diff. length, length determines which value is greater.
            return lt<rt;													// If both strs are of same length, direct comparison gives which value is greater.
        });
        
        return v[v.size()-k];												// Returning the value from the target index.
    }
};

