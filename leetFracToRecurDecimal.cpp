/*
*
//******************************************************166. Fraction to Recurring Decimal.***********************************************

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


-22
-2

22
-2

-22
2


-22
-2.2


2
17

0
1

1
2





// Time Complexity: O(n). 						// Not exactly, depends on the number given. 
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).						// Not exactly, depends on the number given.
// Space Complexity: O(n).	
// This algorithm is iteration based, we iterate until we encounter a remainder which we have already encountered in earlier calc. for decimal
// portion, indicating that following decimals would be repated. So, we stop iterating and return the string acquired till then. At each step, 
// we push the decimal portion char into result str.









class Solution {
public:
    string fractionToDecimal(int64_t  numer, int64_t  denom) {
        if(numer==0) return "0";													// If num. is 0, return 0.
        string res="";																// Final result str.
        unordered_map<int, int>m;													// Stores indices of decimal part in result str.
        
        if(numer<0 ^ denom<0) res+="-";												// If anyone of nums is neg., then res is neg.
        numer=abs(numer);															// Taking the abs. of both nums.
        denom=abs(denom);
        int64_t  rem=numer/denom;													// Calc. the quotient.
        res+=to_string(rem);														// Appending quotient to result str.
        if(numer%denom==0) return res;												// If rem=0, return quotient.
        res+=".";
        rem=numer%denom;															// Calc. remainder.
        rem*=10;
        while(rem){																	// Loop, until remainder becomes zero/ recurring part found.
            // cout<<"rem: "<<rem<<endl;
            if(m.count(rem)==1){													// If recurring part's beginnning is identified.
                // cout<<"Repeated found with temp:"<<temp<<endl;
                res.insert(m[rem],"(");												// Inserting "(" at the beginning of recurring part.
                res+=")"; 															// Appending ")" at the end.
                break;
            }
            m[rem]=res.size();														// Noting the index of curr. decimal  number.
            res+=to_string(rem/denom);												// Appending curr. decimal to result str.
            rem=rem%denom;															// Calc. remainder.
            rem*=10;														// Inc. rem 10 times, for next division(to extract next decimal part).
            // cout<<"temp: "<<temp<<endl;
        }
        return res;																	// Returning the result str.
    }
};