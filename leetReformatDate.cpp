/*
*
//******************************************************1507. Reformat Date.***********************************************************

https://leetcode.com/problems/reformat-date/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"20th Oct 2052"
"2nd Dec 2052"
"6th Jun 1933"
"26th May 1960"



// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(n).	

//***************************************************THIS IS LEET ACCEPTED CODE.*******************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(n).	
// This algorithm is iteration based. We use stringstream to extract words from the string and them add them onto the final string
// satisfying given requirements.






class Solution {
public:
    string reformatDate(string date) {
        stringstream ss(date);
        string res="", word="";
        ss>>word;															// Extracting the day from the date.
        word=word.substr(0,word.length()-2);
        if(word.length()==1) word="0"+word;
        res="-"+word;
        unordered_map<string,string>m;
        m["Jan"]="01";m["Feb"]="02"; m["Mar"]="03"; m["Apr"]="04"; m["May"]="05";m["Jun"]="06";
        m["Jul"]="07";m["Aug"]="08";m["Sep"]="09";m["Oct"]="10";m["Nov"]="11";m["Dec"]="12";
        ss>>word;res="-"+m[word]+res;										// Extracting the month from the date.
        ss>>word;															// Extracting the year from the date.
        res=word+res;
        return res;															// Returning the formatted date.
    }
};