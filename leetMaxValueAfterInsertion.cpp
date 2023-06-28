/*
*
//******************************************************1881. Maximum Value after Insertion.******************************************************

https://leetcode.com/problems/maximum-value-after-insertion/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"99"
9
"-13"
2
"768666753"
6
"-228839238"
6
"123"
4
"-564"
2



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we deal with pos, neg value strings separately, for positive string insert given char at the first index where the value is 
// less than given char, thus we increase the value at the MSB of the string, changing the char prior to this would decrease the value of the string as greater valued char
// is replaced by a smaller one thus decreasing the value of the string.
// We do the opposite in the case of negative value strings.







class Solution {
public:
    string maxValue(string s, int x) {
        string ch=to_string(x);
        // cout<<"char: "<<ch<<endl;
        if(s[0]!='-') {
            int i=0;
            while(i<s.length() && s[i]>=ch[0]) i++;							// Finding first index where char value is < given char and insert char there so that we inc. 
            s.insert(i,ch);													// // string val the most.
        } else {
            int i=1;
            while(i<s.length() && s[i]<=ch[0]) i++;							// Finding first index where char value is > given char and insert char there so that we inc. 
            s.insert(i, ch);												// string val the most.
        }
        return s;															// Returning the modified string.
    }
};
