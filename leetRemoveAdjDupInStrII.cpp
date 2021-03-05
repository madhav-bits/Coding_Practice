/*
*
//******************************************************1209. Remove All Adjacent Duplicates in String II.***********************************************


https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"abcd"
2
"asdjfoaidjlklaksdjfladslk"
2
"sfaldsfjalssssljlsfkkkioejflallll"
3


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is stack based. Here,we iterate over string and keep track of curr. char and repetition until we encounter diff. char, here, we check
// if the prev. char on top of stack is same as curr. char with rep, if they are same we update the cnt part with total%k, if total%k==0 we pop it. If
// they are diff we add curr. char onto stack. At the end of iteration, we form a string based on chars inside the stack, we reverse the string and return
// it.











class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res="";
        stack<pair<char,int>>st;											// Stores char and their count.
        int rep=1;
        char ch=s[0];
        for(int i=1;i<=s.length();i++){										// ITer. over string.
            if(s[i]==ch) rep++;												// Keep cnt of consec. chars.
            else{
                if(!st.empty() && st.top().first==ch){						// If curr. and prev. char on top of stack are same.
                    if((st.top().second+rep)%k==0) st.pop();
                    else st.top().second=(st.top().second+rep)%k;
                }else if(rep%k!=0) st.push({ch,rep%k});						// If curr. and prev. char on top of stack are different.
                if(i<s.length()) ch=s[i];
                rep=1;														// Setting next. char and rep to 1.
            }
        }
        while(!st.empty()){													// Forming string out of left chars.
            res+=string(st.top().second,st.top().first);
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;															// Returning the resulting string after delete operations.
    }
};