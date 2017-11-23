/*

//*****************************************************357. Count Numbers with Unique Digits*****************************************

n a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.


//Time Complexity: O(n) for n<=10 and O(1) for n>10;.
// Space Complexity: O(1).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/

// No. of unique digits follows a mathematical structure. So, as to get the value of that math. exp, following while loop is needed. After-
//- reaching n=10, there can't be any unique digits then. So, returning value of n=10;

// If n=0; the value is of: 1
// If n=1; the value is of: 1+9
// If n=2; the value is of: 1+9+(9*9)
// If n=3; the value is of: 1+9+(9*9)+(8*9*9)
// If n=4; the value is of: 1+9+(9*9)+(8*9*9)+(7*8*9*9)
// If n=5; the value is of: 1+9+(9*9)+(8*9*9)+(7*8*9*9)+(6*7*8*9*9)

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        int a=n,temp=9, count=10,var=9;
        if(a<=10){// If n=3; the value is of: 1+9+(9*9)+(8*9*9)
            while(a>1){// If n=4; the value is of: 1+9+(9*9)+(8*9*9)+(7*8*9*9)
                temp=temp*var;// If n=5; the value is of: 1+9+(9*9)+(8*9*9)+(7*8*9*9)+(6*7*8*9*9)
                count+=temp;
                var--;
                a--;
            }
        }
        else// Once n crosses 10, there won't be any unique integers from there on, So, need to return values from n=10;
            return 8877691;
        
        return count;
    }
};