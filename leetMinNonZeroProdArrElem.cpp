/*
*
//********************************************1969. Minimum Non-Zero Product of the Array Elements.******************************************

https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
2
3
60
59
55
54
4
5
11



// Time Complexity: O(n).													// n-integer provided as input.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n-integer provided as input.
// Space Complexity: O(1).	
// This algorithm is Observation based. Here, we want to decrease the product as much as possible. If we pick a pair of nums, we can dec. product by 
// dec. the smaller value and inc. the greater value by same amounts, at max. we can dec. smaller val to 1. Other observation is that if we pair(i, 2^p-1-i)
// we can dec. the smaller val to 1 and greater val to (2^p)-2 thus reducing ((2^p-1)-1) values to 1 and (2^p)-2, if we pick other alternative pairs we 
// might not be able to get these many 1s and we observe that since we have more number of nums their product would be >above chosen pairs final nums. 
// So, at the end the product of nums will be ((2^p)-1)*((2^p)-2)^(2^(p-1)-1).



// These discussion forum posts has detailed expalanation for the approach:
// https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/discuss/1404343/modPow
// https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/discuss/1403913/Python-math-oneliner-with-proof-explained







class Solution {
public:
    
    int calcPower(long long int base, long long int exp) {					// Calculating base^exp.
        int mod=1000000007, res=1;
        base=base%mod;
        while(exp>0) {
            if((exp&1)!=0) res=(1ll*res*base)%mod;
            exp>>=1;
            // cout<<"base: "<<base<<endl;
            base=(1ll*base*base)%mod;
        }
        return res;
    }
    
    int minNonZeroProduct(int p) {
        int mod=1000000007;
        long long int val=(1ll<<p)-1;
        int temp=calcPower(val-1, (val-1)/2);								// Calc. power value.
        return (1ll*(val%mod)*temp)%mod;									// Returning the product of final state of nums.
    }
};

