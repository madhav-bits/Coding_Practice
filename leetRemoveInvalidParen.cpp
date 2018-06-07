/*
*
//******************************************************301. Remove Invalid Parentheses.***********************************************

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]
Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]
Example 3:

Input: ")("
Output: [""]



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"()())()(())))"


"()(()()"





// Time Complexity: O(n*2^n).  
// Space Complexity: O(n*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*2^n).
// Space Complexity: O(n*n).	
// This algorithm is stack based. We make sure to remove only firt of repeating closing parens at each step to make sure that duplicate final
// results aren't produced. We also reverse the string to deal with consecutive opening parens.


//*****************************************************NEED TO DO THIS PROBLEM IN BFS WAY.*************************************************



class Solution {
public:
    
    void extractStr(std::string s, int start, int lastDel, std::vector<std::string>& ans, std::string parens) {

        int diff = 0; // # of parens[0] - # of parens[1]

        // find the first index that make it invalid
        while (start < s.length()) {
            if (s[start] == parens[0]) {
                ++diff;
            } else if (s[start] == parens[1]) {
                --diff;
            }
            if (diff < 0) {
                break;
            }
            ++start;
        }

        if (start == s.length()) {  // reached the end
            if (parens == ")(") { // we are checking the reversed string
                std::reverse(s.begin(), s.end());
                ans.push_back(s);
            } else { // we only checked the original string for )
                std::reverse(s.begin(), s.end());
                extractStr(s, 0, 0, ans, ")(");
            }
        } else {
            for (int i = lastDel; i <= start; ++i) {
                // try deleting any parens[1] that are the first of consecutive sequence
                if (s[i] == parens[1] && (i == lastDel || s[i-1] != s[i])) {
                    extractStr(s.substr(0, i) + s.substr(i + 1), start, i, ans, parens);
                }
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        extractStr(s,0,0,res,"()");
        return res;
    }
};