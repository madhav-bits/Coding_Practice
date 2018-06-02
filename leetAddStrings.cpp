/*
*
//**************************************************************415. Add Strings.*******************************************************

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.


*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


""
1

"1"
""


"555"
"466"

"5"
"6"

"23"
"7"

"999"
"2"


"2"
"999"




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. We start from the end of both strings, we move to LSB to MSB, whatever the sum we get by adding a sign. bits
// we extract the rem. and pass it to next Signi. bit. We iterate till atleast one of strings have valid bits, if a bit is not present in shorter
// length string, we take the value 0 instead. If after the entire iteration, we still have rem. we append it to the string, later we reverse the
// entire string to get the acutal result.







class Solution {
public:
    string addStrings(string num1, string num2) {
		if(num2.length()==0) return num1;										// If one str. is empty return other str.
        if(num1.length()==0) return num2;
        string res="";
        int ind1=num1.length()-1, ind2=num2.length()-1;							// Setting last ind. of both strs as starting pt. of iteration.
        int rem=0;																// Carries the remainder.
        while(ind1>=0 || ind2>=0){												// If atleast one str has valid bits.
            int addn=0;															// We sum the curr. scanning bits.
            addn+=ind1>=0?num1[ind1]-48:0;										// If bit not present, take default value "0".
            addn+=ind2>=0? num2[ind2]-48:0;
            addn+=rem;															// Adding the rem. from the prev. summation of bits.
            res+=(addn%10)+'0';													// Adding the sum to result str.
            rem=addn/10;														// Calc. the remainder.
            ind1--; ind2--;														// Decreasing the iterator value.
        }
        if(rem!=0) res+=(rem)+'0';												// If rem. still exists, we append it to result str.
        
        int i=0, j=res.length()-1;
        while(i<j){																// Reversing the final result str.
            swap(res[i], res[j]);
            i++; j--;
        }
        return res;																// Returning the result str.
    }
};