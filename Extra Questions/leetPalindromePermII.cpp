/*
*
//**********************************************************267. Palindrome Permutation II.***************************************************

Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could 
be form.

Example 1:

Input: "aabb"
Output: ["abba", "baab"]
Example 2:

Input: "abc"
Output: []




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aabbedcdc"

"aaaaaabcddbc"


"aabbccdde"

"a"

"aaa"

"aaaa"

""


// Time Complexity: O(n!).  
// Space Complexity: O(n*n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).
// Space Complexity: O(n*n!).	
// This algorithm is Backtracking based. We first count #occurances of various chars in given str. If we have >1 odd numbered chars, then return
// false. If not, we call fn. to extract all possible palindromic strings. We iter. through all chars, at each char, we assign curr. char at 
// index, s.length()-1-index psns, we give recursive call to assign values at index+1, s.length()-1-1-index-1. We dec. the char count by 2, and
// pass it to recursive call. We might have only 1 char of a type, we had saved it in the iter. prior to calling recursive fn. We might have
// odd numbers chars, for which #chars dec. to 1, upon dec. to 1, we update ch var to this char and pass it to fn. In the terminating cdn, by 
// the time we reach s.length()/2, we will have char updated, in even length strings, we don't have this issue with last char, just simply, if the 
// moved past s.length()/2, then push str into result vector and return.








class Solution {
public:
    vector<string>res;
    
    void findCombi(vector<int>&v, string&s,int index,char &ch){
        if(s.length()%2==1 && index==s.length()/2 && ch!=NULL){				// Terminating cdn for odd lengthed str, with valid char var.
            // cout<<"Reached end for odd len"<<endl;
            s[index]=ch;													// Assing mid index, the stored char value.
            res.push_back(s);												// Push str into final result vector.
            s[index]=NULL;													// Revert back to orid. value for following recur. calls.
            return ;
        }
        if(s.length()%2==0 && index>=(s.length()/2)){						// Terminating cdn for even lengthed str.
            // cout<<"Reached end for even len"<<endl;	
            res.push_back(s);												// Push the str. to final result vector.
            return ;
        }
        
        for(int i=0;i<v.size();i++){
            if(v[i]>=2){													// If we have >=2 count for curr. char.
                s[index]=i+NULL;											// Updating the final str at that index.
                s[s.length()-1-index]=i+NULL;								// Updating the final at index symmetrical to curr. index.
                v[i]-=2;													// Dec. the count by 2.
                if(v[i]==1) ch=i+NULL;										// If new count is 1, updating char var.
                // cout<<"call from inner cdn. with v[i]: "<<v[i]<<"with char: "<<ch<<endl;	
                findCombi(v,s,index+1,ch);									// Calling fn. recursively.
                v[i]+=2;													// Reverting to orig.count to accomodate further recursive calls.
                s[index]=NULL;												// Reverting back to orig. char values.
                s[s.length()-1-index]=NULL;									// Reverting back to orig. char values.
                if(v[i]==1) ch=NULL;										// Reverting back to orig. char values.
            }
                
                
            
        }
        return ;
    }
    
    vector<string> generatePalindromes(string s) {
        vector<int>occur(128,0);											// As, we work on ASCII chars set, tracks #occurances of all chars.
        for(auto ch:s) occur[ch-NULL]++;									// Storing count of all chars in given str.
        int count=0;														// Tracks #odd numbered chars.
        char ch=NULL;														// Stores odd numbered char.
        for(int i=0;i<128;i++){												// Iter. through count of all chars.
            if(occur[i]%2==1){												// IF odd numbered count encountered.
                if(occur[i]==1)												// If only single numbered char.
                    ch=i+NULL;												// Store the char.
                count++;													// Inc. the count.
            } 
        }
        
        if(count>1) return res;											// If odd numbered chars>1, we can't form palindromic str return empty vec.
        string start(s.length(),NULL);									// Init. the final str.
        findCombi(occur,start,0,ch);									// Calling. fn. to extract all possible combi. of palindromic str.	
        return res;														// Returning the final result vector.
    }
};