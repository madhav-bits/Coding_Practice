/*
*
//****************************************2023. Number of Pairs of Strings With Concatenation Equal to Target.****************************************

https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["777","7","77","77"]
"7777"
["1","1","1"]
"11"
["123","4","12","34"]
"1234"
["123","3123","12","123","3123"]
"123123"



// Time Complexity: O(n!).  
// Space Complexity: O(n*n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*l).													// n-#strings provided, l-avg. length of the string.
// Space Complexity: O(1).	
// This algorithm is Map based. Here, at every step we check if the curr. str can be the first/second part of the concat operation. If it can be first part, 
// we add the occur. of all prev. strs which can be second/rem part which on concat would result in target string. We do the same thing for curr. str being 
// second part too. We return the total #concat pairs at the end of iter.







class Solution {
public:
    int numOfPairs(vector<string>& v, string s) {
        vector<int>prefix(s.length(),0), suffix(s.length(), 0);
        int res=0;
        for(int i=0;i<v.size();i++) {
            if(v[i].length()>=s.length()) continue;
            int start=s.length()-v[i].length(), currLen=v[i].length();
            bool isSuffix=false;
            if(s.substr(start)==v[i]) {										// If the curr. string can be second part of the concat. oper.
                res+=prefix[start-1];										// We add all prev. strs which can be first part to res.
                isSuffix=true;
                // cout<<"inc. suffix at index: "<<start<<endl;
            }
            if(s.substr(0,currLen)==v[i]) {									// If the curr. string can be first part of concat oper.
                res+=suffix[currLen];										// We add all prev. strs which can be second part of res.
                prefix[currLen-1]++;										// Adding the curr. string can be first part/prefix of concat.
                // cout<<"Inc. prefix at index: "<<currLen-1<<endl;
            }
            if(isSuffix) suffix[start]++; 									// Adding the curr. string can be second part/suffix of concat.
        }
        return res;															// Returning the total #pairs which forms target str on concat.
    }
};













//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Map based. While we concat since the psn/order of strings in orig. array doesn't matter. We count #occur. of each string <target length 
// in map. We iter. over these strings, if curr. str can be first part/prefix of concat, we mult. it's occur. with occur. of rem. part/suffix of concat which
// forms target string and add result to res. If prefix==suffix, picking any two of them and concat would lead to target string, we use np2.










class Solution {
public:
    int numOfPairs(vector<string>& v, string s) {
        int res=0;
        unordered_map<string,int>m;
        for(string&str: v) {
            if(str.length()<s.length()) m[str]++;							// Tracking #occur. of each string.
        }
        
        for(auto pr:m) {
            bool isPrefix=(pr.first==s.substr(0, pr.first.length()));		// Tracking that curr. str can be first part/prefix of concat. 
            string rem=s.substr(pr.first.length());
            if(isPrefix && m.count(rem)==1) {								// If the rem. part of target str is present in map.
                if(pr.first==rem) res+=pr.second*(pr.second-1);				// If prefix==suffix, we use np2 and concat them.
                else res+=pr.second*m[rem];									// We mult. occur. of each of the parts and add it to res.
            }
        }
        return res;															// Returning the total #pairs which forms target str on concat.
    }
};

