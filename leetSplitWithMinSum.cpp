/*
*
//************************************************2578. Split With Minimum Sum.***********************************************

https://leetcode.com/problems/split-with-minimum-sum/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


4325
687
332
54
3345
7334
5687
234
76334
8568748
183727383
730093873




// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Greedy+Sorting based. As we are trying to get the min sum, we will get the least value digits in the original number as Most Significant Digits in num1, num2. We convert the
// given number to string and sort them, we iter. from least value digits to highest value digits and alternatively add these digits to num1, num2(Alternatively so that the total would be minm). After
// the iter. we return num1+num2.







class Solution {
public:
    int splitNum(int num) {
        int num1=0, num2=0;
        string s=to_string(num);																		// We convert the num to string.
        sort(s.begin(), s.end());																		// We sort the string.
        for(int i=0;i<s.length();) {																	// We iter. from Least value digits to highest value digits.
            num1=num1*10+(s[i++]-'0');																	// Alternatively assign the digits to num1, num2.
            if(i<s.length()) num2=num2*10+(s[i++]-'0');
        }
        return num1+num2;																				// Return the sum of num1, num2.
    }
};



