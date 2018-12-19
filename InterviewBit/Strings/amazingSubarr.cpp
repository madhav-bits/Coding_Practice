/*
*
//***************************************************************Amazing Subarrays.*********************************************************

https://www.interviewbit.com/problems/amazing-subarrays/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


ABCEfafaieoaefaeofaej


jrlqlla



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is HashMap/iteration based. Here, we iterate over entire string, as we need substrings starting with vowels, we track them
// by using vector, if we find vowel at index-'i', we can get string length-i number of substrings starting from that index, we add all #occur 
// and mod them by 10003 and return the #occurances.








int Solution::solve(string s) {
    long int res=0;															// Tracks total #substrings.
    vector<bool>vowel(57,false);											// Used to track vowels occurances.
    vowel['A'-'A']=true;vowel['E'-'A']=true;								// Marking the vowel indices.
    vowel['I'-'A']=true;vowel['O'-'A']=true;
    vowel['U'-'A']=true;vowel['a'-'A']=true;
    vowel['e'-'A']=true;vowel['i'-'A']=true;
    vowel['o'-'A']=true;vowel['u'-'A']=true;
    for(int i=0;i<s.length();i++){											// Iterating over string.
        if(vowel[s[i]-'A']==true){											// If curr. char in vowel.
            long int comb=s.length()-i;										// Extracting #substrings starting from this index.
            // cout<<"comb: "<<comb<<endl;
            res=(res+comb)%10003;											// Adding those substrings to final count.
        }
    }
    return res;																// Returning the final result.
}
