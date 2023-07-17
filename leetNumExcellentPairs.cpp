/*
*
//******************************************************2354. Number of Excellent Pairs.******************************************************

https://leetcode.com/problems/number-of-excellent-pairs/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,1]
3
[5,1,1]
10
[543,55,3,576,43,787,5,3,78,5,32,56,7,85,2,77,32,43,7,86,3,7,86,4,4]
5
[1,1,2,2,4,4]
2



// Time Complexity: O(n*k)=O(n).											//n-#nums in the array, k-32 bits of the nums.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*k)=O(n).											//n-#nums in the array, k-32 bits of the nums.
// Space Complexity: O(n).	
// This algorithm is Bit Manipulation and observation based. It can be observed that sum of the number of set bits in num1 OR num2 and num1 AND num2 is nothing
// but sum of #set bits each of the nums. If ith bit in both nums are 0,1 their OR would be 1, AND would be 0, if they are 1,1 OR=1, AND=1, which implies 
// that the overall sum of set bits in OR and AND oper. for ith bit is #set bits in ith psn, if we extend the same to all bits, it becomes sum of #set bits in 
// both numbers. We remove duplicate nums from the array to avoid calc. duplicate pairs. Since (1,3) and (3,1) are considered diff. pairs we do 2*occur[i] to 
// get total #pairs that prev. nums forms with curr. num.. We can use number from same index as a pair of nums so we check (arr[i], arr[i]) can be pair, if yes
// we add 1 as reversing nums in the pairs would still result in same pair. We return total #pairs at the end of iter.







class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long int res=0;
        vector<int>occur(32,0);												// Tracks #nums with same #set bits.
        unordered_set<int>st;												// Ensures each num is visited only once.
        for(int num:nums) {
            if(st.count(num)==1) continue;									// Avoids revisiting same num more than once.
            int bits=0, temp=num;
            while(num) {													// Calc. #set bits for curr. number.
                bits+=(num&1);
                num>>=1;
            }
            for(int i=max(k-bits,0);i<=31;i++) res=res+2ll*occur[i];		// Curr. num forming pairs with prev. numbers.
            if(2*bits>=k) res++;											// If curr. num can form pair with itself, we add 1 to res.
            st.insert(temp);												// Inserting curr. num into set.
            occur[bits]++;													// Inc. #nums with 'bits' #set bits.
            // cout<<"res: "<<res<<endl;
        }
        return res;															// Returning total #pairs that satisfies the given conditions.
    }
};

