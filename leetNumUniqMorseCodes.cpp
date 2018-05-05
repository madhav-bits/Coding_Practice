/*
*
//******************************************************804. Unique Morse Code Words.***********************************************

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps 
to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--",
"-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written 
as "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
 

Note:

The length of words will be at most 100.
Each words[i] will have length in range [1, 12].
words[i] will only consist of lowercase letters.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["sfs","ssf","fss"]
[]
["ab","cd"]



// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	



class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& w) {
        vector<vector<string>> v(26);											//This data structure is not used.
        string morse[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string, int> m;														// Stores #Unique Morse Codes.
        for(int i=0;i<w.size();i++){
            string t="";
            for(int j=0;j<w[i].length();j++){									//Extracting the morse code corres. to char in string.
                t+=morse[w[i][j]-'a'];
            }
            m[t]++;																// Inc. the count of occur. of a Morse Code string formed.
            //cout<<"Formed string is: "<<t<<endl;
        }
        //cout<<"The answer is: "<<m.size()<<endl;
        
        return m.size();														// Returning the num. of Unique Morse Codes.
    }
};