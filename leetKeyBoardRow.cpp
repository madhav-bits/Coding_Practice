/*
*
//**************************************************************500. Keyboard Row.*******************************************************

Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["Hello","Alaska","Dadgn","s"]

["Hello","Alaska","Dadgn",""]

["Hello","Alaska","Dad","s"]


["Hello","zAlaska","Dadgn","s"]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is HashMap based. We maintain all chars in a HashMap with chars as keys and their row numbers as values. We iterate through
// all strings, if we find that any char. is from other row than that of else chars, we simply don't push into final result vec. If issue
// doesn't arises and the iterator reaches till words[i].length()-1, then push str into final result vector. We compare the curr. char's line num
// with next char's line num, so we iterate till length-1.






class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        map<char, int> m;													// Stores all chars and their line numbers.
        m['q']=1;m['w']=1;m['e']=1;m['r']=1;m['t']=1;m['y']=1;m['u']=1;m['i']=1;m['o']=1;m['p']=1;
        m['a']=2;m['s']=2;m['d']=2;m['f']=2;m['g']=2;m['h']=2;m['j']=2;m['k']=2;m['l']=2;
        m['z']=3;m['x']=3;m['c']=3;m['v']=3;m['b']=3;m['n']=3;m['m']=3;
        for(int i=0;i<words.size();i++){
            //cout<<"Starting scanning word: "<<words[i]<<endl;
            if(words[i].length()<1) res.push_back(words[i]);				// If empty string is given, push it into final result vector.
            int j=0;
            for(j=0;j<words[i].length()-1;j++){								// Iterates till last but one char.
                //cout<<"Curr. scanning word: "<<words[i][j]<<endl;
                if(m[words[i][j]<=90?words[i][j]+32:words[i][j]]!=m[words[i][j+1]<=90?words[i][j+1]+32:words[i][j+1]]) break;
            }																// We comapre curr. char's line num. with next char's line num.
            if(j==words[i].length()-1) res.push_back(words[i]);				// If iterator reached last but one index, push into final result vec.
        }
        return res;															// Return the final result vec.
    }
};