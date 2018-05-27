/*
*
//**********************************************************76. Minimum Window Substring.***************************************************

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"ADOBECNDEBAXYZNC"
"ABC"


"ADOBECNDEBAXYZNC"
"ABCK"





// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window based. We first store the count of chars of target string in map. We iterate the given string. When a char from
// target string is enocuntered, we dec. req. no. of chars count. We expand to the right, and let go of elem. at the back iff despite remov. those
// beginning of window chars, we still can maintain the presence of all req. chars in the window.
 








class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()==0) return s.substr(0,1);									// Base case.
        int start=0, close=0;
        int minS=0, minE=INT_MAX;												// Start and end index of Window.
        map<char, int>m;														// Stores all req. chars.
        int count=0, dist=t.length();											// Req. no.of chars.
        for(auto str:t) m[str]++;												// Count the occurance of all req. chars.
        for(int i=0;i<s.length();i++){
            //cout<<" Start of iteration i: "<<i<<" and char: "<<s[i]<<endl;
            if( m.count(s[i])==1){//extra.count(s[i])==0 &&
                if(m[s[i]]>0) dist--;											// If a req. char has occured, dec. req. #chars count.
                m[s[i]]--;														// Dec. individual count of each req. char.
            }
            close++;															// Moving the close index ahead by a step.
            
            while((m.count(s[start])==0 || ( m.count(s[start])==1 && m[s[start]]<0)) && start<close){
                if(m.count(s[start])==1){										// Inc. the count of occurances of req. chars.
                    //cout<<"Removing extra chars."<<endl;
                    m[s[start]]++;
                }
                start++;														// Moving the start index forward by a step.
            }
            
            
            //cout<<"m size is: "<<m.size()<<" and extra size is: "<<extra.size()<<endl;
            if(dist==0){														// Del. chars from window, iff req. #chars are maintain. to 0.
                //cout<<"All chars are found."<<endl;
                if(close-start<minE-minS){										// Updating least len. window begin& end.
                    minS=start; minE=close;  
                }
                
            }
            
            //cout<<"End of iteration with start: "<<start<<" and close is: "<<close<<endl;
            
        }
        
        //cout<<"start is: "<<minS<<" and close is: "<<minE<<endl;
        if(minE==INT_MAX) return "";											// If no such substr with all req. chars is found.
        return s.substr(minS, minE-minS);										// Returning the min. length substring with all req. chars.
        
    }
};