/*
*
//******************************************************2380. Time Needed to Rearrange a Binary String.******************************************************

https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"00111"
"0110101"
"11100"
"0110101"
"00110101101" 
"0011100011011011100"
"00110001100"
"001100011"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n).
// Space Complexity: O(1).	
// This algorithm is a Brute Force approach. We repeat the same process until we don't observe any swaps. We run the outermost while loop atmost n times #iter.
// will be at max. #1 times+#some of zeroes which lead to waiting for the last zero for it's turn to swap, so at max. it will be n times.







class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int res=0;
        bool changed=true;
        while(changed) {
            changed=false;
            for(int i=0;i+1<s.length();i++) {
                if(s[i]=='0' && s[i+1]=='1') {
                    swap(s[i], s[i+1]);
                    i++;
                    changed=true;
                }
            }
            res++;
        }
        res--;
        return res;
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. A index with '1' char takes at least #steps taken by it's prev. '1' index to move all zeroes +1, we use atleast as this
// might have to process excess zeroes befor processing zeroes moved by prev. '1'. The #steps can also be affected by #zeroes before curr. index., in case of 
// many zeroes they clog the replacement process and time taken equals #zeroes, we try to assign the max of both to the curr. index with '1'. We return the
// latest res value at the end of iter.


// Discussion forum link for this solution:
// https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/discuss/2454262/DP-vs.-Brute-Force






class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int zeroes=0, res=0;
        for(char&ch:s) {
            if(ch=='0') zeroes++;											// Tracking #zeroes encountered.
            else if(zeroes) {
                res=max(res+1, zeroes);										// Assgning max. replacements steps needed to process all zeroes till this index.
            }
        }
        return res;															// Returning total #replacement steps needed to process all zeroes.
    }
};

