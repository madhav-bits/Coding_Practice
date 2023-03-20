/*
*
//******************************************************2598. Smallest Missing Non-negative Integer After Operations.******************************************************

https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,-10,7,13,6,8]
5
[1,-10,7,13,6,8]
7



// Time Complexity: O(n).																				// value based on which we apply transformations.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).																				// value based on which we apply transformations.
// Space Complexity: O(n).	
// This algorithm is observation based. Here, since we can add or remove value from any nums, a given number can be modified to any of the nums whose transformed number: 
// new_number%value=old_number%value. So, we calculate #nums whose modulus value is same. The least missing value would be the one which has least number of modulo values, 
// ex: #modulo_occur*modulo_value+modulo_value, as rest else modulo values can be produce/transformed into values more than least missing value(result) too without leaving any gaps b/w numbers.








class Solution {
public:
    int findSmallestInteger(vector<int>& v, int value) {
        int ind=0;
        vector<int>occur(value,0);																		// Stores #occur. of each modulo value.
        for(int num:v) {
            num%=value;
            if(num<0) num+=value;																		// Adjustment for neg. numbers/modulos.
            occur[num]++;																				// Updating the modulo count.
        }
        for(int i=0;i<value;i++) {
            if(occur[i]<occur[ind]) ind=i;																// Tracking the first occuring modulo which has least #occur.
        }
        return occur[ind]*value+ind;																	// Calc. the least value missing number and returning it.
    }
};
