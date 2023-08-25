/*
*
//*************************************************2024. Maximize the Confusion of an Exam.************************************************

https://leetcode.com/problems/maximize-the-confusion-of-an-exam/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"TTFF"
2
"TFFT"
1
"TTFTTFTT"
1
"FTTFTFTFTFTTFTFTFFTTTTFTFFTFFFTTTFTFTFTF"
5



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window based. Here, we take chars into window as long as it meets the condition that chars other maxFreq<k, once it doesn't meet 
// condition, we remove only first index in the window to hoping to make the window meet condition and dec. the length of the window to prev length, at this 
// point window may/maynot meet the condition also it can't improve the res and length of the window remains constant anyways. But the next time we improve 
// the res the maxFreq would be based of latest freq. and length of the window is also valid, so res update would be based on properly calculated length of 
// window. We return res at the end of iter.







class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int res=0, start=0, maxFreq=0;
        int trueCount=0, falseCount=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='T') maxFreq=max(maxFreq, ++trueCount);				// Tracking maxFreq.
            else maxFreq=max(maxFreq, ++falseCount);
            if(i-start+1-maxFreq>k) {										// If we don't meet the condition.
                if(s[start++]=='T') trueCount--;							// Remove first index in window and update freq.
                else falseCount--;
            } else if(i-start+1>res) res=i-start+1;							// If window is valid, try updating res.
        }
        return res;															// Returning the max #consecutive T/Fs after the operations.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// This is Sliding Window based. We track freq. of both chars, for us to get max. length of the window/consecutive chars after oper. We must have #non-freq
// chars=k, as these would be the chars which would be changed to the maxFreq char in the window, then all these would become consec. chars. When the window 
// doesn't meet the condition, we remove chars from the front of the window until the non maxFreq char would be <=k and the window becomes valid. We try to 
// update/maximize res with the length of the window in every index and return res at the end of iter.








class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int res=0, start=0;
        int trueCount=0, falseCount=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='T') ++trueCount;										// Tracking #occur. of each of the chars.
            else ++falseCount;
            while(min(trueCount, falseCount)>k) {							// Pop from the front until the window meets the condition of #non maxFreq chars<=k.
                if(s[start++]=='T') trueCount--;							// Removing front index of the window and updatng freq. of chars.
                else falseCount--;
            }
            if(i-start+1>res) res=i-start+1;								// Trying to maximize res with the length of the window.
        }
        return res;															// Returning the max #consecutive T/Fs after the operations.
    }
};

