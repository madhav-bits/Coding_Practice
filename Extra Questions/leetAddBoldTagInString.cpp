/*
*
//******************************************************616. Add Bold Tag in String.***********************************************

Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist 
in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped 
by bold tags are consecutive, you need to combine them.
Example 1:
Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
Example 2:
Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abcxyz123"
["abc","123"]



"aaabbcc"
["aaa","aab","bc"]



"aaabbcc"
[]



// Time Complexity: O((m^2)*n).  
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((m^2)*n).												// m-length of given text, n-avg. length of substr provided.
// Space Complexity: O(m).	
// This algorithm is substring searching based. Here, we had used find function in string library or default linear search implementation. 
// Sinc, we need to merge overlapping and connecting matching substrings in given text. We take a bool array and mark all indices which are
// part of substring matches. Then, later we iter. over bool array and attach <b> and </b> at start and close of matching indices sequence.
// We return the newly formed result string.








class Solution {
public:
    string addBoldTag(string text, vector<string>& words) {
        vector<bool>color(text.length(), false);
        
        
        // unordered_set<string>st;											// Another way of doing it.
        // int maxLen=0;
        // for(int i=0;i<words.size();i++){
        //     maxLen=max(maxLen, (int)words[i].length());
        //     st.insert(words[i]);
        // }
        // for(int i=0;i<text.length();i++){
        //     for(int len=1;len<=maxLen && i+len<=text.length();len++){
        //         // if(i==10) cout<<"THe substr: "<<text.substr(i,len)<<endl;
        //         if(st.count(text.substr(i,len))==1){						// If curr. substr is part of words, mark these indices.
        //             for(int j=i;j<i+len;j++) color[j]=true;
        //         }
        //     }
        // }
        
        
        for(auto word:words){												// Finding matches using find function.
            int idx=text.find(word);
            while(idx!=string::npos){										// If a matching substr if found.
                for(int i=0;i<word.size();i++) color[idx+i]=true;			// Mark those indices to be true.
                idx=text.find(word,idx+1);
            }
        }
        
        string res="";														// Final result string.
        int index=0;
        // for(auto val: color) cout<<val<<" ";
        while(index<text.length()){											// Iter. over all indices.
            if(color[index]){												// If curr. index is part of substr matching sequence.
                if(index==0 || color[index-1]==false) res+="<b>";			// If this is first index of sequence.
            }
            if(color[index]==false){										// If curr. index isn't part of matching sequence.
                if(index>0 && color[index-1]==true) res+="</b>";			// If prev. index is matching index.
            }
            res+=text[index];												// Append curr. char to final result string.
            index++;
        }
        if(color.back()==true) res+="</b>";									// If last char is part of matching sequence.
        return res;															// Return the final result string.
    }
};


