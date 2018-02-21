/*
*
//******************************************************748. Shortest Completing Word.***********************************************

Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. Such a word is said to 
complete the given string licensePlate

Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", the word "pair" does not 
complete the licensePlate, but the word "supper" does.

Example 1:
Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
Output: "steps"
Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
Example 2:
Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
Output: "pest"
Explanation: There are 3 smallest length words that contains the letters "s".
We return the one that occurred first.
Note:
licensePlate will be a string with length in range [1, 7].
licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
words will have a length in the range [10, 1000].
Every words[i] will consist of lowercase letters, and have length in range [1, 15].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"1s3 Psst"											//Various combinations of Capital and Small Alphabets.
["strippesS","stepsS","step","stepple"]


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(1).	
// This algorithm iterates the array, we first iterate the target string and update the map's count of only alphabets. Then we iterate the array
// whenever we encounter chars of target string we dec. count in map.We comapre those strings, which has all elem. in map, and return the first
// string, with least length.


class Solution {
public:
    string shortestCompletingWord(string word, vector<string>& v) {
        string sh;
        if(v.size()==1) return v[0];
        map<char,int>m,n;
        for(auto ch:word){										// Counting the Alphabet occurances in target string.
            if(ch>=65 && ch<=90)
                ch+=32;
            if(ch>=97 && ch<=122)
                m[ch]++;
            //cout<<"char is: "<<ch<<"and count is: "<<m[ch]<<endl;
        }
        
        //for(auto it=m.begin();it!=m.end();it++)
        //    cout<<"Key is: "<<it->first<<" and value is: "<<it->second<<endl;
        for(int i=0;i<v.size();i++){							// Iterating through the array.
            n=m;
            string temp=v[i];
            for(int j=0;j<temp.length();j++){
                if(temp[j]>=65 && temp[j]<=90)					// Converting the Block Alphabets to small alphabets.
                    temp[j]+=32;
                if(n.count(temp[j])>0){
                    n[temp[j]]--;
                    if(n[temp[j]]==0) n.erase(temp[j]);			// Once, the count of a char is zero, then delete that char from map.
                }
            }
            if(n.empty()){										// Comparing those strngs, which has all contents of map and corresponding count.
                //return v[i];
                if(sh=="")
                    sh=v[i];
                else											// Grabbing the first occurance of shortest string.
                    sh=sh.length()<=v[i].length()?sh:v[i];
            }
        }
        return sh;												// Returning the first occurance of shortest string.
    }
};