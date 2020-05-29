/*
*
//**************************************1432. Max Difference You Can Get From Changing an Integer.*************************************

https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/


You are given an integer num. You will apply the following steps exactly two times:

Pick a digit x (0 <= x <= 9).
Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
Replace all the occurrences of x in the decimal representation of num by y.
The new integer cannot have any leading zeros, also the new integer cannot be 0.
Let a and b be the results of applying the operations to num the first and second times, respectively.

Return the max difference between a and b.

 

Example 1:

Input: num = 555
Output: 888
Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
The second time pick x = 5 and y = 1 and store the new integer in b.
We have now a = 999 and b = 111 and max difference = 888
Example 2:

Input: num = 9
Output: 8
Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
The second time pick x = 9 and y = 1 and store the new integer in b.
We have now a = 9 and b = 1 and max difference = 8
Example 3:

Input: num = 123456
Output: 820000
Example 4:

Input: num = 10000
Output: 80000
Example 5:

Input: num = 9288
Output: 8700
 

Constraints:

1 <= num <= 10^8




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


9288


1288

3329

1021


9099


1011




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Observation based. We create huge num by replacing the first non-9 char with 9 in the entire string. We can get 
// low num. by replacing first >1 char with '0' if it is found at an index >0 or replace with '1' if it is found at '0'. This slight
// changes are because it prevents leading zeroes. We subtract both these values and return the result.







class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        int index=-1, firstIndex=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]!='9' && firstIndex==-1) firstIndex=i;					// Tracking index of first non-9 char.
            if(s[i]>'1' && index==-1) index=i;								// Tracking first >1 char's index.
        }
        string up=s, down=s;
        for(int i=0;i<s.length();i++){
            if(firstIndex>=0 && up[i]==s[firstIndex]) up[i]='9';			// Replacing non-9 with 9 to get higher value.
            if(index==0 && s[i]==s[index]) down[i]='1';						// Replacing >1 with 1 to get lower value if findIndex=0.
            else if(index>0 && s[i]==s[index]) down[i]='0';					// Replacing >1 with 0 to get lower value if findIndex>0.
        }
        int high=stoi(up), low=stoi(down);									// Calc. higher and lower value.
        return high-low;													// Calc. diff and return.
    }
};