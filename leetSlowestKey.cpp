/*
*
//********************************************************1629. Slowest Key.***************************************************

https://leetcode.com/problems/slowest-key/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[9,29,49,50]
"cbcd"
[12,23,36,46,62]
"spuda"
[12,23,36,56,62]
"spusa"



// Time Complexity: O(n). 
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we iterate over the given string, calc. press time and try to maximize the long press time
// and track the corresponding char. and return it at the end of iter.







class Solution {
public:
    char slowestKey(vector<int>& times, string s) {
        char res=s[0];
        int maxPress=times[0];
        for(int i=1;i<times.size();i++){
            int diff=times[i]-times[i-1];
            if(diff>maxPress || (diff==maxPress && s[i]>res)){
                res=s[i];
                maxPress=diff;
            }
        }
        return res;
    }
};