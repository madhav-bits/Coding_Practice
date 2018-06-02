/*
*
//**********************************************************383. Ransom Note.***************************************************

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true 
if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abcccc"
"abdcecccc"


""
"ab"

""
""

"ab"
"abc"




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is HashMap based. In this algo. we first iterate the note and save all chars #occurances. We then iterate magazine, if we encoun.
// chars which are present in note, we dec. it's count, if that char's count get to 0, we delete that key. The instant we have empty map, return
// true, if after entire iteration, the map is not empty, return false.








class Solution {
public:
    bool canConstruct(string note, string mag) {
        if(note.length()==0 && mag.length()==0) return true;
        if(mag.length()<note.length()) return false;
        bool res;
        map<char,int>m;
        for(auto ch:note) m[ch]++;																// Counting #occur. of chars in note.
        for(int i=0;i<mag.size();i++){															// Iterating through the magazine.
            if(m.count(mag[i])==1){																// If char. pres. in note, dec. count.
                m[mag[i]]--;
                if(m[mag[i]]==0) m.erase(mag[i]);											// If #occur. matches, then remove that ch. from map.
            }
            if(m.empty()) return true;															// If all chars from note found in mag., ret. true.
        }
        return false;																			// If all chars. still not found, ret. false.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is HashMap based. In this algo. we first iterate the mag and save all chars #occurances. We then iterate note, if we encoun.
// chars which are present in note, we dec. it's count. If we encoun. a char. with count==0, then return false.
// (As #occur. of that char in mag.<#occ in note). If after entire iteration, we don't encounter any neg. count case, then we return true.


class Solution {
public:
    bool canConstruct(string note, string mag) {
        if(note.length()==0 && mag.length()==0) return true;
        if(mag.length()<note.length()) return false;
        vector<int>v(26,0);
        for(auto ch:mag) v[ch-'a']++;											// Counting #occur. of chars in mag.
        for(int i=0;i<note.length();i++){
            if(v[note[i]-'a']<=0) return false;									// If #occur. of char in note>#occur. in mag. return false.
            v[note[i]-'a']--;													// Dec. the count for the chars in note.
        }
        return true;
    }
};





// ******************************************This is slightly improvised version of Algo. 2, #iterations wise.***********************************



class Solution {
public:
    bool canConstruct(string note, string mag) {
        if(note.length()==0 && mag.length()==0) return true;
        if(mag.length()<note.length()) return false;
        vector<int>u,v(26,0);
        for(auto ch:mag) v[ch-'a']++;
        for(auto ch:note)v[ch-'a']--;
        for(int i=0;i<26;i++){
            if(v[i]<0) return false;
        }
        return true;
    }
};