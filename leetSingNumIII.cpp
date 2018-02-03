/*
*
//**********************************************************260. Single Number III.***************************************************

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the 
two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.




//These are the examples I had created, tweaked and worked on.
[9]
[1, 2, 1, 3, 2, 5]
[]

// Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//************************************************THIS IS A TRICKY AND CRAZY QUESTION.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// In the first iteration, we get the xor of all the values. As these non repeated values are distinct, we have atleast single one in the final
// XOR. We calculate the psn of that "1". Separate the elements into two sets, ones whose bit at that psn is "1" and other set having the bit= "0"
// From the two sets, we get the two distinct values.

class Solution {
public:
    vector<int> singleNumber(vector<int>& v) {
		vector<int> u(2,0);
        if(v.size()<2)					// The sln is accepting two zeros instead of that num at (index-0)/NULL in case size<2;
            return u;
        int comb=0;
        for(auto num:v)
            comb^=num;					// Extracting the XOR of all values in the vector.
        comb&=-comb;                    //Extracting the first non zero bit in combination and saving it to itself.
										// Now, comb just holds the first non zero bit of comb.
        for(int i=0;i<v.size();i++){
            if((v[i] & comb) !=0)       //Case where the num has bit as non zero in same psn where earlier comb. has non zero.
                u[0]^=v[i];
            else						// Case where the num has that bit as Zero in the psn where earlier comb. has non zero.
                u[1]^=v[i];
        }
        return u;						// Returning the vector which contains two distinct non repeated values.
    }
};