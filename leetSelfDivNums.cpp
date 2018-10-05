/*
*
//**********************************************************728. Self Dividing Numbers.***************************************************



A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:

The boundaries of each input argument are 1 <= left <= right <= 10000.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



1
105


1
16


1
10




1
1



101
201





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. We iterate over given range of numbers, check whether curr. num. satisfies the Self Dividing numbers cdn
// or not. If the condition isn't satisfied anywhere, then we stop checking if that num. is Self Dividing or not?(We extract each digit from 
// curr. num and divide the curr. num with the digit, if it's not divisible we stop checking). If that's self div. Num., then 
// we push that num. into final result vector.







class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>res;														// Final result vector.
        for(int i=left;i<=right;i++){										// Iter. through all nums. of given range.
            int num=i;														// Temp. storing curr. num.
            //if(i%10==0) continue;											// If it has last digit has '0', then skip it.
            while(num){														// Till digits in curr. num are extracted.
                int rem=num%10;												// Extracting curr. digit.
                if(rem==0 || i%rem!=0) break;								// If the given num isn't divisible by curr. digit stop checking.
                num/=10;													// Removing curr. digit from curr. num.
            }
            if(num==0) res.push_back(i);									// If all digits are extracted without issues, then that's SelfDivNum.
        }
        return res;															// Return the vector of SelfDivNums.
    }
};