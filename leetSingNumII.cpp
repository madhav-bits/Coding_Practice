/*

//******************************************************137. Single Number II.**************************************************

Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/

// Solution 1: 


class Solution {
public:
    int singleNumber(vector<int>& v) {
		/*
        for(const auto& num:v)
            cout<<"Nums are: "<<num<<endl;
		*/
		
        int ones=0, twos =0;
        int n=v.size();
        int common_bit_mask;
        for(int i=0; i<n;i++){
            //cout<<"After index i: "<<i<<endl;
            twos= twos|(ones&v[i]);							// Storing the second occurence of all integers.
            ones=ones^v[i];									// Storing the first occurence of all integers.
            //cout<<"twos is: "<<twos<<endl;
            //cout<<"ones is: "<<ones<<endl;
            common_bit_mask= ~(ones&twos);					// Removing(nullyfying) all elem. which are in ones and twos(occured three times).
            ones &=common_bit_mask;							// Removing those from "ones" which occured three times.
            twos &=common_bit_mask;
        }
        return ones;
    }
};