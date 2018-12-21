/*
*
//**************************************************************Repeating Sub-Sequence.*******************************************************

https://www.interviewbit.com/problems/repeating-subsequence/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



aab


abba


bba


abb


aaa


abab


// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is HashMap based. Here, we need 2 subsequences where indices of corresponding chars from subsequences in the original string 
// shouldn't match. We build substrings of length 2 and store them in map, we also count the #occurances of chars. The substrings might be 
// comprised of same chars, then the count of chars have to be atleast 3 for the subsequences's chars's index to not match. In case of different
// chars, the count of each char has to be 2 for the subsequence indices to be different. If such subsequences are found, then return true else
// return false.








int Solution::anytwo(string s) {
    int res=0;
    unordered_map<string,int>occur;											// Keeps track of encountered subsequences.
    unordered_map<char,int>rep;												// Keeps track of #occurances of each char.
    for(int i=s.length();i>=0;i--){											// Iter. for subsequences starting from curr. index.
        rep[s[i]]++;														// Inc. the count of curr. char.
        string temp="";														// Used to form the substr of length 2.
        temp+=s[i];
        //vector<string>v;
        for(int j=s.length()-1;j>i;j--){									// Iter. through all possibilities for second char in subseq.
            temp+=s[j];
            if(occur.count(temp)==1 && s[j]!=s[i] && rep[s[i]]>=2 && rep[s[j]]>=2) return true;// For subseq of diff. chars.
            if(s[i]==s[j] && rep[s[i]]>=3) return true;						// For subseq of same chars.
            //v.push_back(temp);
			occur[temp]++;													// Noting down occurance of subsequence.
            temp.pop_back();
        }
        //for(auto str:v) occur[str]++;
    }
    
    return false;															// If such subsequences are not found, return false.
}
