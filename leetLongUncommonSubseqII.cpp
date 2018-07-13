/*
*
//**********************************************************522. Longest Uncommon Subsequence II.***************************************************

Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the 
longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining 
elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon 
subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



["aba","cdc","eae"]


["abacd","cdc","eade"]

["ab","cab","ac","ae","cab","cac"]


["abb","cabc","abb","abb","cabc","cabc","ab","z"]





// Time Complexity: O(n^2* Max. length of strings).  								
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2* Max. length of strings).								
// Space Complexity: O(1).	
// This algorithm is observation based. The basic concept is that a string with lesser length can't be total length subsequence formed by a 
// bigger length string. If we encounter a string which is not subsequence of strings with greater lengths than itself and not equal to the strings
// of same length(we can say not a subsequence of same length strings), then we can say that's the bigget uncommon subsequence in the question,
// if we start from iterating from greater to smaller lengths. A string being a subsequence to a greater length, means we can't form a uncommon 
// subsequence from this string, which the greater length string doesn't contain.








class Solution {
public:
    bool isSubsequence(string &s,string &t){								// Check str-"t" is subsequence of str-"s" or not?
        if(s==t) return true;												// If both are same, return true.
        int index=0;
        for(int i=0;i<s.length();i++){
            if(index<t.length() && s[i]==t[index]) index++;					// Whenever chars match, inc. the iterator.
        }
        if(index==t.length()) return true;									// If end of string is reached, then it's subsequence, return true.			
        return false;
    }
    
    int findLUSlength(vector<string>& v) {
        if(v.size()==0) return 0;
        int diff=0, maxm=0;
        sort(v.begin(), v.end(),[=](const string &a,const string&b){		// Sort the strings based on dec. lengths.
            return a.length()>b.length();
        });
        for(int i=0;i<v.size();i++){
            // cout<<"Start iteration at index: "<<i<<endl;
            int j;
            for(j=i+1;j<v.size();j++)                               		// Calc. the last string with same length.
                if(v[j].length()!=v[i].length()) break;
            
            for(int k=i;k<=j-1;k++){										// We iterate strings of same length.
                bool sub=false;
                for(int l=0;l<=j-1;l++){									// Iterate from start till end of strings with same length.
                    if(l==k) continue;
                    if(isSubsequence(v[l],v[k])) sub=true;					// If curr. string is subsequence of any strings.
                }
                if(sub==false) return v[i].length();						// If it's not a subseq of any prev. strings, then return it's length.
            }
            i=j-1;															// Updating the iterator to next smaller length.
        }
        return -1;															// If no uncommon subsequences found, return -1.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2* Max. length of strings).
// Space Complexity: O(1).	
// This algorithm is observation based. The basic concept is that a string with lesser length can't be total length subsequence formed by a 
// bigger length string. If we encounter a string which is not subsequence of strings with greater lengths than itself and not equal to the strings
// of same length(we can say not a subsequence of same length strings), then we can say that's the bigget uncommon subsequence in the question,
// if we start from iterating from greater to smaller lengths. A string being a subsequence to a greater length, means we can't form a uncommon 
// subsequence from this string, which the greater length string doesn't contain.



//This algo. is same as the above one, except that it's slightly optimized one(won't iterate to find the index of last string with same length as
// curr. string). Here, we direclty iterate all strings with lengths greater/equal to curr. string.





class Solution {
public:
    bool isSubsequence(string &s,string &t){
        if(s==t) return true;
        int index=0;
        for(int i=0;i<s.length();i++){
            if(index<t.length() && s[i]==t[index]) index++;
        }
        if(index==t.length()) return true;
        return false;
    }
    
    int findLUSlength(vector<string>& v) {
        if(v.size()==0) return 0;
        int diff=0, maxm=0;
        sort(v.begin(), v.end(),[=](const string &a,const string&b){
            return a.length()>b.length();
        });
        for(int i=0;i<v.size();i++){										// Iterating through the entire array.
            // cout<<"Start iteration at index: "<<i<<endl;
            bool sub=false;
            for(int l=0;l<v.size() && v[l].length()>=v[i].length();l++){	// Iterating all strings with greater/equal length to curr. string.
                if(l==i) continue;
                if(isSubsequence(v[l],v[i])) sub=true;
            }
            if(sub==false) return v[i].length();							// If it's not subseq of any prev. strings, then return it's length.				
        }
        return -1;															// If no uncommon subsequences found, return -1.
    }
};