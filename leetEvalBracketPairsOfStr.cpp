/*
*
//************************************************1807. Evaluate the Bracket Pairs of a String.***********************************************

https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/



You are given a string s that contains some bracket pairs, with each pair containing a non-empty key.

For example, in the string "(name)is(age)yearsold", there are two bracket pairs that contain the keys "name" and "age".
You know the values of a wide range of keys. This is represented by a 2D string array knowledge where each knowledge[i] = [keyi, valuei] indicates 
that key keyi has a value of valuei.

You are tasked to evaluate all of the bracket pairs. When you evaluate a bracket pair that contains some key keyi, you will:

Replace keyi and the bracket pair with the key's corresponding valuei.
If you do not know the value of the key, you will replace keyi and the bracket pair with a question mark "?" (without the quotation marks).
Each key will appear at most once in your knowledge. There will not be any nested brackets in s.

Return the resulting string after evaluating all of the bracket pairs.

 

Example 1:

Input: s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]
Output: "bobistwoyearsold"
Explanation:
The key "name" has a value of "bob", so replace "(name)" with "bob".
The key "age" has a value of "two", so replace "(age)" with "two".
Example 2:

Input: s = "hi(name)", knowledge = [["a","b"]]
Output: "hi?"
Explanation: As you do not know the value of the key "name", replace "(name)" with "?".
Example 3:

Input: s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
Output: "yesyesyesaaa"
Explanation: The same key can appear multiple times.
The key "a" has a value of "yes", so replace all occurrences of "(a)" with "yes".
Notice that the "a"s not in a bracket pair are not evaluated.
Example 4:

Input: s = "(a)(b)", knowledge = [["a","b"],["b","a"]]
Output: "ba"
 

Constraints:

1 <= s.length <= 105
0 <= knowledge.length <= 105
knowledge[i].length == 2
1 <= keyi.length, valuei.length <= 10
s consists of lowercase English letters and round brackets '(' and ')'.
Every open bracket '(' in s will have a corresponding close bracket ')'.
The key in each bracket pair of s will be non-empty.
There will not be any nested bracket pairs in s.
keyi and valuei consist of lowercase English letters.
Each keyi in knowledge is unique.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"(name)is(age)yearsold"
[["name","bob"],["age","two"]]
"hi(name)"
[["a","b"]]


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Hash Map based. While iterating we append all chars not inside parenthesis to final result str. We collect the chars inside paren.
// and we look for string in map, if it is present we replace the string with it's corresponding value in map, it it is not present we replace the
// string with '?'. 









class Solution {
public:
    string evaluate(string s, vector<vector<string>>& v) {
        string res="", temp="";
        unordered_map<string,string>m;										// Maps key, value pairs in knowledge array.
        for(int i=0;i<v.size();i++){
            m[v[i][0]]=v[i][1];
        }
        bool include=true;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){													// Indicates that we shouldn't append chars to final str.
                include=false;
                temp="";													// Init. the str which temp stores the char.
            }else if(s[i]==')'){											// End of paren. 
                // cout<<"temp: "<<temp<<endl;
                if(m.count(temp)==0) res+='?';								// If str gathered is not in map, replace it with '?'.
                else res+=m[temp];											// // If str gathered is in map, replace it with corresponding value str.
                temp="";
                include=true;												// Indicate to add chars to final str from next index.
            }else{
                if(include==true) res+=s[i];								// Add chars outside paren to final res.
                else temp+=s[i];											// Add chars inside paren to temp str
            }
        }
        return res;															// Returning the final str.
    }
};

