/*
*
//**********************************************************28. Implement strStr().***************************************************

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"ababbbbaaabbbaaa"
"bbbb"


"aabaabbbaabbbbabaaab"
"abaa"


"mississippi"
"issipi"



// Time Complexity: O(nm).  
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nm).
// Space Complexity: O(m).	
// This algorithm is Boyes Moore Algo. In case of mismatch it skips unnecc. by making jumps considering the distance of last char. in similar psn
// in str to curr. target string. If the last char is not in target string, we make skips evading comparing it entirely.




class Solution {
public:
    int strStr(string str, string target) {
        if(target.length()==0) return 0;
        map<string, int> m;														// Links char. in target to it's distance from end of target string
        for(int i=0;i<target.length()-1;i++){									// Preprocess by storing the dist of each char to it's end.
            m[target.substr(i,1)]=target.length()-1-i;
            //cout<<"Updating map value of: "<<target.substr(i,1)<<" is: "<<target.length()-1-i<<endl;
        }
        if(m.count(target.substr(target.length()-1,1))==0) m[target.substr(target.length()-1,1)]=target.length();//Last char is alloted leng. val
        int j=target.length()-1;
        while(j<str.length()){													//Checks for matching b/w two strings.
            //cout<<"Starting while with j: "<<j<<endl;
            int k=0;
            while(k<target.length() && str[j-k]==target[target.length()-1-k]){	// Iterate as long as they are matching.
                //cout<<"Curr. k: "<<k<<endl;
                k++;
            }
            if(k!=target.length()){											// Then shift as many as to try to include last char. of curr. target
                //cout<<"Updating j to: using char: "<<str.substr(j,1)<<endl;
                if(m.count(str.substr(j,1))==1) j+=m[str.substr(j,1)];		// If last char is in target, then shift accordingly.
                else j+=target.length();									// If last char is not in target, then move over it.
                
            }
            else															// If entirely matched, return string.
                return j-k+1;
        }
		
        // int j=0;
        // while(j+target.length()<=str.length()){								// This is other implementation of above while loop.
        //     int k=target.length()-1;
        //     while(target[k]==str[j+k]){
        //         if(k==0) return j;
        //         k--;
        //     }
        //     if(m.count(str.substr(j+target.length()-1,1))==1) j+=m[str.substr(j+target.length()-1,1)];
        //     else j+=target.length();
        // }
        return -1;
    }
};