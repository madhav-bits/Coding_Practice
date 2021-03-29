/*
*
//******************************************************1742. Maximum Number of Balls in a Box.******************************************

https://leetcode.com/problems/maximum-number-of-balls-in-a-box/


You are working in a ball factory where you have n balls numbered from lowLimit up to highLimit inclusive (i.e., n == highLimit - lowLimit + 1), 
and an infinite number of boxes numbered from 1 to infinity.

Your job at this factory is to put each ball in the box with a number equal to the sum of digits of the ball's number. For example, the ball 
number 321 will be put in the box number 3 + 2 + 1 = 6 and the ball number 10 will be put in the box number 1 + 0 = 1.

Given two integers lowLimit and highLimit, return the number of balls in the box with the most balls.

 

Example 1:

Input: lowLimit = 1, highLimit = 10
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
Ball Count:  2 1 1 1 1 1 1 1 1 0  0  ...
Box 1 has the most number of balls with 2 balls.
Example 2:

Input: lowLimit = 5, highLimit = 15
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
Ball Count:  1 1 1 1 2 2 1 1 1 0  0  ...
Boxes 5 and 6 have the most number of balls with 2 balls in each.
Example 3:

Input: lowLimit = 19, highLimit = 28
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 12 ...
Ball Count:  0 1 1 1 1 1 1 1 1 2  0  0  ...
Box 10 has the most number of balls with 2 balls.
 

Constraints:

1 <= lowLimit <= highLimit <= 105




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


1
10
5
15
15
100000



// Time Complexity: O(n).  													// #nums in the range.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// #nums in the range.
// Space Complexity: O(1).	
// This algorithm is itetation based. For every num in the range, we calc. the sum of digits and inc. the value in occur array which tracks #nums with 
// this index digit total. We return the max. value stored in this occur array.








class Solution {
public:
    
    int getDigitCount(int num){												// Returns the digit count for this num.
        int res=0;
        while(num){
            res+=num%10;
            num/=10;
        }
        return res;
    }
    
    int countBalls(int lowLimit, int highLimit) {
        vector<int>occur(46,0);												// Stores #nums with the index valued digit count.
        int res=0;
        for(int i=lowLimit;i<=highLimit;i++){
            int cnt=getDigitCount(i);										// Func. call to get digit count.
            occur[cnt]++;
            if(occur[cnt]>res) res=occur[cnt];								// Tracks maxm #nums with same digit count.
        }
        return res;															// Returning the max #nums with same digit count.
    }
};

