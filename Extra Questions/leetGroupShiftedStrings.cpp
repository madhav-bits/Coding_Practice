/*
*
//**********************************************************249. Group Shifted Strings.***************************************************

Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms 
the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output: 
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["abc","bcd","acef","xyz","az","ba","a","z","dcf","cbe"]

["abc","bcd","acef","xyz","az","ba","a","z","dcf","cbe",""]





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is observation based. As,we need to segregate strings which have same pattern of chars. We calc. the diff b/w the adj. chars in 
// the string seperated by "#" and use them as key in map. We iterate the array once, in it we calc. the diff b/w chars of string and check 
// whether the diff. string exists in map, if not we create a new key and add inc. the result str length by one. Thus, at the end we get the 
// strings in seggregated way.








class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& v) {
       unordered_map<string,int>m;											// Has diff b/w chars as key, useful in seggregating strings.
        vector<vector<string>>res;											// Final result string.
        for(int i=0;i<v.size();i++){
            string str="";													// Diff string init.
            for(int j=0;j<v[i].length()-1;j++){								// Calc. diff string for a given string.
                int diff=v[i][j]-v[i][j+1];	
                if(diff<0) diff+=26;
                str+=to_string(diff)+"#";									// Add # to separate two diff ints of string.
            }
            if(m.count(str)==0){											// If this diff. string doesn't exist in map, then create one.
                m[str]=res.size();											// Store the index to place strs with same diff str in result vector.
                res.push_back({});											// Init. a empty array in that index.
            }
            res[m[str]].push_back(v[i]);									// Place the str in the corresponding index in final result vetor.
        }
            
        return res;															// Returning the final result vector.
    }
};