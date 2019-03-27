/*
*
//***************************************************************394. Decode String.******************************************************

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is 
guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, 
there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"2[abc]abcd2[dc]3[cd]ef"

"2[abc3[db]efg2[cd3[a]ef]ghi]ef"

"2[3[db]efg2[cd3[a]ef]ghi]ef"


""

"aaa2[a3[b]b]"



// Time Complexity: O(n).  													// m- avg. value of repetition given in the code.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// m- avg. value of repetition given in the code.
// Space Complexity: O(n*m).	
// This algorithm is Stack based. Here, we gather the #repetitions the string inside the paren. goes. Once, we exit from the paren. we gather the resulting
// string and add it to it's immediate outer layer's string. We add the string accumulated till the time we reach ']' to the stack top's top to replicate
// it. We reset the temp. string to "" and value of rep. to 0. When entering into paren. also we add string accumulated till then into stack's top
// and reset the temp. str to "" and #rep. to 0 and push these values onto top of stack. As this entire code can be inside a paren or they can be a seq
// of parens, I will enclose all of this inside a dup paren with #rep set to 1. At the end of iter. we return the string in the top of stack.
// Here, we maintain two stacks, one to maintain the #rep. of each paren and other to keep track of str to be repeated corresponding to each paren.







class Solution {
public:
    string decodeString(string s) {
        stack<int>nums;
        stack<string>st;
        nums.push(1);st.push("");
        int num=0;
        string curr="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='['){
                // cout<<"assigning: "<<curr<<endl;
                st.top()+=curr;
                nums.push(max(1,num));
                st.push("");
                num=0;
                curr="";
            }else if(s[i]==']'){
                string res="";
                st.top()+=curr;
                // cout<<"rep: "<<nums.top()<<" and temp str: "<<st.top()<<endl;
                for(int j=0;j<nums.top();j++){
                    res+=st.top();
                }
                // cout<<"calc. str: "<<res<<endl;
                st.pop();
                nums.pop();
                st.top()+=res;
                // cout<<"resulting str: "<<st.top()<<endl;
                curr="";
                num=0;
            }else if(s[i]>='0' && s[i]<='9'){
                num=num*10+(s[i]-'0');
            }else curr+=s[i];
        }
        if(curr.length()>0) st.top()+=curr;
        return st.top();
    }
};


