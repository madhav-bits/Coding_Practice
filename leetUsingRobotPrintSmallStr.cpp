/*
*
//******************************************************2434. Using a Robot to Print the Lexicographically Smallest String.******************************************************

https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"zza"
"bac"
"bdda"
"aslekaojgadfgjadfg"
"bca"
"cba"
"dbajlerglajgajrogidflg"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is observation+Greedy based. Here, as we are trying to form lexically smallest string. We store the occur. of each alphabet in an array. Where non-zero values presence of chars.
// We use a ptr to iter over this array and we stay at the least index with non-zero value in it(smallest char yet to be iterated in orig. string), when at an index on orig. string, we pop all 
// smaller chars from stack onto res. Chars in stack indicates those which are iterated but are greater than the smallest yet to be iterated, as we forming lexically smallest, we still can't use 
// these chars, so we add these chars to stack or t string. Now, if the curr. char is the smallest char yet, we add it directly to res else we add it to stack, we dec. the occur. of this char in 
// occur. array as this has been already iterated. Thus at every step we greedily pick chars from stack or curr. index and ensure we append smallest chars to res. At the end of iter. we pop rem.
// chars in stack to res.







class Solution {
public:
    string robotWithString(string s) {
        string res="";
        vector<int>occur(26,0);
        int j=26;
        for(char&ch:s) {																				// Tracks the #occur. of each char in orig. string.
            if(ch-'a'<j) j=ch-'a';																		// Tracks the smallest char.
            occur[ch-'a']++;
        }
        int ind=0;																						// Tracks the smallest char in orig. string yet to be iterated.
        stack<char>st;																					// The temp. string 't'.
        for(int i=0;i<s.length();i++) {
            while(!st.empty() && (st.top()-'a')<=ind) {													// Prev. visited chars which are smaller than the smallest yet to be iterated.
                res+=st.top();																			// Adding these smaller chars to res.
                st.pop();
            }
            if((s[i]-'a')==ind) res+=s[i];																// If curr. char is the smallest char yet to be iter., we add to res.
            else st.push(s[i]);																			// Else we add to stack/'t' string.
            occur[s[i]-'a']--;																			// Dec. the freq/count of chars in occur array.
            while(ind<26 && occur[ind]==0) ind++;														// Moving to next smallest char.
        }
        while(!st.empty()) {																			// Popping rem. chars from stack onto res.
            res+=st.top();
            st.pop();
        }
        return res;																						// Returning the lexically smallest string possible.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// This is slight modified/optimized version of the above algo.











class Solution {
public:
    string robotWithString(string s) {
        string res="";
        vector<char>minChar(s.length());																// Stores the minChar in [i, s.length()-1] indices range in index 'i'.
        minChar.back()=s.back();
        for(int i=s.length()-2;i>=0;i--) {
            if(s[i]<minChar[i+1]) minChar[i]=s[i];														// Populating with the minChar from curr. index to the last index.
            else minChar[i]=minChar[i+1];
        }
        string t="";
        for(int i=0;i<s.length();i++) {
            while(t.size()>0 && t.back()<=minChar[i]) {
                res+=t.back();
                t.pop_back();
            }
            t.push_back(s[i]);																	// As curr. char woudld be >=minChar[i], we can safely add it to 't' as it gets processed in next iter.
        }
        
        while(!t.empty()) {
            res+=t.back();
            t.pop_back();
        }
        return res;
    }
};