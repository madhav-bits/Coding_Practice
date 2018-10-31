/*
*
//**********************************************************932. Beautiful Array.*******************************************************

For some fixed N, an array A is beautiful if it is a permutation of the integers 1, 2, ..., N, such that:

For every i < j, there is no k with i < k < j such that A[k] * 2 = A[i] + A[j].

Given N, return any beautiful array A.  (It is guaranteed that one exists.)

 

Example 1:

Input: 4
Output: [2,1,4,3]
Example 2:

Input: 5
Output: [3,1,2,5,4]
 

Note:

1 <= N <= 1000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



3

15

16

17

10


99





// Time Complexity: O(nlgon).												//   In the worst case, each num is touched logn times.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// In the worst case, each num is touched logn times.
// Space Complexity: O(n).	
// This algorithm is PURELY OBSERVATION based. Here, we can make observations that one Beautiful array can be extracted from a Bea. array by 
// applying arith. operations such as '+','*' or '-'s.So, we start building basic Bea. array of length [1], we perform above operations and 
// create even arrays and odd arrays and append them, as both of them indi. are Bea. arrays and if in the triplet, taking two numbers from 
// a part, other from other part, always gives odd sum, as a result it won't match 2* mid value.


// Below link has even clearer explanation of the above mentioned algorithm.
// https://leetcode.com/problems/beautiful-array/discuss/186679/C++JavaPython-Odd-+-Even-Pattern-O(N)








class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int>res;														// Result Beautiful array.
        res.push_back(1);													// Smallest Beaut. array.
        while(res.size()<N){												// Until target length is reached.
            vector<int>temp;												// Calc. the next step Beat. array from curr. array.
            for(int i=0;i<res.size();i++) if(2*res[i]-1<=N) temp.push_back(2*res[i]-1);	// Calc. even valued Beat. array.
            for(int i=0;i<res.size();i++) if(2*res[i]<=N)temp.push_back(2*res[i]);		// Calc. odd valued Beat. array.
            res=temp;														// Moving forward the Beat. from curr. calculations.
        }
        return res;															// Returning the result Beautiful array.
    }
};