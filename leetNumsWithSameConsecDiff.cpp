/*
*
//****************************************************967. Numbers With Same Consecutive Differences.*********************************************

Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is 
invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1) 1 <= N <= 9
2) 0 <= K <= 9




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



1
6


2
4




7
5


4
8




// Time Complexity: O(2^n).  												// At every stage, there are two possibilities.
// Space Complexity: O(2^n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).													// At every stage, there are two possibilities.
// Space Complexity: O(2^n).	
// This algorithm is Backtracking/DFS based. Here, since we want adj. digits to be of given diff., we have two possibilities at every stage of 
// DFS. One case would be a smaller value, other would be a greater value. In case of smaller value, the value>=0, in case of greater value,
// the value<10. As, the nums. can't have leading zeros, we start from 1 to 9, then later include 0 also in calculations. If we find the 
// digit at curr. stage, we append the new digit at the end of num. formed till now and pass it to recursive call. Once, we obtain the required
// length digit, we push the digit into final res.








class Solution {
public:
    
    void findCombi(int digits, int diff, vector<int>&res, long int num){
        if(digits==0){														// If required len. is formed push it into final res.
            res.push_back(num);
            return ;
        }
        long int temp=num%10;												// Extracting the last digit of num. formed till now.
        if(temp-diff>=0){													// If the smaller value with given diff>=0.
            long int val=temp-diff;											// Get the digit.
            temp=(num*10)+val;												// Form the updated num including new digit.
            findCombi(digits-1, diff, res, temp);							// Give recursive call with new num.
        }
        temp=num%10;														// Also, diff!=0, as duplicates need to be avoided.
        if(diff!=0 && temp+diff<10){										// If larger value is <10.
            long int val=temp+diff;
            temp=(num*10)+val;
            findCombi(digits-1, diff, res, temp);
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N==1) return vector<int>({0,1,2,3,4,5,6,7,8,9});					// Base case of num. length 1.
        vector<int>res;														// Stores final res. nums.
        long int num=0;														// Stores num. formed in the process at every iteration.
        for(int i=1;i<=9;i++){												// Start nums. from 1 to 9.
            num=i;
            findCombi(N-1, K, res, num);									// Call to form various nums starting curr. digit.
        }
        
        return res;															// Returning all the nums. satisfying given cdns.
    }
};