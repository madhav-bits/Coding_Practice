/*
*
//**********************************************************7. Reverse Integer.***************************************************

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For 
the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


-2147483648
2147483647
-1
0
100
201
-321




// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is divison based problem. At each step, we extract the last digit(one's placed) one push into the result and reduce the number
// to number/10(Retains all bits except last digit(one's placed) to be used for next iteration. If there is overflow, we return 0.



class Solution {
public:
    int reverse(int x) {
        long long int ans=0;															// Stores the to be returned result.
        while(x!=0){																	// Until value reduces to 0.
            //cout<<"Curr. value of x: "<<x<<endl;
            ans=(ans*10)+x%10;															// Extracting last digit.
            x/=10;																		// Passing the rest digits for next iteration.
        }
        //cout<<"The result is: "<<ans<<endl;
        return (ans>INT_MAX || ans<INT_MIN)? 0:ans;										// Checking for overflow, if yes return 0 else return ans.
        //return ans;
    }
};