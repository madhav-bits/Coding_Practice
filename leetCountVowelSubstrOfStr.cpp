/*
*
//******************************************************2062. Count Vowel Substrings of a String.******************************************************

https://leetcode.com/problems/count-vowel-substrings-of-a-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aeiouu"
"unicornarihan"
"cuaieuouac"
"alskdjiaoeuoialadfjalkfdgjaoeiuaioeulijarjalaeiaoepdkaieuofaiefoadiaueaoiaeoaeuaueiaaeiouasdiasaeiou"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Map+Sliding Window based. Here, since we want substrs with all five vowels, we keep ading indices to substr and keep track of #unique vowels we have in 
// substr, once we reach, we try to move the start of the window as much as possible yet we can have 5 unique vowels in substr. Now, we can start at all the indices of prev. 
// zero+1 to curr. start of window=[start-prev] till curr. index and yet we can have 5 unique vowels in substr which meets the condition, so we add this diff to res, now we 
// move to next index and add that vowel and repeat the same process, thus we collect all substr with 5 uniq. vowels and return it end of iteration.







class Solution {
public:
    int countVowelSubstrings(string s) {
        int res=0, prev=-1, start=0, req=5;
        int occur[26];
        memset(occur, 0, sizeof(occur));
        for(int i=0;i<s.length();i++) {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
                if(occur[s[i]-'a']++==0) req--;								// As new uniq. vowel added, we dec. the req. vowel count.
                while(req==0 && occur[s[start]-'a']>1) {					// We move the interval start to right as long as 5 uniq. vowels in substrs exist.
                    occur[s[start]-'a']--;
                    start++;
                }
                if(req==0) res+=(start-prev);								// If 5 uniq. vowels exist, we count all substrs ending at 'i' that meets condition.
            } else{															// If non-vowel found, we rest all the values.
                prev=i;														// We store prev. non-vowel index, which is useful in #substrs calculation.
                start=i+1;
                req=5;
                memset(occur, 0, sizeof(occur));
            }
            // cout<<"i: "<<i<<" and res: "<<res<<endl;
        }
        
        return res;															// Returning total #substrs with 5 uniq. vowels.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Map+Sliding Window based. This process is almost same as the above one, except that rather than counting #substrs that exactly meets the condition like 
// above, we find #substrs with atmost 5 uniq. vowels and we substract #substrs with atmost 4 uniq. vowels resulting in #substrs with exactly 5 uniq. vowels.
// We keep adding chars to interval, once we observe #uniq. vowels>target, we move start of interval to right till #uniq. vowels becomes<=target, now we can use each index in
// this interval to start a substr and ending at curr. index which have <=target #uniq. vowels.








class Solution {
public:
    
    int vowelSubstrAtmostK(string&s, int target) {
        int res=0, start=0, req=0;
        int occur[26];
        memset(occur, 0, sizeof(occur));
        for(int i=0;i<s.length();i++) {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
                if(occur[s[i]-'a']++==0) req++;
                while(req>target) {											// If #uniq. vowels>target, we remove chars from the start of the interval.
                    if(--occur[s[start]-'a']==0) req--;						// If #occur. becomes=0, we dec. #uniq. vowels count.
                    start++;
                }
                res+=(i-start+1);											// Adding all the indices in the window which can be the start of substr and substr ending at 'i'.
            } else{															// If non-vowel encountered, we reset all values.
                start=i+1;
                req=0;
                memset(occur, 0, sizeof(occur));
            }
            // cout<<"i: "<<i<<" and res: "<<res<<endl;
        }
        return res;															// Returning total #substrs with atmost target #uniq. vowels.
    }
    
    int countVowelSubstrings(string s) {
        return vowelSubstrAtmostK(s, 5)-vowelSubstrAtmostK(s, 4);			// Returning total #substrs with 5 uniq. vowels.
        
    }
};

