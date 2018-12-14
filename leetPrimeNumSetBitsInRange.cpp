/*
*
//************************************************762. Prime Number of Set Bits in Binary Representation.*****************************************

Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary 
representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 
which has 3 set bits. Also, 1 is not a prime.)

Example 1:

Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
Example 2:

Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
Note:

L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


10842
10888


9001
10229


1
23


// Time Complexity: O(n).  													// As, it takes 32 steps to calc. maxm. 1s in each num.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// As, it takes 32 steps to calc. maxm. 1s in each num.
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we iterate over all nums. in the range. For every num, we extract all the bits and count the 1s
// occurance. Then it's calc. they are prime are not by another function, if it's prime number, we inc. the result by one. At the end of all
// numbers, we return the result number(#Nums. with Prime num. of bits set as 1 in them).








class Solution {
public:
    
    bool isPrime(int count){												// Calc. if a num. is Prime or not?
        if(count<=1) return false;
        if(count==2) return true;
        for(int i=2;i*i<=count;i++){
            if(count%i==0) return false;
        }
        return true;
    }
    
    void calcBits(int num, int&res){										// Count #1 bits in curr. num.
        int div=1, count=0;
        while(num>0){														// Till the num. is valid.
            if(num%2==1) count++;											// If last bit is 1, inc. the count.
            num/=2;															// Moving the digit to the right by 1 bit.
        }
        if(isPrime(count)) res++;											// Calling fn. to know whether count is prime or not?
        return ;
    }
    
    int countPrimeSetBits(int low, int high) {
        int res=0;															// Final result.
        for(int i=low;i<=high;i++){											// Iter. over all nums.
            calcBits(i,res);												// Call fn. to know whether num. has prime 1s or not?
        }
        return res;															// Returning the final count.
    }
};