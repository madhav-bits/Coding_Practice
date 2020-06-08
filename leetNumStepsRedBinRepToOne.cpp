/*
*
//****************************1404. Number of Steps to Reduce a Number in Binary Representation to One.****************************

https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/


Given a number s in their binary representation. Return the number of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It's guaranteed that you can always reach to one for all testcases.

 

Example 1:

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.  
Example 2:

Input: s = "10"
Output: 1
Explanation: "10" corressponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  
Example 3:

Input: s = "1"
Output: 0
 

Constraints:

1 <= s.length <= 500
s consists of characters '0' or '1'
s[0] == '1'




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"1101"

"10"

"11100011"



// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, as we add '1' if we encounter '1' at LSB, we add two to res indicating adding '1' and remo-
// -ving zero after addn, we remove replaced zeroes for the consecutive ones, then we replace first encountered zero with '1'. If 
// we encounter zero, we inc. the result by 1 as we simply div by 2. Thus, each index is visited at most twice. At the end of iter., we
// return the final count. We iter. in reverse direction from LSB to MSB. At the end of iter. we will be left with single bit '1'.






class Solution {
public:
    int numSteps(string s) {
        int res=0;															// Tracks the #steps taken in the process.
        int index=s.length()-1;												// Tracks the ptr.
        while(index>0){
            if(s[index]=='1'){												// If we face '1'.
                res+=2;														// Accouting for adding '1' and removing LSB.
                index--;
                while(index>=0 && s[index]=='1'){							// Removing consec. ones replaced as zeroes after adding '1'.
                    res++;
                    index--;
                }
                if(index>=0) s[index]='1';									// Reassigning first encountered zero after ones as '1'.
            }else{															// If '0' is encountered.
                res++;														// Div. by 2, so we inc. the cnt by 1.
                index--;
            }
        }
        return res;															// Returning the total #steps taken.
    }
};
