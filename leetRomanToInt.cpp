/*
*
//**********************************************************13. Roman to Integer.***************************************************

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The 
number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number 
four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which 
is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: C = 100, L = 50, XXX = 30 and III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"IX"
"X"
""
"X"
"CD"
"MCD"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. At each step, we check whether it forms a combination involvind dec. in value(4,9,400..). If it is we scan
// two chars in that iteration if not we scan only single char in it. We extract the value of that char from a map.




class Solution {
public:
    int romanToInt(string s) {
		if(s.length()==0) return 0;													// Empty roman literal, return 0.
        int index=0, total=0;														// Tracks curr. scanning index, integer sum scanned till now.
        unordered_map<string, int>m;												// Stores Roman To Integer relation.
        m["I"]=1;m["IV"]=4,m["V"]=5;m["IX"]=9, m["X"]=10;m["XL"]=40; m["L"]=50;m["XC"]=90; m["C"]=100;m["CD"]=400; m["D"]=500;m["CM"]=900; m["M"]=1000;
        while(index<s.length()){
            if(s[index]=='I'){														// Dec. in value cases.
                if(index+1<s.length() && (s[index+1]=='V' || s[index+1]=='X')){
                    total+=m[s.substr(index,2)];
                    index++;
                }
                else total+=m[s.substr(index,1)];
            }
            
            else if(s[index]=='X'){													// Dec. in value cases(400,900)
                if(index+1<s.length() && (s[index+1]=='L' || s[index+1]=='C')){
                    total+=m[s.substr(index,2)];
                    index++;
                }
                else total+=m[s.substr(index,1)];
            }
            
            else if(s[index]=='C'){													// Dec. in value cases(4000,9000)
                if(index+1<s.length() && (s[index+1]=='D' || s[index+1]=='M')){
                    total+=m[s.substr(index,2)];
                    index++;
                }
                else total+=m[s.substr(index,1)];
            }
            else total+=m[s.substr(index,1)];										// Stratight forward cases.
            
            index++;
            //cout<<"Total is: "<<total<<" with next scanning index is: "<<index<<endl;
        }
        
        //cout<<"Extracted sum is: "<<total<<endl;
        return total;																// Returning the obtained integer value.
    }
};