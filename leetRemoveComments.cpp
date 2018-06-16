/*
*
//************************************************************722. Remove Comments.*****************************************************

Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an 
increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
Given a C++ program, remove comments from it. The program source is an array where source[i] is the i-th line of the source code. This 
represents the result of splitting the original source code string by the newline character \n.

In C++, there are two types of comments, line comments, and block comments.

The string // denotes a line comment, which represents that it and rest of the characters to the right of it in the same line should be ignored.

The string /* denotes a block comment, which represents that all characters until the next (non-overlapping) occurrence of */ should be 
ignored. (Here, occurrences happen in reading order: line by line from left to right.) To be clear, the string /*/ does not yet end the 
\block comment, as the ending would be overlapping the beginning.

The first effective comment takes precedence over others: if the string // occurs in a block comment, it is ignored. Similarly, if the 
string /* occurs in a line or block comment, it is also ignored.

If a certain line of code is empty after removing comments, you must not output that line: each string in the answer list will be non-empty.

There will be no control characters, single quote, or double quote characters. For example, source = "string s = "/* Not a comment. */";" w
ill not be a test case. (Also, nothing else such as defines or macros will interfere with the comments.)

It is guaranteed that every open block comment will eventually be closed, so /* outside of a line or block comment always starts a new comment.

Finally, implicit newline characters can be deleted by block comments. Please see the examples below for details.

After removing the comments from the source code, return the source code in the same format.

Example 1:
Input: 
source = ["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   
omment for ", "   testing */", "a = b + c;", "}"]

The line by line code is visualized as below:
/*Test program */
int main()
{ 
  // variable declaration 
int a, b, c;
/* This is a test
   multiline  
   comment for 
   testing */
a = b + c;
}

Output: ["int main()","{ ","  ","int a, b, c;","a = b + c;","}"]

The line by line code is visualized as below:
int main()
{ 
  
int a, b, c;
a = b + c;
}

Explanation: 
The string /* denotes a block comment, including line 1 and lines 6-9. The string // denotes line 4 as comments.
Example 2:
Input: 
source = ["a/*comment", "line", "more_comment*/b"]
Output: ["ab"]
Explanation: The original source string is "a/*comment\nline\nmore_comment*/b", where we have bolded the newline characters.  After 
deletion, the implicit newline characters are deleted, leaving the string "ab", which when delimited by newline characters becomes ["ab"].
Note:

The length of source is in the range [1, 100].
The length of source[i] is in the range [0, 80].
Every open block comment is eventually closed.
There are no single-quote, double-quote, or control characters in the source code.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "avd /* This is a test", "   multiline  ", "   comment /*/ for ", "   testing */", "a = b + c;", "}"]



["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "// avd /* This is a test", "   multiline  ", "   comment /*/ for ", "   testing */", "a = b + c;", "}"]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, we check for single line comments(//) or mutiline comments(/*). once we encounter (//), we push the string
// that we have accum/stored till now into final result vector. If we encounter (/*), we change the state of comm to 1. In state of comm=1, we 
// won't store any chars from string,we start storing chars once again after encountering (*/), we push into final result vector at the end of 
// each line, if comm=0 and a non-empty stored string.








class Solution {
public:
    vector<string> removeComments(vector<string>& v) {
        vector<string>res;
        int comm=0;
        string temp="";
        for(int i=0;i<v.size();i++){
            // cout<<"Iterating this line: "<<i<<endl;
            if(comm==0) temp="";
            for(int j=0;j<v[i].length();j++){
                if(comm==0 && j+1<v[i].length() && v[i][j]=='/' && v[i][j+1]=='/'){		// Change of state, comm=1, upon encount. (/*)
                    if(temp!="")
                        res.push_back(temp);
                    break;
                }
                else if(comm==0 && j+1<v[i].length() && v[i][j]=='/' && v[i][j+1]=='*'){// Change of state, comm=0, upon encount. (*/)
                    comm=1;
                    j++;
                }
                else if(comm==1 && j+1<v[i].length() && v[i][j]=='*' && v[i][j+1]=='/'){// If end of Multi-Line Comment is reached
                    comm=0;																// Change state, cumm=0.
                    j++;
                }
                else if(comm==0){														// If state, cumm=0, append the string to temp. str.
                    // cout<<"Updating temp to be: "<<v[i][j]<<endl;
                    temp+=v[i][j];
                }
                
                if(comm==0 && j==v[i].length()-1 && temp!=""){							// If end of line is reached with state, cumm=0.
                    // cout<<"Pushing into res: "<<temp<<endl;							// Push into final result vector.
                    res.push_back(temp);
                }
            }
            // cout<<"temp at end of line is: "<<temp<<endl;
        }
        
        return res;																		// Returning the final result vector.
    }
};