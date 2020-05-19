/*
*
//**************************************************1451. Rearrange Words in a Sentence.*******************************************

Given a sentence text (A sentence is a string of space-separated words) in the following format:

First letter is in upper case.
Each word in text are separated by a single space.
Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two 
words have the same length, arrange them in their original order.

Return the new text following the format shown above.

 

Example 1:

Input: text = "Leetcode is cool"
Output: "Is cool leetcode"
Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
Output is ordered by length and the new first word starts with capital letter.
Example 2:

Input: text = "Keep calm and code on"
Output: "On and keep calm code"
Explanation: Output is ordered as follows:
"On" 2 letters.
"and" 3 letters.
"keep" 4 letters in case of tie order by position in original text.
"calm" 4 letters.
"code" 4 letters.
Example 3:

Input: text = "To be or not to be"
Output: "To be or to be not"
 

Constraints:

text begins with a capital letter and then contains lowercase letters and single space between words.
1 <= text.length <= 10^5





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"Leetcode is cool"

"A adf adsfe a fadf ade aefasd ade"



// Time Complexity: O(nlogn).												// n- number of chars in the array.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n- number of chars in the array.
// Space Complexity: O(n).	
// This algorithm is Custom Sorting based. Here, we extracted words and stored in another array. As, we are trying to sort words based
// on number of chars in them and place them in their if number of chars are same. We store the extracted words and the word's psn
// in a pair form in a new array. We sort this according to req. format, we used lambda notation to describe our requirement. After
// sorting, we iter. over auxilary array, we append all these words to form a new sentence and return it.




class Solution {
public:
    string arrangeWords(string s) {
        if(s.length()==1) return s;
        string text=s;
        vector<pair<string,int>>v;											// Stores extracted words and their psn in sentence.
        int wordIndex=0;													// Assigns psn to each of extracted word.
        string temp="";														// Used to extract words from sentence.
        text[0]+=32;														// Lower casing first char.
        for(auto ch:text){	
            if(ch==' '){													// Encountered delimiting ' ' char.
                if(temp.length()>0) v.push_back({temp, wordIndex});			// Storing the word and index in auxilary array.
                wordIndex++;
                temp="";													// Init. the temp word var.
            }else temp+=ch;
        }
        if(temp.length()>0) v.push_back({temp,wordIndex});					// Storing the last word.
        if(wordIndex==0) return s;											// If there is only one word in sentence.
        sort(v.begin(), v.end(),[](pair<string,int>lt, pair<string,int>rt){	// Sort acc. to problem's requirement.
           return (lt.first.length()<rt.first.length()) || (lt.first.length()==rt.first.length() && lt.second<rt.second);
        });
        string res="";
        for(auto pr:v){														// Iter. over sorted array.
            res+=pr.first+" ";												// Appending words to form new sentence.
        }
        res[0]-=32;															// Upper casing first char.
        res.pop_back();														// Removing lastly attached " ".
        return res;															// Returning newly formed sorted sentence.
    }
};