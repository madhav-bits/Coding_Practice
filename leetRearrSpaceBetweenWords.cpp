/*
*
//*****************************************1592. Rearrange Spaces Between Words.*******************************************

https://leetcode.com/problems/rearrange-spaces-between-words/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"  this   is  a sentence "
"  walks  udp package   into  bar a"
"   aaaaaa" 
"   a     "
"hello   world"
" practice   makes   perfect"
"  this   is  a sentence "
"a"




// Time Complexity: O(n).  													// n- length of the array.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(n).	
// This algorithm is iteration based. We store all the words in an vector and store the #space bars. We use gaps/#words-1 
// to get gap after each word. Remaining spaces are calc. by gaps%#words-1. 





class Solution {
public:
    string reorderSpaces(string text) {
        vector<string>v;													// Stores words from text.
        string temp="";
        int gaps=0;															// Stores #space bars encountered.
        for(auto ch: text){													// Iter. over given string.
            if(ch==' '){
                if(temp!="") v.push_back(temp);								//  Storing the words from text.
                temp="";
                gaps++;														// Counting the gaps.
            }
            if(ch!=' ') temp+=ch;
        }
        // cout<<"gaps: "<<gaps<<endl;
        if(temp!="") v.push_back(temp);										// Storing the last non-empty word.
        int gap=gaps;
        if(v.size()!=1) gap=gaps/(v.size()-1);								// Calc. gap value after each word.
        string res="";
        for(int i=0;i<v.size();i++){										// Appending words, gap into result str.
            res+=v[i];
            if(v.size()==1 || i<v.size()-1) res+=string(gap,' ');
        }
        // cout<<"extra gap: "<<gaps%(v.size()-1)<<endl;
        if(v.size()>1 && gaps%(v.size()-1)!=0) res+=string(gaps%(v.size()-1),' ');	// Adding gap after last word(At end).
        return res;															// Returning the string with rearranged spaces.
    }
};