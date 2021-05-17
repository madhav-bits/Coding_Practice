/*
*
//******************************************************1859. Sorting the Sentence.***********************************************

https://leetcode.com/problems/sorting-the-sentence/



A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase 
English letters.

A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

 

Example 1:

Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
Example 2:

Input: s = "Myself2 Me1 I4 and3"
Output: "Me Myself and I"
Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.
 

Constraints:

2 <= s.length <= 200
s consists of lowercase and uppercase English letters, spaces, and digits from 1 to 9.
The number of words in s is between 1 and 9.
The words in s are separated by a single space.
s contains no leading or trailing spaces.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"is2 sentence4 This1 a3"
"Myself2 Me1 I4 and3"
"This1"
"This1 is4 another2 sentence3"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. Store the words in the temp. array and append those words at the end and return the sentence.






class Solution {
public:
    string sortSentence(string s) {
        vector<string>v(10,"");
        string res="";
        string temp="";
        for(char &ch:s){
            if(ch==' '){
                int index=temp.back()-'1';
                v[index]=temp.substr(0,temp.length()-1);
                temp="";
            }else temp+=ch;
        }
        int index=temp.back()-'1';
        v[index]=temp.substr(0,temp.length()-1);
        
        for(int i=0;i<10 && v[i]!="";i++){
            res+=v[i]+" ";
        }
        res.pop_back();
        return res;
    }
};

