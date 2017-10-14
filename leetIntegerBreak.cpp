/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. 
Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

//**************************************************THIS IS LEET ACCEPTED CODE.**************************************************
*/
class Solution {
public:
    int integerBreak(int n) {
        if(n==1 || n==2)// These are base cases.
            return 1;
        if(n==3)// These are base cases.
            return 2;
        int divisor=0;
        if(n%3==0){
            int divisor=n/3;
            return pow(3,divisor);
        }
        if(n%3==1){// As 4 can be best split as 2+2 rather than 3+1 product wise.
            int divisor=n/3;
            return (pow(3,divisor-1)*4);
        }
        if(n%3==2){//Remainder 2 in this case get multiplied as it is.
            int divisor=n/3;
            return (pow(3,divisor)*2);
        }
    }
};