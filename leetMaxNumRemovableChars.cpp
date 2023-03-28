/*
*
//******************************************************1898. Maximum Number of Removable Characters.******************************************************

https://leetcode.com/problems/maximum-number-of-removable-characters/





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abcacb"
"ab"
[3,1,0]
"abcbddddd"
"abcd"
[3,2,1,4,5,6]
"abcab"
"abc"
[0,1,2,3,4]
"abbccdeefee"
"defe"
[5,3,7,2,1]
"qlevcvgzfpryiqlwy"
"qlecfqlw"
[12,5]



// Time Complexity: O(n*logm).																			// m-#removable chars, n-#string 's'  length.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*logm).																			// m-#removable chars, n-#string 's'  length.
// Space Complexity: O(m).	
// This algorithm is Binary Search based. Here, as we are trying to find max. removable chars 'k', we do binary search on the #removable chars, as if p can't be subsequence of s for a k value of 'i',
// it can't be subsequence of 's' if >i chars are removed, this will only remove extra chars on top of first k removable chars, so the ability to be a subsequence is monotonic in nature, so Bin. 
// Search works. For every test 'k' value, we mark the removable indices with '*' char and store the corres. chars, we iter. and compare s and t strings and check if t is a subseq now. if it is,
// we store the curr. 'k' value and search in the right half for greater k value, else we search in the left half.







class Solution {
public:
    
    bool isSubsequence(string&s, string&t, vector<int>&v, int high) {
        int i=0,j=0;
        vector<char>u;
        for(int k=0;k<=high;k++) {																		// Marking the removed chars with '*' char.
            u.push_back(s[v[k]]);																		// Storing the removed chars to help in restoring the char values.
            s[v[k]]='*';
        }
        while(i<s.length() && j<t.length()) {															// Checking if 't' is subsequence of 's' string.
            if(s[i]!='*' && s[i]==t[j]) j++;
            i++;
        }
        
        for(int k=0;k<=high;k++) {																		// Restoring the string 's' to orig. form.
            s[v[k]]=u[k];
        }
        return (j==t.length());																			// Returning if 't' is a subseq. of 's'.
    }
    
    int maximumRemovals(string s, string p, vector<int>& v) {
        int low=0, high=v.size()-1;
        int ans=0;
        while(low<=high) {																				// Bin. Search to find the greatest possible removable chars length 'k'.
            int mid=(low+high)/2;
            if(isSubsequence(s, p, v, mid)) {															// If curr. 'k' works, we search in right half for greater 'k' value.
                low=mid+1;
                ans=low;																				// Storing curr. 'k' value.
            }
            else high=mid-1;																			// If curr. 'k' doesn't work, we search in lower half.
        }
        return ans;																						// Returning the maxm. 'k' value.
    }
};

