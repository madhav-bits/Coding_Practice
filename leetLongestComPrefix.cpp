/*
*
//******************************************************14. Longest Common Prefix.***********************************************

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["flower", "flowera", "floscence"]
["flower"]
[]
[""]
["flow","float", "floroscence"]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based, we take the first string as Common prefix and iterate the entire array to get te longest common prefix(LCP)
// At each step, we extract only that part of LCP, which has same common prefix to the curr. iterator string. As, LCP of the vector has to be 
// common to all the strings in the vector. 




class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string res="";
        if(v.size()==0) return res;
        if(v.size()==1) return v[0];
        res=v[0];																			// Taking the first string as default LCP.
        for(int i=1;i<v.size();i++){														// Iterating through the entire vector.
            int ind=0;
            while(ind<res.length()){														// Iter. unitl they have common prefix.
                if(res[ind]!=v[i][ind]) break;
                ind++;
            }
            res=res.substr(0,ind);															// Extracting only the prefix common to curr. string.
            //cout<<"Res after index i: "<<i<<" is: "<<res<<endl;
        }
        //cout<<"The result is: "<<res<<endl;
        return res;																			// Returning the LCP to the entire vector of strings.
    }
};