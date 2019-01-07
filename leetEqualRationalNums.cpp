/*
*
//**********************************************************972. Equal Rational Numbers.***************************************************

Given two strings S and T, each of which represents a non-negative rational number, return True if and only if they represent the same number. 
The strings may use parentheses to denote the repeating part of the rational number.

In general a rational number can be represented using up to three parts: an integer part, a non-repeating part, and a repeating part. The number 
will be represented in one of the following three ways:

<IntegerPart> (e.g. 0, 12, 123)
<IntegerPart><.><NonRepeatingPart>  (e.g. 0.5, 1., 2.12, 2.0001)
<IntegerPart><.><NonRepeatingPart><(><RepeatingPart><)> (e.g. 0.1(6), 0.9(9), 0.00(1212))
The repeating portion of a decimal expansion is conventionally denoted within a pair of round brackets.  For example:

1 / 6 = 0.16666666... = 0.1(6) = 0.1666(6) = 0.166(66)

Both 0.1(6) or 0.1666(6) or 0.166(66) are correct representations of 1 / 6.

 

Example 1:

Input: S = "0.(52)", T = "0.5(25)"
Output: true
Explanation:
Because "0.(52)" represents 0.52525252..., and "0.5(25)" represents 0.52525252525..... , the strings represent the same number.
Example 2:

Input: S = "0.1666(6)", T = "0.166(66)"
Output: true
Example 3:

Input: S = "0.9(9)", T = "1."
Output: true
Explanation: 
"0.9(9)" represents 0.999999999... repeated forever, which equals 1.  [See this link for an explanation.]
"1." represents the number 1, which is formed correctly: (IntegerPart) = "1" and (NonRepeatingPart) = "".
 

Note:

1) Each part consists only of digits.
2) The <IntegerPart> will not begin with 2 or more zeros.  (There is no other restriction on the digits of each part.)
3) 1 <= <IntegerPart>.length <= 4
4) 0 <= <NonRepeatingPart>.length <= 4
5) 1 <= <RepeatingPart>.length <= 4




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"0.32(52)"
"0.325(25)"




"0.1252(52)"
"0.1(25)"





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, while comparing two fractions with diff. repeating repre., we iterate over them and form double 
// values from them for up to 20 places in decimals. If both rep. indicate same fraction, then they would be equal. This method is shortcut to get
// result.

// The actual method is explained in Official Solution of Leetcode.
// Actual method is to calculate the value of repeating digits, since the digits in it form Converging geometric progression values. Calc. that 
// fraction value and add that fraction to non-repeating fraction and compare the obtained fraction from both strings and return result.





class Solution {
public:
    
    double toDouble(string s){												// Converts to double.
        string res="";														// Forms the final string after removing '()'s.
        auto psn=s.find('(');												// Find the psn of start of rep. part.
        int index=psn;
        res=s.substr(0,index);												// Add non-repeating part to temp str rep.
        if(psn!=string::npos){												// If rep. part exists.
            string temp=s.substr(index+1, s.length()-2-index);				// Extract repeating part.
            // cout<<"temp: "<<temp<<endl;
            for(int j=0;j<20;j++) res+=temp;								// Add the rep. part upto 20 times to get enough accu. while comparing.
        }
        // cout<<"final str: "<<res<<endl;
        return stod(res);													// Convert the final str repre. into double value.
    }
    
    bool isRationalEqual(string s, string t) {
        double first=toDouble(s);											// Getting double value of this string.
        double second=toDouble(t);
        // cout<<"first: "<<first<<endl;
        // cout<<"second: "<<second<<endl;
        return (first==second);												// Comparing double values of both strings.
    }
};