/*
*
//**********************************************************9. Palindrome Number.***************************************************

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



-1
0
1
9
10
11
121
1331
10901
100901
10001



// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm extracts nums from the last and forms a new number from it. If the newly formed number and prev. number are same, then the 
// given number is a palindrome.








class Solution {
public:
    bool isPalindrome(int num) {
        if(num<0) return false;												// If val<0, then return false.
        if(num<10) return true;												// If val>=0  and vals<10, then return true.
        int rev=0, num2=num;												// Save the num in dup. var.
        while(num!=0){														// Until num becomes 0.
            rev=(rev*10)+num%10;											// Extracting the last bit from the number.
            num/=10;
        }
        return num2==rev;													// If the reversed num and orig. num are same, then return true.
        
    }
};




