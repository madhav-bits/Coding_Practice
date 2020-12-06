/*
*
//****************************************************1678. Goal Parser Interpretation.*************************************************

https://leetcode.com/problems/goal-parser-interpretation/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

Worked on test cases provided with question.
"G()(al)"
"G()()()()(al)"
"(al)G(al)()()G"


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. We iter. over given array, since only 3 types of word combinations are allowed, we check for them
// carefully and append the resulting char to result str and return it at end of iter.








class Solution {
public:
    string interpret(string s) {
        if(s.length()<=1) return s;
        string res="";
        int i=0;
        while(i<s.length()){												// Iter. over entire array.
            if(s[i]=='G'){	
                res+='G';
                i++;
            }else{															// Curr. char is '('
                if(s[i+1]==')'){											// Next char is ')'
                    res+='o';												// Append resulting char 'o' to result str.
                    i+=2;
                }else{														// Append resulting word "al" to result str.
                    res+="al";
                    i+=4;
                }
            }
        }
        return res;															// Return the result str.
    }
};